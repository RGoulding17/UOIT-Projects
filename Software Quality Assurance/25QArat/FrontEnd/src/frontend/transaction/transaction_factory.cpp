/* Name: transaction_factory.cpp
 * Authors: Devon McGrath
 * Description: This cpp file contains the implementation of the
 * TransactionFactory class.
 */

#include "../io/file_handler.h"
#include "../session/front_end.h"
#include "../io/scanner.h"

#include "transaction.h"

namespace transaction {

	#define T_LOGIN "login"
	#define T_LOGOUT "logout"
	#define T_CREATE "create"
	#define T_DELETE "delete"
	#define T_ADVERTISE "advertise"
	#define T_BID "bid"
	#define T_REFUND "refund"
	#define T_ADDCREDIT "addcredit"
	#define T_DISPLAY "display"

	// Checks that the string starts with a valid transaction name.
	// The transaction name is the substring of 'input' from index 0
	// to the first whitespace character or end of string (whichever comes first).
	bool TransactionFactory::Exists(std::string input) {
		
		// Get only the transaction name
		int n = input.find("\n");
		if (n >= 0 && n < input.length()) {
			input = input.substr(0, n);
		}
		
		// Check if it exists
		std::list<std::string> valid = {T_LOGIN, T_LOGOUT, T_CREATE,
			T_DELETE, T_ADVERTISE, T_BID, T_REFUND, T_ADDCREDIT,
			T_DISPLAY};
		std::list<std::string>::iterator it = valid.begin();
		for (; it != valid.end(); it++) {
			if (input == *it) {return true;}
		}
		
		return false;
	}
	
	// Uses the Scanner class to get input from a user to create a transaction.
	// Returns: a Transaction object that represents what the user entered.
	Transaction TransactionFactory::CreateTransaction(session::FrontEnd session) {
		
		std::list<std::string> outputs = {">> "};
		std::string t_name;
		while (true) {
			
			// Get the transaction name
			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) { // EOF reached
				break;
			}
			t_name = inputs.front();
			
			// Check if the transaction is valid
			if (TransactionFactory::Exists(t_name)) { // transaction exists
				
				// Check if user can perform the action
				transaction::Transaction t = transaction::Transaction(t_name, {});
				bool loggedIn = session.GetSession().GetTransactions().size() != 0;
				bool isLogin = (t_name == T_LOGIN);
				bool canPerform = session.GetSession().GetUser().CanPerform(t);

				// Valid transaction
				if (!(loggedIn && isLogin) && ((loggedIn && canPerform) || (!loggedIn && isLogin))) {
					break;
				}
				
				// User cannot do this action
				else if (loggedIn && isLogin) {
					std::cout << "ERROR: A user is already logged in!" << std::endl;
				} else if (loggedIn) {
					std::cout << "ERROR: The user logged in cannot perform this action." << std::endl;
				} else {
					std::cout << "ERROR: No user is logged in." << std::endl;
				}
			} else { // transaction does not exists
				std::cout << "ERROR: The transaction '" << t_name << "' does not exist." << std::endl;
			}
		}
		
		// Get the arguments/fields
		std::list<std::string> args = {};

		// Login transaction
		if (t_name == T_LOGIN) {
			args = TransactionFactory::GetLoginArguments(session);
		}
		
		// Create transaction
		else if (t_name == T_CREATE) {
			args = TransactionFactory::GetCreateArguments(session);
		}
		
		// Delete transaction
		else if (t_name == T_DELETE) {
			args = TransactionFactory::GetDeleteArguments(session);
		}
		
		// Advertise
		else if (t_name == T_ADVERTISE) {
			args = TransactionFactory::GetAdvertiseArguments(session);
		}
		
		// Bid transaction
		else if (t_name == T_BID) {
			args = TransactionFactory::GetBidArguments(session);
		}
		
		// Refund transaction
		else if (t_name == T_REFUND) {
			args = TransactionFactory::GetRefundArguments(session);
		}
		
		// Addcredit transaction
		else if (t_name == T_ADDCREDIT) {
			args = TransactionFactory::GetAddcreditArguments(session);
		}

