/************************
   7Leaves

   Nguyen, Lan
   Lee, Mein

   CS A250 - Fall 2019

   Project 2
*************************/

#include "StudentList.h"

using namespace std;

const double StudentList::EPSILON = 0.0000001f;

// default constructor
StudentList::StudentList()
{
	studentList = new list<Student>;
}

// copy constructor
StudentList::StudentList(const StudentList& otherList)
{
	studentList = new list<Student>(*otherList.studentList);
	//*studentList = *otherList.studentList;
}

// addStudent
void StudentList::addStudent(const Student& newStudent)
{
	studentList->push_back(newStudent);
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return static_cast<int>(studentList->size());
}

// printStudentByID
void StudentList::printStudentByID(int ID) const
{
	if (studentList->empty())
		cerr << "List is empty" << endl;
	else
	{
		auto iterList = studentList->begin();
		auto iterListEnd = studentList->end();

		while (iterList != iterListEnd && iterList->getID() != ID)
			iterList++;

		if (iterList != iterListEnd)
			iterList->printStudentInfo();
		else 
			cout << "No student with ID " << ID 
				 << " found in the list." << endl;
	}
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(
				const string& coursePrefix, int courseNo) const
{
	if (studentList->empty())
		cerr << "List is empty." << endl;
	else
	{
		bool isNonOfStudentCompeleted = true;

		for(auto temp: *studentList)
		{
			if (temp.getNumberOfCourses() > 0 &&
				temp.courseIsCompleted(coursePrefix, courseNo))
			{
				isNonOfStudentCompeleted = false;
				temp.printStudent();
			}
		}

		if (isNonOfStudentCompeleted)
			cout << "No students compeleted " 
				<< coursePrefix << " " << courseNo << "." << endl;
	}
}
// printStudentByName
void StudentList::printStudentByName(const string& lastName) const
{
	if (studentList->empty())
		cerr << "List is empty." << endl;
	else
	{
		bool isStudentOfLastNameFound = false;

		for(auto temp: *studentList)
		{
			if (temp.getLastName() == lastName)
			{
				isStudentOfLastNameFound = true;
				temp.printStudent();
			}
		}

		if (!isStudentOfLastNameFound)
			cout << "No student with last name " << lastName
				 << " is in the list." << endl;
	}
}

// printStudentsOnHold
void StudentList::printStudentsOnHold() const
{
	if (studentList->empty())
		cerr << "No students in the list." << endl;
	else
	{
		bool noneOfTheStudentOnHold = true;

		for(auto temp: *studentList)
		{
			if (!temp.isTuitionPaid())
			{
				noneOfTheStudentOnHold = false;
				temp.printStudentInfo();
			}
		}

		if (noneOfTheStudentOnHold)
			cout << "There are no students on hold." << endl;
	}
}

// printAllStudents
void StudentList::printAllStudents() const
{
	for(auto temp: *studentList)
		temp.printStudentInfo();
}

// destroyStudentList
void StudentList::destroyStudentList()
{
	studentList->clear();
}

//Nguyen, Lan
//printFullTimeStudents
void StudentList::printFullTimeStudents() const
{
	bool noFullTimeStudents = true;

	for (auto temp : *studentList)
		if (static_cast<int>(temp.getUnitsCompleted()) >= 12)
		{
			temp.printStudentInfo();
			noFullTimeStudents = false;
		}

	if (noFullTimeStudents)
		cout << "There are no full time students.\n\n";
}

//Nguyen, Lan
//printStudentsWithMinGPA
void StudentList::printStudentsWithMinGPA(double minGPA) const
{
	bool noStudentsWithMinGPA = true;

	for (auto temp : *studentList)
	{
		double currentStudentGPA = temp.getGPA();
		if ((abs(currentStudentGPA - minGPA) < EPSILON) ||
			(currentStudentGPA > minGPA))
		{
			temp.printStudentInfo();
			noStudentsWithMinGPA = false;
		}
	}

	if (noStudentsWithMinGPA)
		cout << "There are no students with minimum GPA "
			 << fixed << setprecision(2) << minGPA << "\n\n";
}

// overloaded assignment operator
StudentList& StudentList::operator=(const StudentList& otherList)
{
	if(&otherList != this) // make sure objects are distinct
	{
		*studentList = *otherList.studentList;
	}
	else
	cerr << "Attempted assignment to itself." << endl;

	return *this;
}


// destructor
StudentList::~StudentList()
{
	delete studentList;
	studentList = nullptr;
}


