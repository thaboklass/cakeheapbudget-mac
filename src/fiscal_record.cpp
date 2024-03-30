#include "fiscal_record.h"

/**
 The constructor for the FiscalRecord class.
 
 @param fileName       the file name of the fiscal record.
 @param userName       the record creator's user name.
 @param income         the income list.
 @param debt           the debt list.
 @param expense        the expense list.
 @param savings        the savings list.
 @param items          the items list.
 @param reminders      the reminders list.
 */
FiscalRecord::FiscalRecord(string fileName, string userName, IncomeList income,
                    DebtList debt, ExpenseList expenses, SavingsList savings,
                    ItemList items, ReminderList reminders):
itsFileName(fileName),
itsUserName(userName),
itsIncome(income),
itsDebt(debt),
itsExpenses(expenses),
itsSavings(savings),
itsItems(items),
itsReminders(reminders)
{
}
/*
FiscalRecord::~FiscalRecord()
{
    delete itsFileName;
    itsFileName = 0;
    delete itsUserName;
    itsUserName = 0;
    delete itsIncome;
    itsIncome = 0;
    delete itsDebt;
    itsDebt = 0;
    delete itsExpenses;
    itsExpenses = 0;
    delete itsSavings;
    itsSavings = 0;
    delete itsItems;
    itsItems = 0;
    delete itsReminders;
    itsReminders = 0;
}
*/


/**
 The Fiscal Record file name getter.
 
 @param  none.
 @return the fileName.
 */
string FiscalRecord::getFileName() const
{
    return itsFileName;
}


/**
 The Fiscal Record file name setter.
 
 @param fileName the fiscal record's file name.
 @return         nothing.
 */
void FiscalRecord::setFileName(string fileName)
{
    itsFileName = fileName;
}


/**
 The Fiscal Record user name getter.
 
 @param  none.
 @return the user name.
 */
string FiscalRecord::getUserName() const
{
    return itsUserName;
}


/**
 The Fiscal Record user name setter.
 
 @param userName the fiscal record's user name.
 @return         nothing.
 */
void FiscalRecord::setUserName(string userName)
{
    itsUserName = userName;
}


/**
 The Fiscal Record income getter.
 
 @param  none.
 @return the income.
 */
IncomeList FiscalRecord::getIncome() const
{
    return itsIncome;
}


/**
 The Fiscal Record income setter.
 
 @param income the fiscal record's income.
 @return         nothing.
 */
void FiscalRecord::setIncome(IncomeList income)
{/*
    if (itsIncome)
    {
        //delete itsIncome;
        itsIncome = income;
    }
    else*/
        itsIncome = income;
}


/**
 The Fiscal Record debt getter.
 
 @param  none.
 @return the debt.
 */
DebtList FiscalRecord::getDebt() const
{
    return itsDebt;
}


/**
 The Fiscal Record debt setter.
 
 @param debt     the fiscal record's debt.
 @return         nothing.
 */
void FiscalRecord::setDebt(DebtList debt)
{/*
    if (itsDebt)
    {
        //delete itsDebt;
        itsDebt = debt;
    }
    else*/
        itsDebt = debt;
}


/**
 The Fiscal Record expense getter.
 
 @param  none.
 @return the expense.
 */
ExpenseList FiscalRecord::getExpenses() const
{
    return itsExpenses;
}


/**
 The Fiscal Record expense setter.
 
 @param expense  the fiscal record's expense.
 @return         nothing.
 */
void FiscalRecord::setExpenses(ExpenseList expenses)
{/*
    if (itsExpenses)
    {
        //delete itsExpenses;
        itsExpenses = expenses;
    }
    else*/
        itsExpenses = expenses;
}


/**
 The Fiscal Record expense getter.
 
 @param  none.
 @return the expense.
 */
SavingsList FiscalRecord::getSavings() const
{
    return itsSavings;
}


/**
 The Fiscal Record savings setter.
 
 @param savings  the fiscal record's savings.
 @return         nothing.
 */
void FiscalRecord::setSavings(SavingsList savings)
{/*
    if (itsSavings)
    {
        //delete itsSavings;
        itsSavings = savings;
    }
    else*/
        itsSavings = savings;
}


/**
 The Fiscal Record items getter.
 
 @param  none.
 @return the items.
 */
ItemList FiscalRecord::getItems() const
{
    return itsItems;
}


/**
 The Fiscal Record items setter.
 
 @param items    the fiscal record's inventory.
 @return         nothing.
 */

void FiscalRecord::setItems(ItemList items)
{/*
    if (itsItems)
    {
        //delete itsSavings;
        itsItems = items;
    }
    else*/
        itsItems;
}


/**
 The Fiscal Record reminders getter.
 
 @param  none.
 @return the reminders.
 */
ReminderList FiscalRecord::getReminders() const
{
    return itsReminders;
}


/**
 The Fiscal Record reminders setter.
 
 @param reminders   the fiscal record's reminders.
 @return            nothing.
 */
void FiscalRecord::setReminders(ReminderList reminders)
{/*
    if (itsReminders)
    {
        //delete itsReminders;
        itsReminders = reminders;
    }
    else*/
        itsReminders = reminders;
}
/*
FiscalRecord & FiscalRecord::operator=(const FiscalRecord & rhs)
{
    if (this == &rhs)
        return *this;
    itsFileName = rhs.getFileName();
    itsUserName = rhs.getUserName();
    itsIncome = rhs.getIncome();
    itsDebt = rhs.getDebt();
    itsExpenses = rhs.getExpenses();
    itsSavings = rhs.getSavings();
    itsItems = rhs.getItems();
    itsReminders = rhs.getReminders();
}
*/
