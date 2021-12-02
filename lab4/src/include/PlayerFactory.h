#ifndef _PLAYER_FACTORY_
#define _PLAYER_FACTORY_

#include "FactoryException.h"
#include "IPlayerCreator.h"
#include <map>

using namespace std;

class PlayerFactory
{
	map<string, IPlayerCreator*> creators;
	PlayerFactory() = default;

public:
	static PlayerFactory& getInstance();
	void registerCreator(const string& playerType, IPlayerCreator* creator);
	Player* getPlayer(string playerType) const;
};

#endif
