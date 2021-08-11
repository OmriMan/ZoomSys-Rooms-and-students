/*
 * ZoomSys.cpp
 *
 *  Created on: Jan 4, 2021
 *      Author: ise
 */

#include "ZoomSys.h"
#include <algorithm>
#include "Error.h"

ZoomSys::ZoomSys()
{
	room_last_index=0;

	// TODO Auto-generated constructor stub
}


ZoomSys::ZoomSys(string filename)
{
	string line;
	ifstream myfile(filename);//open the file
	if (!(myfile.is_open()))//check that we really open it
	{
		throw "file open error or something like that";
		return;
	}
	room_last_index=0;
	//var that will help us to insert the students from the file to our Sys
	string first;
	string last;
	int id;
	int avg;
	string type;
	//start insert the student, one by one. step by step,pass,pass it's a come :)
	while(getline(myfile,line))
	{
/*		input format:
		1.FirstName LastName ID AVG type
		2.FirstName LastName ID AVG type
		.
		.
		.
		n.FirstName LastName ID AVG type*/
		istringstream iss(line);//one line of words seperated by whitespace(\t) from the input file
		iss>>first;//first word in line and go so...
		iss>>last;
		//s_id is string and our student id is int so we need to make Trick
		string s_id;
		iss>>s_id;
		stringstream geek(s_id);
		geek>>id;
		string s_avg;
		iss>>s_avg;
		stringstream geek1(s_avg);
		geek1>>avg;
		iss>>type;
		//check what kind of student
		if (type.compare("W")==0)
		{
			S_Worker* to_add;
			to_add=new S_Worker(first,last,id,avg);
			this->students.push_back(to_add);
		}
		else if (type.compare("L")==0)
		{
			S_Lazy* to_add;
			to_add =new S_Lazy(first,last,id,avg);
			this->students.push_back(to_add);
		}
		else //(type.compare("R")==0)
		{
			S_Responsible* to_add;
			to_add=new S_Responsible(first,last,id,avg);
			this->students.push_back(to_add);//students.push_back(&to_add);
			//to_add->~Student();
			//std::for_each(students.begin(), students.end(), delete_pointed_to<Student>);

		}

	}
	myfile.close();
	return;

}


ZoomSys::~ZoomSys()
{
	int i = 0;
	while(i < (int)students.size() )
	{
		delete students[i];
		students[i] = nullptr;
		i++;
	}
	students.clear();
	students.shrink_to_fit();
	i =0 ;
	while(i<(int)rooms.size())
	{
		delete rooms[i];
		rooms[i]=nullptr;
		i++;
	}
	rooms.clear();
	rooms.shrink_to_fit();
}


void ZoomSys::S_type(string t)
{
	if (t.compare("W")!= 0 && t.compare("L")!= 0 && t.compare("R")!= 0)
		throw Invalid_details();
}

void ZoomSys::is_Stu_exist(int id)
{
		for (int i = 0 ; i <(int)students.size(); i++)
		{
			if ((students[i]->GetID()) == id)
			{
				throw Invalid_details();
			}
		}
}

void ZoomSys::is_Stu_not_exist(int id)
{
		for (int i = 0 ; i <(int)students.size(); i++)
		{
			if ((students[i]->GetID()) == id)
			{
				return;
			}
		}
		throw Invalid_details();

}

int ZoomSys::Find_stu_postion(int id)
{
	int j = -1;
	for (int i = 0 ; i <(int)students.size(); i++)
	{
		j++;
		if ((students[i]->GetID()) == id)
		{
			//j++;
			break;
			//return i;
		}
	}
	return j;
}

void ZoomSys::is_room_exist(int id)
{
	if (id == -1)
		return;
	for (int i = 0 ; i <(int)rooms.size(); i++)
	{
		if ((rooms[i]->GetID()) == id)
		{
			return;
		}
	}
	throw id_exception();

}

void ZoomSys::is_room_exist1(int id)
{

	for (int i = 0 ; i <(int)rooms.size(); i++)
	{
		if ((rooms[i]->GetID()) == id)
		{
			return;
		}
	}
	throw Invalid_details();

}

int ZoomSys::Find_room_postion(int id)
{
	int j = -1;
	for (int i = 0 ; i <(int)rooms.size(); i++)
	{
		j++;
		if ((rooms[i]->GetID()) == id)
		{
			break;
			return i;
		}
	}
	return j;
}

void ZoomSys::is_1_or_2(char c)
{
	if((c != '1') && (c != '2'))
	{
		throw Invalid_details();
	}
	return;
}




