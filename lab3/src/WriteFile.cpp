#include "WriteFile.h"

list<string> WriteFile::execute(const list<string>& text)
{
	if (args.size() < 1)
		throw MyException("wrong number of arguments in writefile block");
	ofstream out(*args.begin());
	if (!out)
		throw MyException("couldn't find name of file or open file with given name in writefile block", *args.begin());
	for (auto line : text)
		out << line << endl;
	return text;
}

BlockType WriteFile::getType()
{
	return BlockType::OUT;
}
