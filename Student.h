/*
 * Student.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include "Room.h"
#include "Error.h"
using namespace std;
class Room;

class Student {
protected:
	string m_first_name;
	string m_last_name;
	int m_id;
	int m_avg;
	vector<string> m_msg;
	Room* m_curr_room;
	int m_room_id;


public:
	Student();
	Student(string first , string last , int id , int avg);


	friend ostream& operator<<(ostream& out, const Student& other);
	virtual void Cry()=0; // pure virtual for L student
	virtual bool LazyToLazyRoom(Room* to_room)=0;
	//virtual void SendMsg()=0; // pure virtual for R student
	virtual void Work()=0; // pure virtual for W student
	virtual bool WorkerToWorkerRoom(Room* to_room)=0;
	//bool setRoom(int r_id);
	virtual void MoveRoom(Room* to_room);
	virtual void removeRoom();
	virtual void MoveRoom(){Cry(),m_curr_room = nullptr , m_room_id = -1;};
	string getFirstName(){return m_first_name;}
	Student* GetStudent(){return this;};
	int GetID(){return m_id;};
	int GetRoomID(){return m_room_id;};
	Room* GetStuRoom(){return m_curr_room;};
	vector<string> GetMsg(){return m_msg;};
	virtual void Get_Msg_Str(string m);
	virtual void SendMsg(vector<Student*> v,string msg,int room_id)=0;
	virtual ~Student();
	Student* operator=(const Student& other);

	virtual void SetRId(int r_id){m_room_id=r_id;};
	virtual void SetRoomAsNullptr(){m_curr_room=nullptr;};


};


#endif /* STUDENT_H_ */
