#ifndef _I_BLOCK_MAKER_
#define _I_BLOCK_MAKER_

#include "Block.h"

class IBlockMaker 
{
public:
	virtual Block* getBlock() const = 0;
	virtual ~IBlockMaker()
	{

	};
};

#endif