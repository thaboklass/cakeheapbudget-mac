#ifndef BUDGET_FRAME_H_INCLUDED
#define BUDGET_FRAME_H_INCLUDED

#include "ui_budget_frame.h"

class BudgetFrame : public QFrame, public Ui::BudgetFrame
{
    Q_OBJECT
public:
    BudgetFrame(QWidget *parent = 0);
    void resizeEvent(QResizeEvent * event);

private:
    int originalWidth;
    int originalHeight;
    //int originalTableWidth;
    int incomeDateColumnWidth;
    int incomeNameColumnWidth;
    int incomeNatureColumnWidth;
    int incomeAmountColumnWidth;
    int incomeTaxColumnWidth;
    int incomeNetAmountColumnWidth;
    int incomeIDCodeColumnWidth;

    int debtDateColumnWidth;
    int debtNameColumnWidth;
    int debtPriorityLevelColumnWidth;
    int debtAmountColumnWidth;
    int debtAPRColumnWidth;
    int debtNetAmountColumnWidth;
    int debtIDCodeColumnWidth;

    int expensesDateColumnWidth;
    int expensesNameColumnWidth;
    int expensesPriorityLevelColumnWidth;
    int expensesAmountColumnWidth;
    int expensesAPRColumnWidth;
    int expensesNetAmountColumnWidth;
    int expensesIDCodeColumnWidth;
};

#endif // BUDGET_FRAME_H_INCLUDED
