#include "WorkFlowParser.h"

blockList WorkFlowParser::getBlocks(ifstream& in)
{
	blockList blocks;
	string block;
	getline(in, block);
	try
	{
		if (block.compare(beginLine))
			throw MyException("no \"desc\" at the begging of the block description", block);
	}
	catch (MyException& ex)
	{
		cerr << ex.what() << endl;
		ex.showLine();
	}
	getline(in, block);
	while (block.compare(endLine))
	{
		try
		{
			if (in.eof())
				throw MyException("no \"csed at the end of the block description");
		}
		catch (MyException& ex)
		{
			cerr << ex.what() << endl;
		}
		parseBlock(block,blocks);
		getline(in, block);
	}
	return blocks;
}

void WorkFlowParser::parseBlock(string block, blockList& blocks)
{
	int i, j;
	string blockNumber;
	getBlockNumber(i, block, blockNumber);
	string blockName;
	getBlockName(i, j, block,blockName);
	vector<string> nameAndParams;
	nameAndParams.push_back(blockName);
	string param;
	blocks.emplace_back(blockNumber, nameAndParams);
}

void WorkFlowParser::getBlockNumber(int& i, string block, string& blockNumber)
{
	i = block.find(' ');
	try
	{
		if (i == string::npos)
			throw MyException("number of block didn't appear in the next block discription", block);
	}
	catch (MyException& ex)
	{
		cerr << ex.what() << endl;
		ex.showLine();
	}
	blockNumber = block.substr(0, i);
}

void WorkFlowParser::getBlockName(int& i, int& j, string block, string& blockName)
{
	i = block.find_first_not_of("= ", i);
	j = block.find(' ', i);
	try
	{
		if (i == string::npos)
			throw MyException("name of block didn't appear in the next block discription", block);
	}
	catch (MyException& ex)
	{
		cerr << ex.what() << endl;
		ex.showLine();
	}
	blockName.append(block, i, j - i);
}

void WorkFlowParser::getBlockArgs(int& i, int& j, string block, string& param, vector<string>& nameAndParams)
{
	while (j != string::npos)
	{
		j = block.find(' ', i);
		i = block.find_first_not_of("= ", i);
		param.append(block, i, j - i);
		nameAndParams.push_back(param);
	}
}

list<string> WorkFlowParser::getStructure(ifstream& in)
{
	list<string> structure;
	string flow;
	int i, j = 0;
	while (true)
	{
		i = flow.find_first_not_of(" ->", j);
		j = flow.find_first_of(" ->", i);
		if (i == string::npos)
			break;
		structure.push_back(flow.substr(i,j - i));
	}
	return structure;
}
