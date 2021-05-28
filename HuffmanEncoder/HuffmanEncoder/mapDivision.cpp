#include "Classes.h"

void mapDivision::insertMapChar(char ch, int pos)
{
	CharMap.insert(make_pair(ch, pos));
};

void mapDivision::insertMapWeight(int w, int pos)
{
	WeghtMap.insert(make_pair(w, pos));
};

map<char, int> mapDivision::tellMapChar()
{
	return CharMap;
}

map<int, int> mapDivision::tellWeghtMap()
{
	return WeghtMap;
}

void mapDivision::eraseMapWeightBeg()
{
	WeghtMap.erase(WeghtMap.begin());
}

void mapDivision::insertSortedWeight(pair<int, int> pair)
{
	WeghtMap.insert(pair);
}

int mapDivision::tellWeightMapSize()
{
	return WeghtMap.size();
}