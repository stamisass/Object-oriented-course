#include <vector>
#include <string>
#include "Course.h"
#include "SharedPointer.h"
#include "Logger.h"
#include "Student.h"
using namespace std;

#include "Department.h"


	string Department::GetDepName(){
		return name;
	}

	void Department::setName(string _name) {
		name = _name;
	}

	void Department::AddStudent (SharedPointer<Student> stu){
		svec.push_back(SharedPointer<Student>(stu));
		cout << "Student has been added to " << name << " department! " << endl;
		log.log("Student has been added to department: ", name);
	}

	SharedPointer<Student> Department::GetStudent(int i){
		return svec.at(i);
	}

	int Department::GetSvecSize(){
		return svec.size();
	}

	void Department::AddCourse(SharedPointer<Course> crs){
		cvec.push_back(crs);
		cout << endl;
		cout << crs->GetCid() << " is added to " << name << " department" << endl;
		cout << endl;
		log.log("Course added to department: ", to_string((long long)crs->GetCid()), name);
	}
