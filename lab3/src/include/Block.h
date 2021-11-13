#ifndef _BLOCK_
#define _BLOCK_

#include <list>
#include <vector>
#include <fstream>
#include <string>
#include "MyException.h"

using namespace std;

enum class BlockType
{
	IN, OUT, INOUT
};

class BlockDiscription
{
public:
	string blockNumber;
	vector<string> args;
};

class Block
{
protected:
	BlockDiscription blockDiscription;
public:
	virtual list<string> execute(const list<string>& text) = 0;
	void getBlockDiscription(const string& blockNumber,const vector<string>& args);
	virtual BlockType getType() = 0;
	virtual ~Block()
	{

	}
};

#endif