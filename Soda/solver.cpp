#include "Solver.h"
#include "mainwindow.h"
#include <iostream>
using namespace std;

Solver::Solver(){}
void Solver::setData(int N, double x0, double xN, double t, double gamma) {
    Nx = N;
    xL = x0;
    xR = xN;
    tMax = t;
    this->gamma = gamma;
    pL = 1;
    rhoL = 1;
    uL = 0;
    pR = 0.1;
    rhoR = 0.125;
    uR = 0;
}
void Solver::update(){
    View->drawGraph(P, R, U, T, xL, xR, Nx);
}

void Solver::subscribe(MainWindow *w){
    View = w;
}

void Solver::RCS(){
    double tol = 0.01; //tolerance
    double rho2, a2, p2, dp2, rho3, a3, p3, dp3, V4, M4, wd, a;
    double x, x1, x2, x3, x4, x5, xUD;


}//EOF solve()

