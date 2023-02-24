#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {

	cout << "C867 - Scripting and Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 000999884" << endl;
	cout << "Name: Jose Landa" << endl;
	cout << endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Jose,Landa,jlanda4@wgu.edu,29,22,31,27,SOFTWARE"
	};

	const int numberOfStudents = 5;
	//Creates an instance of the Roster class:
	Roster classRoster;


	//Parses through the Roster information and adds eacch student to the classRoster instance
	//of the Roster class
	for (int i = 0; i < numberOfStudents; i++) classRoster.parse(studentData[i]);



	//Prints out all student data:
	cout << "Displaying all students:" << endl;
	classRoster.printAll(); 
	cout << endl;


	//Prints out the invalid emails that were added to the classRoster instance:
	cout << "Displaying invalid emails:" << endl;
	cout << endl;
	classRoster.printInvalidEmails();
	cout << endl;


	//Prints out the average days spent in a course per student ID:
	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");
	cout << endl;


	//Prints out the students in the SOFTWARE degree program:
	cout << "Showing students in degree program: SOFTWARE" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;



	//Removes the student information associated with Student ID A3:
	classRoster.remove("A3");
	cout << endl;


	//Displays the remove function for Student ID A3 again, and prints out an error message that the student ID A3 was not found:
	cout << "Removing A3 again." << endl;
	cout << endl;
	classRoster.remove("A3");

	//Implements the destructor:
	cout << "DONE" << endl;
	return 0;
}