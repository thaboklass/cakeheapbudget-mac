#include "liability.h"

/**
 The constructor for the Liability class.
 
 @param amount the liability amount.
 @param hasAPR a boolean that controls whether the amount has an APR.
 @param APR    the APR.
 @param pLevel the priority level of the liability.
 */
Liability::Liability(double amount, bool hasAPR, float APR, PriorityLevel pLevel):
itsAmount(amount),
itsLAmount(0),
itsAmountType("double"),
itsHasAPR(hasAPR),
itsAPR(APR),
itsPriorityLevel(pLevel)
{
}

Liability::Liability(long lAmount, bool hasAPR, float APR, PriorityLevel pLevel):
itsAmount(0),
itsLAmount(lAmount),
itsAmountType("long"),
itsHasAPR(hasAPR),
itsAPR(APR),
itsPriorityLevel(pLevel)
{
}
 
 
/*
Liability::~Liability()
{
    delete itsPriorityLevel;
    itsPriorityLevel = 0;
}
*/


/**
 The liability amount getter.
 
 @param none.
 @return the liability amount.
 */
double Liability::getAmount() const
{
    return itsAmount;
}


/**
 The liability amount setter.
 
 @param  the liability amount.
 @return nothing.
 */
void Liability::setAmount(double amount)
{
    setAmountType("double");
    itsAmount = amount;
}

double Liability::getLAmount() const
{
    return itsLAmount;
}

void Liability::setLAmount(long lAmount)
{
    setAmountType("long");
    itsLAmount = lAmount;
}


/**
 The liability APR getter.
 
 @param  nothing.
 @return APR.
 */
float Liability::getAPR() const
{
    return itsAPR;
}


/**
 The liability APR setter.
 
 @param  the liability APR.
 @return nothing.
 */
void Liability::setAPR(float APR)
{
    itsAPR = APR;
}


/**
 The liability 'has APR' getter.
 
 @param  nothing.
 @return a boolean indicating whether the liability has APR.
 */
bool Liability::getHasAPR() const
{
    return itsHasAPR;
}


/**
 The liability 'has APR' setter.
 
 @param  the hasAPR boolean.
 @return nothing.
 */
void Liability::setHasAPR(bool hasAPR)
{
    itsHasAPR = hasAPR;
}


/**
 The liability 'priority level' getter.
 
 @param  none.
 @return PriorityLevel.
 */
PriorityLevel Liability::getPriorityLevel() const
{
    return itsPriorityLevel;
}


/**
 The liability 'priority level' setter.
 
 @param  the PriorityLevel.
 @return nothing.
 */
void Liability::setPriorityLevel(PriorityLevel pLevel)
{
    itsPriorityLevel = pLevel;
}


/**
 The liability 'amount type' getter.
 
 @param  none.
 @return the type of liability.
 */
string Liability::getAmountType() const
{
    return itsAmountType;
}


/**
 The liability 'amount type' setter.
 
 @param  the 'amount type' string.
 @return none
 */
void Liability::setAmountType(string amountType)
{
    itsAmountType = amountType;
}
