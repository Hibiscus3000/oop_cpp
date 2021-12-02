#ifndef _CONTROLLER_
#define _CONTROLLER_

#include "Model.h"
#include "View.h"
#include "BotFactory.h"

class Controller
{
	View view;
	Model model;
	void setWordLength(unsigned minWordLength, unsigned maxWordLength);
	void setSecretWord(const string& fromPlayerName, Player& forPlayer);
	void setTryWord(const string& playerName);
	void pvc();
	void pvp(unsigned numberOfPlayers);
	void preGameSettings(unsigned numberOfPlayers);
	void play();
public:
	void start();
};

#endif
