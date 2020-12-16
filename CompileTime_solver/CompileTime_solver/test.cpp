#include "pch.h"


static const double Add(int x, int y)
{ // Useless
	__asm
	{
		mov eax, x;
		mov ebx, y;
		add eax, ebx;
		mov x, eax;
	}
	return x;
}
//Constexpr polynom
constexpr double polynom(double N) {
	return 0.24 + 0.5 * N + 2.33 * N * N - 0.02 * N * N * N;
}

TEST(check_polynom, check_polynom) {
	EXPECT_EQ(24, static_cast<int>(100*polynom(0) ) );
}
// Constexpr Integration
constexpr double Integrate(double step, int32_t points_number, double (*function)(double x)) {
	double sum = 0;
	double current_point = 0;
	for (int i = 0; i < points_number; ++i) {
		double next_point = current_point + step;
		sum += (function(current_point) + function(next_point));
		current_point = next_point;
	}
	sum = 0.5 * sum * step;

	return sum;
}

TEST(Integration, Integration) {
	EXPECT_LT(997, Integrate( 1, 11, polynom));
	EXPECT_GT(998, Integrate(1,  11, polynom));
}


int main(int argc, char** argv)
{
	// Useless
	/*static*/ const int i = 0;
	_asm {
		mov i, 2333
	}

	//static_assert (i == 2333);
	static const double f5 =  integrate1d<10, 1, 1 >::integ1d();
	static const int f0 = intT1d<10>::value;

	static const double f11 = integrate1d_1<10>::val;
	//static_assert(f11 < 998);

	// Template-based calculations
	static const int f6 =  int1d<10>::value;

	static const int f1 = int1d<1>::value;
	static const int g = f6 * 0.005;//997.095;

	static const double H(997+ 0.095);
	cout << f0 << "   f11:   " << f11 << endl;
	static_assert(f0 == 199419/*997.095*/);
	static_assert(f1 == 1674, "int must be 4 bytes");
	static_assert(f6 == 199419, "int must be 4 bytes");
	
	// Successfull static assert
	static_assert(997.095 == f6*0.005);
	static_assert(997/*.095*/ == g);

	// Constexpr static assert

	constexpr auto integral = Integrate(1, 11, polynom);
	static_assert(997.095 == integral);

	cout << "integral = " << integral << endl;
	cout << g << " " << static_cast<int>(100*polynom(0)) << endl;

	cout << f5 << endl;
	cout << f6 * 0.005 << endl;

	static const double h = f6 * 0.005;//997.095;
	//static const double h1 = 44.6;

	//constexpr double h1 = integrate1d_2<10>();

	static const double testVar = 0.005;
	static const int ruut = 80000000;
	static const bool comp = testVar < ruut;

	static_assert(  comp);
	integralchik<10> h1;



	cout << h  << "cobra h1:  "<< h1 .val<< endl;


	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
