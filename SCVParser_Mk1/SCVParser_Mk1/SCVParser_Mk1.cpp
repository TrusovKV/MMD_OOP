#pragma once
#include <iostream>
#include "SCVParserEngine.h"

using namespace std;

int main()
{
    ifstream file_obj("D:\\GitHub\\MMD_OOP\\SCVParser_Mk1\\SCVParser_Mk1\\test.txt");
   // file_obj = ;
    csv_parser<int, string, double> sp( file_obj, 0, SCVCustomizer());
}

