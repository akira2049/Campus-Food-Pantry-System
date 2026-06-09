#ifndef PANTRY_H
#define PANTRY_H

#include <vector>
#include <string>
#include "Item.h"
#include "RequestHistory.h"
using namespace std;

class Pantry {
private:
    vector<Item> items;
    RequestHistory history;

public:
    Pantry();

    void displayInventory() const;
    void addItem(string name, int quantity);
    bool requestItem(string userName, string itemName, int quantity);
    void addRandomDonation();
    void sortInventory();
    void saveInventory(string filename) const;
    void loadInventory(string filename);
    void showHistory() const;
};

#endif