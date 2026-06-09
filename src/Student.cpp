#include "Student.h"

Student::Student() : User() {}

Student::Student(string studentName) : User(studentName) {}

string Student::getRole() const {
    return "Student";
}