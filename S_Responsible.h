/*
 * S_Responsible.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */

#ifndef S_RESPONSIBLE_H_
#define S_RESPONSIBLE_H_

#include "Student.h"


class S_Responsible :
		public Student
{
public:
	S_Responsible();
	S_Responsible(string first , string last , int id , int avg):
		Student(first , last, id , avg){};
	virtual void Cry(){return ;}; // pure virtual for L student
	virtual bool LazyToLazyRoom(Room* to_room){return false;};
	//virtual void SendMsg(); // pure virtual for R student
	virtual void Work(){return ;}; // pure virtual for W student
	virtual bool WorkerToWorkerRoom(Room* to_room){return false;};
	virtual void SendMsg(vector<Student*> v,string msg,int room_id);

	//virtual void MoveRoom();
	virtual ~S_Responsible(){};
};
#endif /* S_RESPONSIBLE_H_ */
