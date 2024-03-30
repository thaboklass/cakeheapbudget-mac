#include <QtGui>
#include "budget_frame.h"

BudgetFrame::BudgetFrame(QWidget *parent)
    : QFrame(parent)
{
    setupUi(this);
    originalWidth = width() - 1;
    originalHeight = height() + 1;
    //originalTableWidth = incomeTable_2->width();
    incomeDateColumnWidth = 60;
    incomeNameColumnWidth = 133;
    incomeNatureColumnWidth = 70;
    incomeAmountColumnWidth = incomeTable_2->columnWidth(3);
    incomeTaxColumnWidth = 52;
    incomeNetAmountColumnWidth = incomeTable_2->columnWidth(5);
    incomeIDCodeColumnWidth = 50;

    debtDateColumnWidth = 60;
    debtNameColumnWidth = 125;
    debtPriorityLevelColumnWidth = debtTable_2->columnWidth(2);
    debtAmountColumnWidth = 85;
    debtAPRColumnWidth = 60;
    debtNetAmountColumnWidth = 85;
    debtIDCodeColumnWidth = 50;

    expensesDateColumnWidth = 60;
    expensesNameColumnWidth = 125;
    expensesPriorityLevelColumnWidth = expensesTable_2->columnWidth(2);
    expensesAmountColumnWidth = 85;
    expensesAPRColumnWidth = 60;
    expensesNetAmountColumnWidth = 85;
    expensesIDCodeColumnWidth = 50;
    
    incomeTable_2->setShowGrid(false);
    incomeTable_2->setAlternatingRowColors(true);
    incomeTable_2->setStyleSheet("QHeaderView::section { text-align: left; } QTableWidget { border: 0px; gridline-color: #fffff8; color: #1b67ac; font-size: 12pt; alternate-background-color: #d1e4f6; background-color: #ffffff; }");
    
    /*incomeTable_2->setStyleSheet("QHeaderView::section { text-align: left; background-color: #646464; padding: 4px; border: 0px solid #fffff8; font-size: 14pt; } QTableWidget { gridline-color: #fffff8; font-size: 12pt; } QTableWidget QTableCornerButton::section { background-color: #646464; border: 1px solid #fffff8; }");*/
    
    debtTable_2->setShowGrid(false);
    debtTable_2->setAlternatingRowColors(true);
    debtTable_2->setStyleSheet("QHeaderView::section { text-align: left; } QTableWidget { border: 0px; gridline-color: #fffff8; color: #1b67ac; font-size: 12pt; alternate-background-color: #d1e4f6; background-color: #ffffff; }");
    
    expensesTable_2->setShowGrid(false);
    expensesTable_2->setAlternatingRowColors(true);
    expensesTable_2->setStyleSheet("QHeaderView::section { text-align: left; } QTableWidget { border: 0px; gridline-color: #fffff8; color: #1b67ac; font-size: 12pt; alternate-background-color: #d1e4f6; background-color: #ffffff; }");
}