void ZoomSys::is_Room_exist_2(int id)
{//if Room not exist throw error
	for (int i=0;i<(int)rooms.size();i++)//casting (int) to prevent warning
	{
		if(rooms[i] == nullptr)
		{
			continue;
		}
		if (rooms[i]->GetID()==id)
			return;
	}
	throw id_exception();
}




Room* ZoomSys::findRoom(int id)
{//use only if you sure that this room exist in the system!!!
	int i;
	for (i=0;i<(int)rooms.size();i++)//casting (int) to prevent warning
	{
		if(rooms[i]->GetID()==id)
		{
			break;
			//return students[i];
		}
	}
	return rooms[i];
}


void ZoomSys::is_Stu_exist_2(int id)
{//if student not exist throw error
	for (int i=0;i<(int)students.size();i++)//casting (int) to prevent warning
	{
		if (students[i]->GetID()==id)
			return;
	}
	throw id_exception();
}



Student* ZoomSys::findStu(int id)
{//use only if you sure that this student exist in the system!!!
	int i;
	for (i=0;i<(int)students.size();i++)//casting (int) to prevent warning
	{
		if(students[i]->GetID()==id)
		{
			break;
		}
	}
	return students[i];
}

void ZoomSys::delete_left_son(Room* left)
{
	for(int i= 0 ; i <left->GetRoomSize() ; i++)
	{
		left->Get_Students()[0]->Cry();
		left->Get_Students()[0]->MoveRoom(left->Get_abba());
		left->remove(left->Get_Students()[0]);
	}
	left->~Room();
	return;
}

void ZoomSys::delete_right_son(Room* right)
{
	for(int i= 0 ; i <right->GetRoomSize() ; i++)
	{
		right->Get_Students()[0]->Cry();
		right->Get_Students()[0]->MoveRoom(right->Get_abba());
		right->remove(right->Get_Students()[0]);
	}
	right->~Room();
	return;
}

void ZoomSys::delete_me(Room* room)
{
	for(int i= 0 ; i <room->GetRoomSize() ; i++)
	{
		room->Get_Students()[0]->Cry();
		room->Get_Students()[0]->MoveRoom(room->Get_abba());
		room->remove(room->Get_Students()[0]);
	}
	room->~Room();
	return;
}

/*bool ZoomSys::room_is_here(int r_id)
{
	for (int i = 0 ; i <(int)rooms.size(); i++)
	{
		if ((rooms[i]->GetID()) == r_id)
		{
			return true;
		}
	}
	return false;

}*/


void ZoomSys::addStudent()
{
	cout<< "---Create Student---"<< endl;
	cout<< "First name:" << endl;
	string first;
	cin>> first;
	string last;
	cout<< "Last name:" << endl;
	cin>> last;
	cout << "ID:" << endl;
	int id;
	cin >> id;
	cout << "avg:" << endl;
	int avg;
	cin >> avg;
	cout << "Worker(W) or Lazy(L) or Responsible(R) Student?" << endl;
	string type;
	cin >> type;
	try{
		S_type(type);
		is_Stu_exist(id);
	}
	catch(exception& e)
	{
		cout << e.what()<< endl;
		return;
	}
	if (type.compare("W") == 0)
	{
		try{
			S_Worker to_add = S_Worker(first , last ,id ,avg);
		}
		catch(exception& e)
		{
			cout << e.what()<< endl;
			return;
		}
		S_Worker* to_add;
		to_add = new S_Worker(first, last,id,avg);
		this->students.push_back(to_add);
	}
	else if(type.compare("L")==0)
	{
		try{
			S_Lazy to_add = S_Lazy(first , last ,id ,avg);
		}
		catch(exception& e)
		{
			cout << e.what()<< endl;
			return;
		}
		S_Lazy* to_add;
		to_add = new S_Lazy(first, last,id,avg);
		this->students.push_back(to_add);
	}
	else if(type.compare("R")==0)
	{
		try{
			S_Responsible to_add = S_Responsible(first , last ,id ,avg);
		}
		catch(exception& e)
		{
			cout << e.what()<< endl;
			return;
		}
		S_Responsible* to_add;
		to_add = new S_Responsible(first, last,id,avg);
		this->students.push_back(to_add);
	}

	return;

}



void ZoomSys::removeStudent()
{
	//get the info from user
	cout<<"---Remove Student---"<<endl;
	int id;
	cout<<"Enter the id:"<<endl;
	cin>>id;
	//valid checks
	try{
		is_Stu_exist_2(id);
	}
	catch(exception& e)
	{
		cout<<e.what()<<endl;
		return;
	}
	Student* to_remove = findStu(id);
	if(!(to_remove->GetRoomID()==-1))
	{//this student in room
		//need to remove the stu from his room
		Room* r =to_remove->GetStuRoom();
		r->remove(to_remove);
	}
	students.erase(std::remove(students.begin(),students.end(),to_remove),students.end());//delete from the vector
	delete to_remove;
}


