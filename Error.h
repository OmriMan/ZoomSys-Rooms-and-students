/*
 * Error.h
 *
 *  Created on: Jan 6, 2021
 *      Author: ise
 */

#ifndef ERROR_H_
#define ERROR_H_
#include <iostream>
#include <string>
#include <exception>

using namespace std;


class Error
{
public:
	Error(){}
};


class id_exception : public exception
{
public:
	virtual const char* what() const throw()
		{
			return "id doesn't exists";
		}
};

class Student_permissions : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "this student don't have permission";
	}
};

class Split_before : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "This room was split before";
	}
};

class Invalid_details : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Please enter valid details";
	}
};



#endif /* ERROR_H_ */
