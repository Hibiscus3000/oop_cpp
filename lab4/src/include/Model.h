#ifndef _MODEL_
#define _MODEL_

#include <string>
#include "ModelException.h"

using namespace std;

class Model
{
	string secretWord, tryWord;
	unsigned wordLength,bulls, cows;

	void setWordLength(unsigned wordLength);
	void setSecretWord(string secretWord);
	void setTryWord(string tryWord);
	void searchForCows(unsigned& wordLengthCp, string& secretWordCp);
	void searchForBulls(unsigned& wordLengthCp, string& secretWordCp);
	void getBullAndCowsNumber();
};

#endif
