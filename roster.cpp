#include <iostream>
#include <string>
#include "roster.h"
using namespace std;



//Function to parse through the information in the studentData array:
void Roster::parse(string studentData) {
	
	int rhs = studentData.find(',');
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs)); //stoi converts the string into integers


	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	int days1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	int days2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	int days3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);

	DegreeProgram dp = DegreeProgram::SECURITY;
	if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') dp = DegreeProgram::SECURITY;
	else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O') dp = DegreeProgram::SOFTWARE;
	else if (studentData.at(lhs) == 'N') dp = DegreeProgram::NETWORK;

	add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, dp);
}

//Add Method - Sets the instance variables from D1 of instructions in order to update the roster:
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int numberOfDaysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++rosterIndex] = new Student(studentID, firstName, lastName, emailAddress, age, numberOfDaysArray, degreeProgram);
}

//Function to remove students from the roster by student ID; prints an error if the student ID doesn't exist
void Roster::remove(string studentID) {
	bool existingID = false;
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			existingID = true;
			Student* tempVariable = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numberOfStudents - 1];
			classRosterArray[numberOfStudents - 1] = tempVariable;
			Roster::rosterIndex--;
		}
	}
	if (existingID) {
		cout << "Student ID " << studentID << " has been removed." << endl;
		printAll();
	}
	else cout << "Student ID " << studentID << " could not be found." << endl;

}



//Prints a complete list of student data:
void Roster::printAll() {
	for (int i = 0; i <= Roster::rosterIndex; i++) Roster::classRosterArray[i]->print();

}

//Function to print out the average days spent in a course organized by student ID:
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << "Student ID: " << studentID << ", average days in course is: ";
			cout << (classRosterArray[i]->getNumberOfDays()[0] + classRosterArray[i]->getNumberOfDays()[1] + classRosterArray[i]->getNumberOfDays()[2]) / 3 << endl;
		}
	}
}


//Function to print out the invalid emaisl that were entered:
void Roster::printInvalidEmails() {
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		size_t missingAtSign = email.find('@');  //size_t is regularly used for array indexing
		size_t missingPeriodDot = email.find('.');

		//to recognize if the @ sign in the email is missing:
		if (missingAtSign == string::npos) { //npos means "to the end of the string"/used to search through entire string
			cout << email << " is invalid." << endl;
		}

		//to recognize if the period/dot in the email is missing:
		else if (missingPeriodDot == string::npos) {
			cout << email << " is invalid." << endl;
		}

		//to recognize if a space was found in the email address:
		else if (email.find(' ') != string::npos) {
			cout << email << " is invalid." << endl;
		}

	}
}

//Print by Degree Program:
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::rosterIndex; i++)
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
}


//Destructor, deletes student records and sets each to a null pointer
Roster::~Roster() {
	for (int i = 0; i < numberOfStudents; i++) {
		classRosterArray[i] = nullptr;
	}
}