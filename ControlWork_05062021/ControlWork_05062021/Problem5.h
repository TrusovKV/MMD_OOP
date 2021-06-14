#pragma once
#include <type_traits>
//templates

template<typename F> struct FunctionTraits;

template<typename R, typename... Args>
struct FunctionTraitsBase
{
	using RetType = R;
	using ArgTypes = std::tuple<Args...>;
	static constexpr std::size_t ArgCount = sizeof...(Args);
};

template<typename R, typename... Args>
struct FunctionTraits<R(*)(Args...)>
{
	using base = FunctionTraitsBase<R, Args...>;
	using Pointer = R(*)(Args...);
	using RetType = R;
	using ArgTypes = std::tuple<Args...>;
	static constexpr std::size_t ArgCount = sizeof...(Args);
	template<std::size_t N>
	using NthArg = std::tuple_element_t<N, ArgTypes>;
	using FirstArg = NthArg<0>;
	using LastArg = NthArg<base::ArgCount - 1>;
};
template<typename R>
struct FunctionTraits<R(*)()>
{
	using Pointer = R(*)();
	using RetType = R;
	using ArgTypes = std::tuple<>;
	static constexpr std::size_t ArgCount = 0;
};




//test func
template<class T>
class test
{
private:
	static auto freqy()
	{};
public:
	void fo()
	{
		cout << std::is_function<T>::value<< endl;
	}
};


double f1(int x, int y) {
	return x + y;
}

double f2(int x, int y) {
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

