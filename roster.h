#pragma once
#include "student.h"
#include "degree.h"


class Roster {

private:
	int rosterIndex = -1; //starting position
	const static int numberOfStudents = 5; //the size of the array
	Student* classRosterArray[numberOfStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr}; //initializes the array of pointers

public:
	//Roster(); //constructor without parameters
	

	void parse(string row);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster(); //Destructor
};