#pragma once
#include <type_traits>
#include<iostream>
using namespace std;

template<class T>
bool close_enough(T a, T b)
{
	T constant = 0.0001;
	if (is_same<T, int>::value || is_same<T, unsigned int>::value) 
	{
		if (a == b)
			cout << "equal" << endl;
		else
			cout << "not equal" << endl;
		return 0;

	}
	if (is_floating_point<T>::value)
	{
		double residual = a - b;
		return (residual >= constant);
	}
	else {
		cout << "crash" << endl;
	}
}
