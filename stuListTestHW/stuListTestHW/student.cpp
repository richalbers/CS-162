/********************************************
Name: student.cpp
Code: Kira Corbett
Date: 5/8/2017
Desc: class implementations for Student class
*********************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;

Student::Student()
{
	//default constructor
	//sets everyting to NULL
	studentGpa = NULL;
	studentName = NULL;
}

//destructor
Student::~Student()
{
	//if space was allocated, destructor makes space available
	if (studentName != NULL)
	{
		delete [] studentName;
	}
}

/* ====================================================================
GPA between 0 and 4; if GPA out of bounds, then 0
dynamically allocate memory for the pointer char and the variable name
==================================================================== */
Student::Student(float gpa, char* name)
{
	//maintains GPA between 0 and 4
	if (gpa < 0 || gpa > 4)
	{
		//if gpa is out of bounds, it is initialized to 0
		gpa = 0.0;
	}
	else
	{
		//else gpa is maintained the same as input
		studentGpa = gpa;

		//dynamically allocate  space (adding 1 to allocate space for NULL) and obtain the address 
		//then copy the contents of the 
		studentName = new char[strlen(name) + 1];
		strcpy(studentName, name);
	}
}

//deallocation and reallocation of memory
void Student::changeName(const char* newName)
{
	//deallocation of memory
	if (studentName != NULL)
	{
		delete [] studentName;

		//reallocation of memory (adding 1 to length of newName to include space for NULL)
		//obtains address of contents and copies from newName to studentName
		studentName = new char[strlen(newName) + 1];
		strcpy(studentName, newName);
	}
}

/* =============================================
Returns true if student's name equals given name.
Returns false if names are not equal.
============================================= */
bool Student::isEqualTo(const char* name) const
{
	if (studentName == NULL)
	{
		return false;
	}

	if (!strcmp(studentName, name))
	{
		//returns true if given name is equal to current name
		return true;
	}
	//returns false if names are not equal
	else return false;
}

/* ============================
prints out the student's name
followed by gpa in ().
============================ */
void Student::print() const
{
	cout << studentName << "(" << fixed << setprecision(1) << studentGpa << ")" << ", " << " ";
}



