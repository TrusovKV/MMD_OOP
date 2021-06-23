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


    while (abs(p2 - p3) > tol) {
        //first family R
        a2 = a1 + delta * (uL - u);
        p2 = pL * pow(a2 / a1, alfa);
        dp2 = -gamma * p2 / a2;

        //second family S
        V4 = (gamma + 1) / 4 * (u - uR) + sqrt(pow((gamma + 1) / 4, 2) * (u - uR) * (u - uR) + a4 * a4);
        M4 = V4 / a4;
        p3 = pR * (1 + (2 * gamma) / (gamma + 1) * (M4 * M4 - 1));
        a3 = a4 * sqrt((gamma + 1 + (gamma - 1) * (p3 / pR)) / (gamma + 1 + (gamma - 1) * (pR / p3)));
        wd = uR - V4;
        dp3 = 2 * gamma * (pR / a4) * (pow((abs(M4)), 3) / (1 + M4 * M4));

        //New velocity and update of the iteration
        u -= (p2 - p3) / (dp2 - dp3);

        iter++;
    }

    rho2 = gamma * p2 / (a2 * a2);
    rho3 = gamma * p3 / (a2 * a3);

    x1 = (uR - a1) * tMax;
    x2 = (u - a2) * tMax;
    x3 = u * tMax;
    x4 = (u + a3) * tMax;
    x5 = (uR + a4) * tMax;

}//EOF solve()

