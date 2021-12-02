#ifndef _MODEL_
#define _MODEL_

#include "Player.h"
#include <memory>
#include <map>

class Model
{
public:
	unsigned wordLength, cows, bulls;
	map<unsigned,shared_ptr<Player>> players;
	string tryWord;
	void makeTurn(Player& player);
	Model() = default;
	Model(unsigned numberOfPlayers);
private:
	void searchForCows(unsigned& wordLengthCp, string& secretWordCp);
	void searchForBulls(unsigned& wordLengthCp, string& secretWordN, string& secretWordCp);
	void countBullsAndCowsNumber(string& secretWordN);
};

#endif
