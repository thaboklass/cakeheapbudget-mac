#include "debt.h"

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
Debt::Debt(string name, double amount, bool hasAPR, float APR, PriorityLevel pLevel, Date dueDate,
    string additionalInfo, int numberOfMonths, int tabIndex):
itsName(name),
itsDueDate(dueDate),
itsAdditionalInfo(additionalInfo),
itsIDCode(0),
itsNumberOfMonths(numberOfMonths),
itsTabIndex(tabIndex),
Liability(amount, hasAPR , APR, pLevel) // this amount may be a new amount or the amount carried
{
    itsPenalty = 0;                                       // forward from the previous month
}


/**
 The constructor for the Debt class.
 
 @param name           the name of the debt.
 @param amount         the debt amount(long).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param pLevel         the priority level of the liability.
 @param date           the date the payment is due.
 @param additionalInfo the debt metadata.
 @param numberOfMonths the number of months the payment is spread across.
 @param tabIndex       the index of the tab where the debt belongs.
 */
Debt::Debt(string name, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel, Date dueDate,
    string additionalInfo, int numberOfMonths, int tabIndex):
itsName(name),
itsDueDate(dueDate),
itsAdditionalInfo(additionalInfo),
itsIDCode(0),
itsNumberOfMonths(numberOfMonths),
itsTabIndex(tabIndex),
Liability(lAmount, hasAPR , APR, pLevel) // this amount may be a new amount or the amount carried
{
    itsPenalty = 0;                                       // forward from the previous month
}
/*
Debt::~Debt()
{
    delete itsDueDate;
    itsDueDate = 0;
    delete itsName;
    itsName = 0;
    delete itsAdditionalInfo;
    itsAdditionalInfo = 0;
}
*/


/**
 The Debt name getter.
 
 @param  nothing.
 @return the name of the debt.
 */
string Debt::getName() const
{
    return itsName;
}


/**
 The debt name setter.
 
 @param name  the name of the debt.
 @return      nothing.
 */
void Debt::setName(string name)
{
    itsName = name;
}


/**
 The debt penalty getter.
 
 @param       none.
 @return      the debt penalty.
 */
double Debt::getPenalty() const
{
    return itsPenalty;
}


/**
 The debt penalty setter.
 
 @param penalty  the penalty amount.
 @return         nothing.
 */
void Debt::setPenalty(double penalty)
{
    itsPenalty = penalty;
}


/**
 The due date setter.
 
 @param          none.
 @return         the due date.
 */
Date Debt::getDueDate() const
{
    return itsDueDate;
}


/**
 The due date setter.
 
 @param          none.
 @return         the due date.
 */
void Debt::setDueDate(Date dueDate)
{
    itsDueDate = dueDate;
}

/**
 The due date setter.
 
 @param          none.
 @return         the due date.
 */
string Debt::getAdditionalInfo() const
{
    return itsAdditionalInfo;
}


/**
 The metadata setter.
 
 @param additionaInfo    the metadata.
 @return                 nothing.
 */
void Debt::setAdditionalInfo(string additionalInfo)
{
    itsAdditionalInfo = additionalInfo;
}

/*
void Debt::setNetAmount(double netAmount)
{
    itsNetAmount = netAmount;
}*/


/**
 Sets the current month's net amount from an initial amount which may be
 a new amount entered by the user or the previous month's net amount.
 
 @param     none.
 @return    nothing
 */
void Debt::setNetAmount()
{
    itsNetAmount = (getAmount() / itsNumberOfMonths) + (getAmount() * (getAPR() / 1200)) + itsPenalty;
}


/**
 The Debt net amount getter.
 
 @param                none.
 @return itsNetAmount  the net amount of debt per month.
 */
double Debt::getNetAmount()
{
    setNetAmount();
    return itsNetAmount;
}


/**
 Sets the current month's net amount from an initial amount which may be
 a new amount entered by the user or the previous month's net amount.
 
 @param     none.
 @return    nothing
 */
void Debt::setNetLAmount()
{
    itsNetLAmount = (getLAmount() / itsNumberOfMonths) + (getLAmount() * (getAPR() / 1200)) + itsPenalty;
}

/**
 The Debt net amount getter.
 
 @param                none.
 @return itsNetAmount  the net amount of debt per month.
 */
double Debt::getNetLAmount()
{
    setNetLAmount();
    return itsNetLAmount;
}


/**
 The Debt 'ID code' getter.
 
 @param             none.
 @return itsIDCode  the ID code.
 */
int Debt::getIDCode() const
{
    return itsIDCode;
}


/**
 The Debt 'ID code' getter.
 
 @param             none.
 @return itsIDCode  the ID code.
 */
void Debt::setIDCode(int IDCode)
{
    itsIDCode = IDCode;
}

/**
 The number of months getter.
 
 @param                     none.
 @return itsNumberOfMonths  the number of months the debt is spread out.
 */
int Debt::getNumberOfMonths()
{
    return itsNumberOfMonths;
}


/**
 The number of months getter.
 
 @param                     none.
 @return itsNumberOfMonths  the number of months the debt is spread out.
 */
void Debt::setNumberOfMonths(int numberOfMonths)
{
    itsNumberOfMonths = numberOfMonths;
}


/**
 Get the tab index of the debt.
 
 @param               none.
 @return itsTabIndex  the tab index of the debt.
 */
int Debt::getTabIndex()
{
    return itsTabIndex;
}


/**
 Set the tab index of the debt.
 
 @param  itsTabIndex  the tab index of the debt.
 @return              nothing.
 */
void Debt::setTabIndex(int tabIndex)
{
    itsTabIndex = tabIndex;
}
