#pragma once

#include <iostream>

class MyException : public exception
{
protected:
	int column, line;
public:
	MyException(int column, int line) : column(column), line(line) {}
	virtual ~MyException() = default;
	virtual void errorReport() = 0;
};

class NoExpectedData : public MyException
{
	string ExpectedType;
public:
	NoExpectedData(int column, int line, string ExpectedType) : 
		MyException(column,line),ExpectedType(ExpectedType)	{}
	void errorReport()
	{
		cerr << "In line " << line << ", column " << column 
			<< " no data appeared, data type expected: " << ExpectedType << '!' << endl;
	}
};

class ExtraData: public MyException
{
	string extraData;
public:
	ExtraData(int column, int line,string extraData) :
		MyException(column,line), extraData(extraData) {}
	void errorReport()
	{
		cerr << "In line " << line << ", column " << column 
			<< " no data expected, but " << extraData << " appeared!" << endl;
	}
};
