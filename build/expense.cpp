#include "expense.h"

/**
 The constructor for the Expense class.
 
 @param name           the name of the expense.
 @param amount         the expense amount(double).
 @param pLevel         the priority level of the expense.
 @param penalty        the penalty (if any) of the expense.
 @param dueDate        the date the payment is due.
 @param additionalInfo the expense metadata.
 @param tabIndex       the index of the tab where the expense belongs.
 */
Expense::Expense(string name, double amount, PriorityLevel pLevel, double penalty, Date dueDate,
    string additionalInfo, int tabIndex):
itsName(name),
itsPenalty(penalty),
itsDueDate(dueDate),
itsAdditionalInfo(additionalInfo),
itsIDCode(0),
itsTabIndex(tabIndex),
Liability(amount, false, 0, pLevel)
{
    setNetAmount();
    itsNetLAmount = 0;
}


/**
 The constructor for the Expense class.
 
 @param name           the name of the expense.
 @param amount         the expense amount(double).
 @param pLevel         the priority level of the expense.
 @param penalty        the penalty (if any) of the expense.
 @param dueDate        the date the payment is due.
 @param additionalInfo the expense metadata.
 @param tabIndex       the index of the tab where the expense belongs.
 */
Expense::Expense(string name, long lAmount, PriorityLevel pLevel, double penalty, Date dueDate,
    string additionalInfo, int tabIndex):
itsName(name),
itsPenalty(penalty),
itsDueDate(dueDate),
itsAdditionalInfo(additionalInfo),
itsIDCode(0),
itsTabIndex(tabIndex),
Liability(lAmount, false, 0, pLevel)
{
    setNetLAmount();
    itsNetAmount = 0;
}
/*
Expense::~Expense()
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
 The Expense name getter.
 
 @param  nothing.
 @return the name of the expense.
 */
string Expense::getName() const
{
    return itsName;
}


/**
 The Expense name setter.
 
 @param  name   the name of the expense.
 @return        nothing.
 */
void Expense::setName(string name)
{
    itsName = name;
}


/**
 The Expense penalty getter.
 
 @param  nothing.
 @return the penalty asssociated with the expense.
 */
double Expense::getPenalty() const
{
    return itsPenalty;
}


/**
 The Expense penalty setter.
 
 @param  name   the penaly associated with the expense.
 @return        nothing.
 */
void Expense::setPenalty(double penalty)
{
    itsPenalty = penalty;
}


/**
 The Expense 'due date' getter.
 
 @param  nothing.
 @return the penalty asssociated with the expense.
 */
Date Expense::getDueDate() const
{
    return itsDueDate;
}


/**
 The Expense 'due date' setter.
 
 @param  name   the due date of the expense.
 @return        nothing.
 */
void Expense::setDueDate(Date dueDate)
{
    itsDueDate = dueDate;
}


/**
 The Expense 'due date' getter.
 
 @param  nothing.
 @return the penalty asssociated with the expense.
 */
double Expense::getNetAmount() const
{
    return itsNetAmount;
}


/**
 The Expense 'net amount' setter.
 
 @param  name   none
 @return        nothing.
 */
void Expense::setNetAmount()
{
    itsNetAmount = getAmount() + itsPenalty;
}


/**
 The Expense 'net amount' getter.
 
 @param  nothing.
 @return the net amount the expense.
 */
double Expense::getNetLAmount() const
{
    return itsNetLAmount;
}


/**
 The Expense 'net amount' setter.
 
 @param  name   none
 @return        nothing.
 */
void Expense::setNetLAmount()
{
    itsNetLAmount = getLAmount() + itsPenalty;
}


/**
 The Expense 'additional info' getter.
 
 @param  nothing.
 @return the metadata the expense.
 */
string Expense::getAdditionalInfo() const
{
    return itsAdditionalInfo;
}


/**
 The Expense 'additional info' setter.
 
 @param  additionalInfo  the expense metadata.
 @return                 nothing.
 */
void Expense::setAdditionalInfo(string additionalInfo)
{
    itsAdditionalInfo = additionalInfo;
}


/**
 The Expense 'ID code' getter.
 
 @param  nothing.
 @return the metadata the expense.
 */
int Expense::getIDCode() const
{
    return itsIDCode;
}


/**
 The Expense 'ID code' setter.
 
 @param  IDCode  the expense ID code.
 @return         nothing.
 */
void Expense::setIDCode(int IDCode)
{
    itsIDCode = IDCode;
}

void Expense::recalculateValues()
{
    setNetAmount();
    setNetLAmount();
}


/**
 The Expense 'tab index' getter.
 
 @param  nothing.
 @return the tab index the expense.
 */
int Expense::getTabIndex()
{
    return itsTabIndex;
}


/**
 The Expense 'ID code' setter.
 
 @param  IDCode  the expense ID code.
 @return         nothing.
 */
void Expense::setTabIndex(int tabIndex)
{
    itsTabIndex = tabIndex;
}
