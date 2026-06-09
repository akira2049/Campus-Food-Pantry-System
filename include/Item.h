#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
private:
    string name;
    int quantity;

public:
    Item();
    Item(string itemName, int itemQuantity);

    string getName() const;
    int getQuantity() const;

    void setName(string itemName);
    void setQuantity(int itemQuantity);

    void addQuantity(int amount);
    bool removeQuantity(int amount);
};

#endif