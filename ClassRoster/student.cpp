#include "student.h"
#include <vector>
#include <numeric>

//Constructors
Student::Student()
{
}

Student::Student(string first, string last, string id, string email, int age, int days1, int days2, int days3, DegreeProgram degree)
{
    setFirstName(first);
    setLastName(last);
    setID(id);
    setEmail(email);
    setAge(age);
    setDays(days1, days2, days3);
    setDegree(degree);
    getAverage();
    print();
}

//Setters
void Student::setFirstName(string first)
{
    firstName = first;
}

void Student::setLastName(string last)
{
    lastName = last;
}

void Student::setID(string id)
{
    studentID = id;
}

void Student::setDays(int days1, int days2, int days3) {
    daysInCourse.push_back(days1);
    daysInCourse.push_back(days2);
    daysInCourse.push_back(days3);
}

void Student::setEmail(string email) {
    studentEmail = email;
}

void Student::setAge(int age) {
    studentAge = age;
}

void Student::setDegree(DegreeProgram degree) {
    studentDegree = degree;
}

//Getters
float Student::getAverage() {

    float average = accumulate(daysInCourse.begin(), daysInCourse.end(), 0.0) / daysInCourse.size();
    return average;
}

string Student::getID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmail()
{
    return studentEmail;
}

int Student::getAge()
{
    return studentAge;
}


DegreeProgram Student::getDegree() 
{
    return studentDegree;
}

//Print Student Information
void Student::print() {
    //determine degree type for printing
    string degreeType;
    switch (studentDegree) 
    {
        case 0:
            degreeType = "Security";
            break;
        case 1: 
            degreeType = "Network";
            break;
        case 2: 
            degreeType = "Software";
            break;
    }

    cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << studentAge<< "\t" <<
         "\tDays In Courses: {" << daysInCourse.at(0) << "," << daysInCourse.at(1) << "," << daysInCourse.at(2) << "}\t" << "Degree: " << degreeType << endl;
}

//Destructor
Student::~Student() {}
