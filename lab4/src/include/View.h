#ifndef _VIEW_
#define _VIEW_

#include <iostream>

using namespace std;

class View
{
public:
	string selectGameMode();
	string selectDifficulty();
	string selectPlayerName(char playerNumber);
	string selectSecretWord(string playerName, unsigned wordLength);
};

#endif 
