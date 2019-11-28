#include "item.h"

namespace transaction {

    Item::Item() {}

    Item::Item(std::string name, int days_left, double current_bid) {
        this->name = name;
        this->days_left = days_left;
        this->current_bid = current_bid;
    }

    Item::Item(std::string name, std::string seller, std::string buyer,
        int days_left, double current_bid) {
        this->name = name;
        this->seller = seller;
        this->buyer = buyer;
        this->days_left = days_left;
        this->current_bid = current_bid;
    }

    // Gets the name of the item for auction
    std::string& Item::GetName() { return name; }

    // Gets the seller's username
    std::string& Item::GetSeller() { return seller; }

    // Sets the seller's username
    void Item::SetSeller(std::string seller) { this->seller = seller; }

    // Gets the buyer's username
    std::string& Item::GetBuyer() { return buyer; }

    // Sets the buyer's username
    void Item::SetBuyer(std::string buyer) { this->buyer = buyer; }

    // Gets the days remaining in the auction
    int& Item::GetDaysLeft() { return days_left; }

    // Gets the current bid on the item
    double& Item::GetCurrentBid() { return current_bid; }

    // Gets a string representing the item
    std::string Item::ToString() {
        std::string days = std::to_string(days_left);
        std::string bid = std::to_string(current_bid);
        std::string res = name + "\t" + seller 
            + "\t" + buyer + "\t" + days + "\t\t$" + bid;
        return res;
    }
}