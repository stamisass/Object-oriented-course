#include <vector>
#include <string>
#include "Logger.h"
#include "SharedPointer.h"
#include "Student.h"
using namespace std;

#pragma once

class Course {
	Logger log;
	int cid;
	int pnts;
	string name;
	vector<SharedPointer<Student>> svec;

public:
	Course(int crs , string logfile):cid(crs),pnts(0),name("NA"),log(logfile){}
	Course(int crs, int pnt , string _name, string logfile):cid(crs),pnts(pnt),name(_name),log(logfile){}
	void setpnts(int pnt);
	void setname(string _name);
	void AddStudent(SharedPointer< Student> stu);
	int GetCid();
	int GetPnts();
	int GetSvecSize();
	SharedPointer<Student> GetStudent(int i);
	SharedPointer<Student> GetStudentById(string id);
	void RemoveStudent(int i);
	void RemoveStudentById(string id);
	void ShowDetails();
	void SetName(string _name);

};

