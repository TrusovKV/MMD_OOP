#ifndef HUB_H
#define HUB_H
#pragma once
//#include <iostream>
//#include "solver.h"
class Solver;


class Hub
{
public:

    Hub(Solver *parasol);
    Hub();
    Solver *sol;
    void transmittData(  int Ninit,
                         double x0init,
                         double xNinit,
                         double tinit,
                         double gammainit,
                         double p1init,
                         double rho1init,
                         double u1init,
                         double p4init,
                         double rho4init,
                         double u4init);

};

#endif // HUB_H
