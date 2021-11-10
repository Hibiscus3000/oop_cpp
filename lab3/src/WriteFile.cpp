#include "WriteFile.h"

list<string> WriteFile::execute(const list<string>& text, const vector<string>& args)
{
	try
	{
		if (args.size() < 1)
			throw MyException("wrong number of arguments in writefile block");
	}
	catch (MyException& ex)
	{
		cout << ex.what() << endl;
	}
	auto it = text.begin();
	ofstream out(*it);
	try
	{
		if (!out)
			throw MyException("couldn't find name of file or open file with given name in writefile block", *it);
	}
	catch (MyException& ex)
	{
		cout << ex.what() << endl;
		ex.showLine();
	}
	++it;
	auto listEndIt = text.end();
	while (it != listEndIt)
	{
		out << *it;
		++it;
	}
	return text;
}

BlockType WriteFile::getType()
{
	return BlockType::OUT;
}