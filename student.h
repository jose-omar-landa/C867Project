#pragma once
#include "degree.h"
using namespace std;



class Student {

public:
	const static int numberOfDaysSize = 3; //specifies the size of the numberOfDays array

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numberOfDays[numberOfDaysSize];
	DegreeProgram degreeProgram;

public:
	Student(); //Constructor without parameters, sets default values

	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], DegreeProgram degreeProgram);

	~Student(); //Destructor


	//Getters or Accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	const int* getNumberOfDays();
	DegreeProgram getDegreeProgram();

	//Setters or Mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setNumberOfDays(const int numberOfDays[]);
	void setDegreeProgram(DegreeProgram dp);


	void print();
};