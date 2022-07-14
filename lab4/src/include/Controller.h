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
	void setSecretWord(int fromPlayerNumber, int forPlayerNumber);
	void setTryWord(int playerNumber);
	void preGameSettings(int numberOfPlayers);
	void setPlayersName(int numberOfPlayers);
	void play();
	void selectDifficulty();
	void mediumBotCheck(const string& difficulty);
	void makeTurns(int numberOfPlayers);
public:
	void start();
};

#endif
