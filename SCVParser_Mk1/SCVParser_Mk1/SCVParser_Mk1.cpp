#pragma once
#include <iostream>
#include "SCVParserEngine.h"

using namespace std;

int main()
{
    ifstream input("D:\\GitHub\\MMD_OOP\\SCVParser_Mk1\\test.csv");
    parserSCV<int, string> parser(input);

    //parser.getElement();
//    parser.printForEach();
    parser.getAllElements();

    return 0;
}

// "D:\\GitHub\\MMD_OOP\\SCVParser_Mk1\\test.csv"