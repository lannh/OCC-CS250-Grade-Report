/************************
   7Leaves

   Nguyen, Lan
   Lee, Mein

   CS A250 - Fall 2019

   Project 2
*************************/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>
#include <list>

class StudentList
{
public:
	// default constructor
	StudentList();

	// copy constructor
	StudentList(const StudentList& otherList);

	// addStudent
	void addStudent(const Student& newStudent);

	// getNoOfStudents
	int getNoOfStudents() const;

	// printStudentByID
	void printStudentByID(int ID) const;

	// printStudentsByCourse
	void printStudentsByCourse(const std::string& coursePrefix, 
								int courseNo) const;
	// printStudentByName
	void printStudentByName(const std::string& lastName) const;

	// printStudentsOnHold
	void printStudentsOnHold() const;

	// printAllStudents
	void printAllStudents() const; 

	// destroyStudentList
	void destroyStudentList();

	//Nguyen, Lan
	//printFullTimeStudents
	void printFullTimeStudents() const;

	//Lan, Nguyen
	//printStudentsWithMinGPA
	void printStudentsWithMinGPA(double minGPA) const;

	// overloaded assignment operator
	StudentList& operator=(const StudentList& otherList);

	// destructor
	~StudentList();

private:
	// member variables
	std::list<Student> *studentList;

	//epsilon for comapring two doubles
	const static double EPSILON;
};

#endif

