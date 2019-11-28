#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "scanner.h"

namespace io {

    std::list<std::string> Scanner::ReadParts(const int& parts) {

		// Nothing to do
		if (parts < 1) { return {}; }

		// Create a list of outputs
		std::list<std::string> outputs (parts, "");

		return Scanner::ReadParts(outputs, parts);
	}

	std::list<std::string> Scanner::ReadParts(std::list<std::string>& outputs, const int& parts) {
		
		// Nothing to do
		if (parts < 1) {
			return {};
		}

		// Iterate through, getting user input
		std::list<std::string> fields = {};
		int n = outputs.size();
		std::list<std::string>::iterator it = outputs.begin();
		for (int i = 0; i < parts; i++) {

			// Use STDIN to get the input
			if (isatty(STDIN_FILENO)) {

				// Print the prompt to the user
				if (i < n) {
					std::cout << *it;
					it++;
				}

				// Get a line of input from the user
				std::string line = "";
				std::getline(std::cin, line);
				fields.push_back(line);
			}

			// Use redirected input (file) to get line
			else {

				// End of file
				if (std::cin.eof()) {
					return {};
				}

				// Read line
				std::string line = "";
				while (line.empty() && !std::cin.eof()) {
					std::getline(std::cin, line);
				}
				if (line.empty()) {
					return {};
				}

				// Display output
				if (i < n) {
					std::cout << *it;
					it++;
				}
				std::cout << line << std::endl;
				
				fields.push_back(line);
			}
		}

		return fields;
	}
}