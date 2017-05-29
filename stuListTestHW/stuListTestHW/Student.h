/*************************************
Name: student.h
Code: Kira Corbett
Date: 5/8/2017
Desc: class definitions for student.h
**************************************/

#ifndef _STUDENT_
#define _STUDENT_


class Student
{
public:
	//default constructor; sets all variables to NULL values
	Student();

	//destructor: frees up allocated space for the variable "name"
	~Student();

	/* ====================================================================
	GPA between 0 and 4; if GPA out of bounds, then 0
	dynamically allocate memory for the pointer char and the variable name
	==================================================================== */
	//constructor with GPA and name as arguments
	Student(float gpa, char* name);

	//deallocation and reallocation of memory
	void changeName(const char* newName);

	/* =============================================
	Returns true if student's name equals given name.
	Returns false if names are not equal.
	============================================= */
	bool isEqualTo(const char* name) const;

	/* ============================
	prints out the student's name
	followed by gpa in ().
	============================ */
	void print() const;

private:
	float studentGpa;
	char* studentName;
};

#endif

