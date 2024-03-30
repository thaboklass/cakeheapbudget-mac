#include <QtGui>
#include "savings_dock.h"
SavingsDock::SavingsDock(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);
    originalWidth = width() - 1;
    originalHeight = height() + 1;

    savingsNameColumnWidth  = savingsTable->columnWidth(0) + 26;
    savingsNatureColumnWidth  = 60;
    savingsAPRColumnWidth  = savingsTable->columnWidth(2);
    savingsAmountColumnWidth  = savingsTable->columnWidth(3);
    
    savingsTable->setShowGrid(false);
    savingsTable->setAlternatingRowColors(true);
    savingsTable->setStyleSheet("QHeaderView::section { text-align: left; } QTableWidget { border: 0px; gridline-color: #fffff8; color: #1b67ac; font-size: 12pt; alternate-background-color: #d1e4f6; background-color: #ffffff; }");
    
    calendar->setGeometry(600, 460, 221, 160);
}

void SavingsDock::resizeEvent(QResizeEvent * event)
{
    int extraWidth = width() - originalWidth;
    int extraHeight = height() - originalHeight;
    //cout << savingsNameColumnWidth << endl;

    calendar->setGeometry(600 + extraWidth, 460 + extraHeight, 221, 160);
    pushButton->setGeometry(670 + extraWidth, 170, 75, 32);
    balanceBox->setGeometry(610 + extraWidth, 350 + extraHeight / 2, 201, 71);
    deleteButton->setGeometry(670 + extraWidth, 130, 75, 32);
    //progressBar->setGeometry(640 + extraWidth, 10, 118, 23);
    editButton->setGeometry(670 + extraWidth, 90, 75, 32);
    scrollArea->setGeometry(0, 0, 600 + extraWidth, 620 + extraHeight);
    addButton->setGeometry(670 + extraWidth, 50, 75, 32);
    savingsTable->setGeometry(10, 40, 581 + extraWidth, 311 + extraHeight);
    descriptionBox->setGeometry(QRect(10, 380 + extraHeight, 571 + extraWidth, 201));
    textBrowser->setGeometry(40, 40, 491 + extraWidth, 131);

    savingsTable->setColumnWidth(0, savingsNameColumnWidth + extraWidth / 4);
    savingsTable->setColumnWidth(1, savingsNatureColumnWidth + extraWidth / 4);
    savingsTable->setColumnWidth(2, savingsAPRColumnWidth + extraWidth / 4);
    savingsTable->setColumnWidth(3, savingsAmountColumnWidth + extraWidth / 4);
    
    int individualColumnsWidth = savingsTable->columnWidth(0) + savingsTable->columnWidth(1) + savingsTable->columnWidth(2) + savingsTable->columnWidth(3);
    
    int widthDifference = savingsTable->width() - individualColumnsWidth;
    
    if (widthDifference > 0)
        savingsTable->setColumnWidth(3, savingsTable->columnWidth(3) + widthDifference);
    
    if (widthDifference < 0)
        savingsTable->setColumnWidth(3, savingsTable->columnWidth(3) - widthDifference);
}
