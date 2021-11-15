#include "WorkFlowExecutor.h"

void WorkFlowExecutor::executeWorkFlow(ifstream& in)
{
	WorkFlowParser parser;
	blockList blocks = parser.getBlocks(in);
	list<string> structure = parser.getStructure(in);
	list<Block*> blockObjects;
	for (auto blockNumber : structure)
	{
		try
		{
			Block* blockObject = BlockFactory::getInstance().getBlock(blocks, blockNumber);
			blockObjects.push_back(blockObject);
		}
		catch (MyException& ex)
		{
			cerr << ex.what() << endl;
			ex.showLine();
			deleteBlocks(blockObjects);
			return;
		}
	}

	try
	{
		blockCheck(blockObjects);
	}
	catch (MyException& ex)
	{
		cerr << ex.what() << endl;
		deleteBlocks(blockObjects);
		return;
	}

	executeBlocks(blockObjects);
	deleteBlocks(blockObjects);
}

void WorkFlowExecutor::blockCheck(list<Block*> blockObjects)
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

void WorkFlowExecutor::executeBlocks(list<Block*> blockObjects)
{
	list<string> text;
	for (auto blockObject : blockObjects)
	{
		try
		{
			text = blockObject->execute(text);
		}
		catch (MyException& ex)
		{
			cerr << ex.what() << endl;
			ex.showLine();
		}
	}
}

void WorkFlowExecutor::deleteBlocks(list<Block*> blockOjects)
{
	for (auto blockObject : blockOjects)
		if (blockObject)
			delete(blockObject);
}