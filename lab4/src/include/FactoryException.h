#ifndef _FACTORY_EXCEPTION_
#define _FACTORY_EXCEPTION_

#include "MyException.h"

class FactoryException : public MyException
{
	string difficulty;
public:
	FactoryException(const string& error,const string& difficulty) : difficulty(difficulty)
	{
		this->error = error;
	}
	void errorReport() const noexcept
	{
		cout << error << ' ' << difficulty << endl;
	}
};

#endif