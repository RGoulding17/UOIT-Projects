#ifndef __misc_h__
#define __misc_h__

#include <iostream>
#include <list>
#include <string>

#include "../session/session.h"

namespace misc {

	enum colour { black = 30, red, green, brown, blue, purple, cyan, grey };
  
	// Posts text to the terminal on a specific line and column
	// with a specified colour
	void Post(int line, int col, std::string text, int colour_code){
		printf("\033[0;%im\033[%i;%iH%s\033[0m",
			colour_code, line, col, text.c_str());
	}

	// Clears the terminal
	void ClearTerminal() {
		//J = clear, 2J = clear whole screen
		//line ; col H = cursor position
		//https://en.wikipedia.org/wiki/ANSI_escape_code
		std::cout << "\033[2J\033[1;1H";
	}

	// Prints the menu relevant to the session
	int PrintMenu(session::Session session) {

		// Post some graphics
		Post(1, 3, "   _____", purple);                       
		Post(2, 3,"  /     \\   ____   ____  __ __ ", purple);
		Post(3, 3," /  \\ /  \\_/ __ \\ /    \\|  |  \\", purple);
		Post(4, 3, "/    Y    \\  ___/|   |  \\  |  /", purple);
		Post(5, 3, "\\____|__  /\\___  >___|  /____/", purple); 
		Post(6, 3, "        \\/     \\/     \\/      ", purple);

		// Print user info
		session::User u = session.GetUser();
		std::string name = u.GetUsername();
		if (!name.empty()) {
			Post(3, 40, "Welcome " + name + "!", cyan);
			char data[64] = "";
			sprintf(data, "Account: %s", u.GetFullType().c_str());
			Post(4, 40, data, cyan);
			sprintf(data, "Balance: $%.2f", u.GetAccountBalance());
			Post(5, 40, data, cyan);
		}

		// Post options
		std::list<std::string> privs = u.GetPrivileges();
		bool loggedIn = session.GetTransactions().size() != 0;
		if (!loggedIn) {
			Post(7, 5, "Please login", purple);
		}
		if (privs.empty()) {
			privs.push_back(loggedIn? "logout" : "login");
		}
		std::list<std::string>::iterator it = privs.begin();
		std::list<std::string>::iterator end = privs.end();
		int line = 9;
		Post(8, 4, "Options:", cyan);
		for (; it != end;) {
			std::string txt = "";
			for (int i = 0; i < 4 && it != end; i ++) {
				if (loggedIn && *it == "login") {
					i --;
					it ++;
					continue;
				}
				Post(line, 5 + 12 * i, *it, cyan);
				it ++;
			}
			line ++;
		}
		Post(++line, 0, "", green);
		
		return line;
    }
}

#endif