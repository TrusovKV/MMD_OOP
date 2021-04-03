#pragma once

#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include "DataConverter.h"
#include "LazyIterator.h"


// класс csv парсера
// реализует ленивое чтение из файла, то есть чтение происходит лишь при запросе
template<typename... Args>
class csv_parser
{
public:
	// задаём итератор для того чтобы работать с файлом 
	using iterator = csv_parser_iterator<Args...>;
	// консруктор принимает на вход:
	// file_obj - объект файла
	// num_skip_rows - количество строк которое необходимо пропустить 
	// settings - объект настройки
	csv_parser(std::ifstream& file_obj, int64_t num_skip_rows, SCVCustomizer settings = SCVCustomizer()) :
		in(file_obj),
		m_settings(settings)
	{
		// проверяем открыт ли файл
		if (!file_obj)
			throw std::runtime_error("File not open");// если нет, то выбросим исключение

		// пропустим то количество строк, которое было передано в конструстор
		std::string buff;
		for (; num_skip_rows > 0; --num_skip_rows)
		{
			static const int max_line = 65536;
			in.ignore(max_line, settings.tellNewLineSymb());
		}
	}
	// деструктор
	~csv_parser()
	{
		// закрываем файл
		in.close();
	}

	// метод возвращает итератор на начало
	iterator begin()
	{
		in.seekg(in.beg);
		return iterator(in, m_settings);
	}
	// метод возвращает итератор на конец
	iterator end()
	{
		return iterator(in, m_settings, true);
	}
	// вовращает позицию чтения в начало файла
	void reset()
	{
		in.seekg(in.beg);
	}

private:
	std::ifstream& in;// объект файла
	SCVCustomizer m_settings;// настройки
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