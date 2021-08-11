/*
 * S_Lazy.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */

#ifndef S_LAZY_H_
#define S_LAZY_H_

#include "Student.h"

class S_Lazy :
		public Student
{
public:
	S_Lazy();
	S_Lazy(string first , string last , int id , int avg):
		Student(first , last, id , avg){};
	virtual void Cry(); // pure virtual for L student
	virtual bool LazyToLazyRoom(Room* to_room);
	//virtual void SendMsg(); // pure virtual for R student
	virtual void Work(){return ;}; // pure virtual for W student
	virtual bool WorkerToWorkerRoom(Room* to_room){return false;};
	virtual void SendMsg(vector<Student*> v,string msg,int room_id);

	//virtual void MoveRoom();
	virtual ~S_Lazy(){};
};

#endif /* S_LAZY_H_ */
