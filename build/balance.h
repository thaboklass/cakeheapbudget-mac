/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Balance class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef BALANCE_H_INCLUDED
#define BALANCE_H_INCLUDED
#include "date.h"
class Balance
{
    public:
        Balance(double monthlyBalace, Date * monthlyBalance);
        ~Balance();
        double getBalance() const;
        void setBalance(double monthlyBalance);
        Date * getDate();
    private:
        double itsMonthlyBalance;
        Date * itsDateOfBalance;
};
#endif // BALANCE_H_INCLUDED
