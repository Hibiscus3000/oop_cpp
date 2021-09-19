#include "wordList.h"

void fillWordCount(map<string, int>* freqCounter, multimap<int, string>* wordCounter)
{
	if ((!freqCounter) || (!wordCounter))
		return;
	map<string, int>::iterator currentWord;
	currentWord = freqCounter->begin();
	while (currentWord != freqCounter->end())
	{
		wordCounter->emplace(currentWord->second, currentWord->first);
		currentWord++;
	}
}

multimap <int, string>* wordCountCreation(map<string, int>* freqCounter)
{
	if (!freqCounter)
		return NULL;
	multimap<int, string>* wordCounter = new multimap<int, string>;
	fillWordCount(freqCounter, wordCounter);
	return wordCounter;
}

void wordCountList(ofstream& out, int numOfWords, multimap<int, string>* wordCounter)
{
	if (!wordCounter)
		return;
	multimap<int, string>::iterator currentWord;
	currentWord = wordCounter->end();
	int proc;
	while (currentWord != wordCounter->begin())
	{
		currentWord--;
		proc = (int)((double)currentWord->first / numOfWords * 100);
		out << "1. " << currentWord->second << " 2. " << currentWord->first << " 3. " << proc << "%" << endl;
	}
}