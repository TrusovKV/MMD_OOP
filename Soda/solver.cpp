#include "solver.h"

Solver::Solver()
{

}
void Solver::subscribtion(MainWindow *w)
{
    this->w = w;
}
double Solver::tellRdat(int i) { return R.at(i); };
double Solver::tellUdat(int i) { return U.at(i); };
double Solver::tellPdat(int i) { return P.at(i); };
double Solver::tellTdat(int i) { return T.at(i); };

int Solver::tellLlenP(){ return P.size();};
int Solver::tellLlenU(){ return U.size();};
int Solver::tellLlenR(){ return R.size();};
int Solver::tellLlenT(){ return T.size();};
void Solver::paint()
{
    int kMax = this->tellLlenP();
    for(int k = 0; k< kMax; k++)
    {
        this->w->pointsP.push_back(QPointF(k,this->tellPdat(k)));
        this->w->pointsT.push_back(QPointF(k,this->tellTdat(k)));
        this->w->pointsU.push_back(QPointF(k,this->tellUdat(k)));
        this->w->pointsR.push_back(QPointF(k,this->tellRdat(k)));
    }
   // this->w-

}
void Solver::getValues(int &Ninit,
                       double &x0init,
                       double &xNinit,
                       double &tinit,
                       double &gammainit,
                       double &p1init,
                       double &rho1init,
                       double &u1init,
                       double &p4init,
                       double &rho4init,
                       double &u4init )
{
    N = Ninit;
    x0 = x0init;
    t = tinit;
    gamma = gammainit;
p1 = p1init;
rho1 = rho1init;
u1 = u1init;
p4 = p4init;
rho4 = rho4init;
u4 = u4init;

}
void Solver::initialize()
{
    cV = R0/(gamma-1);
    delta = (0.5*(gamma-1));
    alpha = (2*gamma/(gamma - 1));
    a1 = (sqrt(gamma + p1/rho1));
    a4 = (sqrt(gamma + p4/rho4));
    zeta = (pow(p1/p4, 1/alpha)*(a1/a4));
    u = ((zeta*(a1 + delta + u1) - a4+delta*4)/(1+zeta) + delta);
}


void Solver::solve()
{
    initialize();
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
    this->paint();
    }
}//EOF solve()


