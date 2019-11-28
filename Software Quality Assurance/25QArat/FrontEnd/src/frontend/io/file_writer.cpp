#include <iostream>
#include <fstream>

#include "file_handler.h"

namespace io {

    // Writes data to a file and returns true if successful
	bool FileWriter::Write(const std::string path,
        std::list<std::string> data) {
        return FileWriter::WriteData(path, data, false);
    }
	
    // Appends data to a file and returns true if successful
    bool FileWriter::Append(const std::string path,
        std::list<std::string> data) {
        return FileWriter::WriteData(path, data, true);
    }

    bool FileWriter::WriteData(const std::string path,
			std::list<std::string> data, bool append) {
        
        // Nothing to do
        if (data.empty() && append) {
            return true;
        }

        // Get the file
        std::ofstream file;
        if (append) {
            file = std::ofstream(path, std::ios::app);
        } else {
            file = std::ofstream(path);
        }

         // Failed to open
        if (!file.is_open()) {
            std::cout << "ERROR: Could not open the file '" << path << "'\n";
            return false;
        }

        // Write the data
        for (auto line : data) {
            file << line + "\n";
        }

        // Close the file
        file.close();

        return true;
    }
}
