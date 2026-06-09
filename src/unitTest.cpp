#include "unitTest.h"
#include "Item.h"
#include "Pantry.h"
#include <iostream>
using namespace std;

void runUnitTests() {
    cout << "\n--- Running Unit Tests ---\n";

    Item item("Rice", 10);

    if (item.getName() == "Rice" && item.getQuantity() == 10) {
        cout << "Item constructor test passed.\n";
    }

    item.addQuantity(5);

    if (item.getQuantity() == 15) {
        cout << "Add quantity test passed.\n";
    }

    if (item.removeQuantity(3) && item.getQuantity() == 12) {
        cout << "Remove quantity test passed.\n";
    }

    Pantry pantry;
    pantry.addItem("Milk", 5);

    if (pantry.requestItem("Test Student", "Milk", 2)) {
        cout << "Pantry request item test passed.\n";
    }

    cout << "--- Unit Tests Finished ---\n";
}