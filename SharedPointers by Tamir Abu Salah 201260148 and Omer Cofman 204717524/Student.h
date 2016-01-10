#include <string>
#include "Logger.h"
using namespace std;

#pragma once

class Student {
	Logger log;
	string fname;
	string lname;
	string id;
	string adrs;
	int RegYear;
	int exYear;
	int activ;
	string dep;

	int pnts;
public:

	Student(string firstname, string lastname, string studentID, string address, int regYear, string department ,string logfile):
	  fname(firstname), lname(lastname), id(studentID), adrs(address), RegYear(regYear), dep(department), pnts(0),activ(1),log(logfile){}
	int GetPnts();
	string GetName();
	string GetId();
	int GetRegYear();
	int isActiv();
	void UpdateStatus(int i);
	void setExYear(int year);
	void UpdatePnts(int _pnts);
	string ShowSDetails();
};