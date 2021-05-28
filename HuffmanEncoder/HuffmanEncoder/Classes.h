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
	char tellChar(int pos);
	int  tellWeight(int pos);
	int tellSize();
	//pair<int, string> getMins();
	//void eraseMins();
	//void insertNode(pair<int, string> mins);
};

class mapDivision
{
private:
	map<char, int> CharMap; // <symbol, place in the tree>
	map<int, int> WeghtMap; // <weight, place in the tree>
public:
	void insertMapChar(char ch, int pos);
	void insertMapWeight(int w, int pos);
	map<char, int> tellMapChar();
	map<int, int> tellWeghtMap();
	void eraseMapWeightBeg();
	void insertSortedWeight(pair<int, int> pair);
	int tellWeightMapSize();
};

class treeBuilder
{};

class node
{
private:
	char ch;
	int parent;
	int num1;
	int num2;
	bool branch;
public:
	node();
	node(int i);
	node(int a, int b);
	void setParent(int par);
	void setBranch(bool br);
};

class Hub
{
private:
	Input_class input;
	mapDivision mDiv;
	vector<node>* tree;
public:
	void buildMaps();
	void buildTree();
	//void keek()
	//{
	//	mDiv.insertSortedWeight(make_pair(3, 4));
	//}
};
