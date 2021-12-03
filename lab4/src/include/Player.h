#ifndef _PLAYER_
#define _PLAYER_

#include <string>

using namespace std;

class Player
{
public:
	string name, secretWord;
	bool victory = false;
	unsigned turnNumber = 0;
	unsigned number;
};

#endif
