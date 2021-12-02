#ifndef _CONTROLLER_
#define _CONTROLLER_

#include "Model.h"
#include "View.h"
#include "ControllerException.h"
#include "PlayerFactory.h"
#include "Human.h"

class Controller
{
	Model model;
	View view;
	void setWordLength();
	string getWord(const string& playerName, const string wordType);
	void playWithBot();
	void playWithHuman();
	void preGameSettings();
public:
	void play();
};

#endif
