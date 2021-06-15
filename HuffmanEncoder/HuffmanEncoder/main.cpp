#include <iostream>
#include <string>
#include "Arch.h"

int main()
{
	std::string cod, in, out;
	std::cout << "enter: ";
	std::cin >> cod;
	std::cin >> in;
	std::cin >> out;

	Huff H(cod, in, out);
}