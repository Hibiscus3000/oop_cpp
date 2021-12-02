#ifndef _MODEL_
#define _MODEL_

#include "Player.h"
#include <memory>

class Model
{
public:
	unsigned wordLength, cows, bulls;
	shared_ptr<Player> player1, player2;
	void makeTurn(string tryWord, Player& player);
private:
	string tryWord;
	void searchForCows(unsigned& wordLengthCp, string& secretWordCp);
	void searchForBulls(unsigned& wordLengthCp, string& secretWordN, string& secretWordCp);
	void countBullsAndCowsNumber(string& secretWordN);
};

#endif
