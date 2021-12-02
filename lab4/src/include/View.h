#ifndef _VIEW_
#define _VIEW_

#include <iostream>
#include <fstream>

using namespace std;

class View
{
public:
	string selectGameMode();
	unsigned selectWordLength();
	string selectDifficulty();
	string selectPlayerName(char playerNumber);
	string selectSecretWord(const string& playerName, unsigned wordLength);
	string makeTurn(const string& playerName, unsigned wordLength);
	void showTurnResults(unsigned cows, unsigned bulls);
	void showVictoryMessage(const string& playerName, unsigned turnNumber);
};

#endif 
