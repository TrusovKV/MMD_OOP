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
       double u4init ) : R0(8.31) , iter(0), tol(0.01), cV(R0/(gammainit-1)), delta(0.5*(gammainit-1)), alpha(2*gammainit/(gammainit - 1)),
                                                       a1(sqrt(gammainit + p1init/rho1init)), a4(sqrt(gammainit + p4init/rho4init)), zeta(pow(p1init/p4init, 1/alpha)*(a1/a4)),
                                p2(1),   p3(0.5),   u((zeta*(a1 + delta + u1init) - a4+delta*4)/(1+zeta) + delta),
                                                      gamma(gammainit), N(Ninit), x0(x0init),xN(xNinit), rho1(rho1init), p1(p1init), u1(u1init), t(tinit),rho4(rho4init), u4(u4init) {}
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

         x1 = (u1 - a1)*t;
         x2 = (u - a2)* t;
         x3 = u*t;
         x4 = (u + a3)*t;
         x5 = (u4 + a4)*t;

//_____________________________________________
         xUD = abs(wd)*t;
         for (int k = 0; k<N; k++)
         {
           x = x0 + k* (xN - x0)  /N;
           if(x <= x1)
           {
               U.push_back(u1);
               P.push_back(p1);
               R.push_back(rho1);

           }
           else if ((x <=x2) && (x > x1))
           {
               U.push_back(1/(1+delta)*(a1 + delta*u1 + (x)/t));
               a = 1/(1+ delta)*(a1) + delta/(delta + 1)*(u1) - delta / (1 + delta)*(x) / t;
               P.push_back(p1*pow(a/a1, alpha));
               R.push_back(gamma*P[k]/(a*a));
           }
           else if((x <= xUD) && (x> x3))
           {
               U.push_back(u);
               P.push_back(p3);
               R.push_back(rho3);
           }
               else
           {
               U.push_back(u4);
               P.push_back(p4);
               R.push_back(rho4);
           }
           T.push_back(P[k]/ (R[k] * cV * (gamma -1)));
         }
     }//EOF solve()

     int tellLlenP(){ return P.size();}
     int tellLlenU(){ return U.size();}
     int tellLlenR(){ return R.size();}
     int tellLlenT(){ return T.size();}

     double tellPdat(int i) { return P.at(i); }

};
