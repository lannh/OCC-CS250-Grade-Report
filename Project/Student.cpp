/************************
   7Leaves

   Nguyen, Lan
   Lee, Mein

   CS A250 - Fall 2019

   Project 2
*************************/

#include "Student.h"

using namespace std;

// default constructor
Student::Student()
{
	studentID = 0;
	totalCourses = 0;
	tuitionWasPaid = false;   
}

// setStudentInfo
void Student::setStudentInfo(const string& newFirstName, 
			const string& newLastName, 
			int newStudentID, bool newTuitionWasPaid, 
			const multimap<Course, char>& newCoursesCompleted)
{
	setName(newFirstName, newLastName);
	studentID = newStudentID;
	totalCourses = static_cast<int>(newCoursesCompleted.size());
	tuitionWasPaid = newTuitionWasPaid;
	coursesCompleted = newCoursesCompleted;
}

// getID
int Student::getID() const
{
	return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return totalCourses;
}

// getUnitsCompleted
double Student::getUnitsCompleted() const
{
	double sum = 0.0;
	for (auto i : coursesCompleted)
		sum += i.first.getCourseUnits();
	return sum;
}

// getGpa
double Student::getGPA() const
{
	double sum = 0.0;
	for (auto i : coursesCompleted)
	{
		switch (i.second)
		{
		case 'A': 
			sum += 4.0 * i.first.getCourseUnits();
			break;
		case 'B' : 
			sum += 3.0 * i.first.getCourseUnits();
			break;
		case 'C': 
			sum += 2.0 * i.first.getCourseUnits();
			break;
		case 'D': 
			sum += i.first.getCourseUnits();
			break;
		case 'F':
			break;
		default: 
			cout << "Invalid Course Grade" << endl; 
		}
	}

	return sum / getUnitsCompleted();
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

// courseIsCompleted
bool Student::courseIsCompleted(const string& coursePrefix, 
								int courseNo) const
{
	auto iterMap = coursesCompleted.begin();
	auto iterMapEnd = coursesCompleted.end();

	while (iterMap != iterMapEnd)
	{
		if (iterMap->first.getCoursePrefix() == coursePrefix && 
			iterMap->first.getCourseNo() == courseNo)
			return true;
		iterMap++;
	}
	return false;
}

// printStudent
void Student::printStudent() const
{
	cout << studentID << " - ";
	printName();
}

// printStudentInfo
void Student::printStudentInfo() const
{
	cout << "Student Name: ";
	printName();
	cout << endl;

	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses completed: " << totalCourses << endl;
	cout << endl;

	cout << "Course    Units     Grade" << endl;
	for (auto i : coursesCompleted)
	{
		i.first.printCourseInfo();

		if (tuitionWasPaid)
			cout << setw(8) << i.second << endl;
		else
			cout << setw(10) << "***" << endl;
	} 

	cout << endl;
	cout << "Total number of unit hours: " 
		<< static_cast<int>(getUnitsCompleted()) << endl;

	if (tuitionWasPaid)
	{
		cout << "Current term GPA: "
			<< fixed << setprecision(2) << getGPA() << endl;
	}
	else 
		cout << "*** Grades are being held for not paying the tuition. ***" 
			 << endl;

	cout << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
}

// destructor
Student::~Student()
{
}


