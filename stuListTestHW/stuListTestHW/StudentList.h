/********************************************
Name: studentList.h
Code: Kira Corbett
Date: 5/13/2017
Desc: class definitions for studentList class
*********************************************/

#ifndef _STUDENTLIST_
#define _STUDENTLIST_

#include "student.h"

//constants
const int MAX_STUDENT_SIZE = 10;

class StudentList
{
public:
	//default constructor that initializes all array entries to NULL
	StudentList();

	//destructor; frees up any allocated space
	~StudentList();

	/* =======================================
	Desc: inserts given student pointer into
	array in the first NULL location
	Returns TRUE if successful
	Returns FALSE otherwise
	====================================== */
	bool insert(Student* student);

	/* =======================================
	Desc: checks if array is full
	Returns TRUE if list is full
	Returns FALSE otherwise
	====================================== */
	bool full() const;

	/* =======================================
	Desc: checks if array is empty
	Returns TRUE if list is empty
	Returns FALSE otherwise
	====================================== */
	bool empty() const;


	/* =============================================
	Desc: removes given name from array
		  (frees up memory and sets pointer to NULL)
	Returns TRUE if remove successful
	Returns FALSE otherwise
	============================================= */
	bool remove(const char* name);

	/* =============================================
	Desc: prints student name and gpa to console
	============================================= */
	void print() const;

private:

	//creates array of 10 pointers to class member students from class Students
	Student* students[MAX_STUDENT_SIZE];
	int totalItems;

};

#endif