#pragma once
#include <iostream>
#include "SCVCustomizer.h"
#include "LazyIterator.h"

using namespace std;



class Engine
{
private:
	ifstream input;
	parserSCV<int, string> parser;
	SCVCustomizer cust;
public:
	Engine() : input("D:\\GitHub\\MMD_OOP\\SCVParser_Mk1\\test.csv"), parser(input)
	{};
	void start()
	{
		parser.getAllElements();
	}
};