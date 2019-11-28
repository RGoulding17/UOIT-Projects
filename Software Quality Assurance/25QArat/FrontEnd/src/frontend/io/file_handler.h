#ifndef __file_handler_h__
#define __file_handler_h__

#include <algorithm>
#include <list>
#include <string>

#include "../transaction/item.h"
#include "../session/user.h"

namespace io {

	// ----- HELPER FUNCTIONS FOR PARSING -----
	// Removes spaces from the start of a string
    static inline void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        std::not1(std::ptr_fun<int, int>(std::isspace))));
    }

    // Removes spaces from the end of a string
    static inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(),
        std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    }

    // Removes spaces from the start and end of a string
    static inline void trim(std::string &s) {
        ltrim(s);
        rtrim(s);
    }
	
	// The FileReader class reads data from a file
	class FileReader {
	public:
		// Reads from a file and returns the data as a list of lines
		static std::list<std::string> Read(const std::string path);

		// Parses the available items file and gets the items in it
		static std::list<transaction::Item> ParseItems(
			const std::string avail_items_file);
		
		// Parses the current user accounts file and gets the users
		static std::list<session::User> ParseUsers(
			const std::string user_accounts_file);
	};

	// The FileWriter class writes and appends data to a file
	class FileWriter {
	public:
	
		// Writes data to a file and returns true if successful
		static bool Write(const std::string path,
			std::list<std::string> data);
		
		// Appends data to a file and returns true if successful
		static bool Append(const std::string path,
			std::list<std::string> data);
	private:
		static bool WriteData(const std::string path,
			std::list<std::string> data, bool append);
	};
}

#endif
