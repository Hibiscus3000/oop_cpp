#include "MyException.h"

void MyException::showLine()
{
	cerr << "inappropriate line: " << str << endl;
}