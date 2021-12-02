#include "Model.h"

void Model::makeTurn(string tryWord, Player& player)
{
	++(player.turnNumber);
	this->tryWord = tryWord;
	countBullsAndCowsNumber(player.secretWord);
	if (this->bulls == wordLength)
		player.victory = true;
}

void Model::searchForBulls(unsigned& wordLengthCp, string& secretWord, string& secretWordCp)
{
	bulls = 0;
	unsigned i;
	string tryWordCp = tryWord;
	for (i = 0; i < wordLength; ++i)
		if (secretWord[i] == tryWord[i])
		{
			tryWordCp.erase(i-bulls, 1);
			secretWordCp.erase(i-bulls, 1);
			++bulls;
		}
	wordLengthCp -= bulls;
	tryWord = tryWordCp;
}

void Model::searchForCows(unsigned& wordLengthCp, string& secretWordCp)
{
	cows = 0;
	unsigned i, j, lengthWithoutBulls = wordLengthCp;
	for (i = 0; i < lengthWithoutBulls; ++i)
		for (j = 0; j < wordLengthCp; ++j)
			if (secretWordCp[j] == tryWord[i])
			{
				++cows;
				--wordLengthCp;
				secretWordCp.erase(j, 1);
				break;
			}
}

void Model::countBullsAndCowsNumber(string& secretWord)
{
	string secretWordCp = secretWord;
	unsigned wordLengthCp = wordLength;
	this->searchForBulls(wordLengthCp, secretWord, secretWordCp);
	this->searchForCows(wordLengthCp, secretWordCp);
}