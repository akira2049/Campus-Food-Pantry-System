#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

class Student : public User {
public:
    Student();
    Student(string studentName);

    string getRole() const override;
};

#endif