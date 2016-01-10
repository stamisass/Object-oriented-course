#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Robot.h"
#include <string>
#include "Struct.h"
using namespace std;


robot_st& setRobot(int _x, int _y){
	int ID;

	int Llength;
	char* Lstatus= new char [N];
	if(Lstatus==0)
		cout<<"MEMORY ERROR"<<endl;
	
	int Lpower;
	float Lversion;

	int Hlength;
	char* Hstatus= new char [N];
	if(Hstatus==0)
		cout<<"MEMORY ERROR"<<endl;
	
	int Hpower;
	float Hversion;

	float Bversion;
	int Bsize;

	const int max=100;
	char v[max];
	char a;

	ifstream infile;
	infile.open("Birth.txt");
	if (infile==0){
		cout<< "Error Opening Birth.txt file"<<endl;
		system("pause");
	}else{system("color b");}

	infile.get(a);
	if(a == '#')
		infile.getline(v, max);
	

	infile>>ID;
	infile.getline(v, max);

	infile.get(a);
	if(a == '#')
		infile.getline(v, max);
	

	infile>>Llength;			//**Leg**//
	infile.get(a);
	infile.get(Lstatus,N);
	for(int i=0;i<N;i++)		//serch for ',' in the string to replace with '\0'
		if(Lstatus[i]==',')
			Lstatus[i]='\0';

	infile>>Lpower;
	infile.get(a);
	infile>>Lversion;

	infile.getline(v, max);					
	infile.get(a);
	if(a == '#')
		infile.getline(v, max);
	
	infile>>Hlength;			//**Hand**//
	infile.get(a);
	infile.get(Hstatus,N);
	for(int i=0;i<N;i++)		//serch for ',' in the string to replace with '\0'
		if(Hstatus[i]==',')
			Hstatus[i]='\0';

	infile>>Hpower;
	infile.get(a);
	infile>>Hversion;

	infile.getline(v, max);					
	infile.get(a);
	if(a == '#')
		infile.getline(v, max);
	

	infile>>Bversion;			//**Brain**//
	infile.get(a);
	infile>>Bsize;

	infile.getline(v, max);					
	infile.get(a);
	if(a == '#')
		infile.getline(v, max);
	

	infile.getline(v, max);		//**Sensors**//
	int q=0;
	int b=0;
	while (v[q] != '\0'){
		if(v[q] == ',')
			b++;
		q++;
	}

	Sensors* sn = new Sensors[b+1];
	if(sn==0)
		cout<<"MEMORY ERROR"<<endl;
	

	char temp[max];
	int i, e=0, t=0;
	while(e<(b+1)){
		for(i=0; v[i]!=','; i++,t++)
			temp[i]=v[t];
		temp[i]='\0';
		i+=1;
		t+=1;
		sn[e].setName(i, temp);
		e++;
	}
	
	robot_st r;
	r.ID=ID;
	r.Llength=Llength;
	r.Lstatus=Lstatus;
	r.Lpower=Lpower;
	r.Lversion=Lversion;
	r.Hlength=Hlength;
	r.Hstatus=Hstatus;
	r.Hpower=Hpower;
	r.Hversion=Hversion;
	r.Bversion=Bversion;
	r.Bsize=Bsize;
	r.sn=sn;

	return r;

}
