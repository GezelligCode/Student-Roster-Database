// C867 Project 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;

class Degree {
public:
    enum DegreeProgram { SECURITY, NETWORK, SOFTWARE } degreeProgram;
    //DegreeProgram Convert(string parsedDegreeProgram);
};

Degree::DegreeProgram Convert(string parsedDegreeProgram) {

    if (parsedDegreeProgram == "SECURITY") {
        Degree::DegreeProgram parsedDegreeProgram = Degree::DegreeProgram::SECURITY;
        return parsedDegreeProgram;
    }
    else if (parsedDegreeProgram == "NETWORK") {
        Degree::DegreeProgram parsedDegreeProgram = Degree::DegreeProgram::NETWORK;
        return parsedDegreeProgram;
    }
    else if (parsedDegreeProgram == "SOFTWARE") {
        Degree::DegreeProgram parsedDegreeProgram = Degree::DegreeProgram::SOFTWARE;
        return parsedDegreeProgram;
    }
}

class Student : Degree {
public:
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
    string GetDegreeProgram();
    void SetDegreeProgram(DegreeProgram degreeProgram);
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

// default constructor
Student::Student() {
    cout << "default constructor called." << endl;
    studentObjPtr = new string; // allocate mem
    *studentObjPtr = "-";
    return;
}

// copy constructor
Student::Student(const Student& origStudent) {
    cout << "copy constructor called." << endl;
    studentObjPtr = new string;
    *studentObjPtr = *(origStudent.studentObjPtr);
    return;
}

// destructor
Student::~Student() {
    cout << "destructor called." << endl;
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



class Roster : Degree {
public:
    void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void Remove();
    void PrintAll();
    void PrintAverageDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
    Roster();

private:
    Student* classRosterArrayMD[5][9];
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

// Default constructor
Roster::Roster() {
  
    // Create a vector copy of studentData
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

    // Try creating a function that will, for each vector element, parse and use each variable as a parameter for the Add() function
     

    for (int i = 0; i < studentCount; ++i) {

        // parse studentID
        studentID_Parsed = studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter)); // extract first substring
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter) + 1); // Remove the substring already parsed

        // parse firstName
        firstName_Parsed = studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter)+1);

        // parse lastName
        lastName_Parsed = studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter)+1);

        // parse email
        emailAddress_Parsed = studentDataCopy.at(i).substr(0, studentDataCopy.at(i).find(delimiter));
        studentDataCopy.at(i).erase(0, studentDataCopy.at(i).find(delimiter)+1);

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

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram) {
    
    // Student ID
    for (int i = 0; i < studentCount; ++i) {

        if (classRosterArrayMD[i][0] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetStudentID(studentID);
            classRosterArrayMD[i][0] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // First Name
    for (int i = 0; i < studentCount; ++i) {

        if (classRosterArrayMD[i][1] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetFirstName(firstName);
            classRosterArrayMD[i][1] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // lastName
    for (int i = 0; i < studentCount; ++i) {

        if (classRosterArrayMD[i][2] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetLastName(lastName);
            classRosterArrayMD[i][2] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // email
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArrayMD[i][3] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetEmailAddress(emailAddress);
            classRosterArrayMD[i][3] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // age
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArrayMD[i][4] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetAge(age);
            classRosterArrayMD[i][4] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // days in course
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArrayMD[i][5] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
            classRosterArrayMD[i][5] = studentObjPtr;
            break;
        }
        else {
            continue;
        }
    }

    // degree program
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArrayMD[i][6] == nullptr) {
            studentObjPtr = new Student;
            studentObjPtr->SetDegreeProgram(degreeProgram);
            classRosterArrayMD[i][6] = studentObjPtr;
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

            classRosterArrayMD[r][c]->Print(); // StudentID
            cout << "\t";
            ++c;
            cout << "First Name: ";
            classRosterArrayMD[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Last Name: ";
            classRosterArrayMD[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Email Address: ";
            classRosterArrayMD[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Age: ";
            classRosterArrayMD[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Days in Course: ";
            classRosterArrayMD[r][c]->Print();
            cout << "\t";
            ++c;
            cout << "Degree Program: ";
            classRosterArrayMD[r][c]->Print();
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
         
        if ((classRosterArrayMD[i][0]->GetStudentID()) == studentID) {

            // get DaysInCourse Data and store in variable
            daysInCourses = classRosterArrayMD[i][5]->GetDaysInCourse();

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
        emailToCheck = classRosterArrayMD[r][3]->GetEmailAddress();

        posSpace = emailToCheck.find(" ");
        posAt = emailToCheck.find("@");
        posDot = emailToCheck.substr(emailToCheck.length()-4).find("."); // finds if there is a "." in the last 4 characters, e.g. .com, .edu

        // Check if conditions not met
        if (posSpace > 0 || posAt < 0 || posDot < 0) {
 
            // List student row data for the email in question
            while (c < 4) {

                classRosterArrayMD[r][c]->Print(); // StudentID
                cout << "\t";
                ++c;
                cout << "First Name: ";
                classRosterArrayMD[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Last Name: ";
                classRosterArrayMD[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Email Address: ";
                classRosterArrayMD[r][c]->Print();
                cout << endl;
                ++c;

            }

            c = 0;

        }
    }
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {

    // For each element in classRosterArray, check if degree program == degreeProgram parameter
    int r = 0;
    int c = 0;
    string degreeProgramToCheck;

    for (r = 0; r < studentCount; ++r) {

        // get degree and store in variable
        degreeProgramToCheck = classRosterArrayMD[r][6]->GetDegreeProgram();

        // Print Information for Specified Degree
        if (degreeProgramToCheck == to_string(degreeProgram)) {
            cout << degreeProgramToCheck << ": " << endl;
            // List student row data for the degree in question
            while (c < 6) {

                classRosterArrayMD[r][c]->Print(); // StudentID
                cout << "\t";
                ++c;
                cout << "First Name: ";
                classRosterArrayMD[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Last Name: ";
                classRosterArrayMD[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Email Address: ";
                classRosterArrayMD[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Age: ";
                classRosterArrayMD[r][c]->Print();
                cout << "\t";
                ++c;
                cout << "Days in Course: ";
                classRosterArrayMD[r][c]->Print();
                cout << endl;
                ++c;

            }

            c = 0;

        }
    }

    return;
}


int main()
{
    cout << "Created Student Roster" << endl;

    Roster classRoster;

    classRoster.PrintAll();

    classRoster.PrintInvalidEmails();

    //loop through classRosterArray and for each element:

    classRoster.PrintAverageDaysInCourse("A1");

    classRoster.PrintByDegreeProgram(SOFTWARE);

 /*   classRoster.Remove("A3");

    classRoster.PrintAll();

    classRoster.Remove("A3");*/
 
}

 
