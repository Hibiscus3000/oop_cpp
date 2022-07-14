#include "util.h"

int main()
{
	ifstream in("input.txt");
	ofstream out("output.csv");
	if ((!in) || (!out))
	{
		cout << "couldn't open file" << endl;
		return 1;
	}
	int numOfWords = 0;
	WordCount wordCount;
	wordCount.readFile(in);
	wordCount.writeFile(out);
	util::cleanUp(in, out);
	return 0;
}