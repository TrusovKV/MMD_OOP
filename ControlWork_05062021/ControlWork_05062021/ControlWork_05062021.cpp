// ControlWork_05062021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"
using namespace std;
	double foo()
	{
		return 0;
	}
	int foo1()
	{
		return 0;
	}

int main()
{
	double gg = 4;
	//double foo();
	test<decltype(foo)> tt;
	auto func = multiply_functions(f1, f2);
	cout << func(f1, f2)<<endl;

	cout << "Testing function types" << endl << "____________"<<endl ; 
	cout << std::is_function<decltype(foo)>::value << endl<< "____________" << endl;
	tt.fo();
	double res = sum1(3.14, 5, 7.);
	cout << res << endl;

	auto lambdaPlus = [](int x, int y) {return x + y; };
	auto lambdaMinus = [](double x, int y) {return x - y; };

	//FunctionTraits(&foo1);

	cout << close_enough(1, 1) << endl;
	cout << "Previous_function" << endl;
	cout << reduce(lambdaMinus, 4, 1) << endl;
	cout << "Updated_function"<< endl; // Corrected, according to the needs
	cout << reduce1(lambdaMinus, 4, 1, 5, 6, 6, 6, 10, 0) << endl;

	cout << "_________TEST__________" << endl;
	//reduce2(f1);
	int a = 5;
	int* ptr = &a;
	cout << "______"<< endl << *ptr << endl;
	//Myshared_ptr d1(ptr);
	//Myshared_ptr d2 = d1;
	//d2 = d1;
	using Dog = int;
	//Myshared_ptr<Dog> d1 = Myshared_ptr(new Dog);
	//Myshared_ptr d2 = d1;
	//Myshared_ptr d3 = new Myshared_ptr(new Dog);

//	d2 = d3;

}

