/* Name: transaction.h
 * Author: Betty Kwong, Devon McGrath, Martin Tuzim
 * Description: This header contains the definition of the Transaction and
 * TransactionFactory classes.
 */

#ifndef __transaction_h__
#define __transaction_h__

#include <list>
#include <string>

#include "../session/session.h"

namespace session { class FrontEnd; }

namespace transaction {

	// The Transaction class represents a transaction which performs an action.
	class Transaction {
	public:
		Transaction();
		
		Transaction(std::string name, std::list<std::string> data);
		
		// Gets the name of the transaction (e.g. login)
		std::string& GetName();
		
		// Gets the specified field value from the transaction
		std::string GetFieldValue(const int& index) const;
		
		// Sets the specifed field value. For example, setting 0 to "abc" on the
		// login transaction would set the username to "abc".
		void SetFieldValue(const int& index, std::string value);
		
		// Gets the list of field values for this transaction
		std::list<std::string>& GetFieldValues();
	private:
		std::string name;
		std::list<std::string> data;
	};

	// The TransactionFactory factory is responsible for generating transactions.
	class TransactionFactory {
	public:
		// Checks that the string starts with a valid transaction name.
		// The transaction name is the substring of 'input' from index 0
		// to the first whitespace character or end of string (whichever comes first).
		static bool Exists(std::string input);

		// Uses the Scanner class to get input from a user to create a
		// transaction.
		// Returns: a Transaction object that represents what the user entered.
		static Transaction CreateTransaction(session::FrontEnd session);
		
	private:
		// Gets the field data for the login transaction
		static std::list<std::string> GetLoginArguments(session::FrontEnd session);
		
		// Gets the field data for the create transaction
		static std::list<std::string> GetCreateArguments(session::FrontEnd session);
		
		// Gets the field data for the delete transaction
		static std::list<std::string> GetDeleteArguments(session::FrontEnd session);
		
		// Gets the field data for the advertise transaction
		static std::list<std::string> GetAdvertiseArguments(session::FrontEnd session);
		
		// Gets the field data for the bid transaction
		static std::list<std::string> GetBidArguments(session::FrontEnd session);
		
		// Gets the field data for the refund transaction
		static std::list<std::string> GetRefundArguments(session::FrontEnd session);
		
		// Gets the field data for the addcredit transaction
		static std::list<std::string> GetAddcreditArguments(session::FrontEnd session);
	};
}

#endif
