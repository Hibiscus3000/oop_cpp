#ifndef _REPLACE_
#define _REPLACE_

#include "Block.h"

class Replace : public Block
{
	list<string> execute(const list<string>& text);
	static BlockType getType();
public:
	static string getName();
};

#endif