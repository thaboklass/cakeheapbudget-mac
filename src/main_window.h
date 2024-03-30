/**
 CakeHeap Budget for Mac
 main_window.h
 Purpose: The MainWin class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef MAIN_WINDOW_H_INCLUDED
#define MAIN_WINDOW_H_INCLUDED

#include <QMainWindow>
#include "main_budget.h"
#include "commands.h"

class MainWin : QMainWindow
{
    Q_OBJECT
    public:
        friend class MainBudget;
        MainWin();
        ~MainWin();

    public:
        MainBudget *mb;

    private slots:
        void addIncomeClick();
        void addOnSelectedItem();
        void insertIncomeDialogValues();
        void closeIncomeDialog();
        void deleteSelectedItem();
        void addExpenseClick();
        void closeExpensesDialog();
        void insertExpensesDialogValues();
        void addDebtClick();
        void insertDebtDialogValues();
        void closeDebtDialog();
        void addSavingsClick();
        void closeSavingsDialog();
        void insertSavingsDialogValues();
        void deleteSelectedSavings();
        void addItemClick();
        void closeItemDialog();
        void insertItemDialogValues();
        void deleteSelectedInventoryItem();
        void addReminderClick();
        void closeReminderDialog();
        void insertReminderDialogValues();
        void deleteSelectedReminder();
        void activateCurrentBudgetTabForMainWin();
};

#endif // MAIN_WINDOW_H_INCLUDED
