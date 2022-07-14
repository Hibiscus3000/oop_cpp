#ifndef  _DUMP_
#define _DUMP_

#include "Block.h"

class Dump : public Block
{
	list<string> execute(const list<string>& text);
	BlockType getType();
};

#endif 
