/*
 * S_Worker.cpp
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */


#include "S_Worker.h"


void S_Worker::Work()
{
	cout << m_first_name << " " << m_last_name << " is working"<< endl;
}

/*void S_Worker::SendMsg()
{
	throw "Student permissions";
}*/

bool S_Worker::WorkerToWorkerRoom(Room* to_room)
{
	this->removeRoom();
	to_room->Add(this);
	return true;
}
void S_Worker::SendMsg(vector<Student*> v,string msg,int room_id)
{
	throw Student_permissions();
}