		// Check if it failed
		if (args.empty() && t_name != T_LOGOUT && t_name != T_DISPLAY) {
			t_name = "";
		}
		
		return Transaction(t_name, args);
	}
	
	// Gets the field data for the login transaction
	std::list<std::string> TransactionFactory::GetLoginArguments(
		session::FrontEnd session) {

		std::list<std::string> outputs = {"Enter username: "};
		std::list<std::string> args;
		while (true) {

			// Get the username
			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			std::string username = inputs.front();
			if (username.empty()) {
				std::cout << "ERROR: You must enter a username!" << std::endl;
				continue;
			} else if (username.length() > 15) {
				username = username.substr(0, 15);
			}

			// Trim whitespace
			io::trim(username);

			// Check if username exists
			if (session.GetUserIndex(username) >= 0) {
				args.push_back(username);
				break;
			}

			// Not found
			std::cout << "ERROR: The username '" << username << "' does not exist!" << std::endl;
		}
		
		return args;
	}
	
	// Gets the field data for the create transaction
	std::list<std::string> TransactionFactory::GetCreateArguments(
		session::FrontEnd session) {
		
		// Get the username
		std::list<std::string> outputs = {"Enter username (15 char. max): "};
		std::list<std::string> args;// = io::Scanner::ReadParts(outputs, 1);
		std::string username = "";
		while (true) {

			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			username = inputs.front();

			// Basic checks
			if (username.empty()) {
				std::cout << "ERROR: You must enter a username!" << std::endl;
				continue;
			} else if (username.length() > 15) {
				username = username.substr(0, 15);
			}

			// Trim whitespace
			io::trim(username);

			// Check if username exists
			if (session.GetUserIndex(username) < 0) {
				args.push_back(username);
				break;
			}

			// Username exists
			std::cout << "ERROR: The user '" << username << "' already exists!" << std::endl;
		}
		
		// Get the user type
		outputs = {"Enter the type of user:\n\tadmin\n\tfull-standard | fs\n\tbuy-standard | bs\n\tsell-standard | ss\n>> "};
		std::string type;
		while (true) {

			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			type = inputs.front();
			
			// Convert to 2 char form
			if (type == "admin") {type = "AA"; break;}
			else if (type == "fs" || type == "full-standard") {
				type = "FS";
				break;
			} else if (type == "bs" || type == "buy-standard") {
				type = "BS";
				break;
			} else if (type == "ss" || type == "sell-standard") {
				type = "SS";
				break;
			}
			
			// Not valid
			else {
				std::cout << "ERROR: '" << type << "' is not a valid user type!" << std::endl;
			}
		}
		args.push_back(type);
		
		return args;
	}
	
	// Gets the field data for the delete transaction
	std::list<std::string> TransactionFactory::GetDeleteArguments(
		session::FrontEnd session) {
		
		// Get the username to delete
		std::list<std::string> outputs = {"Enter the username to delete: "};
		std::list<std::string> args;
		while (true) {

			// Get the username
			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			std::string username = inputs.front();
			if (username.empty()) {
				std::cout << "ERROR: You must enter a username!" << std::endl;
				continue;
			} else if (username.length() > 15) {
				username = username.substr(0, 15);
			}

			// Trim whitespace
			io::trim(username);

			// Check if username exists
			int index = session.GetUserIndex(username);
			bool admin = index < 0? false : session.GetUser(index).GetType() == "AA";
			if (index >= 0 && !admin) {
				args.push_back(username);
				break;
			}

			// Not found
			if (index < 0) {
				std::cout << "ERROR: The user '" << username << "' does not exist!" << std::endl;
			}
			
			// User is an admin
			else {
				std::cout << "ERROR: The user '" << username
					<< "' is an admin and cannot be deleted!" << std::endl;
			}
		}
		
		return args;
	}
	
	// TODO: more checking
	// Gets the field data for the bid transaction
	std::list<std::string> TransactionFactory::GetAdvertiseArguments(
		session::FrontEnd session) {
		
		// Get the item name
		std::list<std::string> outputs = {"Enter the item name (19 char. max): "};
		std::list<std::string> args;
		while (true) {

			// Get the item name
			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			std::string name = inputs.front();

			// Trim whitespace and make sure it is at most 19 chars
			if (name.length() > 19) {
				name = name.substr(0, 19);
			}
			io::trim(name);

			// Validate
			if (name.empty()) {
				std::cout << "ERROR: You must enter an item name!" << std::endl;
				continue;
			} else if (session.GetItemIndex(name) >= 0) {
				std::cout << "ERROR: The item '" << name 
					<< "' already exists!" << std::endl;
				continue;
			}

			args.push_back(name);
			break;
		}

		// Get the minimum bid
		outputs = {"Enter the minimum bid (in dollars): "};
		while (true) {

			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			
			double min_bid = 0;
			try {
				min_bid = std::stod(inputs.front());
			} catch (...) {}

			// Validate
			if (min_bid >= 1000) {
				std::cout << "ERROR: The max bid allowed is $999.99!" << std::endl;
				continue;
			}

			args.push_back(inputs.front());
			break;
		}

		// Get the days for auction
		outputs = {"Enter the number of days for auction (max 100): "};
		while (true) {
			
			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			
			int days = 0;
			try {
				days = std::stoi(inputs.front());
			} catch (...) {}

			// Validate
			if (days > 100) {
				std::cout << "ERROR: " << days 
					<< " is more than the max of 100 days!" << std::endl;
				continue;
			}

			args.push_back(inputs.front());
			break;
		}

		// Made it this far, must be valid
		std::cout << "'" << args.front()
			<< "' successfully added to the auction!" << std::endl;
		
		return args;
	}
	
	// Gets the field data for the refund transaction
	std::list<std::string> TransactionFactory::GetBidArguments(
		session::FrontEnd session) {
		
		// Get the item name
		std::list<std::string> args = {};
		std::list<std::string> outputs = {"Enter the item name: "};
		transaction::Item i;
		while (true) {

			// Get the item name
			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}

			// Check if the item exists
			io::trim(inputs.front());
			int index = session.GetItemIndex(inputs.front());
			if (index < 0) {
				std::cout << "ERROR: The item '" << inputs.front()
					<< "' does not exist!" << std::endl;
				continue;
			}
			args.push_back(inputs.front());
			i = session.GetItem(index);
			break;
		}

		// Get the number of days left and seller
		while (true) {

			// Get the days left
			outputs = {"Enter the number of days until auction: "};
			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			std::string in = inputs.front();
			int days_left = 0;
			try {
				days_left = std::stoi(in);
			} catch (...) {}

			// Get the seller
			outputs = {"Enter the seller's username: "};
			inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}

			// Check that it's valid
			if (i.GetSeller() != inputs.front()) {
				std::cout << "ERROR: That user is not selling this item." << std::endl;
				continue;
			} else if (i.GetDaysLeft() != days_left) {
				std::cout << "ERROR: There are " << i.GetDaysLeft()
					<< " days left for this item." << std::endl;
				continue;
			}

			args.push_back(in);
			args.push_back(inputs.front());
			break;
		}

		// Display item info
		char line[64] = "";
		sprintf(line, "Current bid: $%.2f", i.GetCurrentBid());
		std::cout << line << std::endl;

		// Get the new bid
		session::User u = session.GetSession().GetUser();
		bool admin = u.GetType() == "AA";
		outputs = {"New bid: "};
		double new_bid;
		while (true) {

			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			new_bid = 0;
			try {
				new_bid = std::stod(inputs.front());
			} catch (...) {}

			// Check bid
			if (new_bid <= i.GetCurrentBid()) {
				std::cout << "ERROR: The new bid must be more than the current bid!" << std::endl;
				continue;
			} else if (u.GetAccountBalance() - new_bid < 0) {
				std::cout << "ERROR: Insufficient funds!" << std::endl;
				continue;
			} else if (!admin && i.GetCurrentBid() * 1.05 > new_bid) {
				std::cout << "ERROR: The new bid must be 1.05x more than the current bid!" << std::endl;
				continue;
			} else if (new_bid >= 1000) {
				std::cout << "ERROR: Exceeded maximum bid of $999.99" << std::endl;
				continue;
			}

			args.push_back(inputs.front());
			break;
		}

		// If the user made it here, the bid was successful
		std::cout << "Bid successful!" << std::endl;
		sprintf(line, "Account: $%.2f", u.GetAccountBalance() - new_bid);
		std::cout << line << std::endl;
		
		return args;
	}
	
	// Gets the field data for the addcredit transaction
	std::list<std::string> TransactionFactory::GetRefundArguments(
		session::FrontEnd session) {
		
		// Get the buyer and seller's usernames
		std::list<std::string> args = {};
		std::list<std::string> outputs = {"Enter the username of the buyer: "};
		for (int i = 0; i < 2; i ++) {
			while (true) {

				// Get the username
				std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
				if (inputs.empty()) {
					return {};
				}
				std::string username = inputs.front();
				if (username.empty()) {
					std::cout << "ERROR: You must enter a username!" << std::endl;
					continue;
				} else if (username.length() > 15) {
					username = username.substr(0, 15);
				}

				// Trim whitespace
				io::trim(username);

				// Check if username exists
				int index = session.GetUserIndex(username);
				if (index >= 0) {
					args.push_back(username);
					break;
				}

				// Not found
				std::cout << "ERROR: The user '" << username
					<< "' does not exist!" << std::endl;
			}
			outputs = {"Enter the username of the seller: "};
		}

		// Get the amount
		outputs = {"Enter the refund amount: "};
		while (true) {

			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}

			// Parse the input
			double amount = 0;
			try {
				amount = std::stod(inputs.front());
			} catch (...) {
				std::cout << "ERROR: '" << inputs.front()
					<< "' is not a valid value!" << std::endl;
				continue;
			}
			
			// Check it
			if (amount < 0) {
				std::cout << "ERROR: Cannot refund a negative amount!" << std::endl;
				continue;
			}

			args.push_back(inputs.front());
			break;
		}
		
		return args;
	}
	
	std::list<std::string> TransactionFactory::GetAddcreditArguments(
		session::FrontEnd session) {
		
		// Get the amount of credit
		std::list<std::string> args = {};
		std::list<std::string> outputs = {"Enter the amount of credit to add: "};
		bool admin = session.GetSession().GetUser().GetType() == "AA";
		double amount;
		while (true) {

			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}

			// Parse the input
			amount = 0;
			try {
				amount = std::stod(inputs.front());
			} catch (...) {
				std::cout << "ERROR: '" << inputs.front()
					<< "' is not a valid credit value." << std::endl;
				continue;
			}
			
			// Check it
			if (amount < 0) {
				std::cout << "ERROR: Cannot add a negative amount!" << std::endl;
				continue;
			} else if (admin && amount > 1000) {
				char line[128];
				sprintf(line, "ERROR: $%.2f is more than the max of $1000.00.",
					amount);
				std::cout << line << std::endl;
				continue;
			}

			args.push_back(inputs.front());
			break;
		}

		// Non-admin
		if (!admin) {
			char line[128];
			sprintf(line, "Success! Added $%.2f credit to the system.", amount);
			std::cout << line << std::endl;

			return args;
		}

		// Admin, get the username
		outputs = {"Enter the username to add credit to: "};
		std::string username;
		while (true) {

			// Get the username
			std::list<std::string> inputs = io::Scanner::ReadParts(outputs, 1);
			if (inputs.empty()) {
				return {};
			}
			username = inputs.front();

			// Trim whitespace and make sure it is under the limit
			if (username.length() > 15) {
				username = username.substr(0, 15);
			}
			io::trim(username);

			// Check if username exists
			if (username.empty()) {
				std::cout << "ERROR: You must enter a username!" << std::endl;
				continue;
			} else if (session.GetUserIndex(username) >= 0) {
				args.push_back(username);
				break;
			}

			// Not found
			std::cout << "ERROR: The user '" << username << "' does not exist." << std::endl;
		}

		// Add the success message
		char line[128];
		sprintf(line, "Success! Added $%.2f credit to '%s'.",
			amount, username.c_str());
		std::cout << line << std::endl;
		
		return args;
	}
}