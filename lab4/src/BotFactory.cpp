#include "BotFactory.h"

BotFactory& BotFactory::getInstance()
{
	static BotFactory factory;
	return factory;
}

void BotFactory::registerCreator(const string& difficulty, IBotCreator* creator)
{
	if (creators.find(difficulty) != creators.end())
		throw FactoryException("Multiply creators for given difficulty:", difficulty);
	creators[difficulty] = creator;
}

Bot* BotFactory::getBot(const string& difficulty) const
{
	auto it = creators.find(difficulty);
	if (creators.end() == it)
		throw FactoryException("Unrecognized bot difficulty:", difficulty);
	return it->second->getBot();
}