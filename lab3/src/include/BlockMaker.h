#ifndef _BLOCK_MAKER_
#define _BLOCK_MAKER_

#include "BlockFactory.h"
#include "IBlockMaker.h"

template<typename T>
class BlockMaker : public IBlockMaker
{
public:
	BlockMaker(const string& key)
	{
		BlockFactory::getInstance().RegisterMaker(key, this);
	}
	virtual Block * getBlock() const
	{
		return new T;
	}
};

#endif