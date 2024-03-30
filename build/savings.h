/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Savings class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef SAVINGS_H_INCLUDED
#define SAVINGS_H_INCLUDED
#include "asset.h"
#include "date.h"
#include <string>
using namespace std;

enum SavingsNature { STOCK, BANK };

class Savings : public Asset
{
    public:
        Savings(string name, double amount, float APR, SavingsNature nature, Date date, string description);
        Savings(string name, long lAmount, float APR, SavingsNature nature, Date date, string description);
        ~Savings() {}
        string getName() const;
        void setName(string name);
        SavingsNature getNature() const;
        void setNature(SavingsNature nature);
        int getIDCode() const;
        void setIDCode(int IDCode);
        Date getDate();
        void setDate(Date date);
        string getDescription() const;
        void setDescription(string description);
    private:
        string itsName;
        SavingsNature itsNature;
        int itsIDCode;
        string itsDescription;
        Date itsDate;
};
#endif // SAVINGS_H_INCLUDED
