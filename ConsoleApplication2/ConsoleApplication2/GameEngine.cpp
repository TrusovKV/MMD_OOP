#include "Header.h"

GameEngine::GameEngine() : mesh(nullptr), mesh1(nullptr), tmpAlive(0), time(0), numOfIter(0), S{ 0,0 }
{}

GameEngine::GameEngine(InputInterface& SS) :tmpAlive(0), time(0), numOfIter(0)
{
	// Initializing arrays with predefined sizes
	try
	{
		//Create Cell array #1
		S.sizeX = SS.tellSizes().sizeX;
		S.sizeY = SS.tellSizes().sizeY;
		numOfIter = SS.getIterationNumber();

		mesh = new Cell * [S.sizeX];
		for (int i = 0; i < S.sizeX; ++i) {
			mesh[i] = new Cell[S.sizeY];
		}
		//Create Cell array #2
		mesh1 = new Cell * [S.sizeX];
		for (int i = 0; i < S.sizeX; ++i) {
			mesh1[i] = new Cell[S.sizeY];
		}
	}
	catch (bad_alloc)
	{
		cout << "Bad alloc" << endl;
		return;
	}
}

void GameEngine::getSizes(sizes SS)
{
	this->S = SS;
}

Cell** GameEngine::sendRef()
{
	return this->mesh;
}

Cell** GameEngine::sendRef1()
{
	return this->mesh1;
}

void GameEngine::CreateCellArrays()
{
	//Create Cell array #1
	mesh = new Cell * [S.sizeX];
	for (int i = 0; i < S.sizeX; ++i) {
		mesh[i] = new Cell[S.sizeY];
	}
	mesh1 = new Cell * [S.sizeX];
	for (int i = 0; i < S.sizeX; ++i) {
		mesh1[i] = new Cell[S.sizeY];
	}
}

GameEngine::~GameEngine()
{
	// Free memory
	for (int i = 0; i < S.sizeX; ++i)
		delete[] mesh[i];
	delete[] mesh;

	for (int i = 0; i < S.sizeX; ++i)
		delete[] mesh1[i];
	delete[] mesh1;

}

