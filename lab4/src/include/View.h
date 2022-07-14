#ifndef _VIEW_
#define _VIEW_

#include <iostream>
#include <fstream>
#include <windows.h>
#include "MyException.h"

using namespace std;

class View
{
	HANDLE hConsole;
public:
	View();
	void setColorWhite();
	void setColor(int color);
	bool prevMistake = false;
	int selectNumberOfPlayers();
	int selectWordLength(int minWordLength, int maxWordLength);
	string selectDifficulty();
	string selectPlayerName(int playerNumber);
	string selectSecretWord(const string& fromPlayerName, int forPlayerNumber, const string& forPlayerName, int fromPlayerNumber, int wordLength);
	string makeTurn(const string& playerName, int playerNumber, int wordLength);
	void showTurnResults(int cows, int bulls);
	void showVictoryMessage(const string& playerName,int playerNumber, int turnNumber);
	void showLossMessage(const string& playerName, int playerNumber, const string& secretWord);
	string playAgain();
	void qCheck(const string& str);
};

#endif 
