#include "util.h"

namespace util
{
	char numOfArgCheck(int n)
	{
		if (n != 3)
		{
			cout << "wrong number of arguments" << endl;
			return 1;
		}
		return 0;
	}
	void cleanUp(ifstream& in, ofstream& out)
	{
		if (in)
			in.close();
		if (out)
			out.close();
	}
}