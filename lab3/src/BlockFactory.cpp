#include "BlockFactory.h"

void BlockFactory::RegisterMaker(const string& key, IBlockMaker* maker)
{
	if (_makers.find(key) != _makers.end())
		throw MyException("Multiply makers for given key!",key);
	_makers[key] = maker;
}

BlockFactory& BlockFactory::getInstance()
{
	static BlockFactory factory;
	return factory;
}

Block* BlockFactory::getBlock(blockList& blocks, string blockNumber)
{
	pair<string,vector<string>> blockDiscription;
	for (auto block : blocks)
		if (!block.first.compare(blockNumber))
		{
			blockDiscription = block;
			break;
		}
	auto it = _makers.find(*blockDiscription.second.begin());
	if (it == _makers.end())
		throw MyException("Unrecognized block type", *blockDiscription.second.begin());
	IBlockMaker* maker = it->second;
	Block * block = maker->getBlock();
	blockDiscription.second.erase(blockDiscription.second.begin());
	block->getBlockDiscription(blockDiscription.first, blockDiscription.second);
	return block;
}