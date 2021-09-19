#include "util.h"

int main(int argc, char ** argv)
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
	map<string,int> * freqCounter = freqCount(in, out);

	util::cleanUp();
	return 0;
}