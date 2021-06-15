#ifndef HUB_H
#define HUB_H

#endif // HUB_H
#pragma once
#include <vector>
#include <algorithm>
#include "Solver.h"
using namespace std;

class Hub
{
private:

    double coef_a;
    double coef_b;
    double coef_c;
    double numberDivisions;
    double step;
    double length;
    struct dataXY
    {
        double x;
        double y;
    };
    vector<dataXY> vect;


public:
    Hub(double a, double b, double c, double NumDiv, double st) : coef_a(a), coef_b(b), coef_c(c), numberDivisions(NumDiv), step(st), length(0)  {}
    Hub(){}
    double tellA() {return coef_a;}
    double tellB() {return coef_b;}
    double tellC() {return coef_c;}
    double tellNumDiv() {return numberDivisions;}
    double tellStep() {return step;}

    void getArgs(double &a, double &b, double &c, double &numDiv, double &st)
    {
        coef_a = a;
        coef_b = b;
        coef_c = c;
        numberDivisions = numDiv;
        step = st;
    }

    void getVector()
    {
        Solver parasol(coef_a, coef_b, coef_c, numberDivisions, step) ;
        parasol.TheFinalSolution();
        length = parasol.tellLength();
        for (int i = 0; i < length; i++ )
        {
            double x = parasol.tellVectX(i);
            double y = parasol.tellVectY(i);
            dataXY dat{x, y};
            vect.push_back(dat);
        }

    }

    double tellX(int i)
    {
        return vect.at(i).x;
    }
    double tellY(int i)
    {
        return vect.at(i).y;
    }
    int tellSize()
    {
        return vect.size();
    }
   //Solver parasol(hb.tellA(), hb.tellB(), hb.tellC(), hb.tellNumDiv(), hb.tellStep()) ;
    //hb.getVector( parasol.TheFinalSolution() );
};
