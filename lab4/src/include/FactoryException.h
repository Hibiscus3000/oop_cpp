#ifndef _FACTORY_EXCEPTION_
#define _FACTORY_EXCEPTION_

#include "MyException.h"

class FactoryException : public MyException
{
	string errorType;
	string playerType;
public:
	FactoryException(string errorType, string playerType) : errorType(errorType), playerType(playerType)
	{

	}
	void errorReport() const noexcept
	{
		cout << errorType << ' ' << playerType << endl;
	}
};

#endif