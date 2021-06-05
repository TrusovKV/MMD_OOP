#pragma once
#include <iostream>
using namespace std;

template <typename T>
auto sum(T t) {
	return t;
}
template <typename T, typename ...Args>
auto sum(T t, Args... args) {
	return t + sum1(args...);
}
template <typename... Args>
auto sum1(Args... arg) {
	return (arg + ...);
}