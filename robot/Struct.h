#ifndef _STRCT1101_
#define _STRCT1101_
#define N 6
#include <iostream>
using namespace std;

typedef struct robot_st{
	int ID;

	int Llength;
	char* Lstatus;
	int Lpower;
	float Lversion;

	int Hlength;
	char* Hstatus;
	int Hpower;
	float Hversion;

	float Bversion;
	int Bsize;

	Sensors* sn;
}robot_st;


robot_st& setRobot(int _x=0, int _y=0);



#endif _STRCT1101_