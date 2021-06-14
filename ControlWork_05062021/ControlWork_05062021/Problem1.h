#pragma once
#include<iostream>
using namespace std;



template<class T>
class my_shared_ptr
{
	T* ptr;
	size_t* count;
public:
	size_t tellCount()
	{
		return *count;
	}
	my_shared_ptr() :ptr(nullptr), count(0) {}
	my_shared_ptr(T* p)
	{
		count = new size_t(1);
		ptr = p;
	}

	my_shared_ptr(my_shared_ptr const& p)
	{
		if (ptr == p.ptr)
		{
			++*count;
		}
		else
		{
			ptr = p.ptr;
			count = p.count;
			++*count ;
		}
	}

	~my_shared_ptr() {
		if (ptr != nullptr && count == 0)
		{
			delete[]ptr;
		}
		else
		{
			--*count;
		}
	}

	my_shared_ptr& operator = (my_shared_ptr const& p) {
		if (this != &p)
		{
			--*count;
			ptr = p.ptr;
			count = p.count;
			++*count;
		}
		return *this;
	}

	T* operator ->() const { return ptr; }
	T& operator*() const { return *ptr; }

	my_shared_ptr& operator=(my_shared_ptr<T>&& p) noexcept
	{
		my_shared_ptr(std::move(p)).swap(*this);
		++*count;
		--p.*count;
		return *this;
	}
};