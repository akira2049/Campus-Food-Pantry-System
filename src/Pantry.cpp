#include "Pantry.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

Pantry::Pantry() {
    items.push_back(Item("Rice", 20));
    items.push_back(Item("Beans", 15));
    items.push_back(Item("Water", 30));
    items.push_back(Item("Soap", 10));

    srand(time(0));
}

void Pantry::displayInventory() const {
    cout << "\n--- Pantry Inventory ---\n";

    if (items.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }

    for (const Item& item : items) {
        cout << item.getName() << " - Quantity: " << item.getQuantity() << endl;
    }
}

void Pantry::addItem(string name, int quantity) {
    for (Item& item : items) {
        if (item.getName() == name) {
            item.addQuantity(quantity);
            return;
        }
    }

    items.push_back(Item(name, quantity));
}

bool Pantry::requestItem(string userName, string itemName, int quantity) {
    for (Item& item : items) {
        if (item.getName() == itemName) {
            if (item.removeQuantity(quantity)) {
                history.addRequest(userName, itemName, quantity);
                return true;
            } else {
                cout << "Not enough quantity available.\n";
                return false;
            }
        }
    }

    cout << "Item not found.\n";
    return false;
}

void Pantry::addRandomDonation() {
    string donationItems[] = {"Rice", "Beans", "Water", "Soap", "Pasta", "Cereal"};
    int index = rand() % 6;
    int quantity = (rand() % 10) + 1;

    addItem(donationItems[index], quantity);

    cout << "Random donation added: " << donationItems[index]
         << " x" << quantity << endl;
}

void Pantry::sortInventory() {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.getName() < b.getName();
    });

    cout << "Inventory sorted by item name.\n";
}

void Pantry::saveInventory(string filename) const {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error opening file for saving.\n";
        return;
    }

    for (const Item& item : items) {
        outFile << item.getName() << " " << item.getQuantity() << endl;
    }

    outFile.close();
    cout << "Inventory saved to " << filename << endl;
}

void Pantry::loadInventory(string filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Error opening file for loading.\n";
        return;
    }

    items.clear();

    string name;
    int quantity;

    while (inFile >> name >> quantity) {
        items.push_back(Item(name, quantity));
    }

    inFile.close();
    cout << "Inventory loaded from " << filename << endl;
}

void Pantry::showHistory() const {
    history.displayHistory();
}