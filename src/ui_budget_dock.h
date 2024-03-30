/********************************************************************************
** Form generated from reading UI file 'budget_dock.ui'
**
** Created: Wed 7. Jul 12:08:11 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUDGET_DOCK_H
#define UI_BUDGET_DOCK_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCalendarWidget>
#include <QDockWidget>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
//#include <QProgressBar>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include "cake_calenderwidget.h"

QT_BEGIN_NAMESPACE

class Ui_BudgetDock
{
public:
    QWidget *dockWidgetContents;
    QPushButton *deleteButton;
    QGroupBox *balanceBox;
    QLabel *currentBalanceLabel;
    QLineEdit *currentBalanceLineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *addButton;
    CakeCalendarWidget *calendar;
    QPushButton *editButton;
    QGroupBox *totalsBox;
    QLabel *totalMonthlyIncomeLabel;
    QLineEdit *totalMonthlyIncomeLineEdit;
    QLabel *totalMonthlyDebtLabel;
    QLineEdit *totalMonthlyDebtLineEdit;
    QLabel *totalMonthlyExpenseLabel;
    QLineEdit *totalMonthlyExpensesLineEdit;

    void setupUi(QDockWidget *BudgetDock)
    {
        if (BudgetDock->objectName().isEmpty())
            BudgetDock->setObjectName(QString::fromUtf8("BudgetDock"));
        BudgetDock->resize(825, 620);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        /*progressBar = new QProgressBar(dockWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(640, 10, 118, 23));
        progressBar->setValue(24);*/
        deleteButton = new QPushButton(dockWidgetContents);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(670, 130, 75, 32));
        /*QIcon icon;
        icon.addFile(QString::fromUtf8("images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon);
        deleteButton->setIconSize(QSize(30, 18));*/
        
        balanceBox = new QGroupBox(dockWidgetContents);
        balanceBox->setObjectName(QString::fromUtf8("balanceBox"));
        balanceBox->setGeometry(QRect(610, 350, 201, 71));
        balanceBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dcedc8, stop: 1 #dcedc8); border: 2px solid #dcedc8; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        currentBalanceLabel = new QLabel(balanceBox);
        currentBalanceLabel->setObjectName(QString::fromUtf8("currentBalanceLabel"));
        currentBalanceLabel->setGeometry(QRect(20, 20, 121, 16));
        currentBalanceLineEdit = new QLineEdit(balanceBox);
        currentBalanceLineEdit->setObjectName(QString::fromUtf8("currentBalanceLineEdit"));
        currentBalanceLineEdit->setEnabled(false);
        currentBalanceLineEdit->setGeometry(QRect(20, 40, 161, 20));
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 620));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 598, 598));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        addButton = new QPushButton(dockWidgetContents);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(670, 50, 75, 32));
        /*QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon1);
        addButton->setIconSize(QSize(32, 22));*/
        calendar = new CakeCalendarWidget(dockWidgetContents);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setGeometry(QRect(600, 440, 221, 151));
        editButton = new QPushButton(dockWidgetContents);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(670, 90, 75, 32));
        /*QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon2);
        editButton->setIconSize(QSize(34, 24));*/
        
        totalsBox = new QGroupBox(dockWidgetContents);
        totalsBox->setObjectName(QString::fromUtf8("totalsBox"));
        totalsBox->setGeometry(QRect(610, 170, 201, 171));
        totalsBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffcf8a, stop: 1 #ffcf8a); border: 2px solid #ffcf8a; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        
        totalMonthlyIncomeLabel = new QLabel(totalsBox);
        totalMonthlyIncomeLabel->setObjectName(QString::fromUtf8("totalMonthlyIncomeLabel"));
        totalMonthlyIncomeLabel->setGeometry(QRect(20, 20, 121, 16));
        totalMonthlyIncomeLineEdit = new QLineEdit(totalsBox);
        totalMonthlyIncomeLineEdit->setObjectName(QString::fromUtf8("totalMonthlyIncomeLineEdit"));
        totalMonthlyIncomeLineEdit->setEnabled(false);
        totalMonthlyIncomeLineEdit->setGeometry(QRect(20, 40, 161, 20));
        totalMonthlyDebtLabel = new QLabel(totalsBox);
        totalMonthlyDebtLabel->setObjectName(QString::fromUtf8("totalMonthlyDebtLabel"));
        totalMonthlyDebtLabel->setGeometry(QRect(20, 70, 121, 16));
        totalMonthlyDebtLineEdit = new QLineEdit(totalsBox);
        totalMonthlyDebtLineEdit->setObjectName(QString::fromUtf8("totalMonthlyDebtLineEdit"));
        totalMonthlyDebtLineEdit->setEnabled(false);
        totalMonthlyDebtLineEdit->setGeometry(QRect(20, 90, 161, 20));
        totalMonthlyExpenseLabel = new QLabel(totalsBox);
        totalMonthlyExpenseLabel->setObjectName(QString::fromUtf8("totalMonthlyExpenseLabel"));
        totalMonthlyExpenseLabel->setGeometry(QRect(20, 120, 121, 16));
        totalMonthlyExpensesLineEdit = new QLineEdit(totalsBox);
        totalMonthlyExpensesLineEdit->setObjectName(QString::fromUtf8("totalMonthlyExpensesLineEdit"));
        totalMonthlyExpensesLineEdit->setEnabled(false);
        totalMonthlyExpensesLineEdit->setGeometry(QRect(20, 140, 161, 20));
        BudgetDock->setWidget(dockWidgetContents);

        retranslateUi(BudgetDock);

        QMetaObject::connectSlotsByName(BudgetDock);
    } // setupUi

    void retranslateUi(QDockWidget *BudgetDock)
    {
        BudgetDock->setWindowTitle(QApplication::translate("BudgetDock", "Budget", 0));
        deleteButton->setText(QApplication::translate("BudgetDock", "Delete", 0));
        balanceBox->setTitle(QApplication::translate("BudgetDock", "", 0));
        currentBalanceLabel->setText(QApplication::translate("BudgetDock", "Budget Balance:", 0));
        addButton->setText(QApplication::translate("BudgetDock", "Add", 0));
        editButton->setText(QApplication::translate("BudgetDock", "Edit", 0));
        totalsBox->setTitle(QApplication::translate("BudgetDock", "", 0));
        totalMonthlyIncomeLabel->setText(QApplication::translate("BudgetDock", "Monthly Income:", 0));
        totalMonthlyDebtLabel->setText(QApplication::translate("BudgetDock", "Monthly Debt:", 0));
        totalMonthlyExpenseLabel->setText(QApplication::translate("BudgetDock", "Monthly Expenses:", 0));
    } // retranslateUi
};

namespace Ui {
    class BudgetDock: public Ui_BudgetDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGET_DOCK_H
