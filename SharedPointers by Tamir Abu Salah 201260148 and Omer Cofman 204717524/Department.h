#include <vector>
#include <string>
#include "Course.h"
#include "SharedPointer.h"
#include "Logger.h"
#include "Student.h"
using namespace std;

#pragma once

class Department {
	Logger log;
	string name;
	vector<SharedPointer<Course>> cvec;
	vector<SharedPointer<Student>> svec;
public:
	Department(string _name, string logfile):name(_name),log(logfile){}
	Department(string logfile):log(logfile){}

	string GetDepName();
	void setName(string _name);
	void AddStudent (SharedPointer<Student> stu);
	SharedPointer<Student> GetStudent(int i);
	int GetSvecSize();
	void AddCourse(SharedPointer<Course> crs);
};



