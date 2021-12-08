#include "Controller.h"

void Controller::setWordLength()
{
	while (!model.setWordLength(view.selectWordLength(model.getMinWordLength(), model.getMaxWordLength())))
		view.prevMistake = true;
	view.prevMistake = false;
}

void Controller::setSecretWord(int fromPlayerNumber, int forPlayerNumber)
{
	while (!model.setSecretWord(forPlayerNumber, view.selectSecretWord(model.getPlayerName(fromPlayerNumber), fromPlayerNumber + 1, model.getPlayerName(forPlayerNumber), forPlayerNumber + 1, model.getWordLength())))
		view.prevMistake = true;
	view.prevMistake = false;
}

void Controller::setTryWord(int playerNumber)
{
	while (!model.setTryWord(playerNumber,view.makeTurn(model.getPlayerName(playerNumber), playerNumber + 1, model.getWordLength())))
		view.prevMistake = true;
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
	this->model = move(model);
	if (numberOfPlayers == 1)
		selectDifficulty();
	else
		setWordLength();
	preGameSettings(numberOfPlayers);
	makeTurns(numberOfPlayers);
}

void Controller::selectDifficulty()
{
	string difficulty = view.selectDifficulty();
	mediumBotCheck(difficulty);
	shared_ptr<Bot> bot(BotFactory::getInstance().getBot(difficulty));
	setWordLength();
	model.setSecretWord(0, bot->makeSecretWord(model.getWordLength()));
}

void Controller::preGameSettings(int numberOfPlayers)
{
	string name;
	int i;
	setPlayersName(numberOfPlayers);
	for (i = 1; i < numberOfPlayers; ++i)
		setSecretWord(i - 1, i);
	if (numberOfPlayers != 1)
		setSecretWord(i - 1, 0);
}

void Controller::setPlayersName(int numberOfPlayers)
{
	int i;
	string name;
	for (i = 0; i < numberOfPlayers; ++i)
	{
		name = view.selectPlayerName(i + 1);
		model.setPlayerName(i, name);
	}
}

void Controller::mediumBotCheck(const string& difficulty)
{
	if (!difficulty.compare("medium"))
	{
		model.setMaxWordLength(MAX_WORD_LENGTH);
		model.setMinWordLength(MIN_WORD_LENGTH);
	}
}

void Controller::makeTurns(int numberOfPlayers)
{
	int i, numberOfVictoriesOrLosses = 0;
	while (numberOfVictoriesOrLosses != numberOfPlayers)
	{
		for (i = 0; i < numberOfPlayers; ++i)
		{
			if ((model.getPlayerVictory(i)) || (model.getPlayerLoss(i)))
				continue;
			setTryWord(i);
			if (model.getPlayerLoss(i))
			{
				++numberOfVictoriesOrLosses;
				view.showLossMessage(model.getPlayerName(i), i + 1, model.getSecretWord(i));
				continue;
			}
			model.countTurnResults(i);
			if (model.getPlayerVictory(i))
			{
				++numberOfVictoriesOrLosses;
					view.showVictoryMessage(model.getPlayerName(i), i + 1, model.getPlayerTurnNumber(i));
			}
			else
				view.showTurnResults(model.getCows(), model.getBulls());
		}
	}
}

void Controller::start()
{
	play();
	while (!view.playAgain().compare("yes"))
		play();
}