#include "Model.h"

void Model::setWordLength(unsigned wordLength)
{
	this->wordLength = wordLength;
}

void Model::setSecretWord(string secretWord)
{
	if (secretWord.length() != wordLength)

	this->secretWord = secretWord;
}

void Model::setTryWord(string tryWord)
{
	if (tryWord.length() != wordLength)

	this->tryWord = tryWord;
}

void Model::searchForBulls(unsigned& wordLengthCp, string& secretWordCp)
{
	bulls = 0;
	unsigned i;
	string tryWordCp = tryWord;
	for (i = 0; i < wordLength; ++i)
		if (secretWord[i] == tryWord[i])
		{
			++bulls;
			tryWordCp.erase(i, 1);
			secretWordCp.erase(i, 1);
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

void Model::getBullAndCowsNumber()
{
	string secretWordCp = secretWord;
	unsigned wordLengthCp = wordLength;
	this->searchForBulls(wordLengthCp, secretWordCp);
	this->searchForCows(wordLengthCp, secretWordCp);
}