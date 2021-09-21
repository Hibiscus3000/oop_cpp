#include "util.h"

int main(int argc, char** argv)
{
	if (util::numOfArgCheck(argc))
		return 1;
	ifstream in(argv[1]);
	ofstream out(argv[2]);
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