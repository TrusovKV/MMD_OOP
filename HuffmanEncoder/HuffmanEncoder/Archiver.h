#pragma once
#include "Node.h"
class Archivator
{
public:
	Archivator() :inputPath("input.txt"), outputPath("output.bin"), rearchPath("rearch.txt") {}

	~Archivator() {
		delete root;
	}

	Archivator(const Archivator& el)
	{
		root = new Node;
		*root = *el.root;

		inputPath = el.inputPath;
		outputPath = el.outputPath;
		rearchPath = el.rearchPath;

		code = el.code;
		table = el.table;
	}

	Archivator& operator=(const Archivator& item)
	{
		if (&item == this)
			return *this;

		delete root;

		root = new Node;
		*root = *item.root;

		inputPath = item.inputPath;
		outputPath = item.outputPath;
		rearchPath = item.rearchPath;

		code = item.code;
		table = item.table;

		return *this;
	}

	Archivator(Archivator&& item)
		: root(item.root)
	{
		item.root = nullptr;

		inputPath = item.inputPath;
		outputPath = item.outputPath;
		rearchPath = item.rearchPath;

		code =item.code;
		table = item.table;
		//_______\\
		||        ||
		item.inputPath.clear();
		item.outputPath.clear();
		item.rearchPath.clear();
		item.code.clear();
		item.table.clear();
	}

	Archivator& operator=(Archivator&& item)
	{
		if (&item == this)
			return *this;
		delete root;

		root = item.root;
		item.root = nullptr;

		inputPath =  item.inputPath;
		outputPath = item.outputPath;
		rearchPath = item.rearchPath;

		code =  item.code;
		table = item.table;

		item.inputPath.clear();
		item.outputPath.clear();
		item.rearchPath.clear();
		item.code.clear();
		item.table.clear();

		return *this;
	}

	void archive() {
		ifstream f(inputPath, ios::in | ios::binary);
		ofstream g(outputPath, ios::out | ios::binary);

		map<char, int> m;
		list<Node*> t;

		while (!f.eof())
		{
			char symb = f.get();
			m[symb]++;
		}

		for (map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
		{
			Node* p = new Node;
			p->symbol = itr->first;
			p->freq = itr->second;
			t.push_back(p);
			g << itr->first;
		}
		g << '\0';

		for (map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
		{
			g << itr->second << ' ';
		}

		while (t.size() != 1)
		{
			t.sort(Sorter());

			Node* leftBranch = t.front();
			t.pop_front();
			Node* rightBranch = t.front();
			t.pop_front();

			Node* mainBranch = new Node(leftBranch, rightBranch);
			t.push_back(mainBranch);

		}

		delete this->root;
		this->root = t.front();

		codeTable(this->root);

		f.clear();
		f.seekg(0);

		int count = 0;
		char buf = 0;
		while (!f.eof())
		{
			char symb = f.get();
			vector<bool> x = table[symb];
			for (int n = 0; n < x.size(); n++)
			{
				buf = buf | x[n] << (7 - count);
				count++;
				if (count == 8) {
					count = 0;
					g << buf;
					buf = 0;
				}
			}
		}

		f.close();
		g.close();
	}

	void reArchive() {
		ifstream f(outputPath, ios::in | ios::binary);

		map<char, int> m;
		int coutSymbol = 0;
		char symb = 'q';

		while (symb != '\0') {
			symb = f.get();
			if (symb != '\0') {
				m.insert(make_pair(symb, 0));
			}
		}

		for (map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
		{
			f >> coutSymbol;
			m[itr->first] = coutSymbol;
		}

		list<Node*> t;
		for (map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
		{
			Node* p = new Node;
			p->symbol = itr->first;
			p->freq = itr->second;
			t.push_back(p);
		}

		while (t.size() != 1)
		{
			t.sort(Sorter());

			Node* leftBranch = t.front();
			t.pop_front();
			Node* rightBranch = t.front();
			t.pop_front();

			Node* mainBranch = new Node(leftBranch, rightBranch);
			t.push_back(mainBranch);

		}

		delete this->root;
		this->root = t.front();

		codeTable(root);

		ofstream rearch(rearchPath, ios::out | ios::binary);

		Node* p = root;
		f.get();

		char byte;
		int count = 0;
		byte = f.get();
		while (!f.eof())
		{
			bool b = byte & (1 << (7 - count));
			if (b) {
				p = p->right;
			}
			else {
				p = p->left;
			}
			if (p->left == nullptr && p->right == nullptr) {
				rearch << p->symbol;
				p = root;
			}
			count++;
			if (count == 8) {
				count = 0;
				byte = f.get();
			}
		}

		f.close();
	}
private:
	string inputPath;
	string outputPath;
	string rearchPath;

	vector<bool> code;
	map<char, vector<bool>> table;
	Node* root;

	void codeTable(Node* root)
	{
		if (root->right != nullptr)
		{
			code.push_back(1);
			codeTable(root->right);
		}

		if (root->left != nullptr)
		{
			code.push_back(0);
			codeTable(root->left);
		}

		if (root->left == nullptr && root->right == nullptr) table[root->symbol] = code;

		if (code.size() > 0) {
			code.pop_back();
		}
	}
};