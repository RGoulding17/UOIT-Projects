/* Name: user.cpp
 * Authors: Devon McGrath
 * Description: This cpp file contains the implementation of the User class,
 * which is used to represent all users of the system.
 */
 
#include "user.h"
#include "../transaction/transaction.h"

namespace transaction { class Transaction; }

namespace session {
	User::User() {}
	User::User(std::string username, double account_balance, std::list<std::string> privileges) :
				username(username), account_balance(account_balance), privileges(privileges) {}

	std::string User::GetUsername() const {return username;}

	void User::SetUsername(const std::string username) {
		this->username = username;
	}

	double User::GetAccountBalance() const {return account_balance;}

	void User::SetAccountBalance(double new_balance) {
		new_balance = (new_balance < 0)? 0 : new_balance;
		new_balance = (new_balance > MAX_BALANCE)? MAX_BALANCE : new_balance;
		this->account_balance = new_balance;
	}

	bool User::CanPerform(transaction::Transaction t) const {

		// Check if user can perform this
		std::string t_name = t.GetName();
		std::list<std::string>::const_iterator it = privileges.begin();
		std::list<std::string>::const_iterator end = privileges.end();
		for (; it != end;) {
			if (t_name == *it) { return true; }
			it ++;
		}
		
		return false;
	}

	std::list<std::string>& User::GetPrivileges() {
		return privileges;
	}
		
	void User::SetPrivileges(std::list<std::string> privileges) {
		this->privileges = privileges;
	}

	std::string User::GetType() const { return this->type; }

	std::string User::GetFullType() const {
		if (type == "AA") {
			return "admin";
		} else if (type == "FS") {
			return "full-standard";
		} else if (type == "BS") {
			return "buy-standard";
		} else if (type == "SS") {
			return "sell-standard";
		}

		return "unknown";
	}

	void User::SetType(const std::string type) {
		this->type = type;
	}

	// Deletes the user (sets the state to deleted)
	void User::Delete() {
		this->state = DELETE_STATE;
	}

	// Sets the state to the created state (i.e. can't modify this session)
	void User::Create() {
		this->state = CREATE_STATE;
	}

	// Gets the state of the user object
	int User::GetState() const {
		return state;
	}

	// A boolean flag determined by the state as to whether the user object
	// *should* be modified, it does not stop modification itself
	bool User::CanModify() const {
		return state == NORMAL_STATE;
	}

	int User::AdjustNet(const int val) {
		this->net += val;
		return net;
	}

	Admin::Admin() {}
	Admin::Admin(std::string username, double account_balance)
		: User::User(username,account_balance,{"login", "logout", "create",
		"delete", "advertise", "bid", "refund", "addcredit", "display"}) {
		this->type = "AA";
	}

	FullStandard::FullStandard() {}
	FullStandard::FullStandard(std::string username, double account_balance)
		: User::User(username,account_balance,{"login", "logout",
		"advertise", "bid", "addcredit", "display"}) {
		this->type = "FS";
	}

	BuyStandard::BuyStandard() {}
	BuyStandard::BuyStandard(std::string username, double account_balance)
		: User::User(username,account_balance,{"login", "logout",
		"bid", "addcredit", "display"}) {
		this->type = "BS";
	}

	SellStandard::SellStandard() {}
	SellStandard::SellStandard(std::string username, double account_balance)
		: User::User(username,account_balance,{"login", "logout",
		"advertise", "addcredit", "display"}) {
		this->type = "SS";
	}
}