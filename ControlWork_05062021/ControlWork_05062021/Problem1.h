#pragma once
#include<iostream>
using namespace std;



//class object
//{
//    int myObj;
//    
//};
template<class T>
class Myshared_ptr
{
    T* pObj;
    size_t count; 

public:
    //Myshared_ptr();
    //Myshared_ptr(T* myObj);
    //Myshared_ptr( Myshared_ptr const& myObj);
    //~Myshared_ptr();
    Myshared_ptr() :pObj(nullptr), count(0) {}
    Myshared_ptr(T* p) : pObj(p), count(1)  {}


    Myshared_ptr& operator=(Myshared_ptr const& myObj)
    {
        if (this != &pObj)
        {
            count--;
            pObj = myObj.pObj;
            count = myObj.count;
        }
        return this;
    }
    T* operator ->() const
    { 
        return pObj;
    }
    T& operator*() const 
    {
        return *pObj;
    }
    Myshared_ptr& operator=(Myshared_ptr<T>&& myObj) noexcept
    {
        Myshared_ptr(std::move(pObj)).swap(*this);
        count++;
        pObj.count--;
        return *this;
    //    if (this == &myObj)
    //    {
    //        return *this;
    //    }

    //delete pObj; // local
    //count = 0;
    //pObj = myObj.pObj;
    //++count;
    //myObj.pObj = nullptr;//source
    //--myObj.count;
    //return *this;
    }


    ~Myshared_ptr()
    {
        if (count == 1)
        {
            delete[] pObj;
            count = 0;
            cout << "minus odin" << endl;
        }
        else
        {
            pObj = nullptr;
            count--;
        }
        cout << "deleted" << endl;
    }
    Myshared_ptr(Myshared_ptr const& myObj)
    {
        if (pObj == myObj.pObj)
        {
            count++;
        }
        else
        {
            pObj == myObj.pObj;
            count = myObj.count;
            count++;
        }
    }

};

//int Myshared_ptr::count = 0;

//Myshared_ptr<class T>::Myshared_ptr() : pObj(nullptr), count(1) {};
//
//Myshared_ptr<class T>::Myshared_ptr(T* myObj) : pObj(myObj), count(1) {};

//Myshared_ptr<class T>::Myshared_ptr( Myshared_ptr const& myObj)
//{
//    if (pObj == myObj.pObj)
//    {
//        count++;
//    }
//    else
//    {
//        pObj == myObj.pObj;
//        count = myObj.count;
//        count++;
//    }
//};

//Myshared_ptr<class T>::~Myshared_ptr()
//{
//    if (count == 1)
//    {
//        delete[] pObj;
//        count = 0;
//        cout << "minus odin" << endl;
//    }
//    else
//    {
//        pObj = nullptr;
//        count--;
//    }
//    cout << "deleted" << endl;
//}



//Myshared_ptr<class T>& Myshared_ptr::operator=(Myshared_ptr&& myObj) noexcept
//{
//    if (this == &myObj)
//        return *this;
//
//    delete pObj; // local
//    count = 0;
//    pObj = myObj.pObj;
//    ++count;
//    myObj.pObj = nullptr;//source
//    --myObj.count;
//    return *this;
//}