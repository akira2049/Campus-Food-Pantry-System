#include "Staff.h"

Staff::Staff() : User() {}

Staff::Staff(string staffName) : User(staffName) {}

string Staff::getRole() const {
    return "Staff";
}