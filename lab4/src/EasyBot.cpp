#include "EasyBot.h"

string EasyBot::makeSecretWord(int wordLength)
{
	string secretWord;
	int i;
	for (i = 0; i < wordLength; ++i)
		secretWord.push_back((rand() % 10) + 48);
	return secretWord;
}