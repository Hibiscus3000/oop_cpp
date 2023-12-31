#include "MediumBot.h"

string MediumBot::makeSecretWord(int wordLength)
{
	char cwordLength[MAX_WORD_LENGTH_LENGTH];
	itoa(wordLength, cwordLength, 10);
	string word,fileName = "words.txt";
	fileName.insert(5, cwordLength);
	ifstream words(fileName);
	if (!words)
		throw WrongFile(fileName);
	int i,wordNumber = rand() % 20;
	for (i = 0; i < wordNumber; ++i)
		getline(words, word);
	if (word.length() != wordLength)
		throw WrongWordLength(wordLength, word.length());
	return word;
}