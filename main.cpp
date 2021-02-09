// C867 Project 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include "Student.h"
#include "Roster.h"
#include "Student.cpp"
#include "Roster.cpp"

using namespace std;
using namespace Degrees;

int main()
{   
    cout << "Created Student Roster" << endl;

    Roster classRoster;

    classRoster.PrintAll();

    classRoster.PrintInvalidEmails();

    //loop through classRosterArray and for each element:

    classRoster.PrintAverageDaysInCourse("A3");

    classRoster.PrintByDegreeProgram(SOFTWARE);

    cout << endl;

    classRoster.Remove("A3");

    cout << endl;

    classRoster.PrintAll();

    classRoster.Remove("A3");
 
}

 
