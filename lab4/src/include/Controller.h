#ifndef _CONTROLLER_
#define _CONTROLLER_
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGNTH 6 

#include "Model.h"
#include "View.h"
#include "BotFactory.h"

class Controller
{
	View view;
	Model model;
	void setWordLength(unsigned minWordLength, unsigned maxWordLength);
	void setSecretWord(const Player& fromPlayer, Player& forPlayer);
	void setTryWord(const Player& player);
	void pvc();
	void pvp(unsigned numberOfPlayers);
	void preGameSettings(unsigned numberOfPlayers);
	void play();
public:
	void start();
};

#endif
