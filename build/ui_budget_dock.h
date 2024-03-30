/********************************************************************************
** Form generated from reading UI file 'budget_dock.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUDGET_DOCK_H
#define UI_BUDGET_DOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

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
    QCalendarWidget *calendar;
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
            BudgetDock->setObjectName(QStringLiteral("BudgetDock"));
        BudgetDock->resize(825, 620);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        deleteButton = new QPushButton(dockWidgetContents);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(650, 130, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../wamp/www/budget_project/budget_project/gui/delete.gif"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon);
        deleteButton->setIconSize(QSize(30, 18));
        balanceBox = new QGroupBox(dockWidgetContents);
        balanceBox->setObjectName(QStringLiteral("balanceBox"));
        balanceBox->setGeometry(QRect(610, 350, 201, 71));
        currentBalanceLabel = new QLabel(balanceBox);
        currentBalanceLabel->setObjectName(QStringLiteral("currentBalanceLabel"));
        currentBalanceLabel->setGeometry(QRect(20, 20, 121, 16));
        currentBalanceLineEdit = new QLineEdit(balanceBox);
        currentBalanceLineEdit->setObjectName(QStringLiteral("currentBalanceLineEdit"));
        currentBalanceLineEdit->setEnabled(false);
        currentBalanceLineEdit->setGeometry(QRect(20, 40, 161, 20));
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 600));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 598, 598));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        addButton = new QPushButton(dockWidgetContents);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(650, 50, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../wamp/www/budget_project/budget_project/gui/add.gif"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon1);
        addButton->setIconSize(QSize(32, 22));
        calendar = new QCalendarWidget(dockWidgetContents);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setGeometry(QRect(600, 440, 221, 151));
        editButton = new QPushButton(dockWidgetContents);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(650, 90, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../wamp/www/budget_project/budget_project/gui/edit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon2);
        editButton->setIconSize(QSize(34, 24));
        totalsBox = new QGroupBox(dockWidgetContents);
        totalsBox->setObjectName(QStringLiteral("totalsBox"));
        totalsBox->setGeometry(QRect(610, 170, 201, 171));
        totalMonthlyIncomeLabel = new QLabel(totalsBox);
        totalMonthlyIncomeLabel->setObjectName(QStringLiteral("totalMonthlyIncomeLabel"));
        totalMonthlyIncomeLabel->setGeometry(QRect(20, 20, 121, 16));
        totalMonthlyIncomeLineEdit = new QLineEdit(totalsBox);
        totalMonthlyIncomeLineEdit->setObjectName(QStringLiteral("totalMonthlyIncomeLineEdit"));
        totalMonthlyIncomeLineEdit->setEnabled(false);
        totalMonthlyIncomeLineEdit->setGeometry(QRect(20, 40, 161, 20));
        totalMonthlyDebtLabel = new QLabel(totalsBox);
        totalMonthlyDebtLabel->setObjectName(QStringLiteral("totalMonthlyDebtLabel"));
        totalMonthlyDebtLabel->setGeometry(QRect(20, 70, 121, 16));
        totalMonthlyDebtLineEdit = new QLineEdit(totalsBox);
        totalMonthlyDebtLineEdit->setObjectName(QStringLiteral("totalMonthlyDebtLineEdit"));
        totalMonthlyDebtLineEdit->setEnabled(false);
        totalMonthlyDebtLineEdit->setGeometry(QRect(20, 90, 161, 20));
        totalMonthlyExpenseLabel = new QLabel(totalsBox);
        totalMonthlyExpenseLabel->setObjectName(QStringLiteral("totalMonthlyExpenseLabel"));
        totalMonthlyExpenseLabel->setGeometry(QRect(20, 120, 121, 16));
        totalMonthlyExpensesLineEdit = new QLineEdit(totalsBox);
        totalMonthlyExpensesLineEdit->setObjectName(QStringLiteral("totalMonthlyExpensesLineEdit"));
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
        balanceBox->setTitle(QApplication::translate("BudgetDock", "Balance", 0));
        currentBalanceLabel->setText(QApplication::translate("BudgetDock", "Current Budget Balance:", 0));
        addButton->setText(QApplication::translate("BudgetDock", "Add", 0));
        editButton->setText(QApplication::translate("BudgetDock", "Edit", 0));
        totalsBox->setTitle(QApplication::translate("BudgetDock", "Totals", 0));
        totalMonthlyIncomeLabel->setText(QApplication::translate("BudgetDock", "Total Monthly Income:", 0));
        totalMonthlyDebtLabel->setText(QApplication::translate("BudgetDock", "Total Monthly Debt:", 0));
        totalMonthlyExpenseLabel->setText(QApplication::translate("BudgetDock", "Total Monthly Expenses:", 0));
    } // retranslateUi

};

namespace Ui {
    class BudgetDock: public Ui_BudgetDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGET_DOCK_H
