#ifndef _MEDIUM_BOT_EXCEPTION_
#define _MEDIUM_BOT_EXCEPTION_

#include "MyException.h"

class MediumBotException : public MyException
{
	string fileName;
public:
	MediumBotException(const string& fileName) : fileName(fileName) 
	{

	}
	void errorReport()
	{
		cerr << "Couldn't open file " << fileName << endl;
	}

};

#endif