#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string name;

public:
    User();
    User(string userName);
    virtual ~User();

    string getName() const;
    virtual string getRole() const = 0;
};

#endif