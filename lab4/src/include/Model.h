#ifndef _MODEL_
#define _MODEL_

#include "ModelException.h"
#include "Player.h"
#include <memory>
#include <map>

class Model
{
	int minWordLength = 2, maxWordLength = INT_MAX, wordLength, numberOfPlayers, cows, bulls;
	map<unsigned,shared_ptr<Player>> players;
	string tryWord;
	bool checkLength();
	bool giveUpCheck(int playerNumber, string tryWord);
	void searchForCows(int& wordLengthCp, string& secretWordCp);
	void searchForBulls(int& wordLengthCp, string& secretWordN, string& secretWordCp);
	void countBullsAndCowsNumber(string& secretWordN); 
	void checkPlayerNumber(int playerNumber);
public:
	Model() = default;
	Model(int numberOfPlayers);
	void countTurnResults(int playerNumber);
	int getCows();
	int getBulls();
	int getWordLength();
	int getMinWordLength();
	int getMaxWordLength();
	string getTryWord();
	string getSecretWord(int playerNumber);
	string getPlayerName(int playerNumber);
	int getPlayerTurnNumber(int playerNumber);
	bool getPlayerVictory(int playerNumber);
	bool getPlayerLoss(int playerNumber);
	void setPlayerName(int playerNumber, string playerName);
	void setMinWordLength(int minWordLength);
	void setMaxWordLength(int maxWordLength);
	bool setWordLength(int wordLength);
	bool setTryWord(int playerNumber,string tryWord);
	bool setSecretWord(int playerNumber, string secretWord);
};

#endif
