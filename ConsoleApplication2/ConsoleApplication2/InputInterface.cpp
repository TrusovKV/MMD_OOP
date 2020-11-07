#include "Header.h"

InputInterface::InputInterface() : numOfIter{ 0 }, chTmp(' '), fp("C :\\ "), fPath("C :\\ "), S{ 0,0 }
{}

void InputInterface::getFilePath(string s)
{
	this->fPath = s;
}

void InputInterface::initStates(Cell** mesh, Cell** mesh1)
{
	for (int i = 0; i < S.sizeX; i++)
	{
		for (int j = 0; j < S.sizeY; j++)
		{
			fp >> chTmp;
			mesh[i][j].getState(chTmp);
			mesh1[i][j].getState(chTmp);
		}
	}
}

int InputInterface::getIterationNumber()
{
	cout << endl << "Enter the iteration number ";
	cin >> numOfIter;
	system("CLS");
	return numOfIter;
}

InputInterface::sizes InputInterface::tellSizes()
{
	return S;
}

InputInterface::sizes InputInterface::getSizes()
{
	fp.open(fPath);
	try {
		if (fp.is_open() == false)
		{
			throw  exception("File not opened");
		}
		else
		{
			for (int i = 0; i < 1; ++i)
			{
				fp >> S.sizeX;
				fp >> S.sizeY;

				if (fp.eof())
				{
					throw  exception("Too short file");
				}
			}

		}

	}// EOF try
	catch (exception& e)
	{
		cout << endl << e.what() << endl;
		exit;
	}//EOF catch
	return S;
}
