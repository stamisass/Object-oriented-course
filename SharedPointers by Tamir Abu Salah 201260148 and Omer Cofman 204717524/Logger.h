#include <iostream>
#include <string>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma once


class Logger {
protected:
	string file;
public:

	Logger(string filename):file(filename){}

	void log(string msg, string extra1="", string extra2="");

	string getPath();
};