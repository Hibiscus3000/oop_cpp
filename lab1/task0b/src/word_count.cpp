#include "util.h"

int main(int argc, char** argv)
{
	if (util::numOfArgCheck(argc))
		return 1;
	ifstream in(argv[1]);
	if (!in.is_open())
	{
		cout << "couldn't open file" << endl;
		return 1;
	}
	ofstream out(argv[2]);
	int numOfWords = 0, numOfDifWords = 0;
	map<string, int>* freqCounter = freqCount(in, out, &numOfWords, &numOfDifWords);
	multimap<int, string>* wordCounter = wordCountCreation(freqCounter);
	wordCountList(out, numOfWords, wordCounter);
	util::cleanUp(in,out,freqCounter,wordCounter);
	return 0;
}