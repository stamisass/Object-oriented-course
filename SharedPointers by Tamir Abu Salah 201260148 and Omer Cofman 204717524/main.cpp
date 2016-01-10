#include <string>
#include "SharedPointer.h"
#include "Student.h"
#include "Course.h"
#include "DataManager.h"
#include "Logger.h"
using namespace std;

int main(int argc, char* argv[]) {

	DataManager dm(argv[3]);
	dm.init(argv[1]);				
	dm.simulation(argv[2]);
	cout << "\nEnd\n" << endl;

	system("pause");
	return 0;
}



/*** LAST EDIT: 8 MAY 9:45 PM OMER***/