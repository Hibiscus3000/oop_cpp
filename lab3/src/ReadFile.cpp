#include "ReadFile.h"

list<string> ReadFile::execute(const list<string>& text)
{
	if (blockDiscription.args.size() < 1)
		throw MyException("wrong number of arguments in readfile block");
	ifstream in(*(blockDiscription.args.begin()));
	if (!in)
		throw MyException("couldn't find name of file or open file with given name in readfile block", *(blockDiscription.args.begin()));
	list<string> newText;
	string nextLine;
	getline(in, nextLine);
	while (!in.eof())
	{
		newText.push_back(nextLine);
		getline(in, nextLine);
	}
	return newText;
}

BlockType ReadFile::getType()
{
	return BlockType::IN;
}

string ReadFile::getName()
{
	return "readfile";
}