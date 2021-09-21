#ifndef _WORLD_COUNT_
#define _WORLD_COUNT_

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class WordCount
{
private:

	map<string, int> m_unsortedWords;
	int m_count;

	string findNextWord(string* s);
	void addNewWordToMap(string word);
	void sortWords(multimap<int, string>& wordCounter);
	void displaySortedWords(multimap<int, string>& wordCounter, ofstream& out);

public:
	void readFile(ifstream& in);
	void writeFile(ofstream& out);

};

#endif