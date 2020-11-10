#include "pch.h"


int main() 
{
	 CompileTimeSolver<int> a(0, 10, 300), c(0, 10, 300, velosityProfile);
	 Output<double> b;
	 b.getArg(a.Integrate(velosityProfile));
	 b.getDyntArg(c.tellSum());
	 b.show();
	 b.showDyn();
}
