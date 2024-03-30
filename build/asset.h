/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Asset class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef ASSET_H_INCLUDED
#define ASSET_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class Asset
{
    public:
        Asset(double amount, bool hasAPR, float APR);
        Asset(long lAmount, bool hasAPR, float APR);
        ~Asset() {}
        double getAmount() const;
        double getLAmount() const;
        void setAmount(double amount);
        void setLAmount(long lAmount);
        float getAPR() const;
        void setAPR(float APR);
        bool getHasAPR() const;
        void setHasAPR(bool hasAPR);
        string getAmountType() const;
        void setAmountType(string amountType);
        //double getAPRAmount() const;
        //void setAPRAmount(float APR);


    private:
        double itsAmount;
        long itsLAmount;
        bool itsHasAPR;
        //double itsAPRAmount;
        float itsAPR; // as a percentage
        string itsAmountType;
};
#endif // ASSET_H_INCLUDED
