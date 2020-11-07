
#include "Header.h"

int main ()
{
	InputInterface interIn;
	OutputInterface interOut;

	interIn.getFilePath("D://GitHub//MMD_OOP//ConsoleApplication2//ConsoleApplication2//Input.txt");

	interIn.getSizes();

	GameEngine a( interIn );

	interIn.initStates(a.sendRef(), a.sendRef1());
	interOut.getSizes(interIn);

	a.Engine( interOut );

	return 0;
}