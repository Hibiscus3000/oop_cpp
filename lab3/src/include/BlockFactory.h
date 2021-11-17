#ifndef _BLOCK_FACTORY_
#define _BLOCK_FACTORY_

#include "Block.h"
#include "WorkFlowParser.h"
#include "IBlockMaker.h"
#include <map>

class BlockFactory
{
	BlockFactory() = default;
	map<string, IBlockMaker*> _makers;

public:
	static BlockFactory& getInstance();
	Block* getBlock(string blockName);
	void RegisterMaker(const string& key, IBlockMaker* maker);
};

#endif