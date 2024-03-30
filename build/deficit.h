/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Deficit class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */


#ifndef DEFICIT_H_INCLUDED
#define DEFICIT_H_INCLUDED
#include "liability.h"
class Deficit : public Liability
{
    public:
        Deficit(int amount, bool hasAPR, float APR, PriorityLevel pLevel);
        ~Deficit();
};
#endif // DEFICIT_H_INCLUDED
