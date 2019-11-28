/* Name: user.h
 * Authors: Betty Kwong, Devon McGrath, Martin Tuzim
 * Description: This header file contains the definition of the User classes, which
 * are used to represent all users of the system.
 */

#ifndef __user_h__
#define __user_h__

#include <list>
#include <string>


namespace transaction { class Transaction; }

namespace session {
		
	#define MAX_BALANCE 999999.99
	#define MAX_USERNAME_LENGTH 15
	#define NORMAL_STATE 0
	#define DELETE_STATE 1
	#define CREATE_STATE 2

	// A generic User class that represents a user of the system with specific privileges.
	class User {
	public:
		User();
		
		User(std::string username, double account_balance, std::list<std::string> privileges);
		
		// Checks if the user can perform the transaction specified
		bool CanPerform(transaction::Transaction t) const;
		
		// Gets the username
		std::string GetUsername() const;
		
		// Sets the user's username and ensures it is not more than 15 characters.
		void SetUsername(const std::string username);
		
		// Gets the user's account balance
		double GetAccountBalance() const;
		
		// Sets the new account balance, ensuring it is between 0 and 999,999.99
		// (inclusive).
		void SetAccountBalance(double new_balance);
		
		// Gets the list of user privileges
		std::list<std::string>& GetPrivileges();
		
		// Sets the list of user privileges
		void SetPrivileges(std::list<std::string> privileges);

		// Gets the two character user type ID
		std::string GetType() const;

		// Gets the full account type name (e.g. admin)
		std::string GetFullType() const;

		// Sets the two character user type ID
		void SetType(const std::string type);

		// Deletes the user (sets the state to deleted)
		void Delete();

		// Sets the state to the created state (i.e. can't modify this session)
		void Create();

		// Gets the state of the user object
		int GetState() const;

		// A boolean flag determined by the state as to whether the user object
		// *should* be modified, it does not stop modification itself
		bool CanModify() const;

		// Adjusts the net value added since the start of the session
		int AdjustNet(const int val);
	protected:
		// The username of the user
		std::string username;

		// The current account balance
		double account_balance = 0.0f;

		// The list of transaction privileges
		std::list<std::string> privileges = {};

		// The type of user ID
		std::string type = "ER";

		// Determines whether the user object can be interacted with
		int state = NORMAL_STATE;

		// The net difference from the start of the session until now
		int net;
	};

	// The Admin class represents an admin user on the system who can perform
	// any kind of transaction.
	class Admin: public User {
	public:
		Admin();
		Admin(std::string username, double account_balance);
	};

	// The FullStandard class represents a full-standard user which can bid,
	// advertise, etc.
	class FullStandard: public User {
	public:
		FullStandard();
		FullStandard(std::string username, double account_balance);
	};

	// The BuyStandard class represents a buy-standard user which can bid, etc.
	class BuyStandard: public User {
	public:
		BuyStandard();
		BuyStandard(std::string username, double account_balance);
	};

	// The SellStandard class represents a sell-standard user which can
	// advertise, etc.
	class SellStandard: public User {
	public:
		SellStandard();
		SellStandard(std::string username, double account_balance);
	};
}

#endif
