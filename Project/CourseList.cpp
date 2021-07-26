/************************
   7Leaves

   Nguyen, Lan
   Lee, Mein

   CS A250 - Fall 2019

   Project 2
*************************/

#include "CourseList.h"

using namespace std;

const int CourseList::CAP = 10;

// CourseList
CourseList::CourseList()
{
	courseList.reserve(CAP);
}

// Overloaded constructor
CourseList::CourseList(int newCapacity)
{
	courseList.reserve(newCapacity);
}

// Copy constructor
CourseList::CourseList(const CourseList& otherList)
{
	courseList = otherList.courseList;
}

// addCourse
void CourseList::addCourse(const Course& newCourse)
{
	if (courseList.size() == courseList.capacity())
		courseList.reserve(2 * courseList.capacity());

	courseList.push_back(newCourse);
}

// getCourseUnits
double CourseList::getCourseUnits(const string& coursePrefix, 
									int courseNo) const
{
	int i = 0;
	while (i < courseList.size() &&
		(courseList[i].getCoursePrefix() != coursePrefix ||
			courseList[i].getCourseNo() != courseNo))
	{
		i++;
	}
	
	if (i < courseList.size())
		return courseList[i].getCourseUnits();
	return 0;
}

// searchCourse
bool CourseList::searchCourse(const string& coursePrefix, 
								int courseNo) const
{
	int i = 0;
	while (i < courseList.size())
	{
		if (courseList[i].getCoursePrefix() == coursePrefix
			&& courseList[i].getCourseNo() == courseNo)
			return true;

		++i;
	}

	return false;
}

// overloaded operator=
CourseList& CourseList::operator=(const CourseList& otherList)
{
	if (this == &otherList)
		cerr << "Assigning to self" << endl;
	else
		courseList = otherList.courseList;

	return *this;
}

// destructor
CourseList::~CourseList()
{
}
