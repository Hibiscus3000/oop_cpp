#pragma once

#include <fstream>
#include <tuple>

using namespace std;

template<class Tuple, size_t N>
struct TuplePrinter
{
	static void print(ofstream& out,const Tuple& tuple)
	{
		TuplePrinter<Tuple, N - 1>::print(out, tuple);
		out << ", " << get<N - 1>(tuple);
	}
};

template<class Tuple>
struct TuplePrinter<Tuple,1>
{
	static void print(ofstream& out, const Tuple& tuple)
	{
		out << get<0>(tuple);
	}
};

template <class...Args>
void operator<<(ofstream& out, const tuple<Args...>& tuple)
{
	out << '(';
	TuplePrinter<decltype(tuple), sizeof...(Args)>::print(out, tuple);
	out << ')';
}