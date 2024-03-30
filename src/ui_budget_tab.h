/********************************************************************************
** Form generated from reading UI file 'budget_tab.ui'
**
** Created: Mon 12. Jul 09:35:12 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUDGET_TAB_H
#define UI_BUDGET_TAB_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QTableWidget>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_BudgetTab
{
public:
    QWidget *tab;
    QPushButton *saveMoneyButton;
    QPushButton *addIcomeButtom_2;
    QPushButton *addDebtButton_2;
    QTableWidget *debtTable_2;
    QLabel *expensesLabel_2;
    QTableWidget *incomeTable_2;
    QLabel *incomeLabel_2;
    QTableWidget *expensesTable_2;
    QPushButton *addExpenseButtom_2;
    QLabel *debtLabel_2;

    void setupUi(QTabWidget *BudgetTab)
    {
        if (BudgetTab->objectName().isEmpty())
            BudgetTab->setObjectName(QString::fromUtf8("BudgetTab"));
        BudgetTab->resize(600, 600);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        saveMoneyButton = new QPushButton(tab);
        saveMoneyButton->setObjectName(QString::fromUtf8("saveMoneyButton"));
        saveMoneyButton->setGeometry(QRect(500, 540, 75, 23));
        addIcomeButtom_2 = new QPushButton(tab);
        addIcomeButtom_2->setObjectName(QString::fromUtf8("addIcomeButtom_2"));
        addIcomeButtom_2->setGeometry(QRect(20, 160, 75, 23));
        addDebtButton_2 = new QPushButton(tab);
        addDebtButton_2->setObjectName(QString::fromUtf8("addDebtButton_2"));
        addDebtButton_2->setGeometry(QRect(20, 350, 75, 23));
        debtTable_2 = new QTableWidget(tab);
        if (debtTable_2->columnCount() < 7)
            debtTable_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        debtTable_2->setObjectName(QString::fromUtf8("debtTable_2"));
        debtTable_2->setGeometry(QRect(6, 225, 581, 111));
        debtTable_2->setMaximumSize(QSize(581, 16777215));
        debtTable_2->setProperty("showDropIndicator", QVariant(false));
        //debtTable_2->setAlternatingRowColors(true);
        expensesLabel_2 = new QLabel(tab);
        expensesLabel_2->setObjectName(QString::fromUtf8("expensesLabel_2"));
        expensesLabel_2->setGeometry(QRect(0, 380, 571, 31));
        expensesLabel_2->setStyleSheet(QString::fromUtf8("font: 18pt \"MS Shell Dlg 2\";"));
        incomeTable_2 = new QTableWidget(tab);
        if (incomeTable_2->columnCount() < 6)
            incomeTable_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        incomeTable_2->setObjectName(QString::fromUtf8("incomeTable_2"));
        incomeTable_2->setGeometry(QRect(6, 35, 581, 111));
        incomeLabel_2 = new QLabel(tab);
        incomeLabel_2->setObjectName(QString::fromUtf8("incomeLabel_2"));
        incomeLabel_2->setGeometry(QRect(10, 10, 571, 20));
        incomeLabel_2->setStyleSheet(QString::fromUtf8("font: 18pt \"MS Shell Dlg 2\";"));
        expensesTable_2 = new QTableWidget(tab);
        if (expensesTable_2->columnCount() < 6)
            expensesTable_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        //__qtablewidgetitem13->setSizeHint(QSize(50, 20));
        expensesTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        expensesTable_2->setObjectName(QString::fromUtf8("expensesTable_2"));
        expensesTable_2->setGeometry(QRect(6, 415, 581, 111));
        addExpenseButtom_2 = new QPushButton(tab);
        addExpenseButtom_2->setObjectName(QString::fromUtf8("addExpenseButtom_2"));
        addExpenseButtom_2->setGeometry(QRect(20, 540, 75, 23));
        debtLabel_2 = new QLabel(tab);
        debtLabel_2->setObjectName(QString::fromUtf8("debtLabel_2"));
        debtLabel_2->setGeometry(QRect(10, 200, 571, 20));
        debtLabel_2->setStyleSheet(QString::fromUtf8("font: 18pt \"MS Shell Dlg 2\";"));
        BudgetTab->addTab(tab, QString());

        retranslateUi(BudgetTab);

        BudgetTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BudgetTab);
    } // setupUi

    void retranslateUi(QTabWidget *BudgetTab)
    {
        BudgetTab->setWindowTitle(QApplication::translate("BudgetTab", "TabWidget", 0));
        saveMoneyButton->setText(QApplication::translate("BudgetTab", "Save", 0));
        addIcomeButtom_2->setText(QApplication::translate("BudgetTab", "Add Income", 0));
        addDebtButton_2->setText(QApplication::translate("BudgetTab", "Add Debt", 0));
        QTableWidgetItem *___qtablewidgetitem = debtTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BudgetTab", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = debtTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BudgetTab", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = debtTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BudgetTab", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem3 = debtTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BudgetTab", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem4 = debtTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BudgetTab", "APR(%)", 0));
        QTableWidgetItem *___qtablewidgetitem5 = debtTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("BudgetTab", "Penalty", 0));
        QTableWidgetItem *___qtablewidgetitem6 = debtTable_2->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("BudgetTab", "Net Amount", 0));
        expensesLabel_2->setText(QApplication::translate("BudgetTab", "   Expenses", 0));
        QTableWidgetItem *___qtablewidgetitem7 = incomeTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("BudgetTab", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem8 = incomeTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("BudgetTab", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem9 = incomeTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("BudgetTab", "Nature", 0));
        QTableWidgetItem *___qtablewidgetitem10 = incomeTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("BudgetTab", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem11 = incomeTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("BudgetTab", "Tax(%)", 0));
        QTableWidgetItem *___qtablewidgetitem12 = incomeTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("BudgetTab", "Net Amount", 0));
        incomeLabel_2->setText(QApplication::translate("BudgetTab", "   Income", 0));
        QTableWidgetItem *___qtablewidgetitem13 = expensesTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("BudgetTab", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem14 = expensesTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("BudgetTab", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem15 = expensesTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("BudgetTab", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem16 = expensesTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("BudgetTab", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem17 = expensesTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("BudgetTab", "Penalty", 0));
        QTableWidgetItem *___qtablewidgetitem18 = expensesTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QApplication::translate("BudgetTab", "Net Amount", 0));
        addExpenseButtom_2->setText(QApplication::translate("BudgetTab", "Add Expense", 0));
        debtLabel_2->setText(QApplication::translate("BudgetTab", "  Debt", 0));
        BudgetTab->setTabText(BudgetTab->indexOf(tab), QApplication::translate("BudgetTab", "Tab 1", 0));
    } // retranslateUi

};

namespace Ui {
    class BudgetTab: public Ui_BudgetTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGET_TAB_H
