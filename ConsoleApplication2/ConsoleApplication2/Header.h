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
	//bool tmpAlive;
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
		alive = false;
		//tmpAlive = true;
		numberOfAliveMembers = 0;
			cordXY.x = cordXY.y = 0;
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
