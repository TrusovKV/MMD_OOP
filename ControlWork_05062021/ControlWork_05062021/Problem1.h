#pragma once
#include<iostream>
using namespace std;



//class object
//{
//    int myObj;
//    
//};

class Myshared_ptr
{
    int* pObj;
    static int count; 

public:
    Myshared_ptr();
    Myshared_ptr(int* myObj);
    Myshared_ptr(const Myshared_ptr& myObj);
    ~Myshared_ptr();

    Myshared_ptr& operator=(Myshared_ptr& myObj);
    Myshared_ptr& operator=(Myshared_ptr&& myObj) noexcept;
};

int Myshared_ptr::count = 0;

Myshared_ptr::Myshared_ptr() : pObj(nullptr) {};

Myshared_ptr::Myshared_ptr(int* myObj) : pObj(myObj) {};

Myshared_ptr::Myshared_ptr(const Myshared_ptr& myObj)
{
    Myshared_ptr p1 = new int();
    p1.pObj = myObj.pObj;
    count++;
};

Myshared_ptr::~Myshared_ptr()
{
    if (count == 1)
    {
        delete pObj;
        count = 0;
        cout << "minus odin" << endl;
    }
    else
        pObj = nullptr;
    count--;

    cout << "deleted" << endl;
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