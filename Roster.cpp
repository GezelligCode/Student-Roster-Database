#include <iostream>
#include <vector>
#include <string>
#include "Roster.h"
#include "Student.h"

using namespace std;
using namespace Degrees;


// Default constructor
Roster::Roster() {

    // Create a vector copy of studentData to parse out
    vector<string> studentDataCopy(0);

    for (int i = 0; i < studentCount; ++i) {
        studentDataCopy.push_back(studentData[i]);
        cout << "Vector: " << studentDataCopy.at(i) << endl;
    }

    // Create temp variable to store parsed studentData info
    string studentID_Parsed;
    string firstName_Parsed;
    string lastName_Parsed;
    string emailAddress_Parsed;
    int age_Parsed = 0;
    int daysCourse1_Parsed = 0;
    int daysCourse2_Parsed = 0;
    int daysCourse3_Parsed = 0;
    DegreeProgram degreeProgram_Parsed;
    string delimiter = ",";


    // iterate through student data and parse out each element
    for (int i = 0; i < studentCount; ++i) {

        // parse studentID
        studentID_Parsed = studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter)); // extract first substring
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1); // Remove the substring already parsed

        // parse firstName
        firstName_Parsed = studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1);

        // parse lastName
        lastName_Parsed = studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1);

        // parse email
        emailAddress_Parsed = studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1);

        // parse age
        age_Parsed = stoi(studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter)));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1);

        // parse days in course1
        daysCourse1_Parsed = stoi(studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter)));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1);

        // parse days in course2
        daysCourse2_Parsed = stoi(studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter)));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1);

        // parse days in course 3
        daysCourse3_Parsed = stoi(studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter)));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1);

        // parse degree program
        degreeProgram_Parsed = Convert(studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter)));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1);

        // Update studentRosterClass
        Add(studentID_Parsed, firstName_Parsed, lastName_Parsed, emailAddress_Parsed, age_Parsed, daysCourse1_Parsed, daysCourse2_Parsed, daysCourse3_Parsed, degreeProgram_Parsed);

    }

}

// copy constructor
Roster::Roster(const Roster& origRoster) {
    cout << "Roster copy constructor called." << endl;
    studentObjPtr = new Student;
    *studentObjPtr = *(origRoster.studentObjPtr);
    return;
}

