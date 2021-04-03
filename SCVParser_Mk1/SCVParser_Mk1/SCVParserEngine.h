#pragma once

#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include "DataConverter.h"
#include "LazyIterator.h"

// класс настроек
// с его помощью можно изменять символы разделителя и экранирования при чтении из файла
class csv_settings
{
public:
	// конструктор
	// поумолчанию:
	// разделитель: ','
	// символ экранирования: '"'
	csv_settings() :
		m_delimiter(','),
		m_new_line('\n'),
		m_escaping('"')
	{
	}
	// метод для установки другого символа разделителя
	bool set_delimiter(char n)
	{
		if (n == m_new_line || n == m_escaping)
			return false;

		m_delimiter = n;
		return true;
	}
	// метод для установки другого символа экранирования 
	bool set_escaping_symbol(char n)
	{
		if (n == m_delimiter || n == m_new_line)
			return false;

		m_escaping = n;
		return true;
	}
	// метод для получения символа разделителя
	char const delimiter() const
	{
		return m_delimiter;
	}
	// метод для получения символа экранирования
	char const escaping_symbol() const
	{
		return m_escaping;
	}
	// метод для получения символа перенова строки
	char const new_line_symbol() const
	{
		return m_new_line;
	}

private:
	char m_delimiter;// символ разделителя
	char m_new_line;// символ экранирования
	char m_escaping;// символ переноса строки
};

// класс csv парсера
// реализует ленивое чтение из файла, то есть чтение происходит лишь при запросе
template<typename... Args>
class csv_parser
{
public:
	// задаём итератор для того чтобы работать с файлом 
	using iterator = csv_parser_iterator<Args...>;
public:
	// консруктор принимает на вход:
	// file_obj - объект файла
	// num_skip_rows - количество строк которое необходимо пропустить 
	// settings - объект настройки
	csv_parser(std::ifstream& file_obj, int64_t num_skip_rows, csv_settings settings = csv_settings()) :
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
			in.ignore(max_line, settings.new_line_symbol());
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
	csv_settings m_settings;// настройки
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