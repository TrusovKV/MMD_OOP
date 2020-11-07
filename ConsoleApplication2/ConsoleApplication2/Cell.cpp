#include "Header.h"

Cell::Cell() :alive(false), numberOfAliveMembers(0)
{}

Cell::~Cell()
{}

void Cell::getState(char st)
{
	if (st == '*')
		this->alive = true;
	else
		this->alive = false;
}

void Cell::getState(bool st)
{
	this->alive = st;
}

char Cell::telleState()
{
	if (this->alive == true)
	{
		return '*';
	}
	else
		return '_';
}

void Cell::inkrementAlive()
{
	++(this->numberOfAliveMembers);
}

void Cell::zero()
{
	this->numberOfAliveMembers = 0;
}

bool Cell::tellState()
{
	return this->alive;
}

void Cell::changeState()
{
	// Life
	if (this->alive == true)
	{

		if ((this->numberOfAliveMembers < 2) || (this->numberOfAliveMembers > 3))

			this->alive = false;
		else
			this->alive = true;
	}
	//Dead
	else
		if (this->numberOfAliveMembers == 3)
		{
			this->alive = true;
		}
		else
			this->alive = false;
}