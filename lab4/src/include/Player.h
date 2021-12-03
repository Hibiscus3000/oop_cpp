#ifndef _PLAYER_
#define _PLAYER_

#include <string>

using namespace std;

class Player
{
public:
	string name, secretWord;
	bool victory = false;
	bool loss = false;
	int turnNumber = 0;
	int number;
};

#endif
