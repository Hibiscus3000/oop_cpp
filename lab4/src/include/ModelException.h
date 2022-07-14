#ifndef _MODEL_EXCEPTION_
#define _MODEL_EXCEPTION_

#include "MyException.h"

class ModelException : public MyException
{
	int numberOfPlayers, playerNumber;

public:
	ModelException(int numberOfPlayers, int playerNumber) : numberOfPlayers(numberOfPlayers), playerNumber(playerNumber)
	{

	}
	void errorReport()
	{
		cerr << "Number of players: " << numberOfPlayers << endl << "Given player number: " << playerNumber << endl;
	}
};

#endif
