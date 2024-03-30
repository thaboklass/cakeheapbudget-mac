#include <QtGui>
#include "reminders_dock.h"
#include <iostream>
using namespace std;
RemindersDock::RemindersDock(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);
    originalWidth = width() - 1;
    originalHeight = height() + 1;

    remindersDateColumnWidth  = 60;
    remindersSubjectColumnWidth  = 504;
    
    remindersTable->setShowGrid(false);
    remindersTable->setAlternatingRowColors(true);
    remindersTable->setStyleSheet("QHeaderView::section { text-align: left; } QTableWidget { border: 0px; gridline-color: #fffff8; color: #1b67ac; font-size: 12pt; alternate-background-color: #d1e4f6; background-color: #ffffff; }");
}

void RemindersDock::resizeEvent(QResizeEvent * event)
{
    int extraWidth = width() - originalWidth;
    int extraHeight = height() - originalHeight;
    //cout << extraWidth << endl;

    calendar->setGeometry(600 + extraWidth, 460 + extraHeight, 221, 160);
    scrollArea->setGeometry(0, 0, 600 + extraWidth, 620 + extraHeight);
    remindersTable->setGeometry(10, 40, 581 + extraWidth, 311 + extraHeight);
    messageBox->setGeometry(10, 380 + extraHeight, 571 + extraWidth, 201);
    //progressBar->setGeometry(640 + extraWidth, 10, 118, 23);
    addButton->setGeometry(670 + extraWidth, 50, 75, 32);
    deleteButton->setGeometry(670 + extraWidth, 130, 75, 32);
    editButton->setGeometry(670 + extraWidth, 90, 75, 32);
    textBrowser->setGeometry(35, 40, 501 + extraWidth, 121);

    remindersTable->setColumnWidth(0, remindersDateColumnWidth + extraWidth / 2);
    remindersTable->setColumnWidth(1, remindersSubjectColumnWidth + extraWidth / 2);
    
    int individualColumnsWidth = remindersTable->columnWidth(0) + remindersTable->columnWidth(1);
    cout << individualColumnsWidth << " " << remindersTable->width() << endl;
    
    int widthDifference = remindersTable->width() - individualColumnsWidth;
    
    if (widthDifference > 0)
        remindersTable->setColumnWidth(1, remindersTable->columnWidth(1) + widthDifference);
    
    if (widthDifference < 0)
        remindersTable->setColumnWidth(1, remindersTable->columnWidth(1) - widthDifference);
}
