#include "asset.h"

/**
 The constructor for the Debt class.
 
 @param name           the name of the debt.
 @param amount         the debt amount(double).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param pLevel         the priority level of the debt.
 @param date           the date the payment is due.
 @param additionalInfo the debt metadata.
 @param numberOfMonths the number of months the payment is spread across.
 @param tabIndex       the index of the tab where the debt belongs.
 */
Asset::Asset(double amount, bool hasAPR, float APR):
itsAmount(amount),
itsLAmount(0),
itsAmountType("double"),
itsHasAPR(hasAPR),
itsAPR(APR)
{
}

Asset::Asset(long lAmount, bool hasAPR, float APR):
itsAmount(0),
itsLAmount(lAmount),
itsAmountType("long"),
itsHasAPR(hasAPR),
itsAPR(APR)
{
}


/**
 The Asset amount getter.
 
 @param             none.
 @return itsAmount  the amount value of the asset.
 */
double Asset::getAmount() const
{
    return itsAmount;
}


/**
 The Asset amount setter.
 
 @param amount    the amount value of the asset.
 @return          nothing.
 */
void Asset::setAmount(double amount)
{
    setAmountType("double");
    itsAmount = amount;
}

double Asset::getLAmount() const
{
    //cout << "this is it " << itsLAmount << endl;
    return itsLAmount;
}

void Asset::setLAmount(long lAmount)
{
    setAmountType("long");
    itsLAmount = lAmount;
}


/**
 The Asset APR getter.
 
 @param          none.
 @return itsAPR  the value of the APR.
 */
float Asset::getAPR() const
{
    return itsAPR;
}


/**
 The Asset APR setter.
 
 @param  APR  the apr.
 @return itsAPR  the value of the APR.
 */
void Asset::setAPR(float APR)
{
    itsAPR = APR;
}


/**
 The Asset 'has APR' getter.
 
 @param            none.
 @return itsHasAPR  whether the Asset has an APR.
 */
bool Asset::getHasAPR() const
{
    return itsHasAPR;
}


/**
 The Asset 'has APR' setter.
 
 @param itsHasAPR  whether the Asset has an APR.
 @return           nothing.
 */
void Asset::setHasAPR(bool hasAPR)
{
    itsHasAPR = hasAPR;
}


/**
 The Asset 'amount type' getter.
 
 @param            none.
 @return itsAmountType  the type of amount.
 */
string Asset::getAmountType() const
{
    return itsAmountType;
}


/**
 The Asset 'amount type' setter.
 
 @param  itsAmountType  the type of amount.
 @return                nothing.
 */
void Asset::setAmountType(string amountType)
{
    itsAmountType = amountType;
}
