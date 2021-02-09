#include <iostream>
#include <vector>
#include <string>
#include "student.h"
#include "Roster.h"

using namespace std;
using namespace Degrees;


Degrees::DegreeProgram Convert(string parsedDegreeProgram) {

    if (parsedDegreeProgram == "SECURITY") {
        return SECURITY;
    }
    else if (parsedDegreeProgram == "NETWORK") {
        return NETWORK;
    }
    else if (parsedDegreeProgram == "SOFTWARE") {
        return SOFTWARE;
    }
}


// default constructor
Student::Student() {
    cout << "Student default constructor called." << endl;
    studentObjPtr = new string; // allocate mem
    *studentObjPtr = "-";
    return;
}

// copy constructor
Student::Student(const Student& origStudent) {
    cout << "Student copy constructor called." << endl;
    studentObjPtr = new string;
    *studentObjPtr = *(origStudent.studentObjPtr);
    return;
}

// destructor
Student::~Student() {
    cout << "Student destructor called." << endl;
    delete studentObjPtr;
    return;
}

string Student::GetStudentID() {

    return *studentObjPtr;
};


void Student::SetStudentID(string ID) {

    *studentObjPtr = ID;
    return;
}

void Student::GetFirstName() {

    cout << *studentObjPtr;
    return;
}

void Student::SetFirstName(string fName) {
    *studentObjPtr = fName;
    return;
}

void Student::GetLastName() {

    cout << *studentObjPtr;
    return;
}

void Student::SetLastName(string lName) {
    *studentObjPtr = lName;
    return;
}


string Student::GetEmailAddress() {

    //cout << *studentObjPtr;
    return *studentObjPtr;

};
void Student::SetEmailAddress(string emailAddress) {
    *studentObjPtr = emailAddress;
    return;

};

void Student::GetAge() {
    cout << *studentObjPtr;
    return;
};
void Student::SetAge(int age) {
    *studentObjPtr = to_string(age);
    return;

};
string Student::GetDaysInCourse() {

    return *studentObjPtr;
};
void Student::SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    *studentObjPtr = ((to_string(daysInCourse1) + ", " + to_string(daysInCourse2) + ", " + to_string(daysInCourse3)));
    return;
};
string Student::GetDegreeProgram() {

    return *studentObjPtr;
};

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {

    switch (degreeProgram) {
    case 0:
        *studentObjPtr = "SECURITY";
        break;
    case 1:
        *studentObjPtr = "NETWORK";
        break;
    case 2:
        *studentObjPtr = "SOFTWARE";
        break;
    }

    return;
}


void Student::Print() const {
    cout << *studentObjPtr;
    return;
}