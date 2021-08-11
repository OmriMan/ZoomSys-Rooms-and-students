//============================================================================
// Name        : hw5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "ZoomSys.h"
#include "Student.h"
#include "Room.h"
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include "Room.h"
#include "S_Lazy.h"
#include "S_Worker.h"
#include "S_Responsible.h"
#include <fstream>
#include <sstream>
#include "Error.h"



using namespace std;

/*int main()
{
	string f = "Daniel";
	string l = "Hodisan";
	S_Lazy daniel = S_Lazy(f,l,1,90);
	S_Lazy* d = &(daniel);

	S_Lazy omri = S_Lazy("omri" , "man" , 2 , 95);
	S_Lazy* o = &(omri);

	S_Worker roy = S_Worker("roy" , "haefes" , 3 , 56);
	S_Worker* r = &(roy);
	cout << daniel;
	cout<< omri;
	cout<< roy;


	Room room = Room(0);
	room.Add(d);
	room.Add(o);
	room.Add(r);
	cout << room;
	room.CharecterSplit(1, 2);
	//room.SizeSplit(1,2);
	cout << "After split" <<endl;
	cout << daniel;
	cout<< omri;
	cout<< roy;
	cout<< room;
	//return 0;
}*/

int main(int argc, char*argv[]) {
//int main() {

	ZoomSys* zoomSys = new ZoomSys(argv[1]);
	//ZoomSys* zoomSys = new ZoomSys("/home/ise/eclipse-workspace/hw5/src/input.txt");
	char menuOption;
	while(menuOption!='0')
	{
		cout<< "1. Add Student" << endl;
		cout<< "2. Remove Student" << endl;
		cout<< "3. Assign Student" << endl;
		cout<< "4. Add Room" << endl;
		cout<< "5. Split Room" << endl;
		cout<< "6. Remove Room" << endl;
		cout<< "7. Work" << endl;
		cout<< "8. Send Message" << endl;
		cout<< "9. Print Rooms" << endl;
		cout<< "p. Print Students" << endl;
		cout<< "d. Print Student details" << endl;
		cout<< "0. Exit" << endl;
		cin >> menuOption;
		switch(menuOption){
			case '1':
				zoomSys->addStudent();
				break;
			case '2':
				zoomSys->removeStudent();
				break;
			case '3':
				zoomSys->assignStudent();
				break;
			case '4':
				zoomSys->addRoom();
				break;
			case '5':
				zoomSys->splitRoom();
				break;
			case '6':
				zoomSys->removeRoom();
				break;
			case '7':
				zoomSys->work();
				break;
			case '8':
				zoomSys->sendMessage();
				break;
			case '9':
				zoomSys->printRooms();
				break;
			case 'p':
				zoomSys->printStudents();
				break;
			case 'd':
				zoomSys->printStudentDetails();
				break;
			case '0':
				cout<<"Bye.."<<endl;
				//zoomSys->delete_system();
				//zoomSys->~ZoomSys();
				delete zoomSys;
				//zoomSys = nullptr;
				break;
		}
	}



	return 0;
}
