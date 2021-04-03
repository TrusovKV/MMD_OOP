#pragma once

#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include "DataConverter.h"
#include "LazyIterator.h"


template<typename... Args>
class csv_parser
{
public:

	using iterator = csv_parser_iterator<Args...>;

	csv_parser(std::ifstream& file_obj, int64_t num_skip_rows, SCVCustomizer settings = SCVCustomizer()) :
		in(file_obj),
		m_settings(settings)
	{
		if (!file_obj)
			throw std::runtime_error("File not open");

		std::string buff;
		for (; num_skip_rows > 0; --num_skip_rows)
		{
			static const int max_line = 65536;
			in.ignore(max_line, settings.tellNewLineSymb());
		}
	}

	~csv_parser()
	{
		in.close();
	}

	iterator begin()
	{
		in.seekg(in.beg);
		return iterator(in, m_settings);
	}

	iterator end()
	{
		return iterator(in, m_settings, true);
	}

	void reset()
	{
		in.seekg(in.beg);
	}

private:
	std::ifstream& in;
	SCVCustomizer m_settings;
};

template <size_t n, typename... T>
typename std::enable_if<(n >= sizeof...(T))>::type
print_tuple(std::ostream&, const std::tuple<T...>&)
{}

template <size_t n, typename... T>
typename std::enable_if<(n < sizeof...(T))>::type
	print_tuple(std::ostream& os, const std::tuple<T...>& tup)
{
	if (n != 0)
		os << " ";

	os << std::get<n>(tup);
	print_tuple<n + 1>(os, tup);
}

template <typename... T>
std::ostream& operator<<(std::ostream& os, const std::tuple<T...>& tup)
{
	print_tuple<0>(os, tup);
	return os;
}