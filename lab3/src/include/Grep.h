#ifndef _GREP_
#define _GREP_

#include "Block.h"

class Grep : public Block
{
	list<string> execute(const list<string>& text);
	BlockType getType();
};

#endif