#ifndef _MODEL_
#define _MODEL_

#include "Player.h"
#include <memory>
#include <map>

class Model
{
public:
	int minWordLength = 2, maxWordLength = INT_MAX, wordLength, cows, bulls;
	map<unsigned,shared_ptr<Player>> players;
	string tryWord;
	void makeTurn(Player& player);
	Model() = default;
	Model(int numberOfPlayers);
	bool checkLength();
	bool giveUpCheck();
private:
	void searchForCows(int& wordLengthCp, string& secretWordCp);
	void searchForBulls(int& wordLengthCp, string& secretWordN, string& secretWordCp);
	void countBullsAndCowsNumber(string& secretWordN);
};

#endif
