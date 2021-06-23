#include "hub.h"
#include "solver.h"
#include <iostream>
using namespace std;

Hub::Hub(Solver *M1){
    this->M = M1;
}

void Hub::wasClicked(
                double leftX,
                double rightX,
                double gamma,
                double tmax,
                int N,
                double pL,
                double pR,
                double rhoL,
                double rhoR,
                double uL,
                double uR){
    M->setData(leftX, rightX, gamma, tmax, N, pL, pR, rhoL, rhoR, uL, uR);
    M->RCS();
}
