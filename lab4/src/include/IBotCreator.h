#ifndef _I_BOT_CREATOR_
#define _I_BOT_CREATOR_

#include "Bot.h"

class IBotCreator
{
public:
	virtual Bot* getBot() const = 0;
	virtual ~IBotCreator()
	{

	}
};

#endif