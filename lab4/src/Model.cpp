#include "Model.h"

void Model::searchForBulls(unsigned& wordLengthCp, string& secretWordN, string& secretWordCp)
{
	bulls = 0;
	unsigned i;
	string tryWordCp = tryWord;
	for (i = 0; i < wordLength; ++i)
		if (secretWordN[i] == tryWord[i])
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

void Model::getBullAndCowsNumber(string& secretWordN)
{
	string secretWordCp = secretWordN;
	unsigned wordLengthCp = wordLength;
	this->searchForBulls(wordLengthCp, secretWordN, secretWordCp);
	this->searchForCows(wordLengthCp, secretWordCp);
}