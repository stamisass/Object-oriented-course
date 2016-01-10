#include <iostream>
#include <fstream>
#include "Robot.h"
#include "Struct.h"
using namespace std;




void Leg::setL(int _length, char* _status, int _power, float _version){
		length= _length;
		status= _status;
		power= _power;
		version= _version;
		cout<< "Leg has been set" <<endl;
}

void Hand::setH(int _length, char* _status, int _power, float _version){
		length= _length;
		status= _status;
		power= _power;
		version= _version;
		cout<< "Hand has been set" <<endl;
}

void Brain::setB(float _version, int _size){
		version= _version;
		size= _size;
		cout<< "Brain has been set" <<endl;
}

void Sensors::setName(int size, char* _name){
		name= new char[size+1];
		for(int i=0; i<size; i++)
			name[i]= _name[i];
		name[size]='\0';
}


void Robot::goAhead(int step){
	y += step;
	cout<< "Moving "<< step << " steps ahead. "<< "(" << x << "," << y << ")" <<endl;
}

void Robot::goBack(int step){
	y -= step;
	cout<< "Moving "<< step << " steps backwards. " << "(" << x << "," << y << ")" <<endl;
}

void Robot::goLeft(int step){
	x -= step;
	cout<< "Moving "<< step << " steps to the left. " << "(" << x << "," << y << ")" <<endl;
}

void Robot::goRight(int step){
	x += step;
	cout<< "Moving "<< step << " steps to the right. " << "(" << x << "," << y << ")" <<endl;
}

void Robot::liftFrom(int _x, int _y){
	x = _x;
	y = _y;

	cout<< "Lifting object from "<< "(" << _x << "," << _y << ")" <<endl;
}
