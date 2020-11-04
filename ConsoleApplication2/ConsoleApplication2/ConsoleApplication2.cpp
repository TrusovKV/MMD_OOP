
#include "Header.h"
/*
void playGame(Cell** mesh, Cell** mesh1, int sizeX, int sizeY)
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
			else if (i == 0 && j == sizeY - 1)
			{
				if (mesh[0][sizeY - 2].tellState() == true)
				{
					mesh1[0][sizeY - 1].inkrementAlive();
				}

				if (mesh[1][sizeY - 2].tellState() == true)
				{
					mesh1[0][sizeY - 1].inkrementAlive();
				}

				if (mesh[1][sizeY - 1].tellState() == true)
				{
					mesh1[0][sizeY - 1].inkrementAlive();
				}
			}
			// Bottom Right
			else if (i == sizeX - 1 && j == sizeY - 1)
			{
				if (mesh[sizeX - 1][sizeY - 2].tellState() == true)
				{
					mesh1[sizeX - 1][sizeY - 1].inkrementAlive();
				}

				if (mesh[sizeX - 2][sizeY - 2].tellState() == true)
				{
					mesh1[sizeX - 1][sizeY - 1].inkrementAlive();
				}

				if (mesh[sizeX - 2][sizeY - 1].tellState() == true)
				{
					mesh1[sizeX - 1][sizeY - 1].inkrementAlive();
				}
			}
			// Bottom Left
			else if (i == 0 && j == 0)
			{
				if (mesh[sizeX - 1][1].tellState() == true)
				{
					mesh1[sizeX - 1][0].inkrementAlive();
				}

				if (mesh[sizeX - 2][1].tellState() == true)
				{
					mesh1[sizeX - 1][0].inkrementAlive();
				}

				if (mesh[sizeX - 2][0].tellState() == true)
				{
					mesh1[sizeX - 1][0].inkrementAlive();
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
			else if (i == sizeX - 1)
			{
				if (mesh[sizeX - 1][j + 1].tellState() == true)
				{
					mesh1[sizeX - 1][j].inkrementAlive();
				}

				if (mesh[sizeX - 1][j - 1].tellState() == true)
				{
					mesh1[sizeX - 1][j].inkrementAlive();
				}

				if (mesh[sizeX - 2][j + 1].tellState() == true)
				{
					mesh1[sizeX - 1][j].inkrementAlive();
				}

				if (mesh[sizeX - 2][j - 1].tellState() == true)
				{
					mesh1[sizeX - 1][j].inkrementAlive();
				}

				if (mesh[sizeX - 2][j].tellState() == true)
				{
					mesh1[sizeX - 1][j].inkrementAlive();
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
			else if (j == sizeY - 1)
			{
				if (mesh[i - 1][sizeY - 1].tellState() == true)
				{
					mesh1[i][j].inkrementAlive();
				}

				if (mesh[i + 1][sizeY - 1].tellState() == true)
				{
					mesh1[i][sizeY - 1].inkrementAlive();
				}

				if (mesh[i - 1][sizeY - 2].tellState() == true)
				{
					mesh1[i][sizeY - 1].inkrementAlive();
				}

				if (mesh[i + 1][sizeY - 2].tellState() == true)
				{
					mesh1[i][sizeY - 1].inkrementAlive();
				}

				if (mesh[i][sizeY - 2].tellState() == true)
				{
					mesh1[i][sizeY - 1].inkrementAlive();
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
	int time = 0;
	int numOfIter = 0;
	//cout << sizeX << "	" << sizeY << endl << endl;



	//Create Cell array
	Cell** mesh = new Cell* [sizeX];
	for (int i = 0; i < sizeX; ++i) {
		mesh[i] = new Cell[sizeY];
		for (int j = 0; j < sizeY; ++j) {
			mesh[i][j].getCoordinates(i,j);
		}
	}

	//Create Cell array
	Cell** mesh1 = new Cell * [sizeX];
	for (int i = 0; i < sizeX; ++i) {
		mesh1[i] = new Cell[sizeY];
		for (int j = 0; j < sizeY; ++j) {
			mesh1[i][j].getCoordinates(i, j);
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
	cout << "enter the number of iterations  ";
	cin >> numOfIter;
	cout << endl;
	system("CLS");

	if (numOfIter == 0)
	{
	// Output
	for (int i = 0; i < sizeX; ++i) {
		for (int j = 0; j < sizeY; ++j) {
			cout << mesh[i][j].telleState();
		}
		cout << endl;
	}
	cin.clear(); // clears cin error flags
	cin.ignore(10000, '\n');
	system("CLS");
	}


	while (t < 2)
		// Time step game play
	{
		bool tmpAlive;
		if (numOfIter != 0 && time == numOfIter)
		{
			break;
		}

		if (time % 2 == 0)
		{ 
		playGame(mesh, mesh1, sizeX, sizeY);

			//Change state
			for (int i = 0; i < sizeX; ++i) {
				for (int j = 0; j < sizeY; ++j) {
					tmpAlive = mesh[i][j].tellState();
					mesh1[i][j].getState(tmpAlive);
					mesh1[i][j].changeState();
					mesh1[i][j].zero();
				}
			}
			if (numOfIter == 0) {
				// Output
				for (int i = 0; i < sizeX; ++i) {
					for (int j = 0; j < sizeY; ++j) {
						cout << mesh1[i][j].telleState();
					}
					cout << endl;
				}
			}
		}
		else
		{
			playGame(mesh1, mesh, sizeX, sizeY);

			//Change state
			for (int i = 0; i < sizeX; ++i) {
				for (int j = 0; j < sizeY; ++j) {
					tmpAlive = mesh1[i][j].tellState();
					mesh[i][j].getState(tmpAlive);
					mesh[i][j].changeState();
					mesh[i][j].zero();
				}
			}
			if (numOfIter == 0) {
				// Output
				for (int i = 0; i < sizeX; ++i) {
					for (int j = 0; j < sizeY; ++j) {
						cout << mesh[i][j].telleState();
					}
					cout << endl;
				}
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
		if (time % 2 == 0)
		{
			// Output
			for (int i = 0; i < sizeX; ++i) {
				for (int j = 0; j < sizeY; ++j) {
					cout << mesh1[i][j].telleState();
				}
				cout << endl;
			}
		}
		else
		{
			// Output
			for (int i = 0; i < sizeX; ++i) {
				for (int j = 0; j < sizeY; ++j) {
					cout << mesh[i][j].telleState();
				}
				cout << endl;
			}
		}
		
	}

	// Free memory
	for (int i = 0; i < sizeX; ++i)
		delete[] mesh[i];
	delete[] mesh;

	for (int i = 0; i < sizeX; ++i)
		delete[] mesh1[i];
	delete[] mesh1;
}
*/