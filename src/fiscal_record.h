/**
 CakeHeap Budget for Mac
 fiscal_record.h
 Purpose: The Fiscal Record class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef FISCAL_RECORD_H_INCLUDED
#define FISCAL_RECORD_H_INCLUDED
#include "income.h"
#include "debt.h"
#include "expense.h"
#include "savings.h"
#include "inventory.h"
#include "reminder.h"
#include <string>
using namespace std;

typedef vector<Income> IncomeList;
typedef vector<Debt> DebtList;
typedef vector<Expense> ExpenseList;
typedef vector<Savings> SavingsList;
typedef vector<Items> ItemList;
typedef vector<Reminder> ReminderList;

class FiscalRecord
{
    public:
        FiscalRecord(string fileName, string userName, IncomeList itsIncome,
                    DebtList debt, ExpenseList expenses, SavingsList savings,
                    ItemList items, ReminderList reminders);
        ~FiscalRecord() {}
        string getFileName()const;
        void setFileName(string fileName);
        string getUserName() const;
        void setUserName(string userName);
        IncomeList getIncome() const;
        void setIncome(IncomeList income);
        DebtList getDebt() const;
        void setDebt(DebtList debt);
        ExpenseList getExpenses() const;
        void setExpenses(ExpenseList expenses);
        SavingsList getSavings() const;
        void setSavings(SavingsList savings);
        ItemList getItems() const;
        void setItems(ItemList items);
        ReminderList getReminders() const;
        void setReminders(ReminderList reminders);
        //FiscalRecord & operator=(const FiscalRecord &rhs);
    private:
        string itsFileName;
        string itsUserName;
        IncomeList itsIncome;
        DebtList itsDebt;
        ExpenseList itsExpenses;
        SavingsList itsSavings;
        ItemList itsItems;
        ReminderList itsReminders;
};

#endif // FISCAL_RECORD_H_INCLUDED
