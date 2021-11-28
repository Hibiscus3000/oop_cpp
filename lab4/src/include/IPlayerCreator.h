#ifndef _I_PLAYER_CREATOR_
#define _I_PLAYER_CREATOR_

#include "Player.h"

class IPlayerCreator
{
public:
	virtual Player * getPlayer() const = 0;
	virtual ~IPlayerCreator()
	{

	}
}

#endif