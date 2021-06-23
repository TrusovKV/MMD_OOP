#ifndef SOLVER_H
#define SOLVER_H
#include <QVector>
#include <math.h>
#include <iostream>
#include <mainwindow.h>

class Solver
{
public:
    Solver();
    void setData(
            double leftX,
            double rightX,
            double gamma,
            double tmax,
            int N,
            double pLhs,
            double pRhs,
            double rhoLhs,
            double rhoRhs,
            double uLhs,
            double uRhs);
    void RCS();
    void subscribe(MainWindow *w);
    void update();
    QVector<double> P;
    QVector<double> R;
    QVector<double> U;
    QVector<double> T;
    MainWindow *View;
    int Nx;
    double xL;
    double xR;
    double tMax;
    double gamma;
    double pL;
    double rhoL;
    double uL;
    double pR;
    double rhoR;
    double uR;
};

#endif // SOLVER_H
