#include "Controller.h"

void Controller::setWordLength(unsigned minWordLength, unsigned maxWordLength)
{
	model.wordLength = view.selectWordLength(minWordLength, maxWordLength);
	while ((model.wordLength < minWordLength) || (model.wordLength > maxWordLength))
	{
		view.prevMistake = true;
		model.wordLength = view.selectWordLength(minWordLength, maxWordLength);
	}
	view.prevMistake = false;
}

void Controller::setSecretWord(const string& fromPlayerName, Player& forPlayer)
{
	forPlayer.secretWord = view.selectSecretWord(fromPlayerName, forPlayer.name, model.wordLength);
	while (forPlayer.secretWord.length() != model.wordLength)
	{
		view.prevMistake = true;
		forPlayer.secretWord = view.selectSecretWord(fromPlayerName, forPlayer.name, model.wordLength);
	}
	view.prevMistake = false;
}

void Controller::setTryWord(const string& playerName)
{
	model.tryWord = view.makeTurn(playerName,model.wordLength);
	while (model.tryWord.length() != model.wordLength)
	{
		view.prevMistake = true;
		model.tryWord = view.makeTurn(playerName, model.wordLength);
	}
	view.prevMistake = false;
}

void Controller::play()
{
	unsigned numberOfPlayers = view.selectNumberOfPlayers();
	while (!numberOfPlayers)
	{
		view.prevMistake = true;
		numberOfPlayers = view.selectNumberOfPlayers();
	}
	Model model(numberOfPlayers);
	this->model = model;
	if (numberOfPlayers != 1)
		pvp(numberOfPlayers);
	else pvc();
}

void Controller::pvc()
{
	model.players[0]->name = view.selectPlayerName(1);
	string difficulty = view.selectDifficulty();
	if (!difficulty.compare("medium"))
		setWordLength(MIN_WORD_LENGTH, MAX_WORD_LENGNTH);
	else
		setWordLength(1, INT_MAX);
	model.players[0]->secretWord = BotFactory::getInstance().getBot(difficulty)->makeSecretWord(model.wordLength);
	while (!model.players[0]->victory)
	{
		setTryWord(model.players[0]->name);
		model.makeTurn(*(model.players[0]));
		if (!model.players[0]->victory)
			view.showTurnResults(model.cows, model.bulls);
	}
	view.showVictoryMessage(model.players[0]->name, model.players[0]->turnNumber);
}

void Controller::pvp(unsigned numberOfPlayers)
{
	preGameSettings(numberOfPlayers);
	unsigned i, numberOfVictories = 0;
	while (numberOfVictories != numberOfPlayers)
	{
		for (i = 0; i < numberOfPlayers; ++i)
		{
			if (model.players[i]->victory)
				continue;
			setTryWord(model.players[i]->name);
			model.makeTurn(*(model.players[i]));
			if (model.players[i]->victory)
			{
				++numberOfVictories;
				view.showVictoryMessage(model.players[i]->name, model.players[i]->turnNumber);
			}
			else
				view.showTurnResults(model.cows, model.bulls);
		}
	}
}

void Controller::preGameSettings(unsigned numberOfPlayers)
{
	setWordLength(0,INT_MAX);
	unsigned i;
	for (i = 0; i < numberOfPlayers; ++i)
		model.players[i]->name = view.selectPlayerName(i + 1);
	for (i = 1; i < numberOfPlayers; ++i)
		setSecretWord(model.players[i - 1]->name, *model.players[i]);
	setSecretWord(model.players[i - 1]->name, *model.players[0]);
}

void Controller::start()
{
	play();
	while (!view.playAgain().compare("yes"))
		play();
}