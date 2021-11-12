#ifndef _READ_FILE_
#define _READ_FILE_

#include "Block.h"

class ReadFile : public Block
{
	list<string> execute(const list<string>& text);
	static BlockType getType();
public:
	static string getName();
};

#endif 
