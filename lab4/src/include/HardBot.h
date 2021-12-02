#ifndef _HARD_BOT_
#define _HARD_BOT_

#include "Bot.h"

class HardBot : public Bot
{
public:
	string makeSecretWord(unsigned wordLength);
};

#endif