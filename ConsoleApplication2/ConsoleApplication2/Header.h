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
	int numberOfAliveMembers;
public:

	Cell();

	~Cell();

	void getState(char st);

	void getState(bool st);

	char telleState();

	bool tellState();

	void changeState();

	void inkrementAlive();

	void zero();
};

class InputInterface
{
private:
	char chTmp;
	ifstream fp;
	string fPath;
	struct sizes
	{
		int sizeX;
		int sizeY;
	};
	sizes S;
	int numOfIter;
public:
	InputInterface();

	void getFilePath(string s);

	sizes  getSizes();

	sizes tellSizes();

	void initStates(Cell** mesh, Cell** mesh1);

	int getIterationNumber();

};

class OutputInterface 
{
private:
	struct sizes
	{
		int sizeX;
		int sizeY;
	};
	sizes S;
public:
	OutputInterface();

	OutputInterface(InputInterface& SS);

	~OutputInterface();

	void getSizes(InputInterface& SS);

	void Output(Cell** mesh);
};

class GameEngine 
{
private:
	Cell** mesh;
	Cell** mesh1;
	bool tmpAlive;
	int time;
	struct sizes
	{
		int sizeX;
		int sizeY;
	};
	sizes S;
	int numOfIter;
public:


	GameEngine();

	GameEngine(InputInterface& SS);

	void getSizes(sizes SS);

	Cell** sendRef();

	Cell** sendRef1();

	void CreateCellArrays();

	~GameEngine();

	void playGame(Cell** mesh, Cell** mesh1);

	void Engine(OutputInterface& oI);

	sizes tellSises();
};

