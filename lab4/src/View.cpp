#include "View.h"

unsigned View::selectNumberOfPlayers()
{
	unsigned numberOfPlayers;
	cout << "Please select number of players: ";
	cin >> numberOfPlayers;
	return numberOfPlayers;
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
	system("cls");
	return difficulty;
}

string View::selectPlayerName(unsigned playerNumber)
{
	string name;
	cout << "Player" << playerNumber << " please enter your name: ";
	cin >> name;
	system("cls");
	return name;
}

string View::selectSecretWord(const string& fromPlayerName, const string& forPlayerName, unsigned wordLength)
{
	string secretWord;
	cout << fromPlayerName << ", please enter your " << wordLength << " symbols secret word for " << forPlayerName << ": ";
	cin >> secretWord;
	system("cls");
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