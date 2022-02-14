#include "student.h"
using namespace std;

class Roster{

public:
	Roster();

	void add(string studentID, string firstName, string lastName, string studentEmail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
	void printAll();
	void printByDegree(DegreeProgram degree);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void remove(string id);

	//Destructor
	~Roster();

private:
	Student roster[5];
	Student** classRosterArray;
	int size = 0;

	
};
