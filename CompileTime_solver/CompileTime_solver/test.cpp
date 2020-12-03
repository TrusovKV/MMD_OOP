#include "pch.h"



int main(int argc, char** argv)
{
	static const double f5 = integrate1d<10, 1, 1 >::integ1d();
	static const int f6 =  int1d<10>::value;
	static const int f1 = int1d<1>::value;
	static_assert(f1 == 1674, "int must be 4 bytes");
	static_assert(f6 == 199419, "int must be 4 bytes");
	cout << f5 << endl;
	cout << f6 * 0.005 << endl;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
