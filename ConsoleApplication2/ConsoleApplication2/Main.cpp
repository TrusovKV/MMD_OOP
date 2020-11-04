
#include "Header.h"

int main ()
{
	InputInterface interIn;
	OutputInterface interOut;
	interIn.getFilePath("D://GitHub//MMD_OOP//ConsoleApplication2//ConsoleApplication2//Input.txt");
	try
	{
	GameEngine a(interIn.getSizes());

	interIn.initStates(a.sendRef(), a.sendRef1());

	a.Engine(interIn.getIterationNumber(), interOut);
	}
	catch(bad_alloc)
	{
		cout << "Bad alloc" << endl;
	}

	return 0;
}