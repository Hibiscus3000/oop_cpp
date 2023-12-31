#pragma once

#include "print_tuple.h"
#include "MyException.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

template <size_t N, class Head, class ...Tail>
struct ToTupleConverter
{
	static auto convert(string& str, const string& separators, const string& shielding, int line)
	{
		Head t;
		if (str.empty())
			throw NoExpectedData(N, line, typeid(t).name());
		istringstream istrstream(str);
		istrstream >> t;
		istrstream >> str;
		str.erase(0, 1);
		auto tupleOfCurrentElement = make_tuple(t);
		auto tuple = tuple_cat(tupleOfCurrentElement, ToTupleConverter<N + 1, Tail...>::convert(str, separators, shielding, line));
		return tuple;
	}
};

template<size_t N, class ...Tail>
struct ToTupleConverter<N, string, Tail...>
{
	static auto convert(string& str, const string& separators, const string& shielding, int line)
	{
		if (str.empty())
			throw NoExpectedData(N, line, "string");
		int pos = str.find_first_of(separators);
		while ((pos > 0) && (shielding.find_first_of(str[pos + 1]) != string::npos) && (str[pos - 1] == str[pos + 1]))
		{
			str.erase(pos + 1, 1);
			str.erase(pos - 1, 1);
			pos = str.find_first_of(separators, pos);
		}
		if (string::npos == pos)
			pos = str.length();
		auto tupleOfCurrentElement = make_tuple(str.substr(0, pos));
		str.erase(0, pos + 1);
		auto tuple = tuple_cat(tupleOfCurrentElement, ToTupleConverter<N + 1, Tail...>::convert(str, separators, shielding, line));
		return tuple;
	}
};

void ExtraDataCheck(string& str, int column, int line, const string& separators)
{
	int nextSeparatorInd = str.find_first_of(separators);
	if (string::npos != nextSeparatorInd)
		throw ExtraData(column, line, str.substr(nextSeparatorInd + 1));
}

template <size_t N, class Head>
struct ToTupleConverter<N, Head>
{
	static auto convert(string& str, const string& separators, const string& shielding, int line)
	{
		Head t;
		if (str.empty())
			throw NoExpectedData(N, line, typeid(t).name());
		istringstream istrstream(str);
		istrstream >> t;
		ExtraDataCheck(str, N + 1, line, separators);
		return make_tuple(t);
	}
};

template <size_t N>
struct ToTupleConverter<N, string>
{
	static auto convert(string& str, const string& separators, const string& shielding, int line)
	{
		if (str.empty())
			throw NoExcpectedData(N, line, "string");
		ExtraDataCheck(str, N + 1, line, separators);
		return make_tuple(str);
	}
};

template <class ...Args>
class CSVParser
{
	ifstream* file;
	string separators;
	string shielding;
	int skipLines;

	class Iterator : public iterator<input_iterator_tag, tuple<Args...>>
	{
		ifstream* file = NULL;
		streampos offset;
		string separators;
		string shielding;
		tuple<Args...> currentTuple;
		int line = 0;
		bool endFileFlag = false;

	public:

		Iterator(bool endFileFlag) : endFileFlag(endFileFlag) {}

		Iterator(ifstream* file, const string& separators, const string& shielding, int skipLines)
			: file(file), separators(separators), shielding(shielding)
		{
			file->seekg(0,ios::beg);
			string str;
			getline(*file, str);
			int i;
			for (i = 1; i < skipLines; ++i)
			{
				if (file->eof())
				{
					endFileFlag = true;
					return;
				}
				getline(*file, str);
			}
			line = skipLines + 1;
			currentTuple = ToTupleConverter<1, Args...>::convert(str, separators, shielding, line);
			offset = file->tellg();
		}

		Iterator& operator++()
		{
			file->seekg(offset,ios::beg);
			string str;
			getline(*file, str);
			++line;
			if (file->eof())
				endFileFlag = true;
			else
				currentTuple = ToTupleConverter<0, Args...>::convert(str, separators, shielding, line);
			offset = file->tellg();
			return *this;
		}

		Iterator operator++(int)
		{
			file->seekg(offset, ios::beg);
			Iterator previousIt = *this;
			string str;
			getline(*file, str);
			++line;
			if (file->eof())
				endFileFlag = true;
			else
				currentTuple = ToTupleConverter<0, Args...>::convert(str, separators, shielding, line);
			offset = file->tellg();
			return previousIt;
		}

		bool operator==(const Iterator& it) const
		{
			if ((this->endFileFlag) && (it.endFileFlag))
				return true;
			if (this->line == it.line)
				return true;
			return false;
		}

		bool operator!=(const Iterator& it) const
		{
			return !(*this == it);
		}

		tuple<Args...>& operator*()
		{
			if (endFileFlag)
				throw exception("cannot dereference end CSV iterator");
			return currentTuple;
		}

		tuple<Args...>* operator->() const
		{
			if (endFileFlag)
				throw exception("cannot dereference end CSV iterator");
			return &currentTuple;
		}
	};



public:
	CSVParser(ifstream& file, int skipLines, const string& separators, const string& shielding)
		: file(&file), skipLines(skipLines), separators(separators), shielding(shielding) {}

	Iterator begin()
	{
		return Iterator(file, separators, shielding, skipLines);
	}
	Iterator end()
	{
		return Iterator(true);
	}
};
