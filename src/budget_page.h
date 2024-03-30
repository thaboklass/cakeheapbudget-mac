/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Budget Page model: deals
 with all the commands on the budget page
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef BUDGET_PAGE_H_INCLUDED
#define BUDGET_PAGE_H_INCLUDED

#include "menu.h"
#include "fiscal_record.h"

void addIncome(string name, double amount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, IncomeList &iList);

void addLIncome(string name, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, IncomeList &iList);

void addIncomeAgain(string name, double amount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, int IDCode, IncomeList &iList);

void addLIncomeAgain(string name, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, int IDCode, IncomeList &iList);

void editIncome(string name, double amount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, IncomeList &iList, int IDCode);

void editLIncome(string name, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, IncomeList &iList, int IDCode);

void deleteIncome(IncomeList &iList, int IDCode);

void addOneToTabIndices(IncomeList &iList, int i, string amountType);

void addDebt(string name, double amount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, DebtList &dList);

void editDebt(string name, double amount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, DebtList &dList, int IDCode);

void addLDebt(string name, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, DebtList &dList);

void editLDebt(string name, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, DebtList &dList, int IDCode);

void deleteDebt(DebtList &dList, int IDCode);

void addDebtAgain(string name, double amount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, int IDCode, DebtList &dList);

void addLDebtAgain(string name, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, int IDCode, DebtList &dList);

void addExpense(string name, double amount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, ExpenseList &iList);

void editExpense(string name, double amount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, ExpenseList &eList, int IDCode);

void addLExpense(string name, long lAmount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, ExpenseList &iList);

void editLExpense(string name, long lAmount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, ExpenseList &eList, int IDCode);

void addExpenseAgain(string name, double amount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, int IDCode, ExpenseList &iList);

void addLExpenseAgain(string name, long lAmount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, int IDCode, ExpenseList &iList);

void deleteExpense(ExpenseList &eList, int IDCode);

void saveMoney(ExpenseList &eList, SavingsList &sList, int savingsIDCode,
    double amount, PriorityLevel pLevel, Date dueDate, string additionalInfo, int tabIndex);

void saveLMoney(ExpenseList &eList, SavingsList &sList, int savingsIDCode,
    long amount, PriorityLevel pLevel, Date dueDate, string additionalInfo, int tabIndex);

void shuffleIncomeTabs(int month, int year, int tabIndex, IncomeList &iList);

void shuffleDebtTabs(int month, int year, int tabIndex, DebtList &dList);

void shuffleExpenseTabs(int month, int year, int tabIndex, ExpenseList &eList);



float getBudgetBalance(IncomeList iList, DebtList dList, ExpenseList eList);

void addSavings(string name, double amount, float APR, SavingsNature nature, Date date, string description, SavingsList &sList);

void editSavings(string name, double amount, float APR, SavingsNature nature, Date date,
    string description, SavingsList &sList, int IDCode);

void addLSavings(string name, long lAmount, float APR, SavingsNature nature, Date date, string description, SavingsList &sList);

void editLSavings(string name, long lAmount, float APR, SavingsNature nature, Date date,
    string description, SavingsList &sList, int IDCode);

void deleteSavings(SavingsList &sList, int IDCode);

void getMoney(SavingsList &sList, IncomeList &iList, int savingsIDCode,
    double amount, Date receivedDate);

void getLMoney(SavingsList &sList, IncomeList &iList, int savingsIDCode,
    long lAmount, Date receivedDate);

float getSavingsBalance(SavingsList sList);

void addSavingsAgain(string name, double amount, float APR, SavingsNature nature, Date date, string description, int IDCode, SavingsList &sList);

void addLSavingsAgain(string name, long lAmount, float APR, SavingsNature nature, Date date, string description, int IDCode, SavingsList &sList);



void addItem(string name, double price, int number, string itemID, ItemList &iList);

void editItem(string name, double price, int number, string itemID, ItemList &iList, int IDCode);

void deleteItem(ItemList &iList, int IDCode);

void addItemAgain(string name, double price, int number, string itemID, int IDCode, ItemList &iList);



void addReminder(Date dueDate, string subject, string message, PriorityLevel pLevel, ReminderList &rList);

void editReminder(Date dueDate, string subject, string message, PriorityLevel pLevel,
    ReminderList &rList, int IDCode);

void deleteReminder(ReminderList &rList, int IDCode);

void addReminderAgain(Date dueDate, string subject, string message, PriorityLevel pLevel,
    int IDCode, ReminderList &rList);
#endif // BUDGET_PAGE_H_INCLUDED
