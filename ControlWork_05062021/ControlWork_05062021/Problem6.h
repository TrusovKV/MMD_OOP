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
		data = new(int);
		data = c.data;
		length = c.length;
	}

	MyIntArray& operator=( MyIntArray&& c) noexcept
	{


		delete[] data;
		length = 0;
		data = c.data;
		length = c.length;
		c.length = 0;
		c.data = nullptr;
		return *this;
	}

	MyIntArray( MyIntArray&& c) noexcept
	{
		data = c.data;
		length = c.length;
		c.length = 0;
		c.data = nullptr;
	}

	MyIntArray(const MyIntArray& c)
	{
		data = new(int);
		data = c.data;
		length = c.length;
	}


	


};