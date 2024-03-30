/**
 CakeHeap Budget for Mac
 savings_apr.h
 Purpose: The Savings APR class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef SAVINGS_APR_H_INCLUDED
#define SAVINGS_APR_H_INCLUDED

#include <QtCore/QThread>
#include <QtCore/QDate>
#include "budget_page.h"
//#include <iostream>
using namespace std;

class SavingsAPR : public QThread
{
    public:
        SavingsAPR(SavingsList *sList);
        ~SavingsAPR() {}
        void checkAndDealWithSavingsAndAPR(SavingsList &sList);
        void run();
    private:
        SavingsList *itsSavingsList;
};
#endif // SAVINGS_APR_H_INCLUDED
