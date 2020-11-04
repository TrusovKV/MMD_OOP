#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

class Cell
{
private:
	bool alive;
	//bool tmpAlive;
	int numberOfAliveMembers;
	//struct Coordinates
	//{
	//	int x;
	//	int y;
	//};
	//Coordinates cordXY;
public:

	Cell() :alive(false), numberOfAliveMembers(0)
	{

	}
	~Cell()
	{
		//	cout << "bye" << endl;
	}

	/*void getCoordinates(int i, int j)
	{
		this->cordXY.x = i;
		this->cordXY.y = j;
	}
	Coordinates tellCoordinates()
	{
		return cordXY;
	}*/
	void getState(char st)
	{
		if (st == '*')
			this->alive = true;
		else
			this->alive = false;
	}

	void getState(bool st)
	{
			this->alive = st;
	}

	char telleState()
	{
		if (this->alive == true)
		{
			return '*';
		}
		else
			return '_';
	}
	bool tellState()
	{
		return this->alive;
	}
	void changeState()
	{
		// Life
		if (this->alive == true)
		{

			if ((this->numberOfAliveMembers < 2) || (this->numberOfAliveMembers > 3))

				this->/*tmp*/alive = false;
			else
				this->/*tmp*/alive = true;
		}
		//Dead
		else
			if (this->numberOfAliveMembers == 3)
			{
				this->/*tmp*/alive = true;
			}
			else
				this->/*tmp*/alive = false;
	}

	//void step()
	//{
	//	this->alive  =  this->tmpAlive;
	//	this->numberOfAliveMembers = 0;
	//}

	void inkrementAlive()
	{
		++(this->numberOfAliveMembers);
	}
	void zero()
	{
		this->numberOfAliveMembers = 0;
	}

};
class Globals
{
protected:
	struct sizes
	{
		int sizeX;
		int sizeY;
	};
	sizes S;
	int numOfIter;
public:
		Globals() : S{ 0,0 }, numOfIter(0)
		{}
		~Globals()
		{}
};

class InputInterface : public Globals
{
private: 
	char chTmp;
	ifstream fp;
	string fPath;
public:
	InputInterface() : chTmp(' '), fp("C :\\ "), fPath("C :\\ ")
	{}
	void getFilePath(string s)
	{
		this->fPath = s;
	}
	sizes  getSizes()
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
				//cout << endl << "sizeX = " << S.sizeX << "sizeY = " << S.sizeY << endl;
				if (fp.eof())
					{
						throw  exception("Too short file");
					}
				}
				
			}

		}// EOF try
		catch(exception & e)
		{
			cout << endl << e.what() << endl;
		}//EOF catch
		return S;
	}

	void initStates(Cell** mesh, Cell** mesh1)
	{
		//cout << endl << S.sizeX << " " << S.sizeY << " " << mesh << endl;
		// Initialize states
		for (int i = 0; i < S.sizeX; i++)
		{
			for (int j = 0; j < S.sizeY; j++)
			{
				fp >> chTmp;
				mesh[i][j].getState(chTmp);
				mesh1[i][j].getState(chTmp);
			}
		}
		cout << endl;
	}
	void Output(Cell** mesh)
	{
		cout << endl << "Starting output" << endl;
		//cout << endl << S.sizeX << " " << S.sizeY << " " << mesh << endl;
		for (int i = 0; i < S.sizeX; ++i) {
			for (int j = 0; j < S.sizeY; ++j) {
				cout << mesh[i][j].telleState();
			}
			cout << endl;
		}
		cout << endl << "Output done" << endl;
	}
	int getIterationNumber()
	{
		cout << endl << "Enter the iteration number ";
		cin >> numOfIter;
		system("CLS");
		return numOfIter;
	}
};

class OutputInterface : public Globals
{
private:

public:
	OutputInterface()
	{}
	~OutputInterface()
	{}
	void Output(Cell** mesh, sizes S)
	{
		for (int i = 0; i < S.sizeX; ++i) {
			for (int j = 0; j < S.sizeY; ++j) {
				cout << mesh[i][j].telleState();
			}
			cout << endl;
		}
	}
};

class GameEngine : public Globals
{
private:
	Cell** mesh;
	Cell** mesh1;
	bool tmpAlive;
	int time;
public:


	GameEngine():  mesh(NULL), mesh1(NULL), tmpAlive(0), time(0)
	{
		// Protects program from initializing arrays without sizes
	}

	GameEngine(sizes SS) :tmpAlive(0), time(0)
	{
		// Initializing arrays with predefined sizes

		//Create Cell array #1
		S = SS;
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

	Cell** sendRef()
	{
		//cout << "#1 " << mesh << endl;
		return this->mesh;
	}

	Cell** sendRef1()
	{
		//cout << "#2 " << mesh1 << endl;
		return this->mesh1;
	}

	void CreateCellArrays()
	{
		//Create Cell array #1
		mesh = new Cell * [S.sizeX ];
		for (int i = 0; i < S.sizeX; ++i) {
			mesh[i] = new Cell[S.sizeY];
			//for (int j = 0; j < sizeY; ++j) {
			//	mesh[i][j].getCoordinates(i, j);
			//	cout << j << " ";
			//}
			//cout << endl;
		}
		//cout << endl;
		//cout << endl;
		//Create Cell array #2
		mesh1 = new Cell * [S.sizeX];
		for (int i = 0; i < S.sizeX; ++i) {
			mesh1[i] = new Cell[S.sizeY];
			//for (int j = 0; j < sizeY; ++j) {
			//	mesh1[i][j].getCoordinates(i, j);
			//	cout << j << " ";
			//}
			//cout << endl;
		}
	//cout << endl;
	//cout << endl;	
	}

	~GameEngine()
	{
		
		// Free memory
		for (int i = 0; i < S.sizeX; ++i)
			delete[] mesh[i];
		delete[] mesh;

		for (int i = 0; i < S.sizeX; ++i)
			delete[] mesh1[i];
		delete[] mesh1;

	}

	void playGame(Cell** mesh, Cell** mesh1)
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

	void Engine(int numOfIter, OutputInterface & oI)
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
					oI.Output(mesh1, S);
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
					oI.Output(mesh, S);
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
				oI.Output(mesh1, S);
			}
			else// Output
			{		
				oI.Output(mesh, S);
			}

		}


	}

	sizes tellSises()
	{
		return S;
	}
};

