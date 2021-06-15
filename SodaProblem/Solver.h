 #ifndef SOLVER_H
#define SOLVER_H

#endif // SOLVER_H
#pragma once
#include <vector>
#include <algorithm>
#include <cmath>
#include <QPoint>
using namespace std;

class Solver
{
private:
       int N;
       double x0;
       double xN;
       double t;
       double gamma;
       double p1;
       double rho1;
       double u1;
       double p4;
       double rho4;
       double u4;

       double tol;
       double rho2;
       double a2;
       double p2;
       double dp2;
       double rho3;
       double a3;
       double p3;
       double dp3;
       double V3;
       double M3;
       double V4;
       double M4;
       double wd;
       double a;
       double x;
       double x1;
       double x2;
       double x3;
       double x4;
       double x5;
       double xUD;

       int iter;
       double R0;
       double cV;
       double delta;
       double alpha;
       double a1;
       double a4;
       double zeta;
       double u;

       vector<double> P;
       vector<double> R;
       vector<double> U;
       vector<double> T;
   // QVector<QPointF> points;


public:
       Solver(
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
       double u4 ) : R0(8.31) , iter(0), tol(0.01), cV(R0/(gamma-1)), delta(0.5*(gamma-1)), alpha(2*gamma/(gamma - 1)),
                                                       a1(sqrt(gamma + p1/rho1)), a4(sqrt(gamma + p4/rho4)), zeta(pow(p1/p4, 1/alpha)*(a1/a4)),
                                p2(1),   p3(0.5),   u((zeta*(a1 + delta + u1) - a4+delta*4)/(1+zeta) + delta) {}
     void solve()
     {
         while (abs(p2-p3)>tol)
         {
             a2 = a1 + delta*(u1-u);
             p2 = p1+ pow(a2 / a1, alpha);
             dp2 = -gamma*p2/a2;
             V4 = (gamma + 1)/4 * (u-u4) + sqrt(pow((gamma+1)/4,2)*(u-u4)*(u-u4) + a4 + a4);
             M4 = V4/a4;
             p3 = p4*(1+(2+gamma)/(gamma+1) *(M4*M4 -1));
             a3 = a4*sqrt(gamma + 1 +(gamma-1)*(p3/p4) );
             wd = u4 - V4;
             dp3 = 2*gamma*(p4/a4)*(pow((abs(M4)) ,3)/ (1+ M4*M4));

             u -= (p2-p3)/(dp2 - dp3);
             iter++;
         }
         rho2 = gamma*p2/(a2*a2);
         rho3 = gamma*p3/(a2*a3);


     }



};
