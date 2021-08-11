/*
 * Student.cpp
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */

#include "Student.h"

Student::Student(string first , string last , int id , int avg):m_first_name(first),m_last_name(last)
{
	if (id < 0 || avg < 0 || avg > 100)
	{
		throw Invalid_details();
	}
	m_id = id;
	m_avg = avg;
	m_curr_room = nullptr;
	m_room_id = -1;

}

ostream& operator<<(ostream& out, const Student& other)
{
	out << other.m_first_name << " " << other.m_last_name << " " << other.m_id << " " << other.m_avg << " " << other.m_room_id<< endl;
/*	if (other.m_msg.size()>0)
	{
		out << "---Messages---"<< endl;
		for (int i = 0 ; i < (int)other.m_msg.size();i++)
		{
			out << other.m_first_name << " " << other.m_last_name << ":" << other.m_msg[i] << endl;
		}
	}*/
	return out;

}


Student* Student::operator=(const Student& other)
{
	m_first_name=other.m_first_name;
	m_last_name=other.m_last_name;
	m_id = other.m_id;
	m_avg = other.m_avg;
	m_curr_room = other.m_curr_room;
	m_room_id = other.m_room_id;
	m_msg=other.m_msg;
	return this;
}


void Student::MoveRoom(Room* to_room)
{
	m_room_id = to_room->GetID();
	m_curr_room = to_room;
}

void Student::removeRoom()
{
	m_room_id = -1;
	m_curr_room = nullptr;
}

Student::~Student()
{
	m_msg.clear();
	m_msg.shrink_to_fit();
	m_first_name.clear();
	m_last_name.clear();

}

void Student::Get_Msg_Str(string m)
{
	m_msg.push_back(m);
}



