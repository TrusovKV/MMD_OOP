﻿// ControlWork_05062021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"
using namespace std;

int main()
{

	auto func = multiply_functions(f1, f2);
	cout << func(f1, f2)<<endl;

	double res = sum1(3.14, 5, 7.);
	cout << res << endl;

	auto lambdaPlus = [](int x, int y) {return x + y; };
	auto lambdaMinus = [](double x, int y) {return x - y; };

	cout << reduce(lambdaMinus, 4, 1) << endl;

	cout << close_enough(1, 1) << endl;
}
