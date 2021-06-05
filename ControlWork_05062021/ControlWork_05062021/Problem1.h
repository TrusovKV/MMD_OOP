#pragma once
#include<iostream>
using namespace std;



class object
{
    int myObj;
};

class Myshared_ptr
{
    object* pObj;
    static int count; 

public:
    Myshared_ptr(object* myObj);
    Myshared_ptr(const Myshared_ptr& myObj);
    ~Myshared_ptr();

    Myshared_ptr& operator=(Myshared_ptr& myObj);
    Myshared_ptr& operator=(Myshared_ptr&& myObj) noexcept;
};

int Myshared_ptr::count = 0;

Myshared_ptr::Myshared_ptr(object* myObj) : pObj(myObj) {};

Myshared_ptr::Myshared_ptr(const Myshared_ptr& myObj)
{
    Myshared_ptr p1 = new object();
    p1.pObj = myObj.pObj;
    count++;
};

Myshared_ptr::~Myshared_ptr()
{
    if (count == 1)
    {
        delete pObj;
        count = 0;
    }
    else
        pObj = nullptr;
    count--;
}

Myshared_ptr& Myshared_ptr::operator=(Myshared_ptr& myObj)
{
    count++;
    return myObj;
}

Myshared_ptr& Myshared_ptr::operator=(Myshared_ptr&& myObj) noexcept
{
    if (this == &myObj)
        return *this;

    delete pObj; // local
    count = 0;
    pObj = myObj.pObj;
    ++count;
    myObj.pObj = nullptr;//source
    --myObj.count;
    return *this;
}