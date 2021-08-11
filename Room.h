/*
 * Room.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */

#ifndef ROOM_H_
#define ROOM_H_
#include "Student.h"
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include "Error.h"
using namespace std;
class Student;

class Room {
protected:
	int m_id;
	vector<Student*> in_room;
	int size;
	Room* m_abba;
	Room* m_right;
	Room* m_left;
	bool m_splited;
	bool has_cleared;

public:
	Room();
	Room(int id){m_id = id , m_splited = false, m_abba = nullptr , m_right = nullptr , m_left = nullptr,size = 0, has_cleared = false;};
	Room(int id, Room* abba){m_id = id , m_splited = false ,m_abba = abba, m_right = nullptr , m_left = nullptr,size = 0,has_cleared = false;};
	bool Add(Student* s);
	void remove(int id);
	void remove(Student* s);
	void CharecterSplit(int l_id , int r_id);
	void SizeSplit(int l_id , int r_id);
	void is_splited();
	Student* FindById(int id);
	Room* GetRoom(){return this;};
	Room* Get_L_Room(){return m_left;};
	Room* Get_R_Room(){return m_right;};
	Room* Get_abba(){return m_abba;};
	void set_abba(Room* abba){m_abba = abba;};
	void set_l_room(Room* left){m_left = left;};
	void set_r_room(Room* right){m_right = right;};

	int GetRoomSize(){return size;};
	vector<Student*> Get_Students();
	bool is_cleared(){return has_cleared;};
	void deleteRoom();
	bool R_son(int s_id);

	int GetID(){return m_id;};
	virtual ~Room();

	friend ostream& operator<<(ostream& out, const Room& other);
	Room* operator=(const Room& other);
};


#endif /* ROOM_H_ */
