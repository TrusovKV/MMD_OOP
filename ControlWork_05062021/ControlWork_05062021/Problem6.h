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
	{
		cout << "created by 0" << endl;
	}
	MyIntArray(int LL, const int* dat) :length(LL)
	{
		data = new int[length];
		for (int i = 0; i < length; i++)
		{
			data[i] = dat[i];
		}
		cout << "created by some data" << endl;
	}
	void tellAll()
	{
		cout << endl << "____MyIntArray__of_length__"<< length << "__TEST____" << endl;
		
		for (int i = 0; i < length; i++)
		{
			cout << data[i]<<endl;
		}
	}

	~MyIntArray()
	{
		delete[] data;
		data = nullptr;
		length = 0;
		cout << "deleted" << endl;
	}
	MyIntArray& operator= (const MyIntArray& c) {
		length = c.length;
		data = new int[length];
		for (int i = 0; i < length; i++)
		{
			data[i] = c.data[i];
		}

	}

	MyIntArray& operator=( MyIntArray&& c) noexcept
	{

		//delete[] data;
		//length = 0;
		//data = c.data;
		//length = c.length;
		//c.length = 0;
		//delete[] c.data;
		//c.data = nullptr;
		//return *this;
		int* new_array = new int[c.length];
		copy(c.data, c.data + c.length, new_array);

		delete[] data;

		data = new_array;
		length = c.length;
	}

	MyIntArray( MyIntArray&& c) noexcept
	{
		//data = new int[c.length];

		//for (int i = 0; i < c.length; i++)
		//{
		//	data[i] = c.data[i];
		//}
		//length = c.length;

		//c.length = 0;
		//delete[] c.data;
		//c.data = nullptr;

		//No need to manually copy data
		data = c.data;
		length = c.length;
		c.data = nullptr;

	}

	MyIntArray(const MyIntArray& c) : length(c.length), data(c.length ? new int[c.length] : nullptr) {
		copy(c.data, c.data + c.length, data);
	}

	//MyIntArray(const MyIntArray& c)
	//{
	//	length = c.length;
	//	data = new int[length];

	//	for (int i = 0; i< length; i++)
	//	{
	//		data[i] = c.data[i];
	//	}

	//}


	


};