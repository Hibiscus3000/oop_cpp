#ifndef _CONTROLLER_
#define _CONTROLLER_

#include "Model.h"
#include "View.h"
#include "ControllerException.h"

class Controller
{
	Model model;
	View view;
	void setWordLength(unsigned wordLength);
	void setSecretWord(string secretWord, string& secretWordN);
	void setTryWord(string tryWord);
	void preGameSettings();
	void play();
};

#endif
