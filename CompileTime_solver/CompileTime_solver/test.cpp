#include "pch.h"


int main() 
{
	 CompileTimeSolver<int> a(0, 10, 300);
	 Output<double> b;
	 b.getConstArg(a.Integrate(velosityProfile));
	 b.show();

}
