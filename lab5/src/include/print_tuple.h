#pragma once

#include <ostream>
#include <tuple>

using namespace std;

template<class Ch, class Tr, class Tuple, size_t N>
struct TuplePrinter
{
	static void print(basic_ostream<Ch, Tr>& out,const Tuple& tuple)
	{
		TuplePrinter<Ch, Tr, Tuple, N - 1>::print(out, tuple);
		out << ", " << get<N - 1>(tuple);
	}
};

template<class Ch, class Tr, class Tuple>
struct TuplePrinter<Ch,Tr,Tuple,1>
{
	static void print(basic_ostream<Ch, Tr>& out, const Tuple& tuple)
	{
		out << get<0>(tuple);
	}
};

template <class Ch, class Tr,class...Args>
void operator<<(basic_ostream<Ch,Tr>& out, const tuple<Args...>& tuple)
{
	out << '(';
	TuplePrinter<Ch,Tr,decltype(tuple), sizeof...(Args)>::print(out, tuple);
	out << ')';
}