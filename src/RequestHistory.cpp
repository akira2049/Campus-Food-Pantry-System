#include "RequestHistory.h"
#include <iostream>
using namespace std;

RequestHistory::Node::Node(string u, string i, int q) {
    userName = u;
    itemName = i;
    quantity = q;
    next = nullptr;
}

RequestHistory::RequestHistory() {
    head = nullptr;
}

RequestHistory::RequestHistory(const RequestHistory& other) {
    head = nullptr;
    copyFrom(other);
}

RequestHistory& RequestHistory::operator=(const RequestHistory& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

RequestHistory::~RequestHistory() {
    clear();
}

void RequestHistory::copyFrom(const RequestHistory& other) {
    Node* current = other.head;

    while (current != nullptr) {
        addRequest(current->userName, current->itemName, current->quantity);
        current = current->next;
    }
}

void RequestHistory::clear() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
}

void RequestHistory::addRequest(string userName, string itemName, int quantity) {
    Node* newNode = new Node(userName, itemName, quantity);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }
}

void RequestHistory::displayHistory() const {
    if (head == nullptr) {
        cout << "No request history available.\n";
        return;
    }

    Node* current = head;

    cout << "\n--- Request History ---\n";

    while (current != nullptr) {
        cout << "User: " << current->userName
             << " | Item: " << current->itemName
             << " | Quantity: " << current->quantity << endl;

        current = current->next;
    }
}