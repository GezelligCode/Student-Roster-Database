#pragma once 
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <vector>
#include "Student.h"


 
using namespace std;
using namespace Degrees;



class Roster {
public:
    void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, enum DegreeProgram degreeProgram);
    void Remove();
    void PrintAll();
    void PrintAverageDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
    void Remove(string studentID);
    Roster();
    Roster(const Roster& origRoster); // copy constructor
    ~Roster(); // destructor

private:
    Student* classRosterArray[5][9];
    Student* studentObjPtr;
    const string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Wassa,Anspaugh,wanspau@my.wgu.edu,38,20,25,30,SOFTWARE"
    };
    int studentCount = 5;
    int studentColumns = 7;
};

#endif // !roster