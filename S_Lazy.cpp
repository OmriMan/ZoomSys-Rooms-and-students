/*
 * S_Lazy.cpp
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */

#include "S_Lazy.h"

/*
void S_Lazy::SendMsg()
{
	throw "Student permissions";
}*/

void S_Lazy::Cry()
{
	cout << m_first_name << " " << m_last_name << " is crying" << endl;
}

bool S_Lazy::LazyToLazyRoom(Room* to_room)
{
	this->removeRoom();
	to_room->Add(this);
	return true;
}

void S_Lazy::SendMsg(vector<Student*> v,string msg,int room_id)
{
	throw Student_permissions();
}
