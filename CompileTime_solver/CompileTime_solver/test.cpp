#include "pch.h"

template <typename X> /*static const*/ double functon( /*static const*/ double x)
{
	return 0.3 * x * x + 2.0 * x - 1.0;
}
TEST(check_polynom, check_polynom) {
	EXPECT_EQ(1.3, functon<double>(1.0));
}


int main(int argc, char** argv)
{
	int aff = 5*5;
	//___________________________________________________________________
	 CompileTimeSolver<int> a(0, 10, 300), c(0, 10, 300, velosityProfile);
	 Output<double> b;
	 b.getArg(a.Integrate(velosityProfile));
	 b.getDyntArg(c.tellSum());
	 b.show();
	 b.showDyn();
	 cout<< "hh"<<endl;
	 testing::InitGoogleTest(&argc, argv);
	 return RUN_ALL_TESTS();
}
