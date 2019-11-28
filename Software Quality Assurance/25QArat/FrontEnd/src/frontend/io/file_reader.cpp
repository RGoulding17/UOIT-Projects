#include <iostream>
#include <fstream>

#include "file_handler.h"

namespace io {

    // Reads from a file and returns the data as a list of lines
    std::list<std::string> FileReader::Read(const std::string path) {

        // Empty string
        if (path.empty()) {
            return {};
        }

        std::ifstream file(path);

        // Failed to open
        if (!file.is_open()) {
            std::cout << "ERROR: Could not open the file '" << path << "'\n";
            return {};
        }

        // Get the lines
        std::string line;
        std::list<std::string> lines;
        while (std::getline(file, line)) {

            // Remove \r characters at the end of lines
            if (!line.empty() && line[line.length() - 1] == '\r') {
                line = line.substr(0, line.length() - 1);
            }

            lines.push_back(line);
        }

        // Close the file
        file.close();

        return lines;
    }

    // Parses the available items file and gets the items in it
    std::list<transaction::Item> FileReader::ParseItems(
        const std::string avail_items_file) {
        
        // Get the file data
        std::list<std::string> lines = FileReader::Read(avail_items_file);
        if (lines.empty()) {
            return {};
        }

        // Parse the contents
        std::list<transaction::Item> items;
        for (auto line : lines) {

            // Each line is: 62 chars
            // 19 char item name + space + 15 char seller username
            // + space + 15 char current highest bid username + space
            // + 3 char days left + space + 6 char highest bid

            // Line is not correct length
            if (line.length() != 62) {
                continue;
            }

            // Parse the fields
            std::string name = line.substr(0, 19);
            trim(name);
            std::string seller = line.substr(20, 15);
            trim(seller);
            std::string buyer = line.substr(36, 15);
            trim(buyer);
            int days_left;
            double current_bid;
            try {
                days_left = std::stoi(line.substr(52, 3));
            } catch (...) {}
            try {
                current_bid = std::stod(line.substr(56));
            } catch (...) {}

            // Check if last item
            if (name == "END" && seller.empty()) {
                break;
            }

            // Add the item
            transaction::Item item = transaction::Item(
                name, seller, buyer, days_left, current_bid);
            items.push_back(item);
        }

        return items;
    }
    
    // Parses the current user accounts file and gets the users
    std::list<session::User> FileReader::ParseUsers(
        const std::string user_accounts_file) {
        
        // Get the file data
        std::list<std::string> lines = FileReader::Read(user_accounts_file);
        if (lines.empty()) {
            return {};
        }

        // Parse the contents
        std::list<session::User> users;
        for (auto line : lines) {

            // Each line is: 28 chars
            // 15 char username + space + 2 char user type
            // + space + 9 char available credit

            // Line is not correct length
            if (line.length() != 28) {
                continue;
            }

            // Get the parts
            std::string username = line.substr(0, 15);
            trim(username);
            std::string type = line.substr(16, 2);
            std::string bal = line.substr(19);
            trim(bal);
            double balance;
            try {
                balance = std::stod(bal);
            } catch (...) {}

            // Add the user
            session::User user;
            if (type == "AA") {
                user = session::Admin(username, balance);
            } else if (type == "FS") {
                user = session::FullStandard(username, balance);
            } else if (type == "BS") {
                user = session::BuyStandard(username, balance);
            } else if (type == "SS") {
                user = session::SellStandard(username, balance);
            } else {
                user = session::User(username, balance, {"login", "logout", "display"});
                user.SetType(type);
            }
            users.push_back(user);
        }

        return users;
    }
}