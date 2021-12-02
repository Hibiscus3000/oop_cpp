#include "View.h"

unsigned View::selectNumberOfPlayers()
{
	unsigned numberOfPlayers;
	if (prevMistake)
		cout << "Number of players shouldn't be equal to zero!" << endl;
	cout << "Please select number of players: ";
	cin >> numberOfPlayers;
	return numberOfPlayers;
}

unsigned View::selectWordLength(unsigned minWordLength, unsigned maxWordLength)
{
	unsigned wordLength;
	if (prevMistake)
		cout << "Inappropriate word length, please try again, remember that ";
	else
		cout << "Please select word length, ";
	cout <<	"it should vary from " << minWordLength << " to " << maxWordLength << ": ";
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
	if (prevMistake)
		cout << "Wrong attempt, " << fromPlayerName << ", please try again: ";
	else
		cout << fromPlayerName << ", please enter your " << wordLength << " symbols secret word for " << forPlayerName << ": ";
	cin >> secretWord;
	system("cls");
	return secretWord;
}

string View::makeTurn(const string& playerName, unsigned wordLength)
{
	string tryWord;
	if (prevMistake)
		cout << "Wrong attempt, " << playerName << ", please try again, ";
	else
		cout << playerName << ", please make your turn, ";
	cout << "remember that length of the word should be " << wordLength << ": ";
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

string View::playAgain()
{
	string answer;
	cout << "Do you want to play again? ";
	cin >> answer;
	return answer;
}