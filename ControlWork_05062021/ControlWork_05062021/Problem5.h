#pragma once
#include <type_traits>
//templates

template <class f1, class g1>
struct type_traits_;

template <class F1, class F2, class a, class b>
struct type_traits_<F1(*)(a, b), F2(*)(a, b)> {
	using T1 = a;
	using T2 = b;
};

template<class F1, class F2>
auto reduce2(F1 f1, F2 f2)
{
	return std::is_same
		<
		type_traits_<decltype(f1), decltype(f2)>::T1,
		type_traits_<decltype(f1), decltype(f2)>::T2
		>::value;
};


//test func
template<class T>
class test
{
private:

public:
	void fo()
	{
		cout << std::is_function<T>::value<< endl;
	}
};


constexpr double f1(int x, int y) {
	return x + y;
}

constexpr double f2(int x, int y) {
	return x * y;
}

// Testing, that fi are double and depends on int
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value>::type
toDo(T t)
{
	cout << "Yei!" << endl;
}


template <class A, class B>
auto multiply_functions(A func1, B func2) {

	static auto func3 = [](A func1, B func2) {return func1(1, 2) * func2(1, 2); };

	return func3;
}

