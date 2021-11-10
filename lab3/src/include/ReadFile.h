#ifndef _READ_FILE_
#define _READ_FILE_

#include "Block.h"

class ReadFile : public Block
{
	list<string> execute(const list<string>& text,const vector<string>& args) override;
	BlockType getType();
};

#endif 
