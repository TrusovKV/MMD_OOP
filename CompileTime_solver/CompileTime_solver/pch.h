#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <gtest/gtest.h>
#include <cstdint>
using namespace std;

template<int64_t N >
struct function {
	static const int64_t val = static_cast <const unsigned>(100 * (0.24 + 0.5 * N + 2.33 * N * N - 0.02 * N * N * N));
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
static const double integ1d() {
	return 0.005*int1d<N>::value*( static_cast <const double>(step)/static_cast <const double>(order) );
};
};
TEST(checkU1dInteg, checkU1dInteg) {
	EXPECT_EQ(837, static_cast <const unsigned> (100 * integrate1d<1, 1, 1>::integ1d()));
}

