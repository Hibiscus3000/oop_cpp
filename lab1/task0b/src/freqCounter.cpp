#include "freqCounter.h"

string lettersAndNumerals = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

string findNextWord(string* s)
{
	int pos = s->find_first_not_of(lettersAndNumerals);
	if (pos == -1)
		pos = (int)(s->size());
	string word = s->substr(0, pos);
	s->erase(0, pos + 1);
	return word;
}

void addNewWordToMap(map <string, int>* freqCounter, string word)
{
	freqCounter->emplace(word, 1);
}

map<string, int>* freqCount(ifstream& in, ofstream& out)
{
	map<string, int>* freqCounter = new map<string, int>;
	map <string, int>::iterator currentWord;
	string s;
	while (!in.eof())
	{
		getline(in, s);
		string word = findNextWord(&s);
		currentWord = freqCounter->find(word);
		if (currentWord == freqCounter->cend())
			addNewWordToMap(freqCounter, word);
		else
			(*freqCounter)[word]++;
	}
	return freqCounter;
}
