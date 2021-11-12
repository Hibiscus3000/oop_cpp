#include "WriteFile.h"

list<string> WriteFile::execute(const list<string>& text)
{
	if (blockDiscription.args.size() < 1)
		throw MyException("wrong number of arguments in writefile block");
	ofstream out(*(blockDiscription.args.begin()));
	if (!out)
		throw MyException("couldn't find name of file or open file with given name in writefile block", *(blockDiscription.args.begin()));
	for (auto line : text)
		out << line;
	return text;
}

BlockType WriteFile::getType()
{
	return BlockType::OUT;
}

string WriteFile::getName()
{
	return "writefile";
}