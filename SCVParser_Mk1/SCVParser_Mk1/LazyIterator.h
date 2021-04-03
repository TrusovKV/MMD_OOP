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
	std::ifstream& in;// объект файла
	uint64_t column_count = sizeof...(Args);// ожидаемое количество колонок, это количество полученных параметров шаблона
	int64_t current_row;//текущая строка
	SCVCustomizer & m_settings;//объект настроек
	std::tuple<Args...> buff;//объект с текущими прочитанными данными(одна строка)
		
	// метод чтения строки из файла
	std::tuple<Args...> row_parse();

	// вспомогательный метод для make_tuple_impl
	auto make_tuple_(std::vector<std::string> const& data);

	// метод для формирования tuple из набора данных в строковом виде
		template<typename T, std::size_t... I>
	auto make_tuple_impl(T const& data, std::index_sequence<I...>)
	{
		return std::make_tuple((Convert< Args >(data[I]))...);
	}
public:
	csv_parser_iterator(std::ifstream& file_obj, SCVCustomizer& settings, bool end = false);
	// оператор префиксного инкремента 
	csv_parser_iterator& operator++()
	{
		if (current_row == -1)
			throw std::runtime_error("End iterator not changing");
		// читаем следующую строку из файла 
		buff = row_parse();
		return *this;
	}
	// оператор постфиксного инкремента
	csv_parser_iterator& operator++(int)
	{
		if (current_row == -1)
			throw std::runtime_error("End iterator not changing");
		// читаем следующую строку из файла
		buff = row_parse();
	}
	// оператор разименования
	std::tuple<Args...>& operator*()
	{
		if (current_row == -1)
			throw std::runtime_error("Operator \"*\" not used for end iterator");
		// возвращаем текущие прочитанные данные
		return buff;
	}
	// оператор сравнения итераторов
	bool operator!=(csv_parser_iterator const& r);

	// опретор каста итератора к tuple
	operator std::tuple<Args...>& ()
	{
		return buff;
	}
};


# include "LazIterRealisation.h"
# endif