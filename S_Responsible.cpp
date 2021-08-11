/*
 * S_Responsible.cpp
 *
 *  Created on: Jan 2, 2021
 *      Author: ise
 */


#include "S_Responsible.h"

void S_Responsible::SendMsg(vector<Student*> v,string msg,int room_id)
{
	if (room_id == -1)
		return;
	string fullname = m_first_name + " " +m_last_name + ":" +msg;
	for (int i = 0 ; i < (int)v.size() ; i++)
	{
		if (v[i]->GetRoomID() == room_id)
		{
			v[i]->Get_Msg_Str(fullname);
		}
	}
	return;
}
