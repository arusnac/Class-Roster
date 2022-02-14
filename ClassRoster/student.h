#define STUDENT_H
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include "degree.h"

using namespace std;

class Student
{
public:
    void setFirstName(string first);
    void setLastName(string last);
    void setID(string id);
    void setEmail(string email);
    void setAge(int age);
    void setDegree(DegreeProgram degree);
    void setDays(int days1, int days2, int days3);
    void print();
    float getAverage();
    string getFirstName();
    string getLastName();
    string getID();
    string getEmail();
    int getAge();
    DegreeProgram getDegree();

    Student();
    Student(string first, string last, string id, string email, int age, int days1, int days2, int days3, DegreeProgram degree);

    ~Student();

private:
    string firstName;
    string lastName;
    string studentID;
    string studentEmail;
    int studentAge;
    vector<int> daysInCourse;
    DegreeProgram studentDegree;

    
};