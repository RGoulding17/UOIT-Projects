#ifndef __item_h__
#define __item_h__

#include <string>

namespace transaction {

    class Item {
    public:
        Item();

        Item(std::string name, int days_left, double current_bid);

        Item(std::string name, std::string seller, std::string buyer,
            int days_left, double current_bid);

        // Gets the name of the item for auction
        std::string& GetName();

        // Gets the seller's username
        std::string& GetSeller();

        // Sets the seller's username
        void SetSeller(std::string seller);

        // Gets the buyer's username
        std::string& GetBuyer();

        // Sets the buyer's username
        void SetBuyer(std::string buyer);

        // Gets the days remaining in the auction
        int& GetDaysLeft();

        // Gets the current bid on the item
        double& GetCurrentBid();

        // Gets a string representing the item
        std::string ToString();
    
    private:
        std::string name;

        std::string seller;

        std::string buyer;

        int days_left;

        double current_bid;
        // item name, seller's name, buyer's name, days left, current bid
    };
}

#endif