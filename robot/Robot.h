#ifndef _RBTS1001_
#define _RBTS1001_
#define N 6
#include <iostream>
#include <fstream>
using namespace std;


class Leg{
	int length;
	char* status;
	int power;
	float version;
public:
	~Leg(){
		delete[] status;
		cout<< "Leg D'TOR called"<<endl;
	}
	Leg(int _length, char* _status, int _power, float _version){
		length= _length;
		status= new char[N];
		for(int i=0; i<N; i++)
			status[i]= _status[i];
		power= _power;
		version= _version;
		cout<< "Leg C'TOR called"<<endl;
	}
	void setL(int _length, char* _status, int _power, float _version);
};


class Hand{
	int length;
	char* status;
	int power;
	float version;
public:
	~Hand(){
		delete[] status;
		cout<< "Hand D'TOR called"<<endl;
	}
	Hand(int _length, char* _status, int _power, float _version){
		length= _length;
		status= new char[N];
		for(int i=0; i<N; i++)
			status[i]= _status[i];
		power= _power;
		version= _version;
		cout<< "Hand C'TOR called"<<endl;
	}
	void setH(int _length, char* _status, int _power, float _version);
};


class Brain{
	float version;
	int size;
public:
	Brain(float _version, int _size){
		version= _version;
		size= _size;
		cout<< "Brain C'TOR called"<<endl;
	}
	void setB(float _version, int _size);
};


class Sensors{
	char* name;
public:
	Sensors(){cout<< "Sensors C'TOR called"<<endl;} //"default" c'tor
	Sensors(int size, char* _name){	//conversion c'tor
		name= new char[size+1];
		for(int i=0; i<size; i++)
			name[i]= _name[i];
		name[size]='\0';
		cout<< "Sensors C'TOR called"<<endl;
	}
	void setName(int size, char* _name);
	~Sensors(){
		delete[] name;
		cout<< "Sensors D'TOR called"<<endl;
	}
};


class Robot{
	int ID;
	int x;
	int y;
	Leg l;
	Hand h;
	Brain b;
	Sensors* snsrs;
public:
	Robot(int _ID, int Llength, char* Lstatus, int Lpower, float Lversion,
		int Hlength, char* Hstatus, int Hpower, float Hversion,
		float Bversion, int Bsize,
		Sensors _snsrs[],
		int _x=0, int _y=0):
		l(Llength, Lstatus, Lpower, Lversion),
		h(Hlength, Hstatus, Hpower, Hversion),
		b(Bversion, Bsize){
			ID=_ID;
			x=_x;
			y=_y;
		}
	void goAhead(int step);
	void goBack(int step);
	void goLeft(int step);
	void goRight(int step);
	void liftFrom(int _x, int _y);
	void drop(){cout<< "Object droped"<<endl;} //inline function example
	

};


#endif _RBTS1001_