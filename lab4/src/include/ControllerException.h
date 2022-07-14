#ifndef _CONTROLLER_EXCEPTION_
#define _CONTROLLER_EXCEPTION_

#include "MyException.h"

class InappropriateLength : public MyException
{
	unsigned wordLength, minWordLength, maxWordLength;
public:
	InappropriateLength(unsigned wordLength, unsigned minWordLength, unsigned maxWordLength)
	{
		this->wordLength = wordLength;
		this->minWordLength = minWordLength;
		this->maxWordLength = maxWordLength;
	}
	void errorReport() const noexcept
	{
		cerr << "Word length should vary from " << minWordLength << " to " << maxWordLength << endl;
		cerr << "Word length given: " << wordLength << endl;
	}
};

#endif