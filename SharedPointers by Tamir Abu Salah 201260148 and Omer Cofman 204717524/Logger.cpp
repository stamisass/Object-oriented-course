#include <iostream>
#include <string>
using namespace std;

#include "Logger.h"


	void Logger::log(string msg, string extra1, string extra2) {
		FILE *pf = fopen(file.c_str(), "a");
		if(pf == NULL) {
			cout << "Error opening " << file << endl;
			system("pause");
		}

		fprintf(pf, "%s%s %s%c", msg.c_str(), extra1.c_str(), extra2.c_str(),'\n');

		fclose(pf);
	}

	string Logger::getPath() {
		return file;
	}