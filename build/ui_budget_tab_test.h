/********************************************************************************
** Form generated from reading UI file 'budget_tab_test.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUDGET_TAB_TEST_H
#define UI_BUDGET_TAB_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BudgetTab
{
public:
    QWidget *tab_2;
    QPushButton *addDebtButton_3;
    QTableWidget *expensesTable_3;
    QLabel *incomeLabel_3;
    QTableWidget *debtTable_3;
    QTableWidget *incomeTable_3;
    QLabel *debtLabel_3;
    QLabel *expensesLabel_3;
    QPushButton *addExpenseButtom_3;
    QPushButton *saveMoneyButton_3;
    QPushButton *addIcomeButtom_3;
    QWidget *tab;
    QPushButton *saveMoneyButton_2;
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
            BudgetTab->setObjectName(QStringLiteral("BudgetTab"));
        BudgetTab->resize(600, 600);
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        addDebtButton_3 = new QPushButton(tab_2);
        addDebtButton_3->setObjectName(QStringLiteral("addDebtButton_3"));
        addDebtButton_3->setGeometry(QRect(20, 350, 75, 23));
        expensesTable_3 = new QTableWidget(tab_2);
        if (expensesTable_3->columnCount() < 6)
            expensesTable_3->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        expensesTable_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        expensesTable_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        expensesTable_3->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        expensesTable_3->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        expensesTable_3->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        expensesTable_3->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        expensesTable_3->setObjectName(QStringLiteral("expensesTable_3"));
        expensesTable_3->setGeometry(QRect(6, 415, 581, 111));
        incomeLabel_3 = new QLabel(tab_2);
        incomeLabel_3->setObjectName(QStringLiteral("incomeLabel_3"));
        incomeLabel_3->setGeometry(QRect(10, 10, 571, 20));
        incomeLabel_3->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        debtTable_3 = new QTableWidget(tab_2);
        if (debtTable_3->columnCount() < 7)
            debtTable_3->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        debtTable_3->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        debtTable_3->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        debtTable_3->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        debtTable_3->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        debtTable_3->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        debtTable_3->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        debtTable_3->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        debtTable_3->setObjectName(QStringLiteral("debtTable_3"));
        debtTable_3->setGeometry(QRect(6, 225, 581, 111));
        debtTable_3->setMaximumSize(QSize(581, 16777215));
        debtTable_3->setProperty("showDropIndicator", QVariant(false));
        debtTable_3->setAlternatingRowColors(true);
        incomeTable_3 = new QTableWidget(tab_2);
        if (incomeTable_3->columnCount() < 6)
            incomeTable_3->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        incomeTable_3->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        incomeTable_3->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        incomeTable_3->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        incomeTable_3->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        incomeTable_3->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        incomeTable_3->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        incomeTable_3->setObjectName(QStringLiteral("incomeTable_3"));
        incomeTable_3->setGeometry(QRect(6, 35, 581, 111));
        debtLabel_3 = new QLabel(tab_2);
        debtLabel_3->setObjectName(QStringLiteral("debtLabel_3"));
        debtLabel_3->setGeometry(QRect(10, 200, 571, 20));
        debtLabel_3->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        expensesLabel_3 = new QLabel(tab_2);
        expensesLabel_3->setObjectName(QStringLiteral("expensesLabel_3"));
        expensesLabel_3->setGeometry(QRect(0, 380, 571, 31));
        expensesLabel_3->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        addExpenseButtom_3 = new QPushButton(tab_2);
        addExpenseButtom_3->setObjectName(QStringLiteral("addExpenseButtom_3"));
        addExpenseButtom_3->setGeometry(QRect(20, 540, 75, 23));
        saveMoneyButton_3 = new QPushButton(tab_2);
        saveMoneyButton_3->setObjectName(QStringLiteral("saveMoneyButton_3"));
        saveMoneyButton_3->setGeometry(QRect(500, 540, 75, 23));
        addIcomeButtom_3 = new QPushButton(tab_2);
        addIcomeButtom_3->setObjectName(QStringLiteral("addIcomeButtom_3"));
        addIcomeButtom_3->setGeometry(QRect(20, 160, 75, 23));
        BudgetTab->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        saveMoneyButton_2 = new QPushButton(tab);
        saveMoneyButton_2->setObjectName(QStringLiteral("saveMoneyButton_2"));
        saveMoneyButton_2->setGeometry(QRect(500, 540, 75, 23));
        addIcomeButtom_2 = new QPushButton(tab);
        addIcomeButtom_2->setObjectName(QStringLiteral("addIcomeButtom_2"));
        addIcomeButtom_2->setGeometry(QRect(20, 160, 75, 23));
        addDebtButton_2 = new QPushButton(tab);
        addDebtButton_2->setObjectName(QStringLiteral("addDebtButton_2"));
        addDebtButton_2->setGeometry(QRect(20, 350, 75, 23));
        debtTable_2 = new QTableWidget(tab);
        if (debtTable_2->columnCount() < 7)
            debtTable_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(6, __qtablewidgetitem25);
        debtTable_2->setObjectName(QStringLiteral("debtTable_2"));
        debtTable_2->setGeometry(QRect(6, 225, 581, 111));
        debtTable_2->setMaximumSize(QSize(581, 16777215));
        debtTable_2->setProperty("showDropIndicator", QVariant(false));
        debtTable_2->setAlternatingRowColors(true);
        expensesLabel_2 = new QLabel(tab);
        expensesLabel_2->setObjectName(QStringLiteral("expensesLabel_2"));
        expensesLabel_2->setGeometry(QRect(0, 380, 571, 31));
        expensesLabel_2->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        incomeTable_2 = new QTableWidget(tab);
        if (incomeTable_2->columnCount() < 6)
            incomeTable_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem31);
        incomeTable_2->setObjectName(QStringLiteral("incomeTable_2"));
        incomeTable_2->setGeometry(QRect(6, 35, 581, 111));
        incomeLabel_2 = new QLabel(tab);
        incomeLabel_2->setObjectName(QStringLiteral("incomeLabel_2"));
        incomeLabel_2->setGeometry(QRect(10, 10, 571, 20));
        incomeLabel_2->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        expensesTable_2 = new QTableWidget(tab);
        if (expensesTable_2->columnCount() < 6)
            expensesTable_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem37);
        expensesTable_2->setObjectName(QStringLiteral("expensesTable_2"));
        expensesTable_2->setGeometry(QRect(6, 415, 581, 111));
        addExpenseButtom_2 = new QPushButton(tab);
        addExpenseButtom_2->setObjectName(QStringLiteral("addExpenseButtom_2"));
        addExpenseButtom_2->setGeometry(QRect(20, 540, 75, 23));
        debtLabel_2 = new QLabel(tab);
        debtLabel_2->setObjectName(QStringLiteral("debtLabel_2"));
        debtLabel_2->setGeometry(QRect(10, 200, 571, 20));
        debtLabel_2->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        BudgetTab->addTab(tab, QString());

        retranslateUi(BudgetTab);

        BudgetTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BudgetTab);
    } // setupUi

    void retranslateUi(QTabWidget *BudgetTab)
    {
        BudgetTab->setWindowTitle(QApplication::translate("BudgetTab", "TabWidget", 0));
        addDebtButton_3->setText(QApplication::translate("BudgetTab", "Add Debt", 0));
        QTableWidgetItem *___qtablewidgetitem = expensesTable_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BudgetTab", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = expensesTable_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BudgetTab", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = expensesTable_3->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BudgetTab", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem3 = expensesTable_3->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BudgetTab", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem4 = expensesTable_3->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BudgetTab", "Penalty", 0));
        QTableWidgetItem *___qtablewidgetitem5 = expensesTable_3->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("BudgetTab", "Net Amount", 0));
        incomeLabel_3->setText(QApplication::translate("BudgetTab", "   Income", 0));
        QTableWidgetItem *___qtablewidgetitem6 = debtTable_3->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("BudgetTab", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem7 = debtTable_3->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("BudgetTab", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem8 = debtTable_3->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("BudgetTab", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem9 = debtTable_3->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("BudgetTab", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem10 = debtTable_3->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("BudgetTab", "APR(%)", 0));
        QTableWidgetItem *___qtablewidgetitem11 = debtTable_3->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("BudgetTab", "Penalty", 0));
        QTableWidgetItem *___qtablewidgetitem12 = debtTable_3->horizontalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("BudgetTab", "Net Amount", 0));
        QTableWidgetItem *___qtablewidgetitem13 = incomeTable_3->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("BudgetTab", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem14 = incomeTable_3->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("BudgetTab", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem15 = incomeTable_3->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("BudgetTab", "Nature", 0));
        QTableWidgetItem *___qtablewidgetitem16 = incomeTable_3->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("BudgetTab", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem17 = incomeTable_3->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("BudgetTab", "Tax(%)", 0));
        QTableWidgetItem *___qtablewidgetitem18 = incomeTable_3->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QApplication::translate("BudgetTab", "Net Amount", 0));
        debtLabel_3->setText(QApplication::translate("BudgetTab", "  Debt", 0));
        expensesLabel_3->setText(QApplication::translate("BudgetTab", "   Expenses", 0));
        addExpenseButtom_3->setText(QApplication::translate("BudgetTab", "Add Expense", 0));
        saveMoneyButton_3->setText(QApplication::translate("BudgetTab", "Save Money", 0));
        addIcomeButtom_3->setText(QApplication::translate("BudgetTab", "Add Income", 0));
        BudgetTab->setTabText(BudgetTab->indexOf(tab_2), QApplication::translate("BudgetTab", "Page", 0));
        saveMoneyButton_2->setText(QApplication::translate("BudgetTab", "Save Money", 0));
        addIcomeButtom_2->setText(QApplication::translate("BudgetTab", "Add Income", 0));
        addDebtButton_2->setText(QApplication::translate("BudgetTab", "Add Debt", 0));
        QTableWidgetItem *___qtablewidgetitem19 = debtTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("BudgetTab", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem20 = debtTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("BudgetTab", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem21 = debtTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QApplication::translate("BudgetTab", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem22 = debtTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QApplication::translate("BudgetTab", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem23 = debtTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem23->setText(QApplication::translate("BudgetTab", "APR(%)", 0));
        QTableWidgetItem *___qtablewidgetitem24 = debtTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem24->setText(QApplication::translate("BudgetTab", "Penalty", 0));
        QTableWidgetItem *___qtablewidgetitem25 = debtTable_2->horizontalHeaderItem(6);
        ___qtablewidgetitem25->setText(QApplication::translate("BudgetTab", "Net Amount", 0));
        expensesLabel_2->setText(QApplication::translate("BudgetTab", "   Expenses", 0));
        QTableWidgetItem *___qtablewidgetitem26 = incomeTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem26->setText(QApplication::translate("BudgetTab", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem27 = incomeTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem27->setText(QApplication::translate("BudgetTab", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem28 = incomeTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem28->setText(QApplication::translate("BudgetTab", "Nature", 0));
        QTableWidgetItem *___qtablewidgetitem29 = incomeTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem29->setText(QApplication::translate("BudgetTab", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem30 = incomeTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem30->setText(QApplication::translate("BudgetTab", "Tax(%)", 0));
        QTableWidgetItem *___qtablewidgetitem31 = incomeTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem31->setText(QApplication::translate("BudgetTab", "Net Amount", 0));
        incomeLabel_2->setText(QApplication::translate("BudgetTab", "   Income", 0));
        QTableWidgetItem *___qtablewidgetitem32 = expensesTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("BudgetTab", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem33 = expensesTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("BudgetTab", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem34 = expensesTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("BudgetTab", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem35 = expensesTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem35->setText(QApplication::translate("BudgetTab", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem36 = expensesTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem36->setText(QApplication::translate("BudgetTab", "Penalty", 0));
        QTableWidgetItem *___qtablewidgetitem37 = expensesTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem37->setText(QApplication::translate("BudgetTab", "Net Amount", 0));
        addExpenseButtom_2->setText(QApplication::translate("BudgetTab", "Add Expense", 0));
        debtLabel_2->setText(QApplication::translate("BudgetTab", "  Debt", 0));
        BudgetTab->setTabText(BudgetTab->indexOf(tab), QApplication::translate("BudgetTab", "Tab 1", 0));
    } // retranslateUi

};

namespace Ui {
    class BudgetTab: public Ui_BudgetTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGET_TAB_TEST_H
