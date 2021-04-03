#pragma once

#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include "DataConverter.h"
#include "LazyIterator.h"

// ����� ��������
// � ��� ������� ����� �������� ������� ����������� � ������������� ��� ������ �� �����
class csv_settings
{
public:
	// �����������
	// �����������:
	// �����������: ','
	// ������ �������������: '"'
	csv_settings() :
		m_delimiter(','),
		m_new_line('\n'),
		m_escaping('"')
	{
	}
	// ����� ��� ��������� ������� ������� �����������
	bool set_delimiter(char n)
	{
		if (n == m_new_line || n == m_escaping)
			return false;

		m_delimiter = n;
		return true;
	}
	// ����� ��� ��������� ������� ������� ������������� 
	bool set_escaping_symbol(char n)
	{
		if (n == m_delimiter || n == m_new_line)
			return false;

		m_escaping = n;
		return true;
	}
	// ����� ��� ��������� ������� �����������
	char const delimiter() const
	{
		return m_delimiter;
	}
	// ����� ��� ��������� ������� �������������
	char const escaping_symbol() const
	{
		return m_escaping;
	}
	// ����� ��� ��������� ������� �������� ������
	char const new_line_symbol() const
	{
		return m_new_line;
	}

private:
	char m_delimiter;// ������ �����������
	char m_new_line;// ������ �������������
	char m_escaping;// ������ �������� ������
};

// ����� csv �������
// ��������� ������� ������ �� �����, �� ���� ������ ���������� ���� ��� �������
template<typename... Args>
class csv_parser
{
public:
	// ����� �������� ��� ���� ����� �������� � ������ 
	using iterator = csv_parser_iterator<Args...>;
public:
	// ���������� ��������� �� ����:
	// file_obj - ������ �����
	// num_skip_rows - ���������� ����� ������� ���������� ���������� 
	// settings - ������ ���������
	csv_parser(std::ifstream& file_obj, int64_t num_skip_rows, csv_settings settings = csv_settings()) :
		in(file_obj),
		m_settings(settings)
	{
		// ��������� ������ �� ����
		if (!file_obj)
			throw std::runtime_error("File not open");// ���� ���, �� �������� ����������

		// ��������� �� ���������� �����, ������� ���� �������� � �����������
		std::string buff;
		for (; num_skip_rows > 0; --num_skip_rows)
		{
			static const int max_line = 65536;
			in.ignore(max_line, settings.new_line_symbol());
		}
	}
	// ����������
	~csv_parser()
	{
		// ��������� ����
		in.close();
	}

	// ����� ���������� �������� �� ������
	iterator begin()
	{
		in.seekg(in.beg);
		return iterator(in, m_settings);
	}
	// ����� ���������� �������� �� �����
	iterator end()
	{
		return iterator(in, m_settings, true);
	}
	// ��������� ������� ������ � ������ �����
	void reset()
	{
		in.seekg(in.beg);
	}

private:
	std::ifstream& in;// ������ �����
	csv_settings m_settings;// ���������
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