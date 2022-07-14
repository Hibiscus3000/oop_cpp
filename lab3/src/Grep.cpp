#include "Grep.h"

list<string> Grep::execute(const list<string>& text)
{
	if (args.size() < 1)
		throw MyException("wrong number of arguments in grep block");
	list<string> newText;
	string word = *args.begin();
	for (auto line : text)
		if (line.find(word) != string::npos)
			newText.push_back(line);
	return newText;
}

BlockType Grep::getType()
{
	return BlockType::INOUT;
}
