#include <QtGui>
#include "budget_dock.h"
BudgetDock::BudgetDock(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);
    originalWidth = width() - 1;
    originalHeight = height() + 1;

    /*deleteButton->setFont(QFont("Helvetica Neue"));
    balanceBox->setFont(QFont("Helvetica Neue"));
    currentBalanceLabel->setFont(QFont("Helvetica Neue"));
    currentBalanceLineEdit->setFont(QFont("Helvetica Neue"));
    addButton->setFont(QFont("Helvetica Neue"));
    calendar->setFont(QFont("Helvetica Neue"));
    editButton->setFont(QFont("Helvetica Neue"));
    totalsBox->setFont(QFont("Helvetica Neue"));
    totalMonthlyIncomeLabel->setFont(QFont("Helvetica Neue"));
    totalMonthlyIncomeLineEdit->setFont(QFont("Helvetica Neue"));
    totalMonthlyDebtLabel->setFont(QFont("Helvetica Neue"));
    totalMonthlyDebtLineEdit->setFont(QFont("Helvetica Neue"));
    totalMonthlyExpenseLabel->setFont(QFont("Helvetica Neue"));
    totalMonthlyExpensesLineEdit->setFont(QFont("Helvetica Neue"));*/
    
    /*deleteButton->setMinimumWidth(68);
    addButton->setMinimumWidth(68);
    editButton->setMinimumWidth(68);*/
}

void BudgetDock::resizeEvent(QResizeEvent * event)
{
    int extraWidth = width() - originalWidth;
    int extraHeight = height() - originalHeight;
    //cout << width() << " " << minimumWidth() << endl;
    //cout << extraHeight << endl;
    //progressBar->setGeometry(640 + extraWidth, 10, 118, 23);
    deleteButton->setGeometry(670 + extraWidth, 130, 75, 32);
    balanceBox->setGeometry(610 + extraWidth, 350 + extraHeight / 2, 201, 71);
    scrollArea->setGeometry(0, 0, 600 + extraWidth, 620 + extraHeight);
    addButton->setGeometry(670 + extraWidth, 50, 75, 32);
    calendar->setGeometry(600 + extraWidth, 460 + extraHeight, 221, 159);
    editButton->setGeometry(670 + extraWidth, 90, 75, 32);
    totalsBox->setGeometry(610 + extraWidth, 170 + extraHeight / 2, 201, 171);
}
