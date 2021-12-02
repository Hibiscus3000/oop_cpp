#ifndef _CONTROLLER_
#define _CONTROLLER_

#include "Model.h"
#include "View.h"
#include "ControllerException.h"
#include "BotFactory.h"
#include "Human.h"

class Controller
{
	View view;
	Model model;
	void setWordLength();
	void setSecretWord(const string& fromPlayerName, Player& forPlayer);
	void setTryWord(const string& playerName);
	void pvc();
	void pvp(unsigned numberOfPlayers);
	void preGameSettings(unsigned numberOfPlayers);
public:
	void play();
};

#endif
