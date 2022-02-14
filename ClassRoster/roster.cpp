#include <iostream>
#include "roster.h"
#include <string>

using namespace std;

//Constructors
Roster::Roster() {

}

//Add students to roster
void Roster::add(string studentID, string firstName, string lastName, string studentEmail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {
       
    
    roster[size].setID(studentID);
    roster[size].setFirstName(firstName);
    roster[size].setLastName(lastName);
    roster[size].setEmail(studentEmail);
    roster[size].setAge(age);
    roster[size].setDegree(degree);
    roster[size].setDays(daysInCourse1, daysInCourse1, daysInCourse3);
    size++;
}

//Print entire roster
void Roster::printAll() {
    
    for (int i = 0; i < size; i++) {
        roster[i].print();
    }
}

//Print students by selected degree type
void Roster::printByDegree(DegreeProgram degree) {

    string degreeType;

    switch (degree) {
    case 0: degreeType = "Security";
        break;
    case 1: degreeType = "Network";
        break;
    case 2: degreeType = "Software";
        break;
    }

    cout << "Students in the " << degreeType << " program:" << endl << endl;

    for (int i = 0; i < 5; i++) {
        if (roster[i].getDegree() == degree) {
            roster[i].print();
        }
    }
}

//Print average
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < 5; i++) {
        if (roster[i].getID() == studentID) {
            cout << "Student ID: " << roster[i].getID() << " Average days in courses: " << roster[i].getAverage() << endl;
        }
    }
}

//Print invalid emails
void Roster::printInvalidEmails() {
    for (int i = 0; i < 5; i++) {
        //Search for spaces
        if (roster[i].getEmail().find(' ', 0) != string::npos) {
            cout << roster[i].getEmail() << " is invalid, contains a space." << endl;
        }
        //Search for @ symbol
        else if (roster[i].getEmail().find('@', 0) == string::npos) {
            cout << roster[i].getEmail() << " is invalid, no @ sybmol found." << endl;
        }
        //Search for period
        else if (roster[i].getEmail().find('.', 0) == string::npos) {
            cout << roster[i].getEmail() << " is invalid, no period sybmol found." << endl;
        }
    }
}

//Remove element from roster using id
void Roster::remove(string id) {
    int i;
    bool found = 0;
    //Check for selected element
    for (i = 0; i < 5;i++) {
        if (roster[i].getID() == id) {
            cout << "Student with ID: " << roster[i].getID() << " was removed." << endl;
            found = 1;
            size--;
            break;
        }
    }
    //If element isn't found, report message
    if (found == 0) {
        cout << "STUDENT WITH ID "<< id << " NOT FOUND" << endl;
    }
        
    if (i < 5) {
        for (int n = i; n < size; n++) {
            roster[n] = roster[n + 1];
        }
    }
}

//Destructor
Roster::~Roster() {
    for (int i = 0; i < size; i++)
    {
        delete classRosterArray[i];
    }

}
