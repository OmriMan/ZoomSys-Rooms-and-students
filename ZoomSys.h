/*
 * ZoomSys.h
 *
 *  Created on: Jan 4, 2021
 *      Author: ise
 */

#ifndef ZOOMSYS_H_
#define ZOOMSYS_H_
#include "Room.h"
#include "Student.h"
#include "S_Lazy.h"
#include "S_Worker.h"
#include "S_Responsible.h"
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class ZoomSys {
protected:
	vector<Student*> students;
	vector<Room*> rooms;
	int room_last_index;
public:
	ZoomSys();
	ZoomSys(string filename);
	void addStudent();//1
	void removeStudent();//2
	void assignStudent();//3
	void addRoom();//4
	void splitRoom();//5
	void removeRoom();//6
	void work();//7
	void sendMessage();//8
	void printRooms();//9
	void printStudents();//p
	void printStudentDetails();//d

	void S_type(string t);
	void is_Stu_exist(int id);
	int Find_stu_postion(int id);
	void is_Stu_not_exist(int id);
	void is_room_exist(int id);
	void is_room_exist1(int id);
	int Find_room_postion(int id);
	void is_1_or_2(char c);

	void is_Room_exist_2(int id);
	Room* findRoom(int id);
	void is_Stu_exist_2(int id);
	Student* findStu(int id);


	void delete_left_son(Room* left);
	void delete_right_son(Room* right);
	void delete_me(Room* room);
	void delete_system();
	//bool room_is_here(int r_id);

	virtual ~ZoomSys();
};

#endif /* ZOOMSYS_H_ */
