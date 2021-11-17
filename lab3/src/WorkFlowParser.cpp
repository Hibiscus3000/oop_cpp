#include "WorkFlowParser.h"

blockMap WorkFlowParser::getBlocks(ifstream& in)
{
	blockMap blocks;
	string block;
	getline(in, block);
	if (block.find(beginLine) == string::npos)
		throw MyException("no \"desc\" at the begging of the block description", block);
	getline(in, block);
	while (block.find(endLine) == string::npos)
	{
		if (in.eof())
			throw MyException("no \"csed at the end of the block description");
		parseBlock(block, blocks);
		getline(in, block);
	}
	return blocks;
}

void WorkFlowParser::parseBlock(string block, blockMap& blocks)
{
	int i, j;
	string blockNumber;
	getBlockNumber(i, block, blockNumber);
	string blockName;
	getBlockName(i, j, block, blockName);
	vector<string> nameAndParams;
	nameAndParams.push_back(blockName);
	getBlockArgs(i, j, block, nameAndParams);
	blocks.emplace(blockNumber, nameAndParams);
}

void WorkFlowParser::getBlockNumber(int& i, string block, string& blockNumber)
{
	i = block.find(' ');
	if (i == string::npos)
		throw MyException("number of block didn't appear in the next block discription", block);
	blockNumber = block.substr(0, i);
}

void WorkFlowParser::getBlockName(int& i, int& j, string& block, string& blockName)
{
	i = block.find_first_not_of("= ", i);
	j = block.find(' ', i);
	if (i == string::npos)
		throw MyException("name of block didn't appear in the next block discription", block);
	blockName.append(block, i, j - i);
}

void WorkFlowParser::getBlockArgs(int& i, int& j, string& block, vector<string>& nameAndParams)
{
	string param;
	while (j != string::npos)
	{
		i = block.find_first_not_of("= ", j);
		j = block.find(' ', i);
		param.append(block, i, j - i);
		nameAndParams.push_back(param);
		param.erase();
	}
}
