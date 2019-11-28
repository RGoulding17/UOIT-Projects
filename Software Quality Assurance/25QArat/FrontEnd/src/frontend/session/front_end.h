/* Name: front_end.h
 * Author: Betty Kwong, Devon McGrath, Martin Tuzim
 * Description: This header contains the definition of the FrontEnd class.
 */

#ifndef __front_end_h__
#define __front_end_h__

#include "session.h"
#include "../transaction/transaction.h"

namespace session {
	
	// The FrontEnd class will manage a front-end session and handle
	// transactions made by the user.
    class FrontEnd {
	public:
		FrontEnd();
		
		FrontEnd(bool use_simple_display, std::string users_file,
			std::string items_file, std::string transaction_file);
		
		// Runs the front-end, continuously getting transactions from the user
		// and handling them.
		void Run();

		// Gets the index of an item based on the name
		int GetItemIndex(const std::string name);

		// Gets the item at the index
		transaction::Item GetItem(int index);

		// Gets the index of a user with the specified username
		int GetUserIndex(const std::string username);

		// Gets the user at the index
		User GetUser(int index);

		// Sets the user at the index
		void SetUser(int index, User user);

		// Gets the current session
		Session& GetSession();

	private:

		// Flag used to indicate that non-colour printing should be used
		bool use_simple_display;

		// The current session object
		Session session;
		
		// Processes a transaction and returns true if and only if in the
		// context of the current user, they are allowed to perform the
		// transaction and the transaction fields are valid.
		bool HandleTransaction(transaction::Transaction t, int line);

		// The list of users from the user accounts file
		std::list<session::User> users;

		// The list of items from the current items file
		std::list<transaction::Item> items;

		// The transaction file to write to
		std::string transaction_file;
    };
}


#endif
