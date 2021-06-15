#ifndef SOLVER_H
#define SOLVER_H

#endif // SOLVER_H
#pragma once
#include <vector>
#include <algorithm>
#include <QPoint>
using namespace std;

class Solver
{
private:
    double coef_a;
    double coef_b;
    double coef_c;
    double numberDivisions;
    double step;
    struct dataXY
    {
        double x;
        double y;
    };
    vector<dataXY> vect;
   // QVector<QPointF> points;
private:
    dataXY calcPoint(double x)
    {
        return {x, coef_a*x*x + coef_b * x + coef_c};
    }

public:
    Solver(double a, double b, double c, double NumDiv, double st) : coef_a(a), coef_b(b), coef_c(c), numberDivisions(NumDiv), step(st)  {}
    void getArgs(double &a, double &b, double &c, double &numDiv, double &st)
    {
        coef_a = a;
        coef_b = b;
        coef_c = c;
        numberDivisions = numDiv;
        step = st;
    }
    double tellLength()
    {
        return numberDivisions/step;
    }
    /*vector<dataXY>*/void TheFinalSolution()
    {
        //...dreams fade away and all hope turns to dust
        for (double p = 0.; p >= -0.5*numberDivisions ; p -= step)
        vect.push_back(calcPoint(p));
        std::reverse(vect.begin(), vect.end());
        for (double p = step; p <= 0.5*numberDivisions + 2; p += step)
        vect.push_back(calcPoint(p));

        //return vect;
    }
    auto tellPoint(int i)
    {
        return vect.at(i);
    }
    double tellVectX(int i)
    {
        return vect.at(i).x;
    }
    double tellVectY(int i)
    {
        return vect.at(i).y;
    }

};
