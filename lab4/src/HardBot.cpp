#include "HardBot.h"

string HardBot::makeSecretWord(unsigned wordLength)
{
	string secretWord;
	unsigned i;
	for (i = 0; i < wordLength; ++i)
		secretWord.push_back((rand() % 26) + 97);
	return secretWord;
}