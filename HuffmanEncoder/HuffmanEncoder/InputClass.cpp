#include "Classes.h"



Input_class::Input_class() : ss(""), counter(0), is("D:\\GitHub\\MMD_OOP\\HuffmanEncoder\\test.txt")
{};
void Input_class::printMap()
{
	for (auto elem : Leter_Stack)
	{
		std::cout << elem.first << " " << elem.second << "\n";
	}
};

void Input_class::buildBase()
{
	while (!is.eof())

	{
		ss.push_back(is.get());
		Leter_Stack.insert(make_pair(ss, counter)); // Important!!
		Leter_Stack[ss]++;
		ss.erase();
	}
}

void Input_class::insertBase()
{
	for (auto& elem : Leter_Stack)
	{
		vec.push_back(make_pair(elem.second, elem.first));
	}
}

void Input_class::sortVecOfPairs()
{
	sort(vec.begin(), vec.end(), cmp());
	//for (auto& elem : vec)
	//{
	//	std::cout << elem.first << " " << elem.second << "\n";
	//}
}

//pair<int, string> Input_class::getMins()
//{
//	return make_pair(vec[0].first + vec[1].first, vec[0].second + vec[1].second);
//}
//
//void Input_class::eraseMins()
//{
//	vec.erase(vec.begin(), vec.begin() + 2);
//}
//
//void Input_class::insertNode(pair<int, string> mins)
//{
//	vec.push_back(mins);
//}

char Input_class::tellChar(int pos)
{
	return vec.at(pos).second.at(0);
}

int Input_class::tellWeight(int pos)
{
	return vec.at(pos).first;
}

int Input_class::tellSize()
{
	return vec.size();
}