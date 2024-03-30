/********************************************************************************
** Form generated from reading UI file 'budget_frame.ui'
**
** Created: Thu 15. Jul 10:57:57 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUDGET_FRAME_H
#define UI_BUDGET_FRAME_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QFrame>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_BudgetFrame
{
public:
    QLabel *debtLabel_2;
    QTableWidget *incomeTable_2;
    QTableWidget *expensesTable_2;
    QLabel *incomeLabel_2;
    QPushButton *addDebtButton_2;
    //QPushButton *saveMoneyButton_2;
    QPushButton *addExpenseButtom_2;
    QPushButton *addIcomeButtom_2;
    QLabel *expensesLabel_2;
    QTableWidget *debtTable_2;
    QPushButton *saveMoneyButton;

    void setupUi(QFrame *BudgetFrame)
    {
        if (BudgetFrame->objectName().isEmpty())
            BudgetFrame->setObjectName(QString::fromUtf8("BudgetFrame"));
        BudgetFrame->resize(590, 570);
        BudgetFrame->setFrameShape(QFrame::StyledPanel);
        BudgetFrame->setFrameShadow(QFrame::Raised);
        debtLabel_2 = new QLabel(BudgetFrame);
        debtLabel_2->setObjectName(QString::fromUtf8("debtLabel_2"));
        debtLabel_2->setGeometry(QRect(5, 195, 571, 20));
        debtLabel_2->setStyleSheet(QString::fromUtf8("font: 18pt \"MS Shell Dlg 2\";"));
        incomeTable_2 = new QTableWidget(BudgetFrame);
        if (incomeTable_2->columnCount() < 7)
            incomeTable_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        incomeTable_2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        incomeTable_2->setObjectName(QString::fromUtf8("incomeTable_2"));
        incomeTable_2->setGeometry(QRect(5, 30, 581, 111));
        expensesTable_2 = new QTableWidget(BudgetFrame);
        if (expensesTable_2->columnCount() < 7)
            expensesTable_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        expensesTable_2->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        expensesTable_2->setObjectName(QString::fromUtf8("expensesTable_2"));
        expensesTable_2->setGeometry(QRect(5, 410, 581, 111));
        incomeLabel_2 = new QLabel(BudgetFrame);
        incomeLabel_2->setObjectName(QString::fromUtf8("incomeLabel_2"));
        incomeLabel_2->setGeometry(QRect(5, 5, 571, 20));
        incomeLabel_2->setStyleSheet(QString::fromUtf8("font: 18pt \"MS Shell Dlg 2\";"));
        addDebtButton_2 = new QPushButton(BudgetFrame);
        addDebtButton_2->setObjectName(QString::fromUtf8("addDebtButton_2"));
        addDebtButton_2->setGeometry(QRect(5, 340, 110, 32));
        //saveMoneyButton_2 = new QPushButton(BudgetFrame);
        //saveMoneyButton_2->setObjectName(QString::fromUtf8("saveMoneyButton_2"));
        //saveMoneyButton_2->setGeometry(QRect(5, 535, 75, 32));
        addExpenseButtom_2 = new QPushButton(BudgetFrame);
        addExpenseButtom_2->setObjectName(QString::fromUtf8("addExpenseButtom_2"));
        addExpenseButtom_2->setGeometry(QRect(5, 530, 110, 32));
        addIcomeButtom_2 = new QPushButton(BudgetFrame);
        addIcomeButtom_2->setObjectName(QString::fromUtf8("addIcomeButtom_2"));
        addIcomeButtom_2->setGeometry(QRect(5, 150, 110, 32));
        expensesLabel_2 = new QLabel(BudgetFrame);
        expensesLabel_2->setObjectName(QString::fromUtf8("expensesLabel_2"));
        expensesLabel_2->setGeometry(QRect(5, 375, 571, 31));
        expensesLabel_2->setStyleSheet(QString::fromUtf8("font: 18pt \"MS Shell Dlg 2\";"));
        debtTable_2 = new QTableWidget(BudgetFrame);
        if (debtTable_2->columnCount() < 7)
            debtTable_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        debtTable_2->setHorizontalHeaderItem(6, __qtablewidgetitem20);
        debtTable_2->setObjectName(QString::fromUtf8("debtTable_2"));
        debtTable_2->setGeometry(QRect(5, 220, 581, 111));
        //debtTable_2->setMaximumSize(QSize(581, 16777215));
        debtTable_2->setProperty("showDropIndicator", QVariant(false));
        //debtTable_2->setAlternatingRowColors(true);
        saveMoneyButton = new QPushButton(BudgetFrame);
        saveMoneyButton->setObjectName(QString::fromUtf8("saveMoneyButton"));
        saveMoneyButton->setGeometry(QRect(510, 530, 75, 23));
        saveMoneyButton->setVisible(false);

        retranslateUi(BudgetFrame);

        QMetaObject::connectSlotsByName(BudgetFrame);
    } // setupUi

    void retranslateUi(QFrame *BudgetFrame)
    {
        BudgetFrame->setWindowTitle(QApplication::translate("BudgetFrame", "Frame", 0));
        debtLabel_2->setText(QApplication::translate("BudgetFrame", "   Debt", 0));
        QTableWidgetItem *___qtablewidgetitem = incomeTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BudgetFrame", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = incomeTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BudgetFrame", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = incomeTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BudgetFrame", "Nature", 0));
        QTableWidgetItem *___qtablewidgetitem3 = incomeTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BudgetFrame", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem4 = incomeTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BudgetFrame", "Tax(%)", 0));
        QTableWidgetItem *___qtablewidgetitem5 = incomeTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("BudgetFrame", "Net Amount", 0));
        QTableWidgetItem *___qtablewidgetitem6 = incomeTable_2->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("BudgetFrame", "IDCode", 0));
        QTableWidgetItem *___qtablewidgetitem7 = expensesTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("BudgetFrame", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem8 = expensesTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("BudgetFrame", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem9 = expensesTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("BudgetFrame", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem10 = expensesTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("BudgetFrame", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem11 = expensesTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("BudgetFrame", "Penalty", 0));
        QTableWidgetItem *___qtablewidgetitem12 = expensesTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("BudgetFrame", "Net Amount", 0));
        QTableWidgetItem *___qtablewidgetitem13 = expensesTable_2->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("BudgetFrame", "IDCode", 0));
        incomeLabel_2->setText(QApplication::translate("BudgetFrame", "   Income", 0));
        addDebtButton_2->setText(QApplication::translate("BudgetFrame", "Add Debt", 0));
        //saveMoneyButton_2->setText(QApplication::translate("BudgetFrame", "Save", 0));
        addExpenseButtom_2->setText(QApplication::translate("BudgetFrame", "Add Expense", 0));
        addIcomeButtom_2->setText(QApplication::translate("BudgetFrame", "Add Income", 0));
        expensesLabel_2->setText(QApplication::translate("BudgetFrame", "   Expenses", 0));
        QTableWidgetItem *___qtablewidgetitem14 = debtTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("BudgetFrame", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem15 = debtTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("BudgetFrame", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem16 = debtTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("BudgetFrame", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem17 = debtTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("BudgetFrame", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem18 = debtTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("BudgetFrame", "APR(%)", 0));
        QTableWidgetItem *___qtablewidgetitem19 = debtTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QApplication::translate("BudgetFrame", "Net Amount", 0));
        QTableWidgetItem *___qtablewidgetitem20 = debtTable_2->horizontalHeaderItem(6);
        ___qtablewidgetitem20->setText(QApplication::translate("BudgetFrame", "IDCode", 0));
        saveMoneyButton->setText(QApplication::translate("BudgetFrame", "Save", 0));
    } // retranslateUi

    void setDateTitle(QString dateTitle) { itsDateTitle = dateTitle; }
    QString getDateTitle() { return itsDateTitle; }
    void setMonth(int month) { itsMonth = month; }
    int getMonth() { return itsMonth; }
    void setYear(int year) { itsYear = year; }
    int getYear() { return itsYear; }

private:
    QString itsDateTitle;
    int itsMonth;
    int itsYear;
};

namespace Ui {
    class BudgetFrame: public Ui_BudgetFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGET_FRAME_H
