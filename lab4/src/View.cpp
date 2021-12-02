#include "View.h"

string View::selectGameMode()
{
	string gameMode;
	cout << "Please select game mode: pvp or pvc: ";
	cin >> gameMode;
	return gameMode;
}

unsigned View::selectWordLength()
{
	unsigned wordLength;
	cout << "Please select word length: ";
	cin >> wordLength;
	return wordLength;
}

string View::selectDifficulty()
{
	string difficulty;
	cout << "Please select difficulty: easy, medium, hard: ";
	cin >> difficulty;
	fflush(stdout);
	return difficulty;
}

string View::selectPlayerName(char playerNumber)
{
	string name;
	cout << "Player" << playerNumber << " please enter your name: ";
	cin >> name;
	fflush(stdout);
	return name;
}

string View::selectSecretWord(const string& playerName, unsigned wordLength)
{
	string secretWord;
	cout << playerName << ", please enter your " << wordLength << " symbols secret word: ";
	cin >> secretWord;
	fflush(stdout);
	return secretWord;
}

string View::makeTurn(const string& playerName, unsigned wordLength)
{
	string tryWord;
	cout << playerName << ", please make your turn, remember that length of the word should be " << wordLength << ": ";
	cin >> tryWord;
	return tryWord;
}

void View::showTurnResults(unsigned cows, unsigned bulls)
{
	cout << "Bulls: " << bulls << endl << "Cows: " << cows << endl;
}

void View::showVictoryMessage(const string& playerName, unsigned turnNumber)
{
	cout << playerName << ", you guessed your word in " << turnNumber << " turns! Congratulations!!!" << endl;
}