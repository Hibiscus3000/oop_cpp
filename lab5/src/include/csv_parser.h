#pragma once

#include "print_tuple.h"
#include "MyException.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

template <size_t N,class Head, class ...Tail>
struct ToTupleConverter
{
	static auto convert(string& str, const string& separators, const string& shielding, int line)
	{
		Head t;
		if (str.empty())
			throw NoExcpectedData(N, line, typeid(t).name());
		istringstream istrstream(str);
		istrstream >> t;
		istrstream >> str;
		str.erase(0, 1);
		auto tupleOfCurrentElement = make_tuple(t);
		auto tuple = tuple_cat(tupleOfCurrentElement, ToTupleConverter<N + 1,Tail...>::convert(str, separators, shielding, line));
		return tuple;
	}
};

template<size_t N,class ...Tail>
struct ToTupleConverter<N,string, Tail...>
{
	static auto convert(string& str, const string& separators, const string& shielding, int line)
	{
		if (str.empty())
			throw NoExcpectedData(N, line, "string");
		int pos = str.find_first_of(separators);
		if (string::npos == pos)
			pos = str.length();
		while ((pos) && (shielding.find_first_of(str[pos + 1]) != string::npos) && (str[pos - 1] == str[pos + 1]))
		{
			str.erase(pos + 1, 1);
			str.erase(pos - 1, 1);
			pos = str.find_first_of(separators, pos);
		}
		if (string::npos == pos)
			pos = str.length();
		auto tupleOfCurrentElement = make_tuple(str.substr(0, pos));
		str.erase(0, pos + 1);
		auto tuple = tuple_cat(tupleOfCurrentElement, ToTupleConverter<N + 1,Tail...>::convert(str, separators,shielding,line));
		return tuple;
	}
};

template <size_t N,class Head>
struct ToTupleConverter<N,Head>
{
	static auto convert(string& str, const string& separators, const string& shielding, int line)
	{
		Head t;
		if (str.empty())
			throw NoExcpectedData(N, line, typeid(t).name());
		istringstream istrstream(str);
		istrstream >> t;
		int nextSeparatorInd = str.find_first_of(separators);
		if (string::npos != nextSeparatorInd)
			throw ExtraData(N + 1, line, str.substr(nextSeparatorInd + 1));
		return make_tuple(t);
	}
};

template <size_t N>
struct ToTupleConverter<N,string>
{
	static auto convert(string& str, const string& separators, const string& shielding, int line)
	{
		if (str.empty())
			NoExcpectedData(N, line, "string");
		int nextSeparatorInd = str.find_first_of(separators);
		if (nextSeparatorInd != string::npos)
			throw ExtraData(N + 1, line, str.substr(nextSeparatorInd + 1));
		return make_tuple(str);
	}
};

template <class ...Args>
class CSVParser
{
public:
	list<tuple<Args...>> tupleList;
	CSVParser(ifstream& file, int skipLines, const string& separators,const string& shielding)
	{
		string str;
		int i;
		tuple<Args...> t;
		for (i = 0; i < skipLines; ++i)
			getline(file, str);
		getline(file, str);
		while (!file.eof())
		{
			++i;
			t = ToTupleConverter<1,Args...>::convert(str, separators, shielding,i);
			tupleList.push_back(t);
			getline(file, str);
		}
	}
};
