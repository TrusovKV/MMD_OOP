#pragma once

#include <iostream>

using namespace std;

class MyIntArray
{
private:
	int* data;
	size_t length;


public:
	
	MyIntArray() :length(0), data(new int[length])
	{}

	~MyIntArray()
	{
		delete[] data;
		length = 0;
	}
	MyIntArray& operator= (const MyIntArray& c) {
		data = c.data;
		length = 0;
	}

	MyIntArray& operator=(const MyIntArray&& c) 
	{
		if (this == &c)
			return *this;

		delete[] data;
		length = 0;
		data = c.data;
		length = c.length;
		c.~MyIntArray();
		return *this;
	}

	MyIntArray(const MyIntArray&& c)
	{
		data = c.data;
		length = c.length;
		c.~MyIntArray();
	}

	MyIntArray(const MyIntArray& c)
	{
		data = c.data;
		length = c.length;
	}


	


};