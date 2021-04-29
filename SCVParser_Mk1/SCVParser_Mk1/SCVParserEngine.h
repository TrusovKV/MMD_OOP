#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include <iterator>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

template <typename T> T from_string(const string& str)
{
	stringstream inputString(str);
	T buf;
	inputString >> buf;
	return buf;
}

template <> string from_string(const string& str)
{
	return str;
}

template<size_t J = 0, typename func, typename... Args>
typename enable_if<J != sizeof... (Args)>::type
for_each(tuple<Args...>& tup, func function)
{
	function(get<J>(tup));
	for_each<J + 1, func, Args...>(tup, function);
}

template<size_t J = 0, typename func, typename... Args>
typename enable_if<J == sizeof... (Args)>::type
for_each(tuple<Args...>&, func)
{}

struct print 
{
	template<typename T>
	void operator()(const T& val)
	{
		cout << val << " "; 
	}
};

template <typename... Args>
class parserSCV
{
private:
	ifstream& stream;
	tuple<int, string> rowDat;

	int16_t item;
	int16_t curRow;
	string line;
	size_t pos;
	size_t endPos;
	bool printFlag;
public:


	parserSCV(ifstream& in) : stream(in), item(0), pos(0), endPos(0), line(" "), printFlag(0)
	{
		cout << "started" << endl;
	};

	void getElement()
	{
		getline(stream, line);
		if (line.length() > 0)
		{
			pos = line.find(";");
			get<0>(rowDat) = from_string<int>(line.substr(0, pos));
			item++;

			pos = line.find(";");

			pos = line.find('\"\"');
			endPos = line.find('\"\"', pos + 4);

			if (endPos != -1)
			{
				get<1>(rowDat) = from_string<string>(line.substr(pos + 3, endPos - 3 - 4)); // position , length
			}
			printFlag = 1;
		}
		else
			printFlag = 0;
	}

	void printForEach()
	{
		if(printFlag == 1)
		{
			for_each(rowDat, print());
			cout << " " << endl;
		}
	}

	void getAllElements()
	{
		while (!stream.eof())
		{
			getElement();
			printForEach();
		}
	}

};