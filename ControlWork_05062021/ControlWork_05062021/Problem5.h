#pragma once

double f1(int x, int y) {
	return x + y;
}

double f2(int x, int y) {
	return x * y;
}

template <class A, class B>
auto multiply_functions(A func1, B func2) {

	static auto func3 = [](A func1, B func2) {return func1(1, 2) * func2(1, 2); };

	return func3;
}

