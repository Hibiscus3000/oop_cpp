#ifndef _BOT_FACTORY_
#define _BOT_FACTORY_

#include "FactoryException.h"
#include "IBotCreator.h"
#include <map>

using namespace std;

class BotFactory
{
	map<string, IBotCreator*> creators;
	BotFactory() = default;

public:
	static BotFactory& getInstance();
	void registerCreator(const string& difficulty, IBotCreator* creator);
	Bot* getBot(const string& difficulty) const;
};

#endif