void BudgetFrame::resizeEvent(QResizeEvent * event)
{
    int extraWidth = width() - originalWidth;
    int extraHeight = height() - originalHeight;
    //int extraTableWidth = incomeTable_2->width() - originalTableWidth;
    //cout << width() << " " << minimumWidth() << endl;
    //cout << extraTableWidth << endl;
    incomeTable_2->setGeometry(5, 30, 581 + extraWidth, 111);
    expensesTable_2->setGeometry(5, 410, 581 + extraWidth, 111);
    debtTable_2->setGeometry(5, 220, 581 + extraWidth, 111);
    saveMoneyButton->setGeometry(510 + extraWidth, 530, 75, 23);
    incomeTable_2->setColumnWidth(0, incomeDateColumnWidth + extraWidth / 7);
    incomeTable_2->setColumnWidth(1, incomeNameColumnWidth + extraWidth / 7);
    incomeTable_2->setColumnWidth(2, incomeNatureColumnWidth + extraWidth / 7);
    incomeTable_2->setColumnWidth(3, incomeAmountColumnWidth + extraWidth / 7);
    incomeTable_2->setColumnWidth(4, incomeTaxColumnWidth + extraWidth / 7);
    incomeTable_2->setColumnWidth(5, incomeNetAmountColumnWidth + extraWidth / 7);
    incomeTable_2->setColumnWidth(6, incomeIDCodeColumnWidth + extraWidth / 7);
    
    int individualIncomeColumnsWidth = incomeTable_2->columnWidth(0) + incomeTable_2->columnWidth(1) + incomeTable_2->columnWidth(2) + incomeTable_2->columnWidth(3) + incomeTable_2->columnWidth(4) + incomeTable_2->columnWidth(5) + incomeTable_2->columnWidth(6);
    
    int widthDifference = incomeTable_2->width() - individualIncomeColumnsWidth;
    
    if (widthDifference > 0)
        incomeTable_2->setColumnWidth(6, incomeTable_2->columnWidth(6) + widthDifference);
    
    if (widthDifference < 0)
        incomeTable_2->setColumnWidth(6, incomeTable_2->columnWidth(6) - widthDifference);
    

    debtTable_2->setColumnWidth(0, debtDateColumnWidth + extraWidth / 7);
    debtTable_2->setColumnWidth(1, debtNameColumnWidth + extraWidth / 7);
    debtTable_2->setColumnWidth(2, debtPriorityLevelColumnWidth + extraWidth / 7);
    debtTable_2->setColumnWidth(3, debtAmountColumnWidth + extraWidth / 7);
    debtTable_2->setColumnWidth(4, debtAPRColumnWidth + extraWidth / 7);
    debtTable_2->setColumnWidth(5, debtNetAmountColumnWidth + extraWidth / 7);
    debtTable_2->setColumnWidth(6, debtIDCodeColumnWidth + extraWidth / 7);
    
    int individualDebtColumnsWidth = debtTable_2->columnWidth(0) + debtTable_2->columnWidth(1) + debtTable_2->columnWidth(2) + debtTable_2->columnWidth(3) + debtTable_2->columnWidth(4) + debtTable_2->columnWidth(5) + debtTable_2->columnWidth(6);
    
    widthDifference = debtTable_2->width() - individualDebtColumnsWidth;
    
    if (widthDifference > 0)
        debtTable_2->setColumnWidth(6, debtTable_2->columnWidth(6) + widthDifference);
    
    if (widthDifference < 0)
        debtTable_2->setColumnWidth(6, debtTable_2->columnWidth(6) - widthDifference);
    

    expensesTable_2->setColumnWidth(0, expensesDateColumnWidth + extraWidth / 7);
    expensesTable_2->setColumnWidth(1, expensesNameColumnWidth + extraWidth / 7);
    expensesTable_2->setColumnWidth(2, expensesPriorityLevelColumnWidth + extraWidth / 7);
    expensesTable_2->setColumnWidth(3, expensesAmountColumnWidth + extraWidth / 7);
    expensesTable_2->setColumnWidth(4, expensesAPRColumnWidth + extraWidth / 7);
    expensesTable_2->setColumnWidth(5, expensesNetAmountColumnWidth + extraWidth / 7);
    expensesTable_2->setColumnWidth(6, expensesIDCodeColumnWidth + extraWidth / 7);
    
    int individualExpensesColumnsWidth = expensesTable_2->columnWidth(0) + expensesTable_2->columnWidth(1) + expensesTable_2->columnWidth(2) + expensesTable_2->columnWidth(3) + expensesTable_2->columnWidth(4) + expensesTable_2->columnWidth(5) + expensesTable_2->columnWidth(6);
    
    widthDifference = expensesTable_2->width() - individualExpensesColumnsWidth;
    
    if (widthDifference > 0)
        expensesTable_2->setColumnWidth(6, expensesTable_2->columnWidth(6) + widthDifference);
    
    if (widthDifference < 0)
        expensesTable_2->setColumnWidth(6, expensesTable_2->columnWidth(6) - widthDifference);
}
