
#include "Header.h"

void playGame(Cell** mesh, int sizeX, int sizeY)
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			// Top Left
			if (i == 0 && j == 0)
			{
				if (mesh[0][1].tellState() == true)
				{
					mesh[0][0].inkrementAlive();
				}

				if (mesh[1][1].tellState() == true)
				{
					mesh[0][0].inkrementAlive();
				}

				if (mesh[1][0].tellState() == true)
				{
					mesh[0][0].inkrementAlive();
				}
			}
			// Top Right
			else if (i == 0 && j == sizeY - 1)
			{
				if (mesh[0][sizeY - 2].tellState() == true)
				{
					mesh[0][sizeY - 1].inkrementAlive();
				}

				if (mesh[1][sizeY - 2].tellState() == true)
				{
					mesh[0][sizeY - 1].inkrementAlive();
				}

				if (mesh[1][sizeY - 1].tellState() == true)
				{
					mesh[0][sizeY - 1].inkrementAlive();
				}
			}
			// Bottom Right
			else if (i == sizeX - 1 && j == sizeY - 1)
			{
				if (mesh[sizeX - 1][sizeY - 2].tellState() == true)
				{
					mesh[sizeX - 1][sizeY - 1].inkrementAlive();
				}

				if (mesh[sizeX - 2][sizeY - 2].tellState() == true)
				{
					mesh[sizeX - 1][sizeY - 1].inkrementAlive();
				}

				if (mesh[sizeX - 2][sizeY - 1].tellState() == true)
				{
					mesh[sizeX - 1][sizeY - 1].inkrementAlive();
				}
			}
			// Bottom Left
			else if (i == 0 && j == 0)
			{
				if (mesh[sizeX - 1][1].tellState() == true)
				{
					mesh[sizeX - 1][0].inkrementAlive();
				}

				if (mesh[sizeX - 2][1].tellState() == true)
				{
					mesh[sizeX - 1][0].inkrementAlive();
				}

				if (mesh[sizeX - 2][0].tellState() == true)
				{
					mesh[sizeX - 1][0].inkrementAlive();
				}
			}
			// Top
			else if (i == 0)
			{
				if (mesh[0][j + 1].tellState() == true)
				{
					mesh[0][j].inkrementAlive();
				}

				if (mesh[0][j - 1].tellState() == true)
				{
					mesh[0][j].inkrementAlive();
				}

				if (mesh[1][j + 1].tellState() == true)
				{
					mesh[0][j].inkrementAlive();
				}

				if (mesh[1][j - 1].tellState() == true)
				{
					mesh[0][j].inkrementAlive();
				}

				if (mesh[1][j].tellState() == true)
				{
					mesh[0][j].inkrementAlive();
				}
			}
			// Botom
			else if (i == sizeX - 1)
			{
				if (mesh[sizeX - 1][j + 1].tellState() == true)
				{
					mesh[sizeX - 1][j].inkrementAlive();
				}

				if (mesh[sizeX - 1][j - 1].tellState() == true)
				{
					mesh[sizeX - 1][j].inkrementAlive();
				}

				if (mesh[sizeX - 2][j + 1].tellState() == true)
				{
					mesh[sizeX - 1][j].inkrementAlive();
				}

				if (mesh[sizeX - 2][j - 1].tellState() == true)
				{
					mesh[sizeX - 1][j].inkrementAlive();
				}

				if (mesh[sizeX - 2][j].tellState() == true)
				{
					mesh[sizeX - 1][j].inkrementAlive();
				}
			}
			// Left
			else if (j == 0)
			{
				if (mesh[i - 1][0].tellState() == true)
				{
					mesh[i][0].inkrementAlive();
				}

				if (mesh[i + 1][0].tellState() == true)
				{
					mesh[i][0].inkrementAlive();
				}

				if (mesh[i - 1][1].tellState() == true)
				{
					mesh[i][0].inkrementAlive();
				}

				if (mesh[i + 1][1].tellState() == true)
				{
					mesh[i][0].inkrementAlive();
				}

				if (mesh[i][1].tellState() == true)
				{
					mesh[i][0].inkrementAlive();
				}
			}
			// Right
			else if (j == sizeY - 1)
			{
				if (mesh[i - 1][sizeY - 1].tellState() == true)
				{
					mesh[i][j].inkrementAlive();
				}

				if (mesh[i + 1][sizeY - 1].tellState() == true)
				{
					mesh[i][sizeY - 1].inkrementAlive();
				}

				if (mesh[i - 1][sizeY - 2].tellState() == true)
				{
					mesh[i][sizeY - 1].inkrementAlive();
				}

				if (mesh[i + 1][sizeY - 2].tellState() == true)
				{
					mesh[i][sizeY - 1].inkrementAlive();
				}

				if (mesh[i][sizeY - 2].tellState() == true)
				{
					mesh[i][sizeY - 1].inkrementAlive();
				}
			}
			//Middle
			else {
				if (mesh[i][j - 1].tellState() == true)
				{
					mesh[i][j].inkrementAlive();
				}

				if (mesh[i][j + 1].tellState() == true)
				{
					mesh[i][j].inkrementAlive();
				}

				if (mesh[i - 1][j].tellState() == true)
				{
					mesh[i][j].inkrementAlive();
				}

				if (mesh[i + 1][j].tellState() == true)
				{
					mesh[i][j].inkrementAlive();
				}

				if (mesh[i + 1][j + 1].tellState() == true)
				{
					mesh[i][j].inkrementAlive();
				}

				if (mesh[i - 1][j - 1].tellState() == true)
				{
					mesh[i][j].inkrementAlive();
				}
				if (mesh[i - 1][j + 1].tellState() == true)
				{
					mesh[i][j].inkrementAlive();
				}

				if (mesh[i + 1][j - 1].tellState() == true)
				{
					mesh[i][j].inkrementAlive();
				}
			}

		}
	}
};

