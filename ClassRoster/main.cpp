#include <iostream>
#include "roster.h"

using namespace std;

int main() {

    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Andrew,Rusnac,arusnac@wgu.edu,31,29,30,32,SOFTWARE"};
    

	Roster* classRoster = new Roster();

    string id;
    string first, last, email = "";
    int age = 0;
    int daysInCourse1;
    int daysInCourse2;
    int daysInCourse3;
    string studentDegree;

   

    //parse data from studentData

    for (int i = 0; i<5; i++) {
        
        //get ID
        int r = studentData[i].find(',');
        id = studentData[i].substr(0, r);

        //get First Name
        int l = r + 1;
        r = studentData[i].find(',', l);
        first = studentData[i].substr(l, r - l);

        //get Last Name
        l = r + 1;
        r = studentData[i].find(',', l);
        last = studentData[i].substr(l, r - l);

        //get email
        l = r + 1;
        r = studentData[i].find(',', l);
        email = studentData[i].substr(l, r - l);

        //get age
        l = r + 1;
        r = studentData[i].find(',', l);
        age = stoi(studentData[i].substr(l, r - l));

        //get days
        l = r + 1;
        r = studentData[i].find(',', l);
        daysInCourse1 = stoi(studentData[i].substr(l, r - l));

        l = r + 1;
        r = studentData[i].find(',', l);
        daysInCourse2 = stoi(studentData[i].substr(l, r - l));

        l = r + 1;
        r = studentData[i].find(',', l);
        daysInCourse3 = stoi(studentData[i].substr(l, r - l));
      
        //get degree
        l = r + 1;
        r = studentData[i].find(',', l);
        studentDegree = studentData[i].substr(l, r - l);

        //Determine degree type
        DegreeProgram degree;

        if (studentDegree == "NETWORK") {
            degree = NETWORK;
        }
        else if (studentDegree == "SECURITY") {
            degree = SECURITY;
        }
        else if (studentDegree == "SOFTWARE") {
            degree = SOFTWARE;
        }

        //add all parsed data
        classRoster->add(id, first, last, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
        
    }

    //All print statements below
    cout << "Course: C867" << endl << "Language: C++" << endl << "ID: #008860824" << endl << "Andrew Rusnac" << endl << endl;

    //Print the full roster
    classRoster->printAll();

    cout << endl << ".........................................." << endl << endl;

    //print those in the degree program
    classRoster->printByDegree(SOFTWARE);

    cout << endl << ".........................................." << endl << endl;

    //loop through and pass all student IDs as a parameter to get average and print for each, can also pass IDs individually with no loop
    for (int i = 1; i < 6; i++) {
        string studentID = "A";
        studentID = studentID + to_string(i);
        classRoster->printAverageDaysInCourse(studentID);
    }

    cout << endl << ".........................................." << endl << endl;

    //search and print invalid emails
    classRoster->printInvalidEmails();

    cout << endl << ".........................................." << endl << endl;

    //search for and remove student with id A3
    classRoster->remove("A3");
    
    cout << endl << ".................Updated Roster........................." << endl << endl;

    //print updated roster
    classRoster->printAll();

    cout << endl << ".........................................." << endl << endl;

    //search for student with id A3 and report them not found
    classRoster->remove("A3");
  
  
}