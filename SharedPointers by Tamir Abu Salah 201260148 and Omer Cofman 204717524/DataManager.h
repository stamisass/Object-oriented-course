#include "SharedPointer.h"
#include "Course.h"
#include "College.h"
#include "Department.h"
#include "Student.h"
#include <vector>
#include <string>
#include <stdio.h>
#include "Logger.h"
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma once

class DataManager {
	Logger log;
	College	clg;
	vector<SharedPointer<Course>>		vec_sp_crs;
	vector<SharedPointer<Department>>	vec_sp_dep;
	vector<SharedPointer<Student>>		vec_sp_st;

public:
	DataManager(string logfile):log(logfile),clg(logfile){}

	void init(char * filename);

	void simulation(char * filename);
};