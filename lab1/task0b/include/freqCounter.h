#ifndef _FREQ_COUNTER_
#define _FREQ_COUNTER_

#include <fstream>
#include <map>
#include <string>

using namespace std;

string findNextWord(string* s);
void addNewWordToMap(map <string, int>* freqCounter, string word, int* numOfDifWords);
map<string, int>* freqCount(ifstream& in, ofstream& out, int* numOfWords, int* numOfDifWords);

#endif
