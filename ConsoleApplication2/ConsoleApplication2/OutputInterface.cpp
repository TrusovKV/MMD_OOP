#include "Header.h"

OutputInterface::OutputInterface() : S{ 0,0 }
{}

OutputInterface::~OutputInterface()
{}

OutputInterface::OutputInterface(InputInterface& SS)
{
	S.sizeX = SS.tellSizes().sizeX;
	S.sizeY = SS.tellSizes().sizeY;
}

void OutputInterface::getSizes(InputInterface& SS)
{
	S.sizeX = SS.tellSizes().sizeX;
	S.sizeY = SS.tellSizes().sizeY;
}

void OutputInterface::Output(Cell** mesh)
{
	for (int i = 0; i < S.sizeX; ++i) {
		for (int j = 0; j < S.sizeY; ++j) {
			cout << mesh[i][j].telleState();
		}
		cout << endl;
	}

}