#include "pch.h"



int main(int argc, char** argv)
{
	//integrate1d<N, a, b > <=> integrate from 0 to [N +1]*a/b
	const double f5 = integrate1d<10, 1, 1 >::integ1d();
	cout << f5 << endl;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
