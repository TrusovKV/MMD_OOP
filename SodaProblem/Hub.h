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
    int Ninit;
    double x0init;
    double xNinit;
    double tinit;
    double gammainit;

    double p1init;
    double rho1init;
    double u1init;
    double p4init;
    double rho4init;
    double u4init;

    double numberDivisions;
    double step;
    double length;

    vector<double> P;
    vector<double> T;
    vector<double> U;
    vector<double> R;

public:
    Hub(
    int N,
    double x0,
    double xN,
    double t,
    double gamma,
    double p1,
    double rho1,
    double u1,
    double p4,
    double rho4,
    double u4,

    double NumDiv,
    double st);

    void getVector();

    int tellLlenP();
    int tellLlenU();
    int tellLlenR();
    int tellLlenT();

    double tellPdat(int i);
    double tellTdat(int i);
    double tellUdat(int i);
    double tellRdat(int i);

    double tellNumDiv();
    double tellStep();

};
