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
	}
	MyIntArray& operator= (const MyIntArray& c) {
		data = c.data;
	}

	MyIntArray& operator=(MyIntArray&& c) 
	{
		if (this == &c)
			return *this;

		delete[] data;
		data = c.data;
		c.data = nullptr;
		return *this;
	}

	MyIntArray( MyIntArray&& c)
	{
		data = c.data;
		c.data = nullptr;
	}

	MyIntArray(const MyIntArray& c)
	{
		for (int i = 0; i < this->length; ++i)
		{
			c.data[i] = data[i];
		}
	}


	


};