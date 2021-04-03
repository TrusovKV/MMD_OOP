#pragma once
#include "LazyIterator.h"

template<typename...Args>
std::tuple<Args...> csv_parser_iterator< Args...>::row_parse()

{
	if (in.eof())
	{
		current_row = -1;
		return std::tuple<Args...>();
	}

	std::vector<std::string> data;
	std::stringstream ss;
	uint64_t column = 1;
	try
	{
		while (!in.eof())
		{
			char c = in.get();
			if (c == m_settings.delimiter())
			{
				data.push_back(ss.str());
				ss.str("");
				++column;
			}
			else if (c == m_settings.new_line_symbol())
			{

				data.push_back(ss.str());
				++current_row;
				if (data.size() == column_count)
					return make_tuple_(data);
				else
					throw std::runtime_error("Read data count not equal column count");
			}

			else if (c == m_settings.escaping_symbol())
			{
				bool close = false;
				while (!in.eof())
				{
					c = in.get();
					if (c == m_settings.escaping_symbol())
						if (in.peek() != m_settings.escaping_symbol())
						{
							close = true;
							break;
						}
						else
							in.ignore(1);

					ss << c;
				}
				if (close == false)
					throw std::runtime_error("Open symbol '\"' found, but not found closing symbol '\"'");
			}
			else
			{
				ss << c;
			}
		}
		data.push_back(ss.str());
		++current_row;
		if (data.size() == column_count)
			return make_tuple_(data);
		else
			throw std::runtime_error("read data count not equal column count");
	}
	catch (std::runtime_error const& e)
	{
		throw std::runtime_error(std::string(e.what()) + ": row " + std::to_string(current_row) + ", column " + std::to_string(column));
	}
	catch (...)
	{
		throw std::runtime_error("UNdefine error: row " + std::to_string(current_row) + ", column " + std::to_string(column));
	}

	return std::tuple<Args...>();
}

template<typename...Args>
auto csv_parser_iterator< Args...>::make_tuple_(std::vector<std::string> const& data)
{
	return make_tuple_impl(data, std::make_index_sequence<sizeof...(Args)>{});
}

template<typename...Args>
bool csv_parser_iterator< Args...>::operator!=(csv_parser_iterator const& r)
{
	// проверяем относятся ли итераторы к одному файлу
	if (&in != &(r.in))
		return true;
	// проверяем позицию в файле
	return current_row != r.current_row;
}

