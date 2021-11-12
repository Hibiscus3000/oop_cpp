#include "Replace.h"

list<string> Replace::execute(const list<string>& text)
{
	if (blockDiscription.args.size() < 2)
		throw MyException("wrong number of arguments in replace block");
	list<string> newText;
	auto it = blockDiscription.args.begin();
	string word1 = *it;
	++it;
	string word2 = *it;
	int pos;
	int count = word1.length();
	for (auto line : text)
	{
		pos = line.find(word1);
		while (pos != string::npos)
		{
			line.replace(pos, count, word2);
			pos = line.find(word1);
		}
		newText.push_back(line);
	}
	return newText;
}

BlockType Replace::getType()
{
	return BlockType::INOUT;
}
