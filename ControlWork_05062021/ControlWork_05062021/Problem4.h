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

//The same foe two elems

template <class T, class Op>
auto reduce1(T f, Op t1, Op t2)
{
	return f(t1, t2);
}

template <typename T, class Op, class... Args>
auto reduce1(T g, Op t1, Op t2, Args... arg)
{
	return g(t1, t2) + reduce1(g, arg...) ;
}

