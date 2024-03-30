/**
 CakeHeap Budget for Mac
 liability.h
 Purpose: A base class for all Liabilities
 
 @author Thabo David Nyakallo Klass
 @version 1.1 8/9/16
 */

#ifndef LIABILITY_H_INCLUDED
#define LIABILITY_H_INCLUDED
#include "priority.h"
#include <string>
using namespace std;

class Liability
{
    public:
        Liability(double amount, bool hasAPR, float APR, PriorityLevel pLevel);
        Liability(long lAmount, bool hasAPR, float APR, PriorityLevel pLevel); // This was flagged by the compiler for creating ambiguity
        ~Liability() {}
        double getAmount() const;
        double getLAmount() const;
        void setAmount(double amount);
        void setLAmount(long lAmount);
        float getAPR() const;
        void setAPR(float APR);
        bool getHasAPR() const;
        void setHasAPR(bool hasAPR);
        //double getAPRAmount() const;
        //void setAPRAmount(float APR);
        PriorityLevel getPriorityLevel() const;
        void setPriorityLevel(PriorityLevel pLevel);
        string getAmountType() const;
        void setAmountType(string amountType);

    private:
        double itsAmount;
        long itsLAmount;
        bool itsHasAPR;
        //double itsAPRAmount;
        float itsAPR; // as a percentage
        PriorityLevel itsPriorityLevel;
        string itsAmountType;
};
#endif // LIABILITY_H_INCLUDED
