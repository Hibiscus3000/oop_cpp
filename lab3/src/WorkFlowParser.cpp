#include "WorkFlowParser.h"

blocksList WorkFlowParser::getBlocks(ifstream& in)
{
	blocksList* Blocks = new blocksList;
	string block;
	getline(in, block);
	try
	{
		if (block.compare(beginLine))
			throw MyException("no \"desc\" at the begging of the block description", block);
	}
	catch (MyException& ex)
	{
		cout << ex.what() << endl;
		ex.showLine();
	}
	getline(in, block);
	while (!in.eof())
	{
		parseBlock(block);
		getline(in, block);
	}
}

void WorkFlowParser::parseBlock(string block)
{
	unsigned i = block.find(' '), j;
	try
	{
		if (i == string::npos)
			throw MyException("number of block didn't appear in the next block discription",block);
	}
	catch (MyException& ex)
	{
		cout << ex.what() << endl;
		ex.showLine();
	}
	char* blockNumber = new char [i];
	int number = atoi(blockNumber);
	string blockName;
	i = block.find_first_not_of('= ', i);
	j = block.find(' ', i);
	try
	{
		if (i == string::npos)
			throw MyException("name of block didn't appear in the next block discription", block);
	}
	catch (MyException& ex)
	{
		cout << ex.what() << endl;
		ex.showLine();
	}
	blockName.append(block, i, j - i);
	vector<string> nameAndParams;
	nameAndParams.push_back(blockName);
	string param;
	while (j != string::npos)
	{
		j = block.find(' ', i);
		i = block.find_first_not_of("= ", i);
		param.append(block, i, j - i);
		nameAndParams.push_back(param);
	}
	this->blist.emplace_back(number, nameAndParams);
}