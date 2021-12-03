#include "Controller.h"

void Controller::setWordLength()
{
	model.wordLength = view.selectWordLength(model.minWordLength, model.maxWordLength);
	while (!model.checkLength())
	{
		view.prevMistake = true;
		model.wordLength = view.selectWordLength(model.minWordLength, model.maxWordLength);
	}
	view.prevMistake = false;
}

void Controller::setSecretWord(const Player& fromPlayer, Player& forPlayer)
{
	forPlayer.secretWord = view.selectSecretWord(fromPlayer.name, fromPlayer.number, forPlayer.name, forPlayer.number, model.wordLength);
	qCheck(forPlayer.secretWord);
	while (forPlayer.secretWord.length() != model.wordLength)
	{
		view.prevMistake = true;
		forPlayer.secretWord = view.selectSecretWord(fromPlayer.name, fromPlayer.number, forPlayer.name, forPlayer.number, model.wordLength);
		qCheck(forPlayer.secretWord);
	}
	view.prevMistake = false;
}

void Controller::setTryWord(const Player& player)
{
	model.tryWord = view.makeTurn(player.name, player.number, model.wordLength);
	qCheck(model.tryWord);
	while ((model.tryWord.length() != model.wordLength) && (!model.giveUpCheck()))
	{
		view.prevMistake = true;
		model.tryWord = view.makeTurn(player.name, player.number, model.wordLength);
		qCheck(model.tryWord);
	}
	view.prevMistake = false;
}

void Controller::play()
{
	int numberOfPlayers = view.selectNumberOfPlayers();
	while (numberOfPlayers <= 0)
	{
		view.prevMistake = true;
		numberOfPlayers = view.selectNumberOfPlayers();
	}
	view.prevMistake = false;
	Model model(numberOfPlayers);
	this->model = model;
	if (numberOfPlayers != 1)
		pvp(numberOfPlayers);
	else pvc();
}

void Controller::pvc()
{
	model.players[0]->name = view.selectPlayerName(1);
	qCheck(model.players[0]->name);
	string difficulty = view.selectDifficulty();
	qCheck(difficulty);
	mediumBotCheck(difficulty);
	Bot* bot = BotFactory::getInstance().getBot(difficulty);
	setWordLength();
	model.players[0]->secretWord = bot->makeSecretWord(model.wordLength);
	while ((!model.players[0]->victory) && (model.players[0]->loss))
	{
		setTryWord(*model.players[0]);
		model.makeTurn(*model.players[0]);
		if (model.players[0]->victory)
			view.showVictoryMessage(model.players[0]->name, model.players[0]->number, model.players[0]->turnNumber);
		else
			if (model.players[0]->loss)
				view.showLossMessage(model.players[0]->name, model.players[0]->number, model.players[0]->secretWord);
			else
				view.showTurnResults(model.cows, model.bulls);
	}
	view.showVictoryMessage(model.players[0]->name, model.players[0]->number, model.players[0]->turnNumber);
}

void Controller::pvp(int numberOfPlayers)
{
	preGameSettings(numberOfPlayers);
	int i, numberOfVictoriesOrLosses = 0;
	while (numberOfVictoriesOrLosses != numberOfPlayers)
	{
		for (i = 0; i < numberOfPlayers; ++i)
		{
			if ((model.players[i]->victory) || (model.players[i]->loss))
				continue;
			setTryWord(*model.players[i]);
			model.makeTurn(*model.players[i]);
			if ((model.players[i]->victory) || (model.players[i]->loss))
			{
				++numberOfVictoriesOrLosses;
				if (model.players[i]->victory)
					view.showVictoryMessage(model.players[i]->name, model.players[i]->number, model.players[i]->turnNumber);
				if (model.players[i]->loss)
					view.showLossMessage(model.players[i]->name, model.players[i]->number, model.players[i]->secretWord);
			}
			else
				view.showTurnResults(model.cows, model.bulls);
		}
	}
}

void Controller::preGameSettings(int numberOfPlayers)
{
	setWordLength();
	int i;
	for (i = 0; i < numberOfPlayers; ++i)
	{
		model.players[i]->name = view.selectPlayerName(i + 1);
		qCheck(model.players[i]->name);
	}
	for (i = 1; i < numberOfPlayers; ++i)
		setSecretWord(*model.players[i - 1], *model.players[i]);
	setSecretWord(*model.players[i - 1], *model.players[0]);
}

void Controller::qCheck(const string& str)
{
	if (!str.compare("q"))
		throw MyException("");
}

void Controller::mediumBotCheck(const string& difficulty)
{
	if (!difficulty.compare("medium"))
	{
		model.minWordLength = MIN_WORD_LENGTH;
		model.maxWordLength = MAX_WORD_LENGTH;
	}
}

void Controller::start()
{
	play();
	while (!view.playAgain().compare("yes"))
		play();
}