/* Name: transaction.h
 * Authors: Devon McGrath
 * Description: This header file contains the declaration for the
 * Transaction and TransactionFactory classes.
 */

#include "transaction.h"

namespace transaction {
    Transaction::Transaction() {}
		
	Transaction::Transaction(std::string name, std::list<std::string> data) {
		this->name = name;
		this->data = data;
	}
	
	// Gets the name of the transaction (e.g. login)
	std::string& Transaction::GetName() { return name; }
	
	// Gets the specified field value from the transaction
	std::string Transaction::GetFieldValue(const int& index) const {

		// Out of range
		if (index < 0 || index >= data.size()) { return ""; }

		// Get the value
		std::list<std::string>::const_iterator it = data.begin();
		for (int i = 0; i < index; i ++) {
			it ++;
		}
		return *it;
	}
	
	// Sets the specifed field value. For example, setting 0 to "abc" on the
	// login transaction would set the username to "abc".
	void Transaction::SetFieldValue(const int& index, std::string value) {
		
		// Nothing to set
		if (index < 0 || index >= data.size()) { return; }

		// Set the value
		// TODO: set value
	}
	
	// Gets the list of field values for this transaction
	std::list<std::string>& Transaction::GetFieldValues() { return data; }
}