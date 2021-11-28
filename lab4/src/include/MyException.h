#ifndef _MY_EXCEPTION_
#define _MY_EXCEPTION_

#include <string>
#include <iostream>

using namespace std;

class MyException
{
public:
	virtual void errorReport() const noexcept = 0;
	virtual ~MyException()
	{

	}
};

#endif