// destructor
Roster::~Roster() {
    cout << "Roster destructor called." << endl;
    delete studentObjPtr;
    return;
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, enum DegreeProgram degreeProgram) {

    // Student ID
    for (int i = 0; i < studentCount; ++i) {

        if (classRosterArray[i][0] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetStudentID(studentID);
            classRosterArray[i][0] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // First Name
    for (int i = 0; i < studentCount; ++i) {

        if (classRosterArray[i][1] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetFirstName(firstName);
            classRosterArray[i][1] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // lastName
    for (int i = 0; i < studentCount; ++i) {

        if (classRosterArray[i][2] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetLastName(lastName);
            classRosterArray[i][2] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // email
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i][3] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetEmailAddress(emailAddress);
            classRosterArray[i][3] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // age
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i][4] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetAge(age);
            classRosterArray[i][4] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // days in course
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i][5] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
            classRosterArray[i][5] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // degree program
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i][6] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetDegreeProgram(degreeProgram);
            classRosterArray[i][6] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }
    return;
}

void Roster::PrintAll() {

    int c = 0;
    int r = 0;
    int ctr = 0;


    for (r = 0; r < studentCount; ++r) {

        while (c < studentColumns) {

            classRosterArray[r][c]->Print(); // StudentID
            cout << "\t";
            ++c;
            cout << "First Name: ";
            classRosterArray[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Last Name: ";
            classRosterArray[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Email Address: ";
            classRosterArray[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Age: ";
            classRosterArray[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Days in Course: ";
            classRosterArray[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Degree Program: ";
            classRosterArray[r][c]->Print();
            cout << "\t";
            cout << endl;
            ++c;
        }
        // Reset counter to zero
        c = 0;
    }
    return;
}


void Roster::PrintAverageDaysInCourse(string studentID) {

    string daysInCourses;
    string delimiter = ", ";
    int daysInCourse1 = 0;
    int daysInCourse2 = 0;
    int daysInCourse3 = 0;
    int averageDaysInCourse = 0;
    int i = 0;

    while (i < studentCount) {

        if ((classRosterArray[i][0]->GetStudentID()) == studentID) {

            // get DaysInCourse Data and store in variable
            daysInCourses = classRosterArray[i][5]->GetDaysInCourse();

            break;

        }
        else {

            ++i;
            continue;

        }

    }

    // parse into three ints
    daysInCourse1 = stoi(daysInCourses.substr(0, daysInCourses.find(delimiter)));
    daysInCourses.erase(0, daysInCourses.find(delimiter) + 1);

    daysInCourse2 = stoi(daysInCourses.substr(0, daysInCourses.find(delimiter)));
    daysInCourses.erase(0, daysInCourses.find(delimiter) + 1);

    daysInCourse3 = stoi(daysInCourses.substr(0, daysInCourses.find(delimiter)));
    daysInCourses.erase(0, daysInCourses.find(delimiter) + 1);


    // compute average and cout result
    averageDaysInCourse = (daysInCourse1 + daysInCourse2 + daysInCourse3) / 3;


    cout << "Average Days In Courses: " << averageDaysInCourse;
    cout << endl;


    return;

};

void Roster::PrintInvalidEmails() {

    cout << "Invalid E-mail Address(es): " << endl;

    // loop over classRosterArray, parse out e-mail for each
    string emailToCheck;
    int r = 0;
    int c = 0;
    int posSpace = 0;
    int posAt = 0;
    int posDot = 0;

    for (r = 0; r < studentCount; ++r) {

        // get email and store in variable
        emailToCheck = classRosterArray[r][3]->GetEmailAddress();

        posSpace = emailToCheck.find(" ");
        posAt = emailToCheck.find("@");
        posDot = emailToCheck.substr(emailToCheck.length() - 4).find("."); // finds if there is a "." in the last 4 characters, e.g. .com, .edu

        // Check if conditions not met
        if (posSpace > 0 || posAt < 0 || posDot < 0) {

            // List student row data for the email in question
            while (c < 4) {

                classRosterArray[r][c]->Print(); // StudentID
                cout << "\t";
                ++c;
                cout << "First Name: ";
                classRosterArray[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Last Name: ";
                classRosterArray[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Email Address: ";
                classRosterArray[r][c]->Print();
                cout << endl;
                ++c;

            }

            c = 0;

        }
    }
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {

    string inputDegreeProgram;

    switch (degreeProgram) {
    case 0:
        inputDegreeProgram = "SECURITY";
        break;
    case 1:
        inputDegreeProgram = "NETWORK";
        break;
    case 2:
        inputDegreeProgram = "SOFTWARE";
        break;
    }

    cout << "Students under the " << inputDegreeProgram << " degree: " << endl;

    // For each element in classRosterArray, check if degree program == degreeProgramToCheck parameter
    int r = 0;
    int c = 0;
    string degreeProgramToCheck;

    for (r = 0; r < studentCount; ++r) {

        // get degree and store in variable
        degreeProgramToCheck = classRosterArray[r][6]->GetDegreeProgram();

        // Print Information for Specified Degree
        if (degreeProgramToCheck == inputDegreeProgram) {

            // List student row data for the degree in question
            while (c < 6) {

                classRosterArray[r][c]->Print(); // StudentID
                cout << "\t";
                ++c;
                cout << "First Name: ";
                classRosterArray[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Last Name: ";
                classRosterArray[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Email Address: ";
                classRosterArray[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Age: ";
                classRosterArray[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Days in Course: ";
                classRosterArray[r][c]->Print();
                cout << endl;
                ++c;

            }

            c = 0;

        }
    }

    return;
}

void Roster::Remove(string studentID) {

    int r = 0;
    int c = 0;
    int pos = 0;
    bool studentFound = false;


    // Loop through classRosterArray until match for studentID is found
    for (r = 0; r < studentCount; ++r) {

        // if parameter input matches studentID
        if (studentID == classRosterArray[r][c]->GetStudentID()) {

            --studentCount;

            for (int i = r; i < studentCount; ++i) {

                for (c = 0; c < studentColumns; ++c) {

                    classRosterArray[i][c] = classRosterArray[i + 1][c];

                }

            }

            studentFound = true;
            break;

        }

    }

    if (studentFound == false) {

        cout << "Such a student with this ID was not found." << endl;

    }

}
