#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Robot.h"
#include <string>
#include "Struct.h"
using namespace std;


int main(){
	
	robot_st tmp= setRobot();
	Robot r(tmp.ID,tmp.Llength,tmp.Lstatus,tmp.Lpower,tmp.Lversion,tmp.Hlength,tmp.Hstatus,tmp.Hpower,tmp.Hversion,tmp.Bversion,tmp.Bsize,tmp.sn);//x=0, y=0 -by default

	const int max=100;
	char v[max];
	char a;

	int choose;
	cout <<endl << "Do you wish to upload commands from file or control in real time? file =0, real time =1, close program=2 " <<endl;
	cin>>choose;
	if(choose == 2) return 0;
	if (choose == 0){
		ifstream infile;
		infile.open("simulation.txt");
		if (infile==0){
			cout<< "Error Opening simulation.txt file"<<endl;
			system("pause");
		}

		int p=0;
		while (!(infile.eof())){
			int operation=0, steps=0, x=0, y=0;
			infile.get(a);
			if(a == '#'){infile.getline(v, max);}

			infile>>operation;
			infile.get(a);

			switch(operation){
			case (1):
				infile>>steps;
				r.goAhead(steps);
				break;
			case(2):
				infile>>steps;
				r.goBack(steps);
				break;
			case(3):
				infile>>steps;
				r.goLeft(steps);
				break;
			case(4):
				infile>>steps;
				r.goRight(steps);
				break;
			case(5):
				infile>>x;
				infile.get(a);
				infile>>y;
				r.liftFrom(x,y);
				break;
			case(6):
				r.drop();
				break;
			default:
				cout<<"Error with command"<<endl;
				break;
			}

			infile.getline(v, max);
			infile.getline(v, max);
			p++;
		}
	}else{				//////else//////
		while(1){
			int operation=0, steps=0, x=0, y=0;

			cout<<endl<< "Choose an Operation: 1- go ahead, 2- go back, 3- go left, 4- go right, 5-lift from, 6-drop item , 7-close program: "<<endl;
			cin>>operation;


			switch(operation){
			case (1):
				cout<<"How many steps?: "<<endl;
				cin>>steps;
				r.goAhead(steps);
				break;
			case(2):
				cout<<"How many steps?: "<<endl;
				cin>>steps;
				r.goBack(steps);
				break;
			case(3):
				cout<<"How many steps?: "<<endl;
				cin>>steps;
				r.goLeft(steps);
				break;
			case(4):
				cout<<"How many steps?: "<<endl;
				cin>>steps;
				r.goRight(steps);
				break;
			case(5):
				cout<<"Choose x: "<<endl;
				cin>>x;
				cout<<"Choose y: "<<endl;
				cin>>y;
				r.liftFrom(x,y);
				break;
			case(6):
				r.drop();
				break;
			case(7):
				return 0;
			default:
				cout<<"Error with command"<<endl;
				break;
			}

		}

	}

	cout<<endl<<endl<<endl;
	system("pause");
	return 0;
}

