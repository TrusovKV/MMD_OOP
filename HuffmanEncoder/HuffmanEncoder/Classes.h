#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <Bits.h>

using namespace std;
class Input_class
{
private:
	string path;// = "D:\\GitHub\\MMD_OOP\\HuffmanEncoder\\test.txt";
	string ss;
	int counter;// = 0;
	ifstream is;// (path);

	map<string, int > Leter_Stack;
	map<string, int >::iterator LSp;
	vector<pair<int, string>> vec;

	struct cmp
	{
		bool operator()(pair<int, string> const& a, pair<int, string> const& b)
		{
			return a.first < b.first;
		}
	};

public:
	Input_class();
	void buildBase();
	void printMap();
	void insertBase();
	void sortVecOfPairs();
	pair<int, string> getMins();
	void eraseMins();
	void insertNode(pair<int, string> mins);
};

class Node
{
private:
	bool isNode;
	int number;
	pair<string, string> node;
	//unique_ptr< Left;

	//    int  , string
public:
	void getNumber(int & num)
	{
		number = num;
	}
	int tellNumber()
	{
		return number;
	}
	bool tellIsNode()
	{
		return isNode;
	}
	void addNum(int & num)
	{
		node.first.push_back(num);
	}
};

class TreeBuilder
{
private:
	Input_class inp;
public:

	void makeBase()
	{
		inp.buildBase();
		inp.insertBase();
	}

	void buildTree();

};