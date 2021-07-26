/************************
   7Leaves

   Nguyen, Lan
   Lee, Mein

   CS A250 - Fall 2019

   Project 2
*************************/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"
#include <vector>

class CourseList
{
public:
	// CourseList
	CourseList();

	// Overloaded constructor
	CourseList(int newCapacity);

	// Copy constructor
	CourseList(const CourseList& otherList);

	// addCourse
	void addCourse(const Course& newCourse);

	// getCourseUnits
	double getCourseUnits(const std::string& coursePrefix, int courseNo) const;

	// searchCourse
	bool searchCourse(const std::string& coursePrefix, int courseNo) const;

	// overloaded operator=
	CourseList& operator=(const CourseList& otherList);

	// destructor
	~CourseList();
private:
	std::vector<Course> courseList;
	static const int CAP;

};

#endif
