#pragma once

#include "print_tuple.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

template <class Head, class ...Tail>
struct ToTupleConverter
{
	static auto convert(string& str, const string& separators)
	{
		istringstream istrstream(str);
		if (!istrstream)
			throw exception();
		Head t;
		istrstream >> t;
		istrstream >> str;
		str.erase(0, 1);
		auto tupleOfCurrentElement = make_tuple(t);
		auto tuple = tuple_cat(tupleOfCurrentElement, ToTupleConverter<Tail...>::convert(str, separators));
		return tuple;
	}
};

template<class ...Tail>
struct ToTupleConverter<string, Tail...>
{
	static auto convert(string& str, const string& separators)
	{
		int pos = str.find_first_of(separators);
		auto tupleOfCurrentElement = make_tuple(str.substr(0, pos));
		str.erase(0, pos + 1);
		auto tuple = tuple_cat(tupleOfCurrentElement, ToTupleConverter<Tail...>::convert(str, separators));
		return tuple;
	}
};

template <class Head>
struct ToTupleConverter<Head>
{
	static auto convert(string& str, const string& separators)
	{
		istringstream istrstream(str);
		if (!istrstream)
			throw exception();
		Head t;
		istrstream >> t;
		return make_tuple(t);
	}
};

template <>
struct ToTupleConverter<string>
{
	static auto convert(string& str, const string& separators)
	{
		return make_tuple(str.substr(0, str.find_first_of(separators)));
	}
};

template <class ...Args>
class CSVParser
{
public:
	list<tuple<Args...>> tupleList;
	CSVParser(ifstream& file, int skipLines, const string& separators)
	{
		string str;
		int i;
		tuple<Args...> t;
		for (i = 0; i < skipLines; ++i)
			getline(file, str);
		getline(file, str);
		while (!file.eof())
		{
			t = ToTupleConverter<Args...>::convert(str, separators);
			tupleList.push_back(t);
			getline(file, str);
		}
	}
};
