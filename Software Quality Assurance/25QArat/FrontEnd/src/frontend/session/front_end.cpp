/* Name: front_end.h
 * Author: Betty Kwong, Devon McGrath, Martin Tuzim
 * Description: This cpp file contains the implementation of the FrontEnd class.
 */

#include "../io/file_handler.h"
#include "../misc/misc.h"
#include "session.h"

#include "front_end.h"

#define DEFAULT_OUT "_TRANSACTIONS.txt"

namespace session {
	
	FrontEnd::FrontEnd() {
		this->transaction_file = DEFAULT_OUT;
	}

	FrontEnd::FrontEnd(bool use_simple_display, std::string users_file,
		std::string items_file, std::string transaction_file) {
		this->use_simple_display = use_simple_display;
		this->users = io::FileReader::ParseUsers(users_file);
		this->items = io::FileReader::ParseItems(items_file);
		this->transaction_file =
			transaction_file.empty()? DEFAULT_OUT : transaction_file;
	}
	
	// Runs the front-end, continuously getting transactions from the user
	// and handling them.
	void FrontEnd::Run() {
		
		// Loop until the user exits or no more input (if redirected)
		while (true) {

			// Setup the terminal
			int last_line = 0;
			if (!use_simple_display) {
				misc::ClearTerminal();
				last_line = misc::PrintMenu(session);
			}

			// Get the transaction
			transaction::Transaction t =
				transaction::TransactionFactory::CreateTransaction(*this);

			// Handle the transaction
			if (HandleTransaction(t, last_line)) {
				session.Log(t);
			}

			// Check if end of input stream
			if (std::cin.eof()) {
				break;
			}
		}
		
	}

