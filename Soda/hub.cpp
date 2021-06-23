#include "hub.h"
#include "solver.h"

Hub::Hub()
{

}

 Hub::Hub(Solver *parasol)
 {
    sol = parasol;
 }
 void Hub::transmittData(  /*int Ninit,
                           double x0init,
                           double xNinit,
                           double tinit,
                           double gammainit,
                           double p1init,
                           double rho1init,
                           double u1init,
                           double p4init,
                           double rho4init,
                           double u4init*/)
 {/*
     this->sol->getValues(   Ninit,
                             x0init,
                             xNinit,
                             tinit,
                             gammainit,
                             p1init,
                             rho1init,
                             u1init,
                             p4init,
                             rho4init,
                             u4init );*/
     this->sol->solve();
 }
