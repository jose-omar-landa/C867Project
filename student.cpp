#include <iostream>
#include <string>
#include "student.h"
using namespace std;


//Empty Constructor, creates a blank student
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numberOfDaysSize; i++) this->numberOfDays[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}
//Full Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numberOfDaysSize; i++) this->numberOfDays[i] = numberOfDays[i];
	this->degreeProgram = degreeProgram;
}
 
//Destructor
Student::~Student() {}


//Getters or Accessors
string Student::getStudentID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

const int* Student::getNumberOfDays() {
	return this->numberOfDays;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}


//Setters or Mutators
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setNumberOfDays(const int numberOfDays[]) {
	for (int i = 0; i < numberOfDaysSize; i++) this->numberOfDays[i] = numberOfDays[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


void Student::print() {
	cout << this->studentID << "\t";
	cout << this->firstName << "\t";
	cout << this->lastName << "\t";
	cout << this->age << "\t";
	cout << "{" << this->numberOfDays[0] << ",";
	cout << this->numberOfDays[1] << ",";
	cout << this->numberOfDays[2] << "}" << "\t";
	cout << degreeProgramStrings[(int)this->degreeProgram];
	cout << endl;
}