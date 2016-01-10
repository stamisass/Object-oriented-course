#include "SharedPointer.h"
#include "Course.h"
#include "College.h"
#include "Department.h"
#include "Student.h"
#include <vector>
#include <string>
#include <stdio.h>
#include "Logger.h"
using namespace std;

#include "DataManager.h"




void DataManager::init(char * filename) {
	char dash = '#', comma = ',', colon = ':', dot ='.';
	char line[500];
	int CrsArr[100];
	string sline;
	int index1, index2;
	int i;
	FILE *pf = fopen(filename,"r");
	if(pf == NULL) {
		cout << "Error opening " << filename << endl;
		log.log("Error opening ", filename);
		system("pause");
	}
	cout << "init file: \n" << endl;
	i = 0;
	while(fgets(line, 500, pf) != NULL) {
		if(line[0] != dash && line[0] != dot) {
			sline = line;
			index1 = sline.find(colon) +1;
			index2 = 0;

			if(i == 0) {  //College
				index2 = sline.length();
				clg.setName(sline.substr(index1, index2));
			}

			if(i == 1) {  //CollageDepartments
				while(index2 != -1){

					index2 = sline.find(comma);
					string temp = sline.substr(index1, index2-index1);
					if(temp.find('\n') != string::npos) {
						int size = temp.size();
						temp.resize(size-1);
					}
					clg.AddDep(temp); //add department to department vector (department constructor is called)
					index1 = sline.find(comma);
					if(index1 != -1) { //it turns out that string::substr() returns the first instence of what we look for, not the next; and -1 on failure
						sline[index1++] = colon;
					}
				}
			}

			if(i == 2) {  //CollageCoursesList
				int index3 =0;
				int tmp;

				while(index2 != -1){

					index2 = sline.find(comma);
					tmp = atoi(sline.substr(index1, index2-index1).c_str());
					clg.AddCrs(tmp);
					index3++;
					index1 = sline.find(comma);
					if(index1 != -1) { 
						sline[index1++] = colon;
					}
				}

			}

			if(i >= 3) {  //CourseDetails

				int index3 = 0;
				string dep;
				string name;
				int pnts;

				index2 = sline.find(comma);
				index3 = atoi(sline.substr(index1, index2-index1).c_str()); //course id (index) 



				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				dep = sline.substr(index1, index2-index1); //course department
				clg.AddCourseToDep(index3 , dep);


				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma); // //course points
				pnts = atoi(sline.substr(index1, index2-index1).c_str());
				clg.GetCourse(index3)->setpnts(atoi(sline.substr(index1, index2).c_str()));

				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma); // //course name
				name = sline.substr(index1, index2-index1);
				clg.GetCourse(index3)->SetName(sline.substr(index1, index2));


			}

			i++;
		}
	}

}




void DataManager::simulation(char * filename) {
	char dash = '#', comma = ',', colon = ':';
	char line[500];
	string sline;
	int index1, index2;
	int i;
	FILE *pf = fopen(filename,"r");
	if(pf == NULL) {
		cout << "Error opening " << filename << endl;
		log.log("Error opening ", filename);
		system("pause");
	}
	cout << endl << endl << "simulation file : \n" << endl;

	while(fgets(line, 500, pf) != NULL) {
		if(line[0] != dash) {
			sline = line;
			index1 = sline.find(comma);
			if(index1 != -1) {
				sline[index1++] = colon; 
			}
			index2 = sline.find(comma);

			if(sline[0]=='1'){ //operation 1 : add student to collage
				string id;
				string dep;
				string name;
				string lname;
				string adrr;
				int year;


				name = sline.substr(index1, index2-index1); //student name

				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				lname = sline.substr(index1, index2-index1); //student last name

				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				id = sline.substr(index1, index2-index1); //student id

				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				adrr = (sline.substr(index1, index2-index1)); //student adrres

				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				year = atoi(sline.substr(index1, index2-index1).c_str()); //student regYear

				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				dep = (sline.substr(index1, index2-index1)); //student department

				clg.AddStudent(name , lname , id , adrr , year , dep);
				clg.AddStudentToDep( id , dep ); //adds the student to the department




			}

			if(sline[0]=='2'){ // operation 2 : add student to course
				int cid;
				string id;

				id = sline.substr(index1, index2-index1); //student id
				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				cid = atoi(sline.substr(index1, index2-index1).c_str()); //course id

				clg.AddStudentToCrs(id , cid); // adds student to course


			}

			if(sline[0]=='3'){ // operation 3 : end course
				int cid;
				cid = atoi(sline.substr(index1,index2-index1).c_str()); //course id

				clg.EndCourse(cid);

			}

			if(sline[0]=='4'){ // operation 4 : student ends a course
				int cid,pnts;

				string id = sline.substr(index1, index2-index1); //student id
				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				cid = atoi(sline.substr(index1, index2-index1).c_str()); //course id
				pnts = clg.GetCourse(cid)->GetPnts();
				if(clg.GetCourse(cid)->GetSvecSize() != 0){
					clg.GetCourse(cid)->GetStudentById(id)->UpdatePnts(pnts);
					clg.GetCourse(cid)->RemoveStudentById(id);
				}
				else{
					cout << "student not found!" << endl;
					log.log("student not found!");
				}


			}

			if(sline[0]=='5'){ // operation 5 : remove student from a course
				int cid ,pnts;
				string id;

				id = sline.substr(index1,  index2-index1); //student id
				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				cid = atoi(sline.substr(index1, index2-index1).c_str()); //course id
				pnts = clg.GetCourse(cid)->GetPnts();



				if(clg.GetCourse(cid)->GetSvecSize() != 0){
					clg.GetCourse(cid)->RemoveStudentById(id);
				}
				else{
					cout << "student not found!" << endl;
					log.log("student not found!");
				}

			}

			if(sline[0]=='6'){ // operation 6 : remove student from collage
				int exYear;
				string id;

				id = sline.substr(index1, index2-index1); //student id
				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				exYear = atoi(sline.substr(index1, index2-index1).c_str()); //year when excluded

				clg.RemoveStuFromCollag(id , exYear); //remove student from collage

			}

			if(sline[0]=='7'){ //operation 7 : show department cycle details
				int year;
				string dep;

				dep = sline.substr(index1, index2-index1); //department name
				index1 = sline.find(comma);
				if(index1 != -1) {
					sline[index1++] = colon;
				}
				index2 = sline.find(comma);
				year = atoi(sline.substr(index1, index2-index1).c_str()); //cycle year

				clg.ShowCycleDetails(dep, year); //show cycle details

			}

			if(sline[0]=='8'){ //show course details
				int cid;

				cid = atoi(sline.substr(index1, index2-index1).c_str()); //course id
				if(clg.GetCourse(cid) == NULL){
					cout << "Course not found!" << endl;
					log.log("Course not found!");
				}else{
					clg.GetCourse(cid)->ShowDetails();
				}


			}

		}
	}
}