#ifndef _MY_EXCEPTION_
#define _MY_EXCEPTION_

#include "WorkFlowParser.h"
#include <iostream>

class MyException : public exception
{
	string str;

public:
	MyException(const char* msg) : exception(msg)
	{

	}
	MyException(const char* msg, string str) : exception(msg)
	{
		this->str = str;
	}
	void showLine();
};

#endif