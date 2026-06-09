#include "Item.h"

Item::Item() {
    name = "";
    quantity = 0;
}

Item::Item(string itemName, int itemQuantity) {
    name = itemName;
    quantity = itemQuantity;
}

string Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setName(string itemName) {
    name = itemName;
}

void Item::setQuantity(int itemQuantity) {
    quantity = itemQuantity;
}

void Item::addQuantity(int amount) {
    quantity += amount;
}

bool Item::removeQuantity(int amount) {
    if (amount <= quantity) {
        quantity -= amount;
        return true;
    }
    return false;
}