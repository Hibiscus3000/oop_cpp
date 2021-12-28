#include "include/csv_parser.h"
#include <list>

int main()
{
	ifstream file("in.csv");
	if (!file)
	{
		cerr << "couldn't open file" << endl;
		return 1;
	}
	string separators, shielding;
	cin >> separators >> shielding;
	try
	{
		CSVParser<double, string, string, double> parser(file, 0, separators, shielding);
		for (tuple<double, string, string, double> rs : parser)
		{
			cout << rs;
			cout << endl;
		}

	}
	catch (MyException& ex)
	{
		ex.errorReport();
		return 1;
	}

	catch (exception& ex)
	{
		cerr << ex.what();
		return 1;
	}
}
