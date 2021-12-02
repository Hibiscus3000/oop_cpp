#ifndef _BOT_CREATOR_
#define _BOT_CREATOR_

#include "BotCreator.h"
#include "BotFactory.h"

template<typename T>
class BotCreator : public IBotCreator
{
public:
	BotCreator(const string& difficulty)
	{
		BotFactory::getInstance().registerCreator(difficulty, this);
	}
	Player* getPlayer() const
	{
		return new T;
	}
};

#endif