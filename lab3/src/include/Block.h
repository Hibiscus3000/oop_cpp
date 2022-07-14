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

class Block
{
protected:
	vector<string> args;
public:
	virtual list<string> execute(const list<string>& text) = 0;
	void setBlockArgs(const vector<string>& args);
	virtual BlockType getType() = 0;
	virtual ~Block()
	{

	}
};

#endif