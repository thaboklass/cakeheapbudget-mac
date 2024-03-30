#include "income.h"
#include "budget_page.h"

/**
 The constructor for the Income class.
 
 @param name           the name of the income.
 @param amount         the income amount(double).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param date           the date the payment is received.
 @param nature         the nature of the income.
 @param tex            the tax rate.
 @param additionalInfo the income metadata.
 @param tabIndex       the index of the tab where the debt belongs.
 */
Income::Income(string name, double amount, bool hasAPR, float APR, Date receivedDate, Nature nature, float tax,
    string additionalInfo, int tabIndex):
itsName(name),
itsReceivedDate(receivedDate),
itsNature(nature),
itsTax(tax),
itsAdditionalInfo(additionalInfo),
itsIDCode(0),
itsTabIndex(tabIndex),
Asset(amount, hasAPR, APR)
{
    if (itsNature != IOU)
        itsIsTaxable = true;
    else
        itsIsTaxable = false;
    setNetAmount(itsTax);

    itsNetLAmount = 0;
}


/**
 The constructor for the Income class.
 
 @param name           the name of the income.
 @param amount         the income amount(long).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param date           the date the payment is received.
 @param nature         the nature of the income.
 @param tex            the tax rate.
 @param additionalInfo the income metadata.
 @param tabIndex       the index of the tab where the debt belongs.
 */
Income::Income(string name, long lAmount, bool hasAPR, float APR, Date receivedDate, Nature nature, float tax,
    string additionalInfo, int tabIndex):
itsName(name),
itsReceivedDate(receivedDate),
itsNature(nature),
itsTax(tax),
itsAdditionalInfo(additionalInfo),
itsIDCode(0),
itsTabIndex(tabIndex),
Asset(lAmount, hasAPR, APR)
{
    if (itsNature != IOU)
        itsIsTaxable = true;
    else
        itsIsTaxable = false;
    setNetLAmount(itsTax);
    itsNetAmount = 0;
}


/**
 The Income nature getter.
 
 @param  nothing.
 @return the nature of the income.
 */
Nature Income::getNature() const
{
    return itsNature;
}


/**
 The Income nature setter.
 
 @param nature  the nature of the income.
 @return        nothing.
 */
void Income::setNature(Nature nature)
{
    itsNature = nature;
}


/**
 The Income 'is taxable' getter.
 
 @param                nothing.
 @return itsIsTaxable  a boolean indicating whether in the income is taxable.
 */
bool Income::getIsTaxable() const
{
    return itsIsTaxable;
}


/**
 The Income nature setter.
 
 @param nature  the nature of the income.
 @return        nothing.
 */
void Income::setIsTaxable(bool isTaxable)
{
    itsIsTaxable = isTaxable;
}


/**
 The Income tax getter.
 
 @param                nothing.
 @return itsTax the % value of tax paid.
 */
float Income::getTax() const
{
    return itsTax;
}


/**
 The Income tax setter.
 
 @param tax     the % value of tax paid.
 @return        nothing.
 */
void Income::setTax(float tax)
{
    itsTax = tax;
}


/**
 The Income 'net amount' getter.
 
 @param                nothing.
 @return itsNetAmount  the % value of tax paid.
 */
double Income::getNetAmount() const
{
    return itsNetAmount;
}


/**
 The Income 'net amount' setter.
 
 @param tax     the income net amount.
 @return        nothing.
 */
void Income::setNetAmount(float tax)
{
    if (itsIsTaxable)
    {
        double taxAmount = (getAmount() * tax) / 100;
        itsNetAmount = getAmount() - taxAmount;
    }
    else
        itsNetAmount = getAmount();
}

double Income::getNetLAmount() const
{
    return itsNetLAmount;
}

void Income::setNetLAmount(float tax)
{
    if (itsIsTaxable)
    {
        long taxAmount = (getLAmount() * tax) / 100;
        itsNetLAmount = getLAmount() - taxAmount;
        //cout << itsNetLAmount << endl;
    }
    else
    {
        itsNetLAmount = getLAmount();
        //cout << itsNetLAmount << endl;
    }
}


/**
 The Income 'received date' getter.
 
 @param                   nothing.
 @return itsReceivedDate  the date the income was received.
 */
Date Income::getReceivedDate() const
{
    return itsReceivedDate;
}


/**
 The Income 'received date' setter.
 
 @param receivedDate     the income net amount.
 @return                 nothing.
 */
void Income::setReceivedDate(Date receivedDate)
{
    itsReceivedDate = receivedDate;
}


/**
 The Income name getter.
 
 @param           nothing.
 @return itsName  the name of the income.
 */
string Income::getName() const
{
    return itsName;
}


/**
 The Income name setter.
 
 @param name     the name of the income.
 @return         nothing.
 */
void Income::setName(string name)
{
    itsName = name;
}


/**
 The Income 'additional info' getter.
 
 @param                     nothing.
 @return itsAdditionalInfo  the income metadata.
 */
string Income::getAdditionalInfo() const
{
    return itsAdditionalInfo;
}


/**
 The Income 'additional info' setter.
 
 @param itsAdditionalInfo  the income metadata.
 @return                   nothing.
 */
void Income::setAdditionalInfo(string additionalInfo)
{
    itsAdditionalInfo = additionalInfo;
}


/**
 The Income 'ID code' getter.
 
 @param             none.
 @return itsIDCode  the income ID code.
 */
int Income::getIDCode() const
{
    return itsIDCode;
}


/**
 The Income 'ID code' setter.
 
 @param itsIDCode  the income metadata.
 @return           nothing.
 */
void Income::setIDCode(int IDCode)
{
    itsIDCode = IDCode;
}

void Income::recalculateValues()
{
    if (getAmountType() == "double")
        setNetAmount(itsTax);
    else
        setNetLAmount(itsTax);
}


/**
 The Income 'tab index' getter.
 
 @param               none.
 @return itsTabIndex  the income tab index.
 */
int Income::getTabIndex()
{
    return itsTabIndex;
}


/**
 The Income 'tab index' setter.
 
 @param tabIndex   the income tab index.
 @return           nothing.
 */
void Income::setTabIndex(int tabIndex)
{
    itsTabIndex = tabIndex;
}
