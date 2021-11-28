#ifndef _MODEL_
#define _MODEL_

#include "Player.h"

class Model
{
public:
	Player player1, player2;
	string tryWord;
	unsigned wordLength, bulls, cows;

private:
	void searchForCows(unsigned& wordLengthCp, string& secretWordCp);
	void searchForBulls(unsigned& wordLengthCp, string& secretWordN, string& secretWordCp);
	void getBullAndCowsNumber(string& secretWordN);
};

#endif