void main()
{

	char chTmp;
	ifstream fp("Input.txt");
	int sizeX = 0;
	int sizeY = 0;
	fp >> sizeX;
	fp >> sizeY;
	char a;
	//cout << sizeX << "	" << sizeY << endl << endl;



	//Create Cell array
	Cell** mesh = new Cell* [sizeX];
	for (int i = 0; i < sizeX; ++i) {
		mesh[i] = new Cell[sizeY];
		for (int j = 0; j < sizeY; ++j) {
			mesh[i][j].getCoordinates(i,j);
		}
	}

	// Initialize states
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			fp >> chTmp;
			mesh[i][j].getState(chTmp);
		}
	}

	//for (int t = 0; t < 100; t++)
	int t = 1;
	int count = 0;
	while (t < 2)
		// Time step game play
	{
		//cout << "turn #" << count ++ << endl;
		playGame(mesh, sizeX, sizeY);



		// Count neighbours
	/*
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
			// Top Left
				if (i == 0 && j == 0)
				{
					if (mesh[0][1].tellState() == true)
					{mesh[0][0].inkrementAlive();}

					if (mesh[1][1].tellState() == true)
					{mesh[0][0].inkrementAlive();}

					if (mesh[1][0].tellState() == true)
					{mesh[0][0].inkrementAlive();}
				}
			// Top Right
				else if (i == 0 && j == sizeY - 1)
				{
					if (mesh[0][sizeY - 2].tellState() == true)
					{mesh[0][sizeY -1].inkrementAlive();}

					if (mesh[1][sizeY - 2].tellState() == true)
					{mesh[0][sizeY -1].inkrementAlive();}

					if (mesh[1][sizeY - 1].tellState() == true)
					{mesh[0][sizeY -1].inkrementAlive();}
				}
			// Bottom Right
				else if (i == sizeX - 1 && j == sizeY - 1)
				{
					if (mesh[sizeX - 1][sizeY - 2].tellState() == true)
					{mesh[sizeX - 1][sizeY -1].inkrementAlive();}

					if (mesh[sizeX - 2][sizeY - 2].tellState() == true)
					{mesh[sizeX - 1][sizeY -1].inkrementAlive();}

					if (mesh[sizeX - 2][sizeY - 1].tellState() == true)
					{mesh[sizeX - 1][sizeY -1].inkrementAlive();}
				}
			// Bottom Left
				else if (i == 0 && j == 0)
				{
					if (mesh[sizeX - 1][1].tellState() == true)
					{mesh[sizeX - 1][0].inkrementAlive();}

					if (mesh[sizeX - 2][1].tellState() == true)
					{mesh[sizeX - 1][0].inkrementAlive();}

					if (mesh[sizeX - 2][0].tellState() == true)
					{mesh[sizeX - 1][0].inkrementAlive();}
				}
			// Top
				else if (i == 0)
				{
					if (mesh[0][j+1].tellState() == true)
					{
						mesh[0][j].inkrementAlive();
					}

					if (mesh[0][j-1].tellState() == true)
					{
						mesh[0][j].inkrementAlive();
					}

					if (mesh[1][j + 1].tellState() == true)
					{
						mesh[0][j].inkrementAlive();
					}

					if (mesh[1][j - 1].tellState() == true)
					{
						mesh[0][j].inkrementAlive();
					}

					if (mesh[1][j].tellState() == true)
					{
						mesh[0][j].inkrementAlive();
					}
				}
			// Botom
				else if (i == sizeX - 1)
				{
					if (mesh[sizeX - 1][j + 1].tellState() == true)
					{
						mesh[sizeX - 1][j].inkrementAlive();
					}

					if (mesh[sizeX - 1][j - 1].tellState() == true)
					{
						mesh[sizeX - 1][j].inkrementAlive();
					}

					if (mesh[sizeX - 2][j + 1].tellState() == true)
					{
						mesh[sizeX - 1][j].inkrementAlive();
					}

					if (mesh[sizeX - 2][j - 1].tellState() == true)
					{
						mesh[sizeX - 1][j].inkrementAlive();
					}

					if (mesh[sizeX - 2][j].tellState() == true)
					{
						mesh[sizeX - 1][j].inkrementAlive();
					}
				}
			// Left
				else if (j == 0)
				{
					if (mesh[i - 1][0].tellState() == true)
					{
						mesh[i][0].inkrementAlive();
					}

					if (mesh[i + 1][0].tellState() == true)
					{
						mesh[i][0].inkrementAlive();
					}

					if (mesh[i - 1][1].tellState() == true)
					{
						mesh[i][0].inkrementAlive();
					}

					if (mesh[i + 1][1].tellState() == true)
					{
						mesh[i][0].inkrementAlive();
					}

					if (mesh[i][1].tellState() == true)
					{
						mesh[i][0].inkrementAlive();
					}
				}
			// Right
				else if (j == sizeY - 1)
				{
					if (mesh[i - 1][sizeY - 1].tellState() == true)
					{
						mesh[i][j].inkrementAlive();
					}

					if (mesh[i + 1][sizeY - 1].tellState() == true)
					{
						mesh[i][sizeY - 1].inkrementAlive();
					}

					if (mesh[i - 1][sizeY - 2].tellState() == true)
					{
						mesh[i][sizeY - 1].inkrementAlive();
					}

					if (mesh[i + 1][sizeY - 2].tellState() == true)
					{
						mesh[i][sizeY - 1].inkrementAlive();
					}

					if (mesh[i][sizeY - 2].tellState() == true)
					{
						mesh[i][sizeY - 1].inkrementAlive();
					}
				}
			//Middle
				else {
					if (mesh[i][j - 1].tellState() == true)
					{
						mesh[i][j].inkrementAlive();
					}

					if (mesh[i][j + 1].tellState() == true)
					{
						mesh[i][j].inkrementAlive();
					}

					if (mesh[i - 1][j].tellState() == true)
					{
						mesh[i][j].inkrementAlive();
					}

					if (mesh[i + 1][j].tellState() == true)
					{
						mesh[i][j].inkrementAlive();
					}

					if (mesh[i + 1][j + 1].tellState() == true)
					{
						mesh[i][j].inkrementAlive();
					}

					if (mesh[i - 1][j - 1].tellState() == true)
					{
						mesh[i][j].inkrementAlive();
					}
					if (mesh[i - 1][j + 1].tellState() == true)
					{
						mesh[i][j].inkrementAlive();
					}

					if (mesh[i + 1][j - 1].tellState() == true)
					{
						mesh[i][j].inkrementAlive();
					}
				}

			}
		}
	*/


	// Output
		for (int i = 0; i < sizeX; ++i) {
			for (int j = 0; j < sizeY; ++j) {
				cout << mesh[i][j].telleState();
			}
			cout << endl;
		}
		//Change state
		for (int i = 0; i < sizeX; ++i) {
			for (int j = 0; j < sizeY; ++j) {
				mesh[i][j].changeState();
			}
		}
		//Next turn
		for (int i = 0; i < sizeX; ++i) {
			for (int j = 0; j < sizeY; ++j) {
				mesh[i][j].step();
			}
		}
		cin.clear(); // clears cin error flags
		cin.ignore(10000, '\n');
		system("CLS");

	}



	// Free memory
	for (int i = 0; i < sizeX; ++i)
		delete[] mesh[i];
	delete[] mesh;

}
