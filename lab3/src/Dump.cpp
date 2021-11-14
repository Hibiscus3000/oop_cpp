#include "Dump.h"

list<string> Dump::execute(const list<string>& text)
{
	if (blockDiscription.args.size() < 1)
		throw MyException("wrong number of arguments in dump block");
	ofstream out(*blockDiscription.args.begin());
	for (auto line : text)
		out << line << endl;
	return text;
}

BlockType Dump::getType()
{
	static BlockType dumpType = BlockType::INOUT;
	return dumpType;
}
