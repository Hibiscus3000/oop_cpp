#ifndef _WRITE_FILE_
#define _WRITE_FILE_

#include "Block.h"

class WriteFile : public Block
{
	list<string> execute(const list<string>& text, const vector<string>& args) override;
	BlockType getType();
};

#endif 
