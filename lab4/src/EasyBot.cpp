#include "EasyBot.h"

string EasyBot::makeSecretWord(unsigned wordLength)
{
	string secretWord;
	unsigned i;
	for (i = 0; i < wordLength; ++i)
		secretWord.push_back((rand() % 10) + 48);
	return secretWord;
}