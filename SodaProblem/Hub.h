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
    double st) :
         Ninit(N),
         x0init(x0),
         xNinit(xN),
         tinit(t),
         gammainit(gamma),

         p1init(p1),
         rho1init(rho1),
         u1init(u1),
         p4init(p4),
         rho4init(rho4),
         u4init(u4),

         numberDivisions(NumDiv), step(st), length(0)  {}

    Hub(){}

    void getVector()
    {
        Solver parasol(        Ninit,
                               x0init,
                               xNinit,
                               tinit,
                               gammainit,
                               p1init,
                               rho1init,
                               u1init,
                               p4init,
                               rho4init,
                               u4init
                       );

        parasol.solve();

        for (int i = 0; i < parasol.tellLlenP(); i++ )
        {
            P.push_back(parasol.tellPdat(i));
        }
        for (int i = 0; i < parasol.tellLlenP(); i++ )
        {
            T.push_back(parasol.tellTdat(i));
        }
        for (int i = 0; i < parasol.tellLlenP(); i++ )
        {
            U.push_back(parasol.tellUdat(i));
        }
        for (int i = 0; i < parasol.tellLlenP(); i++ )
        {
            R.push_back(parasol.tellRdat(i));
        }
    }

    int tellLlenP(){ return P.size();}
    int tellLlenU(){ return U.size();}
    int tellLlenR(){ return R.size();}
    int tellLlenT(){ return T.size();}

    double tellPdat(int i) { return P.at(i); }
    double tellTdat(int i) { return T.at(i); }
    double tellUdat(int i) { return U.at(i); }
    double tellRdat(int i) { return R.at(i); }

    double tellNumDiv() {return numberDivisions;}
    double tellStep() {return step;}

   //Solver parasol(hb.tellA(), hb.tellB(), hb.tellC(), hb.tellNumDiv(), hb.tellStep()) ;
    //hb.getVector( parasol.TheFinalSolution() );
};
