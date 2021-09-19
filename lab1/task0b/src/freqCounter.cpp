#include "freqCounter.h"

string lettersAndNumerals = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

string findNextWord(string* s)
{
	if (!s)
		return "";
	int pos = s->find_first_not_of(lettersAndNumerals);
	if (pos == string::npos)
		pos = (int)(s->size());
	string word = s->substr(0, pos);
	s->erase(0, pos);
	pos = s->find_first_of(lettersAndNumerals);
	if (pos == string::npos)
	{
		s->clear();
		return word;
	}
	s->erase(0, pos);
	return word;
}

void addNewWordToMap(map <string, int>* freqCounter, string word, int* numOfDifWords)
{
	if (!numOfDifWords)
		return;
	(*numOfDifWords)++;
	freqCounter->emplace(word, 1);
}

map<string, int>* freqCount(ifstream& in, ofstream& out, int* numOfWords, int* numOfDifWords)
{
	if ((!numOfWords) || (!numOfDifWords))
		return NULL;
	map<string, int>* freqCounter = new map<string, int>;
	map <string, int>::iterator currentWord;
	string s;
	while (!in.eof())
	{
		getline(in, s);
		while (!s.empty())
		{
			string word = findNextWord(&s);
			currentWord = freqCounter->find(word);
			if (currentWord == freqCounter->end())
				addNewWordToMap(freqCounter, word, numOfDifWords);
			else
				(*freqCounter)[word]++;
			(*numOfWords)++;
		}
	}
	return freqCounter;
}