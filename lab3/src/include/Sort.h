#ifndef _SORT_
#define _SORT_

#include "Block.h"
#include <algorithm>

class Sort : public Block
{
	list<string> execute(const list<string>& text);
	BlockType getType();
};

bool compare(string str1, string str2);

#endif