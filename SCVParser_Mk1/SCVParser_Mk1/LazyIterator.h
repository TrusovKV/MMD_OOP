#pragma once
# ifndef LazIter_H
# define LazIter_H
#include <tuple>
#include <fstream>
#include "DataConverter.h"
#include "SCVCustomizer.h"
template<typename...Args>
class csv_parser_iterator
{
private:
	std::ifstream& in;
	uint64_t column_count = sizeof...(Args);
	int64_t current_row;
	SCVCustomizer & m_settings;
	std::tuple<Args...> buff;//row
		

	std::tuple<Args...> row_parse();

	auto make_tuple_(std::vector<std::string> const& data);

		template<typename T, std::size_t... I>
	auto make_tuple_impl(T const& data, std::index_sequence<I...>)
	{
		return std::make_tuple((Convert< Args >(data[I]))...);
	}
public:
	csv_parser_iterator(std::ifstream& file_obj, SCVCustomizer& settings, bool end = false);

	csv_parser_iterator& operator++()
	{
		if (current_row == -1)
			throw std::runtime_error("End iterator not changing");
		buff = row_parse();
		return *this;
	}

	csv_parser_iterator& operator++(int)
	{
		if (current_row == -1)
			throw std::runtime_error("End iterator not changing");
		buff = row_parse();
	}
 
	std::tuple<Args...>& operator*()
	{
		if (current_row == -1)
			throw std::runtime_error("Operator \"*\" not used for end iterator");
		return buff;
	}

	bool operator!=(csv_parser_iterator const& r);

	operator std::tuple<Args...>& ()
	{
		return buff; // cust it to tuple
	}
};


# include "LazIterRealisation.h"
# endif