void GameEngine::playGame(Cell** mesh, Cell** mesh1)
{
	for (int i = 0; i < S.sizeX; i++)
	{
		for (int j = 0; j < S.sizeY; j++)
		{
			// Top Left
			if (i == 0 && j == 0)
			{
				if (mesh[0][1].tellState() == true)
				{
					mesh1[0][0].inkrementAlive();
				}

				if (mesh[1][1].tellState() == true)
				{
					mesh1[0][0].inkrementAlive();
				}

				if (mesh[1][0].tellState() == true)
				{
					mesh1[0][0].inkrementAlive();
				}
			}
			// Top Right
			else if (i == 0 && j == S.sizeY - 1)
			{
				if (mesh[0][S.sizeY - 2].tellState() == true)
				{
					mesh1[0][S.sizeY - 1].inkrementAlive();
				}

				if (mesh[1][S.sizeY - 2].tellState() == true)
				{
					mesh1[0][S.sizeY - 1].inkrementAlive();
				}

				if (mesh[1][S.sizeY - 1].tellState() == true)
				{
					mesh1[0][S.sizeY - 1].inkrementAlive();
				}
			}
			// Bottom Right
			else if (i == S.sizeX - 1 && j == S.sizeY - 1)
			{
				if (mesh[S.sizeX - 1][S.sizeY - 2].tellState() == true)
				{
					mesh1[S.sizeX - 1][S.sizeY - 1].inkrementAlive();
				}

				if (mesh[S.sizeX - 2][S.sizeY - 2].tellState() == true)
				{
					mesh1[S.sizeX - 1][S.sizeY - 1].inkrementAlive();
				}

				if (mesh[S.sizeX - 2][S.sizeY - 1].tellState() == true)
				{
					mesh1[S.sizeX - 1][S.sizeY - 1].inkrementAlive();
				}
			}
			// Bottom Left
			else if (i == 0 && j == 0)
			{
				if (mesh[S.sizeX - 1][1].tellState() == true)
				{
					mesh1[S.sizeX - 1][0].inkrementAlive();
				}

				if (mesh[S.sizeX - 2][1].tellState() == true)
				{
					mesh1[S.sizeX - 1][0].inkrementAlive();
				}

				if (mesh[S.sizeX - 2][0].tellState() == true)
				{
					mesh1[S.sizeX - 1][0].inkrementAlive();
				}
			}
			// Top
			else if (i == 0)
			{
				if (mesh[0][j + 1].tellState() == true)
				{
					mesh1[0][j].inkrementAlive();
				}

				if (mesh[0][j - 1].tellState() == true)
				{
					mesh1[0][j].inkrementAlive();
				}

				if (mesh[1][j + 1].tellState() == true)
				{
					mesh1[0][j].inkrementAlive();
				}

				if (mesh[1][j - 1].tellState() == true)
				{
					mesh1[0][j].inkrementAlive();
				}

				if (mesh[1][j].tellState() == true)
				{
					mesh1[0][j].inkrementAlive();
				}
			}
			// Botom
			else if (i == S.sizeX - 1)
			{
				if (mesh[S.sizeX - 1][j + 1].tellState() == true)
				{
					mesh1[S.sizeX - 1][j].inkrementAlive();
				}

				if (mesh[S.sizeX - 1][j - 1].tellState() == true)
				{
					mesh1[S.sizeX - 1][j].inkrementAlive();
				}

				if (mesh[S.sizeX - 2][j + 1].tellState() == true)
				{
					mesh1[S.sizeX - 1][j].inkrementAlive();
				}

				if (mesh[S.sizeX - 2][j - 1].tellState() == true)
				{
					mesh1[S.sizeX - 1][j].inkrementAlive();
				}

				if (mesh[S.sizeX - 2][j].tellState() == true)
				{
					mesh1[S.sizeX - 1][j].inkrementAlive();
				}
			}
			// Left
			else if (j == 0)
			{
				if (mesh[i - 1][0].tellState() == true)
				{
					mesh1[i][0].inkrementAlive();
				}

				if (mesh[i + 1][0].tellState() == true)
				{
					mesh1[i][0].inkrementAlive();
				}

				if (mesh[i - 1][1].tellState() == true)
				{
					mesh1[i][0].inkrementAlive();
				}

				if (mesh[i + 1][1].tellState() == true)
				{
					mesh1[i][0].inkrementAlive();
				}

				if (mesh[i][1].tellState() == true)
				{
					mesh1[i][0].inkrementAlive();
				}
			}
			// Right
			else if (j == S.sizeY - 1)
			{
				if (mesh[i - 1][S.sizeY - 1].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}

				if (mesh[i + 1][S.sizeY - 1].tellState() == true)
				{
					mesh1[i][S.sizeY - 1].inkrementAlive();
				}

				if (mesh[i - 1][S.sizeY - 2].tellState() == true)
				{
					mesh1[i][S.sizeY - 1].inkrementAlive();
				}

				if (mesh[i + 1][S.sizeY - 2].tellState() == true)
				{
					mesh1[i][S.sizeY - 1].inkrementAlive();
				}

				if (mesh[i][S.sizeY - 2].tellState() == true)
				{
					mesh1[i][S.sizeY - 1].inkrementAlive();
				}
			}
			//Middle
			else {
				if (mesh[i][j - 1].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}

				if (mesh[i][j + 1].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}

				if (mesh[i - 1][j].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}

				if (mesh[i + 1][j].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}

				if (mesh[i + 1][j + 1].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}

				if (mesh[i - 1][j - 1].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}
				if (mesh[i - 1][j + 1].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}

				if (mesh[i + 1][j - 1].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}
			}

		}
	}

}

void GameEngine::Engine(OutputInterface& oI)
{
	while (1)
		// Time step game play
	{
		bool tmpAlive;
		if (numOfIter != 0 && time == numOfIter)
		{
			break;
		}

		if (time % 2 == 0)
		{
			playGame(mesh, mesh1);

			//Change state
			for (int i = 0; i < S.sizeX; ++i) {
				for (int j = 0; j < S.sizeY; ++j) {
					tmpAlive = mesh[i][j].tellState();
					mesh1[i][j].getState(tmpAlive);
					mesh1[i][j].changeState();
					mesh1[i][j].zero();
				}
			}
			if (numOfIter == 0) {
				// Output
				oI.Output(mesh1);
			}
		}
		else
		{
			playGame(mesh1, mesh);

			//Change state
			for (int i = 0; i < S.sizeX; ++i) {
				for (int j = 0; j < S.sizeY; ++j) {
					tmpAlive = mesh1[i][j].tellState();
					mesh[i][j].getState(tmpAlive);
					mesh[i][j].changeState();
					mesh[i][j].zero();
				}
			}
			if (numOfIter == 0) {
				// Output
				oI.Output(mesh);
			}
		}
		++time;
		if (numOfIter == 0) {
			cin.clear(); // clears cin error flags
			cin.ignore(10000, '\n');
			system("CLS");
		}
	}
	if (numOfIter != 0)
	{
		if (time % 2 == 0)// Output
		{
			oI.Output(mesh1);
		}
		else// Output
		{
			oI.Output(mesh);
		}

	}
}

GameEngine::sizes GameEngine::tellSises()
{
	return S;
}