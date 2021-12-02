#ifndef _PLAYER_CREATOR_
#define _PLAYER_CREATOR_

#include "IPlayerCreator.h"
#include "PlayerFactory.h"

template<typename T>
class PlayerCreator : public IPlayerCreator
{
public:
	PlayerCreator(const string& playerType)
	{
		PlayerFactory::getInstance().registerCreator(playerType, this);
	}
	Player* getPlayer() const
	{
		return new T;
	}
};

#endif