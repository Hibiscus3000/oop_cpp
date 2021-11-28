#ifndef _CONTROLLER_EXCEPTION_
#define _CONTROLLER_EXCEPTION_

#include "MyException.h"

class ControllerException : public MyException
{
protected:
	string error;
	string unrecognizedGameSettings;
	string wordType;
	string wrongWord;
	unsigned wordLength;
};

class inappropriateWord: public ControllerException
{
public:
	inappropriateWord(string wordType, string wrongWord, unsigned wordLength)
	{
		this->wordLength = wordLength;
		this->wordType = wordType;
		this->wrongWord = wrongWord;
	}
	void errorReport() const noexcept
	{
		cerr << "Wrong word length in given " << wordType << ": " << wrongWord << "\nWord length expected:" << wordLength << endl;
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
		cerr << "Word length shouldn't be equal to the given number: " << wordLength << endl;
	}
};

class UnrecognizedGameSettings : public ControllerException
{
public:
	UnrecognizedGameSettings(string error, string unrecognizedGameSettings)
	{
		this->error = error;
		this->unrecognizedGameSettings = unrecognizedGameSettings;
	}
	void errorReport() const noexcept
	{
		cerr << error << ' ' << unrecognizedGameSettings << endl;
	}
};

#endif