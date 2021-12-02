#include "PlayerFactory.h"

PlayerFactory& PlayerFactory::getInstance()
{
	static PlayerFactory factory;
	return factory;
}

void PlayerFactory::registerCreator(const string& playerType, IPlayerCreator* creator)
{
	if (creators.find(playerType) != creators.end())
		throw FactoryException("Multiply creators for given playerType", playerType);
	creators[playerType] = creator;
}

Player* PlayerFactory::getPlayer(string playerType) const
{
	auto it = creators.find(playerType);
	if (creators.end() == it)
		throw FactoryException("Unrecognized player type", playerType);
	return it->second->getPlayer();
}