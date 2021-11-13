#include "Block.h"

void Block::getBlockDiscription(const string& blockNumber, const vector<string>& args)
{
	this->blockDiscription.blockNumber = blockNumber;
	this->blockDiscription.args = args;
}