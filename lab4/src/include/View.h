#ifndef _VIEW_
#define _VIEW_

#include <iostream>
#include <fstream>

using namespace std;

class View
{
public:
	unsigned selectNumberOfPlayers();
	unsigned selectWordLength();
	string selectDifficulty();
	string selectPlayerName(unsigned playerNumber);
	string selectSecretWord(const string& fromPlayerName,const string& forPlayerName, unsigned wordLength);
	string makeTurn(const string& playerName, unsigned wordLength);
	void showTurnResults(unsigned cows, unsigned bulls);
	void showVictoryMessage(const string& playerName, unsigned turnNumber);
};

#endif 
