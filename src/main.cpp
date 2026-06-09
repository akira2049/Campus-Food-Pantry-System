#include <iostream>
#include <string>
#include "Pantry.h"
#include "Student.h"
#include "Staff.h"
#include "unitTest.h"
using namespace std;

int main() {
    Pantry pantry;
    int choice;

    runUnitTests();

    do {
        cout << "\n===== Campus Food Pantry System =====\n";
        cout << "1. Display Inventory\n";
        cout << "2. Request Item\n";
        cout << "3. Add Random Donation\n";
        cout << "4. Sort Inventory\n";
        cout << "5. Save Inventory\n";
        cout << "6. Load Inventory\n";
        cout << "7. Show Request History\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            pantry.displayInventory();
        }

        else if (choice == 2) {
            string name;
            string itemName;
            int quantity;

            cout << "Enter student name: ";
            cin >> name;

            Student student(name);

            cout << "Enter item name: ";
            cin >> itemName;

            cout << "Enter quantity: ";
            cin >> quantity;

            if (pantry.requestItem(student.getName(), itemName, quantity)) {
                cout << "Request successful.\n";
            } else {
                cout << "Request failed.\n";
            }
        }

        else if (choice == 3) {
            pantry.addRandomDonation();
        }

        else if (choice == 4) {
            pantry.sortInventory();
        }

        else if (choice == 5) {
            pantry.saveInventory("inventory.txt");
        }

        else if (choice == 6) {
            pantry.loadInventory("inventory.txt");
        }

        else if (choice == 7) {
            pantry.showHistory();
        }

        else if (choice == 8) {
            cout << "Exiting program.\n";
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);

    return 0;
}