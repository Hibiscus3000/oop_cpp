#include "WorkFlowExecutor.h"

void WorkFlowExecutor::executeWorkFlow(ifstream& in)
{
	WorkFlowParser parser;
	list<Block*> blockObjects;
	blockMap blocks = parser.getBlocks(in);
	createBlockObjects(blocks, blockObjects, in);
	blockCheck(blockObjects);
	executeBlocks(blockObjects);
}

void WorkFlowExecutor::blockCheck(list<Block*>& blockObjects)
{
	auto it = blockObjects.begin(), listEndIt = --blockObjects.end();
	if ((*it)->getType() != BlockType::IN)
		throw MyException("no readfile block at the begging of the block structure");
	++it;
	while (it != listEndIt)
	{
		if ((*it)->getType() != BlockType::INOUT)
			throw MyException("wrong order of the block structure");
		++it;
	}
	if ((*listEndIt)->getType() != BlockType::OUT)
		throw MyException("no writefile block at the end of the block structure");

}

void WorkFlowExecutor::executeBlocks(list<Block*>& blockObjects)
{
	list<string> text;
	for (auto blockObject : blockObjects)
	{
		text = blockObject->execute(text);
	}
}

void WorkFlowExecutor::createBlockObjects(blockMap& blocks, list<Block*> blockObjects, ifstream& in)
{
	string flow;
	getline(in, flow);
	int i, j = 0;
	string blockNumber, blockName;
	while (true)
	{
		i = flow.find_first_not_of(" ->", j);
		j = flow.find_first_of(" ->", i);
		if (i == string::npos)
			break;
		blockNumber = flow.substr(i, j - i);
		auto it = blocks.find(blockNumber);
		if (it == blocks.end())
			throw MyException("Unrecognized block number", blockNumber);
		blockName = *it->second.begin();
		it->second.erase(it->second.begin());
		Block* blockObject = BlockFactory::getInstance().getBlock(blockName);
		blockObject->setBlockArgs(it->second);
		blockObjects.push_back(blockObject);
	}
}