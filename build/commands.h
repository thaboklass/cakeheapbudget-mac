/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Commands class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED

#include <QUndoCommand>
#include "main_budget.h"
#include "budget_page.h"

class AddIncomeCommand : public QUndoCommand
{
public:
    friend class MainWin;
    AddIncomeCommand(MainBudget *mb, string name, double amount, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, int IDCode,
            QUndoCommand *parent = 0);
    void undo();
    void redo();

private:
    MainBudget *itsMb;
    Income *itsIncome;
    //QString itsIncomeName;
};

class DeleteIncomeCommand : public QUndoCommand
{
    public:
        friend class MainWin;
        DeleteIncomeCommand(MainBudget *mb, string name, double amount, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, int IDCode,
            QUndoCommand *parent = 0);
        void undo();
        void redo();

    private:
        MainBudget *itsMb;
        Income *itsIncome;
};

class AddExpenseCommand : public QUndoCommand
{
public:
    friend class MainWin;
    AddExpenseCommand(MainBudget *mb, string name, double amount, long lAmount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, int IDCode,
            QUndoCommand *parent = 0);
    void undo();
    void redo();

private:
    MainBudget *itsMb;
    Expense *itsExpense;
};

class DeleteExpenseCommand : public QUndoCommand
{
    public:
        friend class MainWin;
        DeleteExpenseCommand(MainBudget *mb, string name, double amount, long lAmount, PriorityLevel pLevel, double penalty,
            Date dueDate, string additionalInfo, int tabIndex, int IDCode,
            QUndoCommand *parent = 0);
        void undo();
        void redo();

    private:
        MainBudget *itsMb;
        Expense *itsExpense;
};

class AddDebtCommand : public QUndoCommand
{
public:
    friend class MainWin;
    AddDebtCommand(MainBudget *mb, string name, double amount, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel, Date dueDate,
    string additionalInfo, int numberOfMonths, int tabIndex, int IDCode,
            QUndoCommand *parent = 0);
    void undo();
    void redo();

private:
    MainBudget *itsMb;
    Debt *itsDebt;
};

class DeleteDebtCommand : public QUndoCommand
{
    public:
        friend class MainWin;
        DeleteDebtCommand(MainBudget *mb, string name, double amount, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel, Date dueDate,
        string additionalInfo, int numberOfMonths, int tabIndex, int IDCode,
                QUndoCommand *parent = 0);
        void undo();
        void redo();

    private:
        MainBudget *itsMb;
        Debt *itsDebt;
};

class AddSavingsCommand : public QUndoCommand
{
public:
    friend class MainWin;
    AddSavingsCommand(MainBudget *mb, string name, double amount, long lAmount, float APR, SavingsNature nature, Date date, string description, int IDCode,
            QUndoCommand *parent = 0);
    void undo();
    void redo();

private:
    MainBudget *itsMb;
    Savings *itsSavings;
};

class DeleteSavingsCommand : public QUndoCommand
{
    public:
        friend class MainWin;
        DeleteSavingsCommand(MainBudget *mb, string name, double amount, long lAmount, float APR, SavingsNature nature, Date date, string description, int IDCode,
                QUndoCommand *parent = 0);
        void undo();
        void redo();

    private:
        MainBudget *itsMb;
        Savings *itsSavings;
};

class AddItemCommand : public QUndoCommand
{
public:
    friend class MainWin;
    AddItemCommand(MainBudget *mb, string name, double price, int number, string itemID, int IDCode,
            QUndoCommand *parent = 0);
    void undo();
    void redo();

private:
    MainBudget *itsMb;
    Items *itsItem;
};

class DeleteItemCommand : public QUndoCommand
{
    public:
        friend class MainWin;
        DeleteItemCommand(MainBudget *mb, string name, double price, int number, string itemID, int IDCode,
            QUndoCommand *parent = 0);
        void undo();
        void redo();

    private:
        MainBudget *itsMb;
        Items *itsItem;
};

class AddReminderCommand : public QUndoCommand
{
public:
    friend class MainWin;
    AddReminderCommand(MainBudget *mb, Date dueDate, string subject, string message, PriorityLevel pLevel, int IDCode,
            QUndoCommand *parent = 0);
    void undo();
    void redo();

private:
    MainBudget *itsMb;
    Reminder *itsReminder;
};

class DeleteReminderCommand : public QUndoCommand
{
    public:
        friend class MainWin;
        DeleteReminderCommand(MainBudget *mb, Date dueDate, string subject, string message, PriorityLevel pLevel, int IDCode,
            QUndoCommand *parent = 0);
        void undo();
        void redo();

    private:
        MainBudget *itsMb;
        Reminder *itsReminder;
};

#endif // COMMANDS_H_INCLUDED
