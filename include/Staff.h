#ifndef STAFF_H
#define STAFF_H

#include "User.h"

class Staff : public User {
public:
    Staff();
    Staff(string staffName);

    string getRole() const override;
};

#endif