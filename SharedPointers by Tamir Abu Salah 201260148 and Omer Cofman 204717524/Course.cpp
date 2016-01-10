#include <vector>
#include <string>
#include "Logger.h"
#include "SharedPointer.h"
#include "Student.h"
using namespace std;

#include "Course.h"


void Course::setpnts(int pnt){pnts=pnt;}

void Course::setname(string _name){name = _name;}

void Course::AddStudent (SharedPointer< Student> stu){
	if(stu->isActiv() == 1){
		svec.push_back(stu);
		cout << stu->GetName() <<" has been added to the course " << name << endl;
		log.log("Student has been added to the course: ", name, stu->GetName());
	}
	else{
		cout << "Cannot add this student , He or She is not register to the collage !" << endl; 
		log.log("Cannot add this student ", "He or She is not register to the collage: ",stu->GetName());
	}
}

int Course::GetCid(){return cid;}

int Course::GetPnts(){return pnts;}

int Course::GetSvecSize(){return svec.size();}

SharedPointer<Student> Course::GetStudent(int i){return svec.at(i);}

SharedPointer<Student> Course::GetStudentById(string id){
	int j;
	for(j=0 ; j < svec.size()-1 ; j++){
		if(svec.at(j)->GetId().compare(id)) break; //search for the course in the course vec
		if(j == svec.size()-1) j = -1;
	}
	if(j != -1){
		return svec.at(j);
	}
	else{
		cout << "Student Not Found!" <<endl;
		log.log("Student Not Found: ", id);
	}
	
	
	
}

void Course::RemoveStudent(int i){svec.erase(svec.begin()+i);}

void Course::RemoveStudentById(string id){
	int j;
	for(j=0 ; j < svec.size() ; j++){
		if(id.compare(svec.at(j)->GetId()) == 0) break; //search for the student in the course svec
		if(j == svec.size()-1) j = -1;
	}
	if(j != -1){
		svec.erase(svec.begin()+j);
		cout << "Student removed from course!" <<endl;
		log.log("Student removed from course: ", id);

	}
	else{
		cout << "Student Not Found!" << endl;
		log.log("Student Not Found: ", id);
	}
}
void Course::SetName(string _Name){name=_Name;}

void Course::ShowDetails(){

	cout << "Course number: " << cid << endl;		log.log("Course number: ", to_string((long long)cid));
	cout << "Course points: " << pnts << endl;	log.log("Course points: ", to_string((long long)pnts));
	cout << "Course students: " << endl;			log.log("Course students:");
	for(int i=0 ; i <= svec.size() ; i++){
		log.log(svec.at(i)->ShowSDetails());	
	}
}