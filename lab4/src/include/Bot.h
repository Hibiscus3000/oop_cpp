#ifndef _BOT_
#define _BOT_

#include <string>

using namespace std;

class Bot
{
public:
	virtual string makeSecretWord(int wordLength) = 0;
};

#endif
