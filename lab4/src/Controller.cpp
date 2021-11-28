#include "Controller.h"

void Controller::setWordLength(unsigned wordLength)
{
	if (!wordLength)
		throw inappropriateLength(wordLength);
	model.wordLength = wordLength;
}

void Controller::setSecretWord(string secretWord, string& secretWordN)
{
	if (secretWord.length() != model.wordLength)
		throw inappropriateWord("secret word", secretWord, model.wordLength);
	secretWordN = secretWord;
}

void Controller::setTryWord(string tryWord)
{
	if (tryWord.length() != model.wordLength)
		throw inappropriateWord("try word", tryWord, model.wordLength);
	model.tryWord = tryWord;
}

void Controller::preGameSettings()
{
	view.
}

void Controller::play()
{
	preGameSettings();
}

