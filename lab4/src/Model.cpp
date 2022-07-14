#include "Model.h"

Model::Model(int numberOfPlayers) : numberOfPlayers(numberOfPlayers)
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

void Model::countTurnResults(int playerNumber)
{
	checkPlayerNumber(playerNumber);
	++(players[playerNumber]->turnNumber);
	countBullsAndCowsNumber(players[playerNumber]->secretWord);
	if (this->bulls == wordLength)
		players[playerNumber]->victory= true;
}

bool Model::giveUpCheck(int playerNumber, string Word)
{
	checkPlayerNumber(playerNumber);
	if (Word.compare("giveup"))
		return false;
	players[playerNumber]->loss = true;
	return true;
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

void Model::checkPlayerNumber(int playerNumber)
{
	if ((playerNumber < 0) || (playerNumber >= numberOfPlayers))
		throw ModelException(numberOfPlayers, playerNumber);
}

int Model::getCows()
{
	return cows;
}

int Model::getBulls()
{
	return bulls;
}

int Model::getWordLength()
{
	return wordLength;
}

int Model::getMinWordLength()
{
	return minWordLength;
}

int Model::getMaxWordLength()
{
	return maxWordLength;
}

string Model::getTryWord()
{
	return tryWord;
}

string Model::getSecretWord(int playerNumber)
{
	checkPlayerNumber(playerNumber);
	return players[playerNumber]->secretWord;
}

string Model::getPlayerName(int playerNumber)
{
	checkPlayerNumber(playerNumber);
	return players[playerNumber]->name;
}

int Model::getPlayerTurnNumber(int playerNumber)
{
	checkPlayerNumber(playerNumber);
	return players[playerNumber]->turnNumber;
}

bool Model::getPlayerVictory(int playerNumber)
{
	checkPlayerNumber(playerNumber);
	return players[playerNumber]->victory;
}

bool Model::getPlayerLoss(int playerNumber)
{
	checkPlayerNumber(playerNumber);
	return players[playerNumber]->loss;
}

void Model::setPlayerName(int playerNumber, string playerName)
{
	checkPlayerNumber(playerNumber);
	players[playerNumber]->name = playerName;
}

void Model::setMinWordLength(int minWordLength)
{
	this->minWordLength = minWordLength;
}

void Model::setMaxWordLength(int maxWordLength)
{
	this->maxWordLength = maxWordLength;
}

bool Model::setWordLength(int wordLength)
{
	if ((wordLength < minWordLength) || (wordLength > maxWordLength))
		return false;
	this->wordLength = wordLength;
	return true;
}

bool Model::setTryWord(int playerNumber,string tryWord)
{
	checkPlayerNumber(playerNumber);
	if (giveUpCheck(playerNumber, tryWord))
	{
		players[playerNumber]->loss = true;
		return true;
	}
	if (wordLength != tryWord.length())
		return false;
	this->tryWord = tryWord;
	return true;
}

bool Model::setSecretWord(int playerNumber, string secretWord)
{
	checkPlayerNumber(playerNumber);
	if (wordLength != secretWord.length())
		return false;
	players[playerNumber]->secretWord = secretWord;
	return true;
}