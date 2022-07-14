#ifndef _MEDIUM_BOT_
#define _MEDIUM_BOT_
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define NUMBER_OF_WORDS 20
#define MAX_WORD_LENGTH_LENGTH 10

#include "Bot.h"
#include "MediumBotException.h"
#include <fstream>
#include <stdlib.h>

class MediumBot : public Bot
{
public:
	string makeSecretWord(int wordLength);
};

#endif