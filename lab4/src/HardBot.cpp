#include "HardBot.h"

string HardBot::makeSecretWord(int wordLength)
{
	string secretWord;
	int i;
	for (i = 0; i < wordLength; ++i)
		secretWord.push_back((rand() % 26) + 97);
	return secretWord;
}