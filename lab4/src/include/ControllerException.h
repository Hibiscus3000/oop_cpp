#ifndef _CONTROLLER_EXCEPTION_
#define _CONTROLLER_EXCEPTION_

#include "MyException.h"

class ControllerException : public MyException
{
protected:
	string error;
	string unrecognizedDifficulty;
	string wordType;
	string wrongWord;
	unsigned wordLength;
};

class inappropriateWord: public ControllerException
{
public:
	inappropriateWord(const string& wordType, const string& wrongWord, unsigned wordLength)
	{
		this->wordLength = wordLength;
		this->wordType = wordType;
		this->wrongWord = wrongWord;
	}
	void errorReport() const noexcept
	{
		cerr << "Wrong word length in given " << wordType << ": " << wrongWord << "\nWord length expected: " << wordLength << endl;
	}
};

class inappropriateLength : public ControllerException
{
public:
	inappropriateLength(unsigned wordLength)
	{
		this->wordLength = wordLength;
	}
	void errorReport() const noexcept
	{
		cerr << "Word length shouldn`t be equal to the given number: " << wordLength << endl;
	}
};

#endif