/* Name: session.h
 * Author: Betty Kwong, Devon McGrath, Martin Tuzim
 * Description: This header contains the definition of the Session class.
 */

#ifndef __session_h__
#define __session_h__

#include <iostream>
#include <list>
#include <string>

#include "../transaction/item.h"
#include "user.h"

namespace transaction { 
	class Transaction;
	class TransactionFactory;
}

namespace session {

	class FrontEnd;
	
	// The Session class represents a front-end session and keeps track of the
	// valid transactions that are performed by the user in the session. The
	// first transaction recorded should be a login.
	class Session {
	public: 
		Session();
		
		Session(User user);
		
		// Logs a valid transaction that happens in the session
		void Log(transaction::Transaction t);
		
		// Ends the session and writes the transactions to the Daily Transaction file
		void EndSession(FrontEnd handler, std::string transaction_file);
		
		// Gets the user of this session
		User& GetUser();
		
		// Gets the list of valid transactions performed in this session
		std::list<transaction::Transaction>& GetTransactions();
	private:

		// The user of this session
		User user;

		// The transactions in this session
		std::list<transaction::Transaction> transactions;
	};
}

#endif
