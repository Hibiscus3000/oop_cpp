#include "Controller.h"

void Controller::setWordLength()
{
	unsigned wordLength = view.selectWordLength();
	if (!wordLength)
		throw inappropriateLength(wordLength);
	model.wordLength = wordLength;
}

void Controller::setSecretWord(const string& fromPlayerName, Player& forPlayer)
{
	string secretWord = view.selectSecretWord(fromPlayerName, forPlayer.name, model.wordLength);
	if (secretWord.length() != model.wordLength)
		throw inappropriateWord("secret word", secretWord, model.wordLength);
	forPlayer.secretWord = secretWord;
}

void Controller::setTryWord(const string& playerName)
{
	string tryWord = view.makeTurn(playerName, model.wordLength);
	if (tryWord.length() != model.wordLength)
		throw inappropriateWord("try word", tryWord, model.wordLength);
	model.tryWord = tryWord;
}

void Controller::play()
{
	unsigned numberOfPlayers = view.selectNumberOfPlayers();
	if (!numberOfPlayers)
		throw MyException("Number of players shouldn't be equal to zero");
	Model model(numberOfPlayers);
	this->model = model;
	setWordLength();
	model.players[0]->name = view.selectPlayerName(1);
	if (numberOfPlayers != 1)
		pvp(numberOfPlayers);
	//if (!gameMode.compare("pvc"));
}

void Controller::pvc()
{

}

void Controller::pvp(unsigned numberOfPlayers)
{
	preGameSettings(numberOfPlayers);
	unsigned i,numberOfVictories = 0;
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
	unsigned i;
	for (i = 1; i < numberOfPlayers; ++i)
		model.players[i]->name = view.selectPlayerName(i + 1);
	for (i = 1; i < numberOfPlayers; ++i)
		setSecretWord(model.players[i - 1]->name, *model.players[i]);
	setSecretWord(model.players[i - 1]->name, *model.players[0]);
}

