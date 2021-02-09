#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include "Roster.h"


namespace Degrees {
    enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };
}

using namespace std;
using namespace Degrees;

class Student {
public:
    void SetDegreeProgram(DegreeProgram degreeProgram);
    string GetDegreeProgram();
    string GetStudentID();
    void SetStudentID(string ID);
    void GetFirstName();
    void SetFirstName(string fName);
    void GetLastName();
    void SetLastName(string lName);
    string GetEmailAddress();
    void SetEmailAddress(string emailAddress);
    void GetAge();
    void SetAge(int age);
    string GetDaysInCourse();
    void SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void Print() const;

    Student(); // constructor
    Student(const Student& origStudent); // copy constructor
    ~Student(); // destructor

private:

    string studentID;
    string* studentObjPtr;
    string firstName;
    string lastName;
    string emailAddress;
    int age;


};

#endif // !STUDENT