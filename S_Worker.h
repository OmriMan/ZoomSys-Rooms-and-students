/*
 * S_Worker.h
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */

#ifndef S_WORKER_H_
#define S_WORKER_H_

#include "Student.h"


class S_Worker :
		public Student
{
public:
	S_Worker();
	S_Worker(string first , string last , int id , int avg):
		Student(first , last, id , avg){};
	virtual void Cry(){return ;}; // pure virtual for L student
	virtual bool LazyToLazyRoom(Room* to_room){return false;};
	//virtual void SendMsg(); // pure virtual for R student
	virtual void Work(); // pure virtual for W student
	virtual bool WorkerToWorkerRoom(Room* to_room);
	virtual void SendMsg(vector<Student*> v,string msg,int room_id);


	//virtual void MoveRoom();
	virtual ~S_Worker(){};
};
#endif /* S_WORKER_H_ */
