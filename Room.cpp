/*
 * Room.cpp
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */

#include "Room.h"
#include <algorithm>
/*Room::Room() {
	// TODO Auto-generated constructor stub

}*/
/*Room::~Room() {
	this->set_abba(nullptr);
	//this->
	// TODO Auto-generated destructor stub
}*/
Room::~Room()
{
	in_room.clear();
	in_room.shrink_to_fit();
	//delete ;
	//delete this;

}

bool Room::Add(Student* s)
{
	in_room.push_back(s);
	s->MoveRoom(this);
	size++;
	return true;
}
void Room::remove(Student* s)
{

	in_room.erase(std::remove(in_room.begin(),in_room.end(),s),in_room.end());//delete s from the vector
	size--;
	s->removeRoom();

}

void Room::remove(int id)// need to change it to id shit
{
	Student* s = this->FindById(id);
	//in_room.erase(std::remove(in_room.begin(),in_room.end(),*s),in_room.end());
	s->removeRoom();
	size--;

}

Student* Room::FindById(int id)
{
	int size = in_room.size();
	for (int i = 0 ; i < size ; i++)
	{
		if ((in_room[i]->GetID()) == id )
		{
			Student* s = (in_room[i]);
			return s;
		}
	}
	throw id_exception();
	//return s;
}


void Room::CharecterSplit(int l_id , int r_id)
{
	if (this->m_splited)
	{
		throw "Split before";
	}
	Room* temp = new Room(l_id);
	temp->m_abba = this;
	this->m_left = temp->GetRoom();
	Room* temp1 = new Room(r_id);
	temp1->m_abba = this;
	this->m_right = temp1->GetRoom();
	int i = 0;
	while (i < size )
	{
		if(i>(int)in_room.size())
			break;
		Student* s = (in_room[i]);
		//Student* s = (t);//its magic
		if(!(s->LazyToLazyRoom(this->m_right)))
		{
			i++;
			continue;
		}
		//(*s).removeRoom();
		//this->m_right->Add(s);
		//this->m_right->in_room.push_back(s);
		in_room.erase(std::remove(in_room.begin(),in_room.end(),s),in_room.end());
		size--;
	}
	i = 0 ;
	//this->size = in_room.size();
	while (i < size )
	{
		if(i>(int)in_room.size())
			break;
		Student* s = (in_room[i]);
		//Student* s = (t);//its magic
		if(!(s->WorkerToWorkerRoom(this->m_left)))
		{
			i++;
			continue;
		}
		//(*s).removeRoom();
		//this->m_right->Add(s);
		//this->m_left->Add(s);
		in_room.erase(std::remove(in_room.begin(),in_room.end(),s),in_room.end());
		size--;
	}
	//this->size = 0;
	this->m_splited = true;

}


void Room::SizeSplit(int l_id , int r_id)// need to change the rooms so they will get the right room number
{
	if (this->m_splited)
	{
		throw "Split before";
	}
	Room* temp = new Room(l_id ); // need to fix
	temp->m_abba = this;
	this->m_left = temp->GetRoom();
	Room* temp1 = new Room(r_id ); // need to fix
	temp1->m_abba = this;
	this->m_right = temp1->GetRoom();
	int i = 0 ;
	if (size > 0)
	{
		while (i < (size /2) + 1)
		{

			Student* s = (in_room[(size/2) +i]);
			//Student* s = (t);//its magic
			(*s).removeRoom();
			this->m_right->Add(s);
			in_room[(size/2)+i] = nullptr;
			//in_room.pop_back();
			i++;
		}
		i = 0 ;
		while (i < (size /2) )
		{
			Student* s = (in_room[i]);
			//Student* s = &(*t);//its magic
			(*s).removeRoom();
			this->m_left->Add(s);
			in_room[i]=nullptr;
			//in_room.pop_back();
			i++;
		}

	}
	i = 0;
	while (i < size  )
	{
		in_room.pop_back();
		i++;
	}
	this->size = 0;
	this->m_splited = true;
}

void Room::is_splited()
{
	if (this->m_splited == true)
	{
		throw Split_before();
	}
	return;
}



ostream& operator<<(ostream& out, const Room& other)
{
	out << "room id:" <<  other.m_id << ", students:" << other.size << endl;
	return out;

}


Room* Room::operator=(const Room& other)
{
	m_id=other.m_id;
	in_room=other.in_room;
	size=other.size;
	m_abba=other.m_abba;
	m_right=other.m_right;
	m_left=other.m_left;
	m_splited=other.m_splited;
	return this;
}



void Room::deleteRoom()
{
	//base step - check sons
	if (m_splited)
	{
		//start from left son - if exists
		if(this->Get_L_Room()!=nullptr)
			this->Get_L_Room()->deleteRoom();
		//right son - only if exist!
		if(this->Get_R_Room()!=nullptr)
			this->Get_R_Room()->deleteRoom();
	}
	//if i have abba i need to transfer all my students to him
	if (this->m_abba!=nullptr)
	{
		for (int i=0;i<(int)this->in_room.size();i++)
		{
			m_abba->Add(this->in_room[i]);
			this->in_room[i]->Cry();
			this->in_room[i]=nullptr;
		}
		//need to check what kind of son am i - R/L
		//and update abba
		if(m_abba->R_son(m_id))
		{
			m_abba->m_right=nullptr;
		}
		else
		{
			m_abba->m_left=nullptr;
		}

	}
	else//i dont have abba :(, all my students need to go to room -1
	{
		for (int i=0;i<(int)this->in_room.size();i++)
		{
			this->in_room[i]->SetRId(-1);
			this->in_room[i]->Cry();
		}
		for (int i=0;i<(int)this->in_room.size();i++)
		{
			this->remove(this->in_room[i]);
			this->in_room[i]=nullptr;
		}
	}
	has_cleared = true;//update that i gone
	in_room.clear();//clear my leftovers

}



bool Room::R_son(int s_id)
{//return true if son is right son
	if (m_right==nullptr)
		return false;
	if (this->m_right->m_id==s_id)
		return true;
	return false;
}



vector<Student*> Room::Get_Students()
{
	vector<Student*> v;
	if(size==0)
		return v;
	else
		return in_room;
}







