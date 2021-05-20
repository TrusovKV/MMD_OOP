// HuffmanEncoder.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Classes.h"

using namespace std;



int main()
{
	Input_class inp;

	inp.buildBase();
	inp.printMap();
	inp.insertBase();
	cout << endl;
	inp.sortVecOfPairs();
	cout << endl;
	inp.insertNode(inp.getMins());
	inp.eraseMins();
	inp.sortVecOfPairs();

}

