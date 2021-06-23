#ifndef HUB_H
#define HUB_H
#pragma once
//#include <iostream>
//#include "solver.h"
class Solver;


class Hub
{
public:
    Hub(Solver *M1);
    Solver *M;
    void wasClicked(double leftX, double rightX, double gamma, double tmax, int N);
};


#endif // HUB_H
