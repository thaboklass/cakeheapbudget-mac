#include "balance.h"

/**
 The constructor for the Balance class.
 
 @param monthlyBalance    the name of the debt.
 @param dateOfBalance     the debt amount(double).
 */
Balance::Balance(double monthlyBalance, Date * dateOfBalance):
itsMonthlyBalance(monthlyBalance),
itsDateOfBalance(dateOfBalance)
{
}


/**
 The Balance class destructor.
 
 @param monthlyBalance    none.
 */
Balance::~Balance()
{
    delete itsDateOfBalance;
    itsDateOfBalance = 0;
}


/**
 The balance name getter.
 
 @param  nothing.
 @return the name of the debt.
 */
double Balance::getBalance() const
{
    return itsMonthlyBalance;
}


/**
 The balance name setter.
 
 @param  monthlyBalance  the monthly balance.
 @return the name of the debt.
 */
void Balance::setBalance(double monthlyBalance)
{
    itsMonthlyBalance = monthlyBalance;
}


/**
 The balance date getter.
 
 @param  nothing.
 @return itsDateOfBalance  the balance's date.
 */
Date * Balance::getDate()
{
    return itsDateOfBalance;
}
