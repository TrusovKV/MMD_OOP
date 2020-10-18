#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Cell
{
private:
	bool alive;
	bool tmpAlive;
	int numberOfAliveMembers;
	struct Coordinates
	{
	int x;
	int y;
	};
	Coordinates cordXY;
public:

	Cell()
	{
		alive = true;
		tmpAlive = true;
		numberOfAliveMembers = cordXY.x = cordXY.y = 0;
		//cout << "hello" << endl;
	}
	~Cell()
	{
	//	cout << "bye" << endl;
	}

	void getCoordinates(int i, int j)
	{
		this->cordXY.x = i;
		this->cordXY.y = j;
	}
	Coordinates tellCoordinates()
	{
		return cordXY;
	}
	void getState(char st)
	{
		if(st == '*')
		this->alive = true;
		else
			this->alive = false;
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
		if(this->alive == true)
		{

		if( (this->numberOfAliveMembers < 2) || (this->numberOfAliveMembers > 3))

				this->tmpAlive = false;
		else
				this->tmpAlive = true;
		}
		//Dead
		else
			if (this->numberOfAliveMembers == 3)
			{
				this->tmpAlive = true;
			}
			else
				this->tmpAlive = false;
	}

	void step()
	{
		this->alive  =  this->tmpAlive;
		this->numberOfAliveMembers = 0;
	}

	void inkrementAlive()
	{
		++this->numberOfAliveMembers;
	}
};

/*
class Interface
{
private:

	int sizeX;
	int sizeY;
	int i;
	int j;
	string filename;
	ifstream fp;
	Cell** mesh;

public:

	Interface()
	{
		filename = "Input.txt";
		fp.open(filename);
		fp >> sizeX;
		fp >> sizeY;

		Cell** mesh = new Cell * [sizeX];
		for (int i = 0; i < sizeX; ++i) 
		{
			mesh[i] = new Cell[sizeY];
			for (int j = 0; j < sizeY; ++j) {
				mesh[i][j].getCoordinates(i, j);
			}
		}

	}

	~Interface(Cell** mesh, int sizeX)
	{
		cout << "Wow!" << endl;

		// Free memory
		for (int i = 0; i < sizeX; ++i)
			delete[] mesh[i];
		delete[] mesh;

	}
	
};*/