/*
void ZoomSys::removeStudent()
{
	cout<< "---Remove Student---"<< endl;
	cout<< "Enter the id:" << endl;
	int id;
	cin>> id;
	try{
		is_Stu_not_exist(id);
	}
	catch(const char* exp)
	{
		cout << "id doesn't exists"<< endl;
		return;
	}
	int i = Find_stu_postion(id);
	this->students.erase(students.begin() + i);

}*/


void ZoomSys::assignStudent()
{
	//get the info from user
	cout<<"---Assign Student---"<<endl;
	int s_id;
	cout<<"Enter student id:"<<endl;
	cin>>s_id;
	int r_id;
	cout<<"Enter room id:"<<endl;
	cin>>r_id;
	try{
		is_Stu_exist_2(s_id);

	}
	catch(exception& e)
	{
		cout<<e.what()<<endl;
		return;
	}
	//if the room that we want to assign its -1-just remove student from his curr room
	Student* s=findStu(s_id);
	if (r_id==-1)
	{
	//remove student from his curr room if its not -1
		if(s->GetRoomID()!=-1)
		{
			Room* r_to_remove_this_stu =s->GetStuRoom();
			r_to_remove_this_stu->remove(s);
		}
		return;
	}
	else
	{
	//we need to remove s from his curr room and add s to this room(if this room exists in our system)
		try{//check if this room exists in our system
			is_Room_exist_2(r_id);

		}
		catch(exception& e)
		{
			cout<<e.what()<<endl;
			return;
		}

	}
	if(s->GetRoomID()!=-1)
	{//remove s from his curr room
		Room* r_to_remove_this_stu =s->GetStuRoom();
		r_to_remove_this_stu->remove(s);
	}
	//add s to this room
	Room* r=findRoom(r_id);
	r->Add(s);
}


void ZoomSys::addRoom()
{
	Room* to_add =new Room(this->room_last_index);
	this->room_last_index++;
	this->rooms.push_back(to_add);
	cout << "New room created" << endl;
}

void ZoomSys::splitRoom()
{
	cout << "---Split Room---" << endl;
	cout << "Room id:" << endl;
	int r_id;
	cin>> r_id;
	try{
		is_Room_exist_2(r_id);
	}
	catch(exception& e)
	{
		cout << e.what()<< endl;
		return;
	}
	int j = Find_room_postion(r_id);
	try{

		this->rooms[j]->is_splited();
	}
	catch(exception& e)
	{
		cout << e.what()<< endl;
		return;
	}
	char menuOption;

		cout<< "1.Character split" << endl;
		cout<< "2.Size split" << endl;
		cin >> menuOption;
		try
		{
			is_room_exist(r_id);
			is_1_or_2(menuOption);
		}
		catch(exception& e)
		{
			cout << e.what()<< endl;
			return;
		}
		switch(menuOption)
		{
		case '1':
			this->rooms[j]->CharecterSplit(this->room_last_index, this->room_last_index+1);
			this->rooms[j]->Get_L_Room()->set_abba(this->rooms[j]);
			this->rooms.push_back(this->rooms[j]->Get_L_Room());
			this->rooms[j]->Get_R_Room()->set_abba(this->rooms[j]);
			this->rooms.push_back(this->rooms[j]->Get_R_Room());
			this->room_last_index = this->room_last_index +2;
			break;
		case '2':
			this->rooms[j]->SizeSplit(this->room_last_index, this->room_last_index+1);
			this->rooms[j]->Get_L_Room()->set_abba(this->rooms[j]);
			this->rooms.push_back(this->rooms[j]->Get_L_Room());
			this->rooms[j]->Get_R_Room()->set_abba(this->rooms[j]);
			this->rooms.push_back(this->rooms[j]->Get_R_Room());
			this->room_last_index = this->room_last_index +2;

			break;
		}
}