	// TODO: finish implementing transaction actions
	// Processes a transaction and returns true if and only if in the
	// context of the current user, they are allowed to perform the
	// transaction and the transaction fields are valid.
	bool FrontEnd::HandleTransaction(transaction::Transaction t, int line) {

		std::string t_name = t.GetName();

		// Check if the user is logged in
		if (session.GetTransactions().size() == 0 && t_name != "login") {
			return false;
		}

		// Check if the user logged in
		if (t_name == "login") {
			
			// Create the new session
			User user = GetUser(GetUserIndex(t.GetFieldValue(0)));
			session = Session(user);

			// Print simple output
			if (use_simple_display) {
				std::cout << "Welcome " << user.GetUsername() << "!" << std::endl;
				char data[64] = "";
				sprintf(data, "Account: %s", user.GetFullType().c_str());
				std::cout << data << std::endl;
				sprintf(data, "Balance: $%.2f", user.GetAccountBalance());
				std::cout << data << std::endl;
			}

			return true;
		}

		// Check if the user is logging out
		if (t_name == "logout") {
			session.Log(t);
			session.EndSession(*this, transaction_file);
			return false;
		}

		// Display
		if (t_name == "display") {

			// If using a simple display
			if (use_simple_display) {
				std::cout << "Available Items:" << std::endl;
				std::cout << "Item Name           Seller          "
					<< "Highest Bid     Days Left Bid" << std::endl;
				for (auto item : items) {
					std::cout << item.ToString() << std::endl;
				}
			}
			
			// If using colour text
			else {
				int col[5] = {4, 25, 42, 59, 70};
				misc::Post((++line)++, col[0], "Available Items:", misc::cyan);
				misc::Post(line, col[0], "Item Name", misc::cyan);
				misc::Post(line, col[1], "Seller", misc::cyan);
				misc::Post(line, col[2], "Highest Bid", misc::cyan);
				misc::Post(line, col[3], "Days Left", misc::cyan);
				misc::Post(line++, col[4], "Bid", misc::cyan);
				for (auto item : items) {
					misc::Post(line, col[0], item.GetName(), misc::purple);
					misc::Post(line, col[1], item.GetSeller(), misc::purple);
					misc::Post(line, col[2], item.GetBuyer(), misc::purple);
					char data[32] = "";
					sprintf(data, "%i", item.GetDaysLeft());
					misc::Post(line, col[3], data, misc::purple);
					sprintf(data, "$%.2f", item.GetCurrentBid());
					misc::Post(line++, col[4], data, misc::purple);
					std::cout << std::endl;
				}
				if (items.empty()) {
					misc::Post(line++, (col[4] + 3 - col[0]) / 2 + col[0] - 23,
						"==================== NONE ====================",
						misc::red);
				}

				// Wait for user to press enter
				std::cout << "\nPress ENTER to continue: ";
				getchar();
			}
			return false; // don't log the 'display' transaction
		}

		// Create user
		if (t_name == "create") {
			User u;
			std::string type = t.GetFieldValue(1);
			if (type == "AA") {
				u = Admin(t.GetFieldValue(0), 0);
			} else if (type == "FS") {
				u = FullStandard(t.GetFieldValue(0), 0);
			} else if (type == "BS") {
				u = BuyStandard(t.GetFieldValue(0), 0);
			} else if (type == "SS") {
				u = SellStandard(t.GetFieldValue(0), 0);
			} else {
				u = User(t.GetFieldValue(0), 0, {"login", "logout", "display"});
			}
			u.Create();
			users.push_back(u);

			// Tell the user the transaction was successful
			std::cout << "User '" << u.GetUsername() << "' successfully created!" << std::endl;
			return true;
		}

		// Delete user
		if (t_name == "delete") {
			std::string username = t.GetFieldValue(0);
			int index = GetUserIndex(username);
			User u = GetUser(index);
			u.Delete();
			SetUser(index, u);
			std::cout << "'" << username << "' successfully deleted!" << std::endl;
			return true;
		}

		// Refund
		if (t_name == "refund") {
			std::string buyer = t.GetFieldValue(0);
			std::string seller = t.GetFieldValue(1);
			double amount = 0;
			try {
				amount = std::stod(t.GetFieldValue(2));
			} catch (...) {}
			char line[128];
			sprintf(line, "%s successfully refunded $%.2f by %s!",
				buyer.c_str(), amount, seller.c_str());
			std::cout << line << std::endl;
			return true;
		}

		// TODO: implement the rest of the transaction functionality

	   return true;
	}

	// Gets the index of an item based on the name
	int FrontEnd::GetItemIndex(const std::string name) {

		// Trivial case
		if (name.empty()) { return -1; }

		// Find the index
		int index = 0;
		for (auto item : items) {
			if (item.GetName() == name) {
				return index;
			}
			index ++;
		}

		return -1;
	}

	// Gets the item at the index
	transaction::Item FrontEnd::GetItem(int index) {
		transaction::Item i;
		if (index < 0 || index >= items.size()) { return i; }
		std::list<transaction::Item>::iterator it = items.begin();
		for (; index > 0; index --) {
			it ++;
		}
		return *it;
	}

	// Gets the index of a user with the specified username
	int FrontEnd::GetUserIndex(const std::string username) {

		// Trivial case
		if (username.empty()) { return -1; }

		// Find the index
		int index = 0;
		for (auto user : users) {
			if (user.GetUsername() == username) {
				return index;
			}
			index ++;
		}

		return -1;
	}

	// Gets the user at the index
	User FrontEnd::GetUser(int index) {
		User u;
		if (index < 0 || index >= users.size()) { return u; }
		std::list<User>::iterator it = users.begin();
		for (; index > 0; index --) {
			it ++;
		}
		return *it;
	}

	// Sets the user at the index
	void FrontEnd::SetUser(int index, User user) {
		if (index < 0 || index >= users.size()) { return; }
		std::list<User>::iterator it = users.begin();
		for (; index > 0; index --) {
			it ++;
		}
		*it = user;
	}

	// Gets the current session
	Session& FrontEnd::GetSession() { return session; }
}
