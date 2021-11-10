#ifndef _BLOCK_
#define _BLOCK_

#include <list>
#include <vector>
#include <fstream>
#include <string>
#include "MyException.h"

using namespace std;

typedef enum class BlockType
{
	IN, OUT, INOUT
};

class Block
{
	virtual list<string> execute(const list<string>& text, const vector<string>& args) = 0;
	virtual BlockType getType() = 0;
};

class BlockFactory
{
	BlockFactory() = default;

public:
	static BlockFactory& getInstance()
	{
		static BlockFactory factory;
		return factory;
	}
};
#endif