#ifndef _CONTROLLER_
#define _CONTROLLER_
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 6 

#include "Model.h"
#include "View.h"
#include "BotFactory.h"

class Controller
{
	View view;
	Model model;
	void setWordLength();
	void setSecretWord(const Player& fromPlayer, Player& forPlayer);
	void setTryWord(const Player& player);
	void pvc();
	void pvp(int numberOfPlayers);
	void preGameSettings(int numberOfPlayers);
	void play();
	void qCheck(const string& str);
	void mediumBotCheck(const string& difficulty);
public:
	void start();
};

#endif
