#ifndef _UTIL_
#define _UTIL_

#include "wordList.h"
#include <iostream>

namespace util
{
	char numOfArgCheck(int n);
	void cleanUp(ifstream& in, ofstream& out, map<string, int>* freqCounter, multimap<int, string>* wordCounter);
}
#endif