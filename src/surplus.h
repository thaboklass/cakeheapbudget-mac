#ifndef SURPLUS_H_INCLUDED
#define SURPLUS_H_INCLUDED
#include "asset.h"
class Surplus : public Asset
{
    public:
        Surplus(int amount, bool hasAPR, float APR);
        ~Surplus();
};
#endif // SURPLUS_H_INCLUDED
