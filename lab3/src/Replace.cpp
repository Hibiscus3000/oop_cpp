#include "Replace.h"

list<string> Replace::execute(const list<string>& text)
{
	if (blockDiscription.args.size() < 2)
		throw MyException("wrong number of arguments in replace block");
	list<string> newText;
	auto it = blockDiscription.args.begin();
	string word1 = *it;
	word1.insert(0, 1, ' ');
	word1.push_back(' ');
	string word2 = *(++it);
	word2.insert(0, 1, ' ');
	word2.push_back(' ');
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
