#ifndef HUB_H
#define HUB_H
#pragma once
//#include <iostream>
//#include "solver.h"
class Solver;


class Hub
{
public:
    Hub(Solver *MM);
    Solver *M;
    void wasClicked(double leftX,
                    double rightX,
                    double gamma,
                    double tmax,
                    int N,
                    double pL,
                    double pR,
                    double rhoL,
                    double rhoR,
                    double uL,
                    double uR);
};


#endif // HUB_H
