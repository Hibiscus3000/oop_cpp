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
	void cleanUp()
	{

	}
}