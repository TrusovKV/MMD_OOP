#pragma once
#pragma once
#include <string>
#include <map>
#include <vector>

using namespace std;

class myArchivator
{
private:

	string name;
	string ad;

	multimap<int, int> sortedWeight;
	int weight[0x100];

	struct Node
	{
		char ch;
		int parent;
		int zero;
		int one;
		bool branch;
	};

	vector<Node> tree;
	vector<bool> data;
	map<char, int> charMap;

public:
	myArchivator(string adres, string final_name) : ad(adres), name(final_name) {};

	// Packing //
	void readTxt();

	void BuildTree();

	void HaffmansCode();

	void writeToTxt();

	// Unpacking //
	void GetInfo();

	void UnPack();

};