 #ifndef SOLVER_H
#define SOLVER_H

#endif // SOLVER_H
#pragma once
#include <vector>
#include <algorithm>
#include <cmath>
//#include <QPoint>
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

       struct length_error{
           int lenP;
           int lenR;
           int lenU;
           int lenT;
       };

   // QVector<QPointF> points;


public:
       Solver(
       int Ninit,
       double x0init,
       double xNinit,
       double tinit,
       double gammainit,
       double p1init,
       double rho1init,
       double u1init,
       double p4init,
       double rho4init,
       double u4init );

     void solve();

     int tellLlenP();
     int tellLlenU();
     int tellLlenR();
     int tellLlenT();

     double tellPdat(int i);
     double tellTdat(int i);
     double tellUdat(int i);
     double tellRdat(int i);

};
