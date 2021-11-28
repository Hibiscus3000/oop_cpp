#include "View.h"

string View::selectGameMode()
{
	string gameMode;
	cout << "Please, select game mode: pvp or pvc: ";
	cin >> gameMode;
	return gameMode;
}

string View::selectDifficulty()
{
	string difficulty;
	cout << "Please, select difficulty: easy, medium, hard: ";
	cin >> difficulty;
	cin.clear();
	return difficulty;
}

string View::selectPlayerName(char playerNumber)
{
	string name;
	cout << "Player" << playerNumber << " please enter your name: ";
	cin >> name;
	return name;
}

string View::selectSecretWord(string playerName, unsigned wordLength)
{
	cin.clear();
	string secretWord;
	cout << playerName << ", please enter your " << wordLength << " symbols secret word: ";
	return secretWord;
}