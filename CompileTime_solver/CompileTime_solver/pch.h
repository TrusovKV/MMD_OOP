#pragma once
#include <Windows.h>


#include "gtest/gtest.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <gtest/gtest.h>
#include <cstdint>

using namespace std;

template<unsigned N >
struct function {
	static const unsigned val = 24 + 50 * N + 233 * N * N - 2 * N * N * N; /*static_cast < const unsigned>(100 * (0.24 + 0.5 * N + 2.33 * N * N - 0.02 * N * N * N))*/;
};

TEST(checkFunc, checkFunc) {
	EXPECT_EQ(24, function<0>::val);
}

template<int64_t N >
struct partSum {
	static const int64_t val = function<N+1>::val + function<N>::val;
};
TEST(checkPS, checkPS) {
	EXPECT_EQ(329, partSum<0>::val);
}
template<int64_t N>
struct int1d {
	static const int64_t value = partSum<N>::val + int1d<N - 1>::value;
};
template<>
struct int1d<0> {
	static const int64_t value = partSum<0>::val;
};
TEST(checkU1dInt0, checkU1dInt0) {
	EXPECT_EQ(329, int1d<0>::value);
}

TEST(checkU1dInt, checkU1dInt) {
	EXPECT_EQ(1674, int1d<1>::value);
}

template<int64_t N, int8_t step, int8_t order>
struct integrate1d{
static const double /*int*/ integ1d() {
	return (step)*int1d<N>::value*( 0.005/(order) );
};
};
TEST(checkU1dInteg, checkU1dInteg) {
	EXPECT_EQ(837, static_cast <const unsigned> (100 * integrate1d<1, 1, 1>::integ1d()));
}

template<int64_t N>
struct intT1d {
static const int value = /*0.005**/(partSum<N>::val + int1d<N - 1>::value);
};

template<unsigned N>
struct integrate1d_1 {
	static const int ii = int1d<N>::value;
inline const static double val = ii * 0.005;
static_assert(val < 1000);
};

template<unsigned N>
constexpr double integrate1d_2() {
	return (int1d<N>::value )* 0.005;
};

template <unsigned N> 
class integralchik
{
public:
	static const int ii = int1d<N>::value;
	inline static const double val = ii * 0.005;

};


template<unsigned N >
struct func {
	inline static const double val = 0.24 + 0.5 * N + 2.33 * N * N - 0.02 * N * N * N;
};

template<int N>
struct summ
{
	inline static const double res = 0.5*(function<N>::val + summ<N - 1>::res);
};

template<>
struct summ<0>
{
	inline static const double res = 0.5* function<0>::val;
};