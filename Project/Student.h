/************************
   7Leaves

   Nguyen, Lan
   Lee, Mein

   CS A250 - Fall 2019

   Project 2
*************************/

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <iterator>
#include <fstream>
#include <string>

class Student: public Person
{
public:
	// default constructor
	Student();

	// setStudentInfo
	void setStudentInfo(const std::string&, const std::string&, 
				int, bool, const std::multimap<Course, char>&);

	// getID
	int getID() const;

	// getNumberOfCourses
	int getNumberOfCourses() const;

	// getUnitsCompleted
	double getUnitsCompleted() const;

	// getGpa
	double getGPA() const;

	// isTuitionPaid
	bool isTuitionPaid() const;

	// courseIsCompleted
	bool courseIsCompleted(const std::string&, int) const;

	// printStudent
	void printStudent() const;

	// printStudentInfo
	void printStudentInfo() const;

	// destructor
	~Student();

private:
    int studentID;				
    bool tuitionWasPaid;
	int totalCourses;
	std::multimap<Course, char> coursesCompleted;
};

#endif


