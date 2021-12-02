#include "Controller.h"

void Controller::setWordLength()
{
	unsigned wordLength = view.selectWordLength();
	if (!wordLength)
		throw inappropriateLength(wordLength);
	model.wordLength = wordLength;
}

string Controller::getWord(const string& playerName,const string wordType)
{
	string word;
	if (!wordType.compare("secret word"))
		word = view.selectSecretWord(playerName, model.wordLength);
	else
		word = view.makeTurn(playerName, model.wordLength);
	if (word.length() != model.wordLength)
		throw inappropriateWord(wordType, word, model.wordLength);
	return word;
}

void Controller::play()
{
	string gameMode = view.selectGameMode();
	if (gameMode.compare("pvp") && gameMode.compare("pvc"))
		throw UnrecognizedGameSettings("Unrecognised game mode:", gameMode);
	setWordLength();
	shared_ptr<Player> human(PlayerFactory::getInstance().getPlayer("human"));
	model.player1 = human;
	model.player1->name = view.selectPlayerName('1');
	if (!gameMode.compare("pvp"))
		playWithHuman();
	//if (!gameMode.compare("pvc"));
}

void Controller::playWithBot()
{

}

void Controller::playWithHuman()
{
	preGameSettings();
	while ((!model.player1->victory) || (!model.player2->victory))
	{
		model.makeTurn(view.makeTurn(model.player1->name, model.wordLength),*(model.player1));
		if (model.player1->victory)
			view.showVictoryMessage(model.player1->name, model.player1->turnNumber);
		else
			view.showTurnResults(model.cows, model.bulls);
		model.makeTurn(view.makeTurn(model.player2->name, model.wordLength), *(model.player2));
		if (model.player2->victory)
			view.showVictoryMessage(model.player2->name, model.player2->turnNumber);
		else
			view.showTurnResults(model.cows, model.bulls);
	}
}

void Controller::preGameSettings()
{
	shared_ptr<Player> human(PlayerFactory::getInstance().getPlayer("human"));
	model.player2 = human;
	model.player2->name = view.selectPlayerName('2');
	model.player2->secretWord = getWord(model.player1->name, "secret word");
	model.player1->secretWord = getWord(model.player2->name, "secret word");
}

