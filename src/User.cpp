#include "User.h"

User::User() {
    name = "";
}

User::User(string userName) {
    name = userName;
}

User::~User() {}

string User::getName() const {
    return name;
}