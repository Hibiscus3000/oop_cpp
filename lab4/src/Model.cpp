#include "Model.h"

Model::Model(int numberOfPlayers)
{
	int i;
	for (i = 0; i < numberOfPlayers; ++i)
	{
		shared_ptr<Player> player(new Player);
		player->number = i + 1;
		players[i] = player; 
	}
}

bool Model::checkLength()
{
	if ((wordLength < minWordLength) || (wordLength > maxWordLength))
		return false;
	return true;
}

void Model::makeTurn(Player& player)
{
	if (giveUpCheck())
	{
		player.loss = true;
		return;
	}
	++(player.turnNumber);
	countBullsAndCowsNumber(player.secretWord);
	if (this->bulls == wordLength)
		player.victory= true;
}

bool Model::giveUpCheck()
{
	if (!tryWord.compare("giveup"))
		return true;
	return false;
}

void Model::searchForBulls(int& wordLengthCp, string& secretWord, string& secretWordCp)
{
	bulls = 0;
	int i;
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

void Model::searchForCows(int& wordLengthCp, string& secretWordCp)
{
	cows = 0;
	int i, j, lengthWithoutBulls = wordLengthCp;
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
	int wordLengthCp = wordLength;
	this->searchForBulls(wordLengthCp, secretWord, secretWordCp);
	this->searchForCows(wordLengthCp, secretWordCp);
}