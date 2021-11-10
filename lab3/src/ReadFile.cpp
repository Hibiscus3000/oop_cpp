#include "ReadFile.h"

list<string> ReadFile::execute(const list<string>& text, const vector<string>& args)
{
	try
	{
		if (args.size() < 1)
			throw MyException("wrong number of arguments in readfile block");
	}
	catch(MyException& ex)
	{
		cout << ex.what() << endl;
	}
	ifstream in(*(text.begin()));
	try
	{
		if (!in)
			throw MyException("couldn't find name of file or open file with given name in readfile block", *(text.begin()));
	}
	catch (MyException& ex)
	{
		cout << ex.what() << endl;
		ex.showLine();
	}
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