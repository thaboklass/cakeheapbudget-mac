#include "indicator.h"

Indicator::Indicator(Balance * monthlyBalance, Status status):
itsMonthlyBalance(monthlyBalance),
itsStatus(status)
{
}

Indicator::~Indicator()
{
    delete itsMonthlyBalance;
    itsMonthlyBalance = 0;
}

Balance * Indicator::getBalance() const
{
    return itsMonthlyBalance;
}

void Indicator::setBalance(Balance * monthlyBalance)
{
    itsMonthlyBalance = monthlyBalance;
}

Status Indicator::getStatus() const
{
    return itsStatus;
}

void Indicator::setStatus(Status status)
{
    itsStatus = status;
}
