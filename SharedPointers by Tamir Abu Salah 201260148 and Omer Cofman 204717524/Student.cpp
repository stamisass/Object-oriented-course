#include <string>
#include "Logger.h"
using namespace std;

#include "Student.h"


int Student::GetPnts(){return pnts;}

string Student::GetName(){return fname;}

string Student::GetId(){return id;}

int Student::GetRegYear(){return RegYear;}

int Student::isActiv(){return activ;}

void Student::UpdateStatus(int i){activ = i;}

void Student::setExYear(int year){exYear = year;}

void Student::UpdatePnts(int _pnts){
	if(_pnts != 0){
	pnts += _pnts;
	cout <<"Student points are updated!" <<endl;
	log.log("Student points are updated: ",to_string((long long)_pnts));
	}else cout << " " ;
}

string Student::ShowSDetails(){
	string sd = "";
	sd += fname + " " + lname;
	cout << sd << endl;
	return sd;
}