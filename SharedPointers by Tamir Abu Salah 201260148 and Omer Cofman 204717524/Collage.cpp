#include <vector>
#include <string>
#include "Course.h"
#include "Department.h"
#include "SharedPointer.h"
#include "Student.h"
#include "Logger.h"
using namespace std;

#include "College.h"


void College::setName(string _name) {
	name = _name;
	cout << "new college: " << _name << endl;
}

string College::getName() const {
	return name;
}

void College::AddDep(string dep){
	dvec.push_back(SharedPointer<Department>(new Department(dep, log.getPath())));	
	cout << dep << " department has been added!" << endl;
	log.log("Department has been added: ", dep);
}

void College::AddCrs(int crs){
	SharedPointer<Course> _crs = new Course(crs,log.getPath());
	cvec.push_back(_crs);	//add course to course vec
	cout << "Course added to college" << endl;
	log.log("Course added to college");
	
}

SharedPointer<Course> College::GetCourse(int crs){
	int j;
	for(j=0 ; j < cvec.size() ; j++){
		if(cvec.at(j)->GetCid() == crs) break; //search for the course in the course vec
		if(j == cvec.size()-1){ j = -1;break;}
	}
	if(j != -1){
		return cvec.at(j);
	}
	else{
		return NULL;
	}
}

void College::AddStudent(string firstname, string lastname, string studentID, string address, int regYear, string department){
	svec.push_back( SharedPointer<Student>(new Student(firstname,lastname,studentID,address,regYear,department,log.getPath())));
	cout << firstname << " " <<lastname << " is added to college" <<endl;
	log.log("Student added to collage: ", firstname, lastname);
}

void College::AddStudentToDep(string id , string dep ){
	int i,j;
	for(i = 0 ; i < svec.size() ; i++){
		if(id.compare(svec.at(i)->GetId()) == 0) break; //search for the student in the student vec
		if(i == svec.size()-1){
			i = -1;
			break;
		}
	}
	if(i != -1){
		for(j=0 ; j < dvec.size() ; j++){
			if(dvec.at(j)->GetDepName().compare(name)) break; //search for the department in the departmrnt vec
			if(j == dvec.size()-1){
				j = -1;
				break;
			}
		}
		if(j != -1){
			dvec.at(j)->AddStudent(svec.at(i)); //adds the student to the department
		} else {
			cout << "Department Not Found!" << endl;
			log.log("Department Not Found: ", dep);
		}
	} else {
		cout << "Student Not Found!"<< endl;
		log.log("Student Not Found: ", id);
	}
}



void College::AddCourseToDep(int cid , string dep ){
	int i,j;
	for(i = 0 ; i < cvec.size() ; i++){
		if(cvec.at(i)->GetCid() == cid) break; //search for the course in the course vec
		if(i == cvec.size()-1){
			i = -1;
			break;
		}
	}
	if(i != -1){
		for(j=0 ; j < dvec.size() ; j++){
			if(dvec.at(j)->GetDepName().compare(dep)) break; //search for the department in the departmrnt vec
			if(j == dvec.size()-1){
				j = -1;
				break;
			}
		}
		if(j != -1){
			dvec.at(j-1)->AddCourse(cvec.at(i)); //adds the course to the department
		} else {
			cout << "Department Not Found!" << endl;
			log.log("Department Not Found: ", dep);
		}
	} else {
		cout << "Course Not Found!"<< endl;
	}
}


void College::AddStudentToCrs(string id , int Crs ){
	int i,j;

	for(i = 0 ; i < svec.size() ; i++){
		if(id.compare(svec.at(i)->GetId()) == 0) break; //search for the student in the student vec
		if(i == svec.size()-1) i = -1;
	}
	if(i != -1){
		for(j=0 ; j < cvec.size() ; j++){
			if(cvec.at(j)->GetCid() == Crs) break; //search for the course in the course vec
			if(j == cvec.size()-1){ j = -1; break;}
		}
		if(j != -1){
			cvec.at(j)->AddStudent(svec.at(i)); //adds the student to the course
		}
		else{
			cout << "Course Not Found!" << endl;
			log.log("Course Not Found: ", to_string((long long)Crs));
		}
	}
	else{
		cout << "Student Not Found!" << endl;
		log.log("Student Not Found: ", id);
	}
}	

void College::EndCourse(int cid){
	int i,j,pnts;

	for(j=0 ; j < cvec.size() ; j++){
		if(cvec.at(j)->GetCid() == cid) break; //search for the course in the course vec
		if(j == cvec.size()-1) {j = -1; break;}
	}
	if(j != -1){
		pnts=cvec.at(j)->GetPnts();
		for(i=0 ; i < cvec.at(j)->GetSvecSize() ; i++){
			cvec.at(j)->GetStudent(i)->UpdatePnts(pnts);
			cvec.at(j)->RemoveStudent(i);
		}
		cout << "Course is ended!" << endl;
		log.log("Course is ended: ", to_string((long long)cid));
	}
	else{
		cout << "Course not found!" <<endl;
		log.log("Course not found: ", to_string((long long)cid));
	}

}

void College::ShowCycleDetails(string dep , int year){
	int j,i,s=0;
	for(j=0 ; j < dvec.size() ; j++){
		if(dvec.at(j)->GetDepName().compare(name)) break; //search for the department in the departmrnt vec
		if(j == dvec.size()-1) j = -1;
	}
	if(j != -1){
		for(i=0 ; i < dvec.at(j)->GetSvecSize() ; i++){
			if(dvec.at(j)->GetStudent(i)->GetRegYear() == year){
				s++;
				if(dvec.at(j)->GetStudent(i)->GetPnts() < 160 && dvec.at(j)->GetStudent(i)->isActiv() == 0){
					string acc = "Graduated students: ";
					cout << acc << endl;
					string grad = dvec.at(j)->GetStudent(i)->ShowSDetails();
					log.log(acc+grad);
				}
			}
		}
		cout << "Number of students started in " << year << " is : " << s << endl;

		log.log("Number of students started in: ", to_string((long long)year), to_string((long long)s));
	}
}

void College::RemoveStuFromCollag(string id , int exyear){

	int i,j;
	for(i = 0 ; i < svec.size() ; i++){
		if(id.compare(svec.at(i)->GetId()) == 0) break; //search for the student in the student vec
		if(i == svec.size()-1) i = -1;
	}
	if(i != -1){

		svec.at(i)->UpdateStatus(0); //disactive student
		svec.at(i)->setExYear(exyear); //update excluded  year
		cout << "Student has been removed from collage!" << endl;
		log.log("Student has been removed from collage: ", id);
	}
}
