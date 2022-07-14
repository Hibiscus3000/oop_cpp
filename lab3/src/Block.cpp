#include "Block.h"

void Block::setBlockArgs(const vector<string>& args)
{
	this->args = args;
	this->args.erase(this->args.begin());
}