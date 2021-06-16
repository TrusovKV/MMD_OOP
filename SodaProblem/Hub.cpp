#include "Hub.h"
Hub::Hub(
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

     numberDivisions(NumDiv), step(st), length(0)  {};

bool Hub::getVector()
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
    return parasol.sayYes();

}

int Hub::tellLlenP(){ return P.size();};
int Hub::tellLlenU(){ return U.size();};
int Hub::tellLlenR(){ return R.size();};
int Hub::tellLlenT(){ return T.size();};

double Hub::tellPdat(int i) { return P.at(i); };
double Hub::tellTdat(int i) { return T.at(i); };
double Hub::tellUdat(int i) { return U.at(i); };
double Hub::tellRdat(int i) { return R.at(i); };

double Hub::tellStep() {return step;};
double Hub::tellNumDiv() {return numberDivisions;};
