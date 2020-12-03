#include "pch.h"
#include "Classes.h"

Input_class::Input_class() : flag(0),  path( "d:\\GitHub\\MMD_OOP\\Huffman_Encoder\\Test.txt")
{}

map<string, int32_t > Input_class::putInMap()
{
	for (p = output.begin(); p < output.end(); p++) // vector insertion into map
	{
		Leter_Stack.insert(make_pair(testWord, counter)); // Important!!
		testWord = *p;
		Leter_Stack[testWord]++;
	}
	return Leter_Stack;
}