#include "../io/file_handler.h"
#include "front_end.h"
#include "../transaction/transaction.h"

#include "session.h"

namespace session {
    Session::Session() {}

    Session::Session(User user) : user(user) {}

	User& Session::GetUser() { return user; }

	std::list<transaction::Transaction>& Session::GetTransactions() { return transactions; }

	void Session::Log(transaction::Transaction t) {
		this->transactions.push_back(t);
	}

	void Session::EndSession(FrontEnd handler, std::string transaction_file) {

		// Process the transactions
		std::list<std::string> lines;
		for (auto t : transactions) {

			std::string n = t.GetName();
			char line[128];

			// Login
			if (n == "login") {
				sprintf(line, "10 %-15.15s %-2s %09.2f", user.GetUsername().c_str(),
					user.GetType().c_str(), user.GetAccountBalance());
				lines.push_back(line);
			}

			// Logout
			else if (n == "logout") {
				sprintf(line, "00 %-15.15s %-2s %09.2f", user.GetUsername().c_str(),
					user.GetType().c_str(), user.GetAccountBalance());
				lines.push_back(line);
			}

			// Delete or create
			else if (n == "delete" || n == "create") {

				// Get the user
				int index = handler.GetUserIndex(t.GetFieldValue(0));
				bool create = n == "create";
				if (index < 0 && !create) { continue; }
				User u2 = create? User(t.GetFieldValue(0), 0, {}) : handler.GetUser(index);
				if (create) {
					u2.SetType(t.GetFieldValue(1));
				}

				// Get the line
				sprintf(line, "0%i %-15.15s %-2s %09.2f",
					create? 1 : 2,
					u2.GetUsername().c_str(), u2.GetType().c_str(),
					u2.GetAccountBalance());
				lines.push_back(line);
			}
			
			// Refund
			else if (n == "refund") {
				double amount = 0;
				try {
					amount = std::stod(t.GetFieldValue(2));
				} catch (...) {}
				amount = amount < 0? -amount : amount;
				sprintf(line, "05 %-15.15s %-15.15s %09.2f",
					t.GetFieldValue(0).c_str(), t.GetFieldValue(1).c_str(),
					amount);
				lines.push_back(line);
			}

			// Advertise
			else if (n == "advertise") {

				// Get values
				double bid = 0;
				int days = 0;
				try {
					bid = std::stod(t.GetFieldValue(1));
				} catch (...) {}
				try {
					days = std::stoi(t.GetFieldValue(2));
				} catch (...) {}
				bid = bid < 0? -bid : bid;
				days = days < 0? 0 : days;

				// Create the line
				sprintf(line, "03 %-19.19s %-15.15s %03i %06.2f",
					t.GetFieldValue(0).c_str(), user.GetUsername().c_str(),
					days, bid);
				lines.push_back(line);
			}

			// Bid: item name, days to auction, seller's username, new bid
			else if (n == "bid") {

				// Get the new bid
				double bid = 0;
				try {
					bid = std::stod(t.GetFieldValue(3));
				} catch (...) {}
				bid = bid < 0? -bid : bid;

				// Create the line
				sprintf(line, "04 %-19.19s %-15.15s %-15.15s %06.2f",
					t.GetFieldValue(0).c_str(), t.GetFieldValue(2).c_str(),
					user.GetUsername().c_str(), bid);
				lines.push_back(line);
			}

			// Add credit
			else if (n == "addcredit") {

				std::string username = user.GetUsername();
				std::string type = user.GetType();
				double bal = 0;
				try {
					bal = std::stod(t.GetFieldValue(0));
				} catch (...) {}
				bool admin = type == "AA";
				if (admin) {
					username = t.GetFieldValue(1);
					int index = handler.GetUserIndex(username);
					User u = handler.GetUser(index);
					type = u.GetType();
					u.SetAccountBalance(u.GetAccountBalance() + bal);
					bal = u.GetAccountBalance();
					handler.SetUser(index, u);
				}

				// Get the line
				sprintf(line, "06 %-15.15s %-2s %09.2f",
					username.c_str(), type.c_str(), bal);
				lines.push_back(line);
			}
		}
		io::FileWriter::Append(transaction_file, lines);

		// Clear transactions and logged in user
		this->transactions = {};
		this->user = User();
	}
}