void ZoomSys::removeRoom()
{
	cout<<"---Remove Room---"<<endl;
	cout << "Enter room id:" << endl;
	int r_id;
	cin>>r_id;
	try{
		is_Room_exist_2(r_id);
	}
	catch(exception& e)
	{
		cout<<e.what()<<endl;
		return;
	}
	Room* r=findRoom(r_id);
	r->deleteRoom();//call to function from Room.cpp
	//now we need to update the rooms vector
	vector<Room*> update;
	for(int i=0;i<(int)rooms.size();i++)
	{
		if(rooms[i]==nullptr)
			continue;
		if(!(rooms[i]->is_cleared()))
		{
			update.push_back(rooms[i]);
		}
		else
		{
			delete rooms[i];
			//rooms[i]->~Room();
			update.push_back(nullptr);
		}
	}
	rooms.clear();
	rooms.shrink_to_fit();
	rooms=update;
	//check that all the students are good and not stoned and stay in deleted room :0
	/*for(int i=0;i<(int)students.size();i++)
	{
		int room_ind = students[i]->GetRoomID();
		if (rooms[room_ind]==nullptr)
		{//stoned student, lets wake him up
			students[i]->SetRId(-1);
			students[i]->SetRoomAsNullptr();
			//students[i]->removeStudentFromRoom() - i think thats also will work
		}
	}*/
}




void ZoomSys::work()
{
	cout << "Enter the room you want to work:" << endl;
	int r_id;
	cin>>r_id;
	try{
		is_Room_exist_2(r_id);
	}
	catch(exception& e)
	{
		cout<<e.what()<<endl;
		return;
	}
	Room* r=findRoom(r_id);
	if(r->GetRoomSize()==0)
		return;
	vector<Student*> v=r->Get_Students();
	for(int i=0;i<(int)v.size();i++)
	{
		v[i]->Work();
	}
	return;

}


void ZoomSys::sendMessage()
{
	int s_id;
	cout<<"Enter the id:"<<endl;
	cin>>s_id;
	//valid check
	try{
		is_Stu_exist_2(s_id);

	}
	catch(exception& e)
	{
		cout<<e.what()<<endl;
		return;
	}
	string msg_to_send;
	cout<<"Enter the message:"<<endl;
	cin>>msg_to_send;
	Student* s= findStu(s_id);
	vector<Student*> v;
	if (s->GetRoomID()==-1)
	{
		v.push_back(s);
		v.pop_back();
	}
	else
	{
		Room* r=s->GetStuRoom();
		v = r->Get_Students();
	}
	try{
		s->SendMsg(v,msg_to_send,s->GetRoomID());
	}
	catch(exception& e)
	{
		cout<<e.what()<<endl;
		//cout<<"this student don't have permission"<<endl;
		return;
	}

}



/*void ZoomSys::sendMessage()
{
	int s_id;
	cout<<"Enter the id:"<<endl;
	cin>>s_id;
	try{
		is_Stu_exist_2(s_id);

	}
	catch(const char* exp)
	{
		cout<<"id doesn't exists"<<endl;
		return;
	}
	string msg_to_send;
	cout<<"Enter the message:"<<endl;
	cin>>msg_to_send;
	Student* s= findStu(s_id);
	Room* r=s->GetStuRoom();
	vector<Student*> v = r->Get_Students();
	try{
		s->SendMsg(v,msg_to_send,r->GetID());
	}
	catch(const char* exp)
	{
		cout<<"this student don't have permission"<<endl;
		return;
	}

}*/




void ZoomSys::printRooms()
{
	for(int i=0;i<(int)rooms.size();i++)
	{
		if(rooms[i] != nullptr)
		{
			cout<<*(rooms[i]);
		}
	}
}



void ZoomSys::printStudents()
{
	cout<<"First name, Last Name, ID, Avg, Room ID"<<endl;
	for(int i=0;i<(int)students.size();i++)
	{
		cout<<*(students[i]);
	}
}


void ZoomSys::printStudentDetails()
{
	int s_id;
	cout<<"Enter student id:"<<endl;
	cin>>s_id;
	try{
		is_Stu_exist_2(s_id);

	}
	catch(exception& e)
	{
		cout<<e.what()<<endl;
		return;
	}
	Student* s = findStu(s_id);
	cout<<*s;
	if ((int)s->GetMsg().size()==0)//if s has 0 msg
		return;
	cout<<"---Messages---"<<endl;
	vector<string> msg = s->GetMsg();
	for(int i=0;i<(int)msg.size();i++)
	{
		cout<<msg[i]<<endl;
	}
	return;
}

void ZoomSys::delete_system()
{
	/*int i = 0;
	while(i < (int)students.size() )
	{
		delete students[i];
		students[i] = nullptr;
		i++;
	}
	students.clear();
	students.shrink_to_fit();
	i =0 ;
	while(i<(int)rooms.size())
	{
		delete rooms[i];
		rooms[i]=nullptr;
		i++;
	}
	rooms.clear();
	rooms.shrink_to_fit();*/

}




