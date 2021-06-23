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

    P.clear();
    R.clear();
    U.clear();
    T.clear();

    int iter = 0;
    double R0 = 8.31;
    double cV = R0 / (gamma - 1);
    double delta = (gamma - 1) / 2;
    double alfa = 2 * gamma / (gamma - 1);

    //speeds of sound
    double a1 = sqrt(gamma * pL / rhoL);
    double a4 = sqrt(gamma * pR / rhoR);

    double zeta = pow(pL / pR, 1 / alfa) * (a1 / a4); //Entropy difference between gas 1 and gas 4

    //First approximation velocity
    double u = (zeta * (a1 + delta * uL) - a4 + delta * uR) / ((1 + zeta) * delta);
    p2 = 1;
    p3 = 0.5;

}//EOF solve()

