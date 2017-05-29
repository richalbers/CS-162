/********************************************
Name: stuListTest.cpp
Code: Kira Corbett
Date: 5/8/2017
Desc: program that develops a student gradebook
to practice utilizing classes, pointers,
and dynamically allocated memory
*********************************************/

#include <iostream>
#include <cstring>
#include "student.h"
#include "studentList.h"


using namespace std;


int main() {
	StudentList list;
	Student* student;

	//test data
	char* names[] = { "Adam", "Bob", "Clara", "Dot", "Ed", "Frank",
		"Greg", "Hiedi", "Ida", "Joe", "Kay" };
	float gpas[] = { 3.5,    3.6,   3.7,     3.8,   3.9,  4.0,
		2.0,    2.5,     2.6,   2.7,   2.8 };

	//try inserting 11.
	for (int x = 0; x < 11; x++) {
		student = new Student(gpas[x], names[x]);
		if (list.insert(student) == false) {
			cout << "Error - student insert failed" << endl;
			delete student;
		}
	}
	list.print();

	//remove a few
	list.remove("Adam");
	list.remove("Frank");
	list.remove("Joe");
	list.print();

	//insert two more (note: they won’t be in order)
	student = new Student(1.0, "zed");
	student->changeName("Zorro");
	list.insert(student);
	list.insert(new Student(1.1, "Zorro2"));
	list.print();

	return 1;
}



//Test inserting 1 student
//student = new Student(1.0, "zed");
//list.insert(student);

//list.print();


//student = new Student(1.2, “Zorro2”);
//list.insert(student);

////After inserting, you should call print to verify they’re in the list.
//list.print();

////then try removing one of them
//list.remove(“Zorro1”);
//list.print();

//EQUIVALENT STATEMENTS
//list.insert(new Student(1.1, "Zorro1"));
//student = new Student(1.1, "Zorro1");
//list.insert(student);


//// ===============================TESTING CLASS STUDENT=============================

////declares pointer, creates object
////Test out of bounds
//student = new Student(4.5, "bob");
//student->print();
//
////Test in bounds
//student = new Student(4.0, "joe");
//student->print();
//
////Test destructor
//student->~Student();
//
////Test changeName function
//student = new Student(1.0, "zed");
//student->changeName("zorro");
//student->print();
//
////Test isEqualTo function
//student = new Student(1.3, "BOB");
//if (student->isEqualTo("BOB"))
//cout << "Successful!" << endl;

////=================================TESTING CLASS STUDENT_LIST=====================



