#ifndef HUB_H
#define HUB_H
#include <iostream>
class Solver;

class Hub
{
public:

    Hub(Solver *parasol);
    Hub();
    Solver *sol;

};

#endif // HUB_H
