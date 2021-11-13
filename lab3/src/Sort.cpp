#include "Sort.h"

bool compare(string str1, string str2)
{
	int i = 0,length, length1 = str1.length(), length2 = str2.length();
	if (length1 > length2)
		length = length2;
	else
		length = length1;
	while (i != length)
	{
		if (str1[i] < str2[i])
			return true;
		if (str1[i] > str2[i])
			return false;
		++i;
	}
	if (length1 > length)
		return true;
	else
		return false;
}

list<string> Sort::execute(const list<string>& text)
{
	list<string> newText = text;
	newText.sort(compare);
	return newText;
}

BlockType Sort::getType()
{
	return BlockType::INOUT;
}
