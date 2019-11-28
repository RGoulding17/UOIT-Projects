/* Name: scanner.h
 * Author: Betty Kwong, Devon McGrath, Martin Tuzim
 * Description: This header contains the definition of the Scanner class.
 */

#ifndef __scanner_h__
#define __scanner_h__

#include <list>
#include <string>

namespace io {
	
	// The Scanner class acts as a way to get user input of specified length
	// in lines.
	class Scanner {
	public:
		// Reads the specified number of lines from the terminal.
		// Returns a list of lines entered by the user of length parts.
		static std::list<std::string> ReadParts(const int& parts);

		// Reads the specified number of lines from the terminal and also for
		// each line puts the corresponding output prompt text.
		// Returns a list of lines entered by the user of length parts.
		static std::list<std::string> ReadParts(
			std::list<std::string>& outputs, const int& parts);
	};
}

#endif
