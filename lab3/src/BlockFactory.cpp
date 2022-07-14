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

Block* BlockFactory::getBlock(string blockName)
{
	auto it = _makers.find(blockName);
	if (it == _makers.end())
		throw MyException("Unrecognized block type", blockName);
	return it->second->getBlock();
}