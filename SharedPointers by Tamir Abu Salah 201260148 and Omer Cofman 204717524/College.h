#include <vector>
#include <string>
#include "Course.h"
#include "Department.h"
#include "SharedPointer.h"
#include "Student.h"
#include "Logger.h"
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma once

class College {
	Logger log;
	string name;
	vector<SharedPointer<Department>> dvec;
	vector<SharedPointer<Course>> cvec;
	vector<SharedPointer<Student>> svec;
public:

	College(string logfile):log(logfile){}
	College(string _name, string logfile): name(_name),log(logfile){}

	void setName(string _name);

	string getName() const;
	void AddDep(string dep);
	void AddCrs(int crs);
	SharedPointer<Course> GetCourse(int crs);

	void AddStudent(string firstname, string lastname, string studentID, string address, int regYear, string department);
	void AddStudentToDep(string id , string dep );
	void AddCourseToDep(int cid , string dep );

	void AddStudentToCrs(string id , int Crs );
	void EndCourse(int cid);
	void ShowCycleDetails(string dep , int year);
	void RemoveStuFromCollag(string id , int exyear);


};
