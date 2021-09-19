#ifndef _WORD_LIST_
#define _WORD_LIST_

#include "freqCounter.h"

void fillWordCount(map<string, int>* freqCounter, multimap<int, string>* wordCounter);
multimap <int, string>* wordCountCreation(map<string, int>* freqCounter);
void wordCountList(ofstream& out, int numOfWords, multimap<int, string>* wordCounter);

#endif