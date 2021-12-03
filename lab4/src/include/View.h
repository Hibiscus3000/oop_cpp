#ifndef _VIEW_
#define _VIEW_

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class View
{
	HANDLE hConsole;
public:
	View();
	void setColorWhite();
	void setColor(unsigned color);
	bool prevMistake = false;
	unsigned selectNumberOfPlayers();
	unsigned selectWordLength(unsigned minWordLength, unsigned maxWordLength);
	string selectDifficulty();
	string selectPlayerName(unsigned playerNumber);
	string selectSecretWord(const string& fromPlayerName, unsigned forPlayerNumber, const string& forPlayerName, unsigned fromPlayerNumber, unsigned wordLength);
	string makeTurn(const string& playerName, unsigned playerNumber, unsigned wordLength);
	void showTurnResults(unsigned cows, unsigned bulls);
	void showVictoryMessage(const string& playerName,unsigned playerNumber, unsigned turnNumber);
	string playAgain();
};

#endif 
