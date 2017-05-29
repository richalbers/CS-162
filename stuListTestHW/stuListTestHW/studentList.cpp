/***********************************************
Name: studentList.cpp
Code: Kira Corbett
Date: 5/13/2017
Desc: class implementations for studentList Class
************************************************/

#include <iostream>
#include "StudentList.h"

using namespace std;

//default constructor
StudentList::StudentList()
{
	//initializes all array items to NULL
	for (int i = 0; i < MAX_STUDENT_SIZE; i++)
	{
		students[i] = NULL;
	}
}

//destructor
StudentList::~StudentList()
{
	//circulates through array
	for (int i = 0; i < MAX_STUDENT_SIZE; i++)
	{
		//if space was allocated, destructor makes space available
		if (students[i] != NULL)
		{
			delete students[i];
			students[i] = NULL;
		}
		//delete students[i];
		//students[i] = NULL;
	}
}

/* =======================================
Desc: inserts given student pointer into
array in the first NULL location
Returns TRUE if successful
Returns FALSE otherwise
====================================== */
bool StudentList::insert(Student* student)
{
	//verifies that the array is not full
	if (full() == true)
	{
		//if the array is full, return false
		return false;
	}

	//circulates through array
	for (int i = 0; i < MAX_STUDENT_SIZE; i++)
	{
		if (students[i] == NULL)
		{
			students[i] = student;
			return true;
		}
	}
}

/* =======================================
Desc: checks if array is full
Returns TRUE if list is full
Returns FALSE otherwise
====================================== */
bool StudentList::full() const
{
	//circulates through array
	for (int i = 0; i < MAX_STUDENT_SIZE; i++)
	{
		//if there is an empty spot, return false
		if (students[i] == NULL)
		{
			return false;
		}
	}
	return true;
}

/* =======================================
Desc: checks if array is empty
Returns TRUE if list is empty
Returns FALSE otherwise
====================================== */
bool StudentList::empty() const
{
	//Returns true if the list is empty (contains all NULL pointers)
	for (int i = 0; i < MAX_STUDENT_SIZE; i++)
	{
		//if there is not an empty spot, return false
		if (students[i] != NULL)
		{
			return false;
		}
	}
	return true;
}

/* =============================================
Desc: removes given name from array
(frees up memory and sets pointer to NULL)
Returns TRUE if remove successful
Returns FALSE otherwise
============================================= */
bool StudentList::remove(const char* name)
{
	//search for item in array
	for (int i = 0; i < MAX_STUDENT_SIZE; i++)
	{
		//checks if item is not NULL AND not already in the list
		if (students[i] != NULL && students[i]->isEqualTo(name))
		{
			//deallocate memory
			//removes the student with given name from the array
			delete students[i];
			students[i] = NULL;
			return true;
		}
	}
	return false;
}

/* =============================================
Desc: prints student name and gpa to console
============================================= */
void StudentList::print() const
{
	if (empty())
	{
		return;
	}

	for (int i = 0; i < MAX_STUDENT_SIZE; i++)
	{
		if (students[i] != NULL)
		{
			students[i]->print();
		}
	}

	cout << endl;
	cout << endl;
}

