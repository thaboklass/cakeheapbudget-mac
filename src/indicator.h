#ifndef INDICATOR_H_INCLUDED
#define INDICATOR_H_INCLUDED
#include "balance.h"

enum Status { BLACK, RED };

class Indicator
{
    public:
        Indicator(Balance * monthlyBalance, Status status);
        ~Indicator();
        Balance * getBalance() const;
        void setBalance(Balance * monthyBalance);
        void setStatus(Status status);
        Status getStatus() const;
    private:
        Balance * itsMonthlyBalance;
        Status itsStatus;
};
#endif // INDICATOR_H_INCLUDED
