/* CSCI 3060U - Software Quality Assurance - Front-End
 * Name: main.cpp
 * Authors: Betty Kwong, Devon McGrath, Martin Tuzim
 * Description: This cpp file starts the front-end and contains the main method.
 *
 * =========================== PROGRAM DESCRIPTION ===========================
 * Description:
 * This program is an Auction/Bidding system which allows users to sell and bid
 * on items. It is the front-end and does all the front-end processing. Users
 * are able to use it in sessions, where a session is the set of transactions
 * starting from login to logout.
 *
 * The front-end is similar to other terminal applications (e.g. Command Prompt)
 * and takes transactions (commands) which perform various actions. These include:
 * login	 - Logs a user into the system
 * logout	 - Logs a user out of a session
 * create	 - Creates a new user
 * delete	 - Deletes a user from the system
 * advertise - Puts a new item up for auction
 * bid		 - Places a bid on an item
 * refund	 - Refunds a user account
 * addcredit - Adds credit to a user account
 * display	 - Displays the list of available items
 *
 * In addition to transactions, there are four different types of users:
 * admin		 - Full privileges
 * Full-Standard - Has permission to buy and sell items
 * Buy-Standard	 - Has permission to buy items
 * Sell-Standard - Has permission to sell items
 *
 * The front-end interacts with three main files: 1) the Daily Transaction file,
 * 2) the Current User Accounts, and 3) the Available Items file. At the end of
 * each session, the transactions that successfully occurred during the session
 * are appended to the Daily Transaction file. The back-end will do the overnight
 * batch processing on the Daily Transaction file to update the Current User
 * Accounts and Available Items files. The Current User Accounts and Available
 * Items files are used by the front-end to ensure that users can buy and sell
 * items.
 */

#include <string.h>

#include "./session/front_end.h"

int main(int argc, char** argv) {

	int test_flag_index = -1;
	std::string in_users_file = "";
	std::string in_items_file = "";
	std::string out_transaction_file = "";

	// Check for testing flag
	for (int i = 1; i < argc; i ++) {
		if (strcmp(argv[i], "-test") == 0) {
			test_flag_index = i;
			break;
		}
	}

	// Get the file paths, if any
	int index = 0;
	for (int i = 1; i < argc; i ++) {
		if (i == test_flag_index) { continue; }
		if (index == 0) {
			in_users_file = argv[i];
		} else if (index == 1) {
			in_items_file = argv[i];
		} else if (index == 2) {
			out_transaction_file = argv[i];
		} else {
			break;
		}
		index ++;
	}
	
	// Start the front end
	session::FrontEnd front_end (test_flag_index >= 0,
		in_users_file, in_items_file, out_transaction_file);
	front_end.Run();

	return 0;
}