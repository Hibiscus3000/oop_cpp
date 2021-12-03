#include "View.h"

View::View()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setColorWhite();
}

void View::setColorWhite()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void View::setColor(unsigned color)
{
	color = color % 11 + 4;
	SetConsoleTextAttribute(hConsole, color);
}

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
		cout << "Inappropriate word length, please remember that ";
	else
		cout << "Please select word length, ";
	cout <<	"it should vary from " << minWordLength << " to " << maxWordLength << ": ";
	cin >> wordLength;
	return wordLength;
}

string View::selectDifficulty()
{
	string difficulty;
	cout << "Please select difficulty: easy, medium or hard: ";
	cin >> difficulty;
	system("cls");
	return difficulty;
}

string View::selectPlayerName(unsigned playerNumber)
{
	string name; 
	setColor(playerNumber);
	cout << "Player" << playerNumber;
	setColorWhite();
	cout << " please enter your name: ";
	setColor(playerNumber);
	cin >> name;
	setColorWhite();
	system("cls");
	return name;
}

string View::selectSecretWord(const string& fromPlayerName,unsigned forPlayerNumber, const string& forPlayerName,unsigned fromPlayerNumber, unsigned wordLength)
{
	string secretWord;
	if (prevMistake)
	{
		cout << "Wrong attempt, ";
		setColor(fromPlayerNumber);
		cout << fromPlayerName;
		setColorWhite();
		cout << ", please try again: ";
	}
	else
	{
		setColor(fromPlayerNumber);
		cout << fromPlayerName;
		setColorWhite();
		cout << ", please enter your " << wordLength << " symbols secret word for ";
		setColor(forPlayerNumber);
		cout << forPlayerName;
		setColorWhite();
		cout << ": ";
	}
	setColor(fromPlayerNumber);
	cin >> secretWord;
	setColorWhite();
	system("cls");
	return secretWord;
}

string View::makeTurn(const string& playerName, unsigned playerNumber, unsigned wordLength)
{
	string tryWord;
	if (prevMistake)
	{
		cout << "Wrong attempt, ";
		setColor(playerNumber);
		cout << playerName;
		setColorWhite();
		cout << ", please try again, ";
	}
	else
	{
		setColor(playerNumber);
		cout << playerName;
		setColorWhite();
		cout << ", please make your turn, ";
	}
	cout << "remember that length of the word should be " << wordLength << ": ";
	setColor(playerNumber);
	cin >> tryWord;
	setColorWhite();
	return tryWord;
}

void View::showTurnResults(unsigned cows, unsigned bulls)
{
	cout << "Bulls: " << bulls << endl << "Cows: " << cows << endl;
}

void View::showVictoryMessage(const string& playerName, unsigned playerNumber, unsigned turnNumber)
{
	setColor(playerNumber);
	cout << playerName; 
	setColorWhite();
	cout << ", you guessed your word in " << turnNumber << " turns! Congratulations!!!" << endl;
}

string View::playAgain()
{
	string answer;
	cout << "Do you want to play again? ";
	cin >> answer;
	return answer;
}