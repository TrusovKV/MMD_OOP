#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <string>;
using namespace std;

class Node
{
public:
	size_t freq;
	char symbol;
	Node* left, * right;

	Node() {
		left = right = nullptr;
	}

	~Node() {
		//	cout << "node destructor" << endl;
		delete left;
		delete right;
	}

	Node(const Node& item)
	{
		left = new Node;
		*left = *item.left;

		right = new Node;
		*right = *item.right;

		freq = item.freq;
		symbol = item.symbol;
	}

	Node& operator=(const Node& item)
	{
		if (&item == this)
			return *this;

		delete left;
		delete right;

		left = new Node;
		*left = *item.left;

		right = new Node;
		*right = *item.right;

		freq = item.freq;
		symbol = item.symbol;

		return *this;
	}

	Node(Node&& item)
		: left(item.left), right(item.left)
	{
		item.left = nullptr;
		item.right = nullptr;

		freq = move(item.freq);
		symbol = move(item.symbol);
	}

	Node& operator=(Node&& item)
	{
		if (&item == this)
			return *this;
		delete left;
		delete right;

		left = item.left;
		item.left = nullptr;

		right = item.right;
		item.right = nullptr;


		freq = move(item.freq);
		symbol = move(item.symbol);

		return *this;
	}

	Node(Node* const L, Node* const R)
	{
		left = L;
		right = R;
		freq = L->freq + R->freq;
	}
};

struct Sorter
{
	bool operator()(const Node* l, const Node* r) const {
		return l->freq < r->freq;
	}
};
