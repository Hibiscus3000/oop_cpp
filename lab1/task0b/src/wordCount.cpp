#include "wordCount.h"

string lettersAndNumerals = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

void WordCount::readFile(ifstream& in)
{
	map <string, int>::iterator currentWord;
	string s, word;
	while (!in.eof())
	{
		getline(in, s);
		while (!s.empty())
		{
			word = findNextWord(&s);
			currentWord = m_unsortedWords.find(word);
			if (currentWord == m_unsortedWords.end())
				addNewWordToMap(word);
			else
				m_unsortedWords[word]++;
			m_count++;
		}
	}
}

string WordCount::findNextWord(string* s)
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

void WordCount::addNewWordToMap(string word)
{
	m_unsortedWords.emplace(word, 1);
}

void WordCount::writeFile(ofstream& out)
{
	multimap<int, string> sortedWords;
	sortWords(sortedWords);
	displaySortedWords(sortedWords, out);
}

void WordCount::sortWords(multimap<int,string>& sortedWords)
{
	map<string, int>::iterator currentWord = m_unsortedWords.begin();
	while (currentWord != m_unsortedWords.end())
	{
		sortedWords.emplace(currentWord->second, currentWord->first);
		currentWord++;
	}
}

void WordCount::displaySortedWords(multimap<int,string>& sortedWords, ofstream& out)
{
	multimap<int, string>::iterator currentWord = sortedWords.end();
	int proc;
	while (currentWord != sortedWords.begin())
	{
		currentWord--;
		proc = (int)((double)currentWord->first / m_count * 100);
		out << "1. " << currentWord->second << " 2. " << currentWord->first << " 3. " << proc << "%,";
	}
}