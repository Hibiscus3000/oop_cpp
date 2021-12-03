#ifndef _MEDIUM_BOT_EXCEPTION_
#define _MEDIUM_BOT_EXCEPTION_

#include "MyException.h"

class WrongFile : public MyException
{
	string fileName;
public:
	WrongFile(const string& fileName) : fileName(fileName)
	{

	}
	void errorReport()
	{
		cerr << "Couldn't open file " << fileName << endl;
	}
};

class WrongWordLength : public MyException
{
	unsigned expWordLength, givenWordLength;
public:
	WrongWordLength(unsigned expWordLength, unsigned givenWordLength) : expWordLength(expWordLength), givenWordLength(givenWordLength)
	{

	}
	void errorReport()
	{
		cerr << "Wrong length of the word given by medium bot!" << endl << "Excepcted length: " << expWordLength << endl;
		cerr << "Length of the given word: " << givenWordLength << endl;
	}
};

#endif