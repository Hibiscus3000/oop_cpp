#ifndef _MY_EXCEPTION_
#define _MY_EXCEPTION_

#include <string>
#include <iostream>

using namespace std;

class MyException
{
protected:
	string error;
public:
	MyException() = default;
	MyException(const string & error)
	{
		this->error = error;
	}
	virtual void errorReport() const noexcept
	{
		cerr << error << endl;
	}
	virtual ~MyException()
	{

	}
};

#endif