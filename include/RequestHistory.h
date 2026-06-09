#ifndef REQUESTHISTORY_H
#define REQUESTHISTORY_H

#include <string>
using namespace std;

class RequestHistory {
private:
    struct Node {
        string userName;
        string itemName;
        int quantity;
        Node* next;

        Node(string u, string i, int q);
    };

    Node* head;

    void copyFrom(const RequestHistory& other);
    void clear();

public:
    RequestHistory();
    RequestHistory(const RequestHistory& other);
    RequestHistory& operator=(const RequestHistory& other);
    ~RequestHistory();

    void addRequest(string userName, string itemName, int quantity);
    void displayHistory() const;
};

#endif