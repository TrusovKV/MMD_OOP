#pragma once
#include <iostream>
using namespace std;

template <class Op, class... Args>
auto reduce(Op f, Args... arg)
{
	return f(arg...);
}

template <class Op, class Args>
auto reduce(Op f, Args arg)
{
	return f(arg);
}