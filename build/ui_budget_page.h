/********************************************************************************
** Form generated from reading UI file 'budget_page.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUDGET_PAGE_H
#define UI_BUDGET_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BudgetPage
{
public:
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QCalendarWidget *calendar;
    QProgressBar *progressBar;
    QGroupBox *balanceBox;
    QLabel *currentBalanceLabel;
    QLineEdit *currentBalanceLineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *incomeTable;
    QLabel *incomeLabel;
    QPushButton *addIcomeButtom;
    QPushButton *addDebtButton;
    QTableWidget *debtTable;
    QLabel *debtLabel;
    QPushButton *addExpenseButtom;
    QTableWidget *expensesTable;
    QLabel *expensesLabel;
    QPushButton *saveMoneyButton;

    void setupUi(QDialog *BudgetPage)
    {
        if (BudgetPage->objectName().isEmpty())
            BudgetPage->setObjectName(QStringLiteral("BudgetPage"));
        BudgetPage->resize(825, 600);
        addButton = new QPushButton(BudgetPage);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(650, 160, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("add.gif"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 22));
        editButton = new QPushButton(BudgetPage);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(650, 200, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral("edit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon1);
        editButton->setIconSize(QSize(34, 24));
        deleteButton = new QPushButton(BudgetPage);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(650, 240, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral("delete.gif"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon2);
        deleteButton->setIconSize(QSize(30, 18));
        calendar = new QCalendarWidget(BudgetPage);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setGeometry(QRect(600, 440, 221, 151));
        progressBar = new QProgressBar(BudgetPage);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(640, 20, 118, 23));
        progressBar->setValue(24);
        balanceBox = new QGroupBox(BudgetPage);
        balanceBox->setObjectName(QStringLiteral("balanceBox"));
        balanceBox->setGeometry(QRect(610, 340, 201, 71));
        currentBalanceLabel = new QLabel(balanceBox);
        currentBalanceLabel->setObjectName(QStringLiteral("currentBalanceLabel"));
        currentBalanceLabel->setGeometry(QRect(20, 20, 121, 16));
        currentBalanceLineEdit = new QLineEdit(balanceBox);
        currentBalanceLineEdit->setObjectName(QStringLiteral("currentBalanceLineEdit"));
        currentBalanceLineEdit->setEnabled(false);
        currentBalanceLineEdit->setGeometry(QRect(20, 40, 161, 20));
        scrollArea = new QScrollArea(BudgetPage);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 600));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 598, 598));
        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 600, 600));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        incomeTable = new QTableWidget(tab);
        if (incomeTable->columnCount() < 6)
            incomeTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        incomeTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        incomeTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        incomeTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        incomeTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        incomeTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        incomeTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        incomeTable->setObjectName(QStringLiteral("incomeTable"));
        incomeTable->setGeometry(QRect(6, 35, 581, 111));
        incomeLabel = new QLabel(tab);
        incomeLabel->setObjectName(QStringLiteral("incomeLabel"));
        incomeLabel->setGeometry(QRect(10, 10, 571, 20));
        incomeLabel->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        addIcomeButtom = new QPushButton(tab);
        addIcomeButtom->setObjectName(QStringLiteral("addIcomeButtom"));
        addIcomeButtom->setGeometry(QRect(20, 160, 75, 23));
        addDebtButton = new QPushButton(tab);
        addDebtButton->setObjectName(QStringLiteral("addDebtButton"));
        addDebtButton->setGeometry(QRect(20, 350, 75, 23));
        debtTable = new QTableWidget(tab);
        if (debtTable->columnCount() < 7)
            debtTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        debtTable->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        debtTable->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        debtTable->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        debtTable->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        debtTable->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        debtTable->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        debtTable->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        debtTable->setObjectName(QStringLiteral("debtTable"));
        debtTable->setGeometry(QRect(6, 225, 581, 111));
        debtTable->setMaximumSize(QSize(581, 16777215));
        debtTable->setProperty("showDropIndicator", QVariant(false));
        debtTable->setAlternatingRowColors(true);
        debtLabel = new QLabel(tab);
        debtLabel->setObjectName(QStringLiteral("debtLabel"));
        debtLabel->setGeometry(QRect(10, 200, 571, 20));
        debtLabel->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        addExpenseButtom = new QPushButton(tab);
        addExpenseButtom->setObjectName(QStringLiteral("addExpenseButtom"));
        addExpenseButtom->setGeometry(QRect(20, 540, 75, 23));
        expensesTable = new QTableWidget(tab);
        if (expensesTable->columnCount() < 6)
            expensesTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        expensesTable->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        expensesTable->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        expensesTable->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        expensesTable->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        expensesTable->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        expensesTable->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        expensesTable->setObjectName(QStringLiteral("expensesTable"));
        expensesTable->setGeometry(QRect(6, 415, 581, 111));
        expensesLabel = new QLabel(tab);
        expensesLabel->setObjectName(QStringLiteral("expensesLabel"));
        expensesLabel->setGeometry(QRect(0, 380, 571, 31));
        expensesLabel->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        saveMoneyButton = new QPushButton(tab);
        saveMoneyButton->setObjectName(QStringLiteral("saveMoneyButton"));
        saveMoneyButton->setGeometry(QRect(500, 540, 75, 23));
        tabWidget->addTab(tab, QString());
        scrollArea->setWidget(scrollAreaWidgetContents);
        QWidget::setTabOrder(incomeTable, addIcomeButtom);
        QWidget::setTabOrder(addIcomeButtom, debtTable);
        QWidget::setTabOrder(debtTable, addDebtButton);
        QWidget::setTabOrder(addDebtButton, expensesTable);
        QWidget::setTabOrder(expensesTable, addExpenseButtom);
        QWidget::setTabOrder(addExpenseButtom, saveMoneyButton);
        QWidget::setTabOrder(saveMoneyButton, addButton);
        QWidget::setTabOrder(addButton, editButton);
        QWidget::setTabOrder(editButton, deleteButton);
        QWidget::setTabOrder(deleteButton, currentBalanceLineEdit);
        QWidget::setTabOrder(currentBalanceLineEdit, calendar);
        QWidget::setTabOrder(calendar, tabWidget);
        QWidget::setTabOrder(tabWidget, scrollArea);

        retranslateUi(BudgetPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BudgetPage);
    } // setupUi

    void retranslateUi(QDialog *BudgetPage)
    {
        BudgetPage->setWindowTitle(QApplication::translate("BudgetPage", "Dialog", 0));
        addButton->setText(QApplication::translate("BudgetPage", "Add", 0));
        editButton->setText(QApplication::translate("BudgetPage", "Edit", 0));
        deleteButton->setText(QApplication::translate("BudgetPage", "Delete", 0));
        balanceBox->setTitle(QApplication::translate("BudgetPage", "Balance", 0));
        currentBalanceLabel->setText(QApplication::translate("BudgetPage", "Current Budget Balance:", 0));
        QTableWidgetItem *___qtablewidgetitem = incomeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BudgetPage", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = incomeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BudgetPage", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = incomeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BudgetPage", "Nature", 0));
        QTableWidgetItem *___qtablewidgetitem3 = incomeTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BudgetPage", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem4 = incomeTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BudgetPage", "Tax(%)", 0));
        QTableWidgetItem *___qtablewidgetitem5 = incomeTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("BudgetPage", "Net Amount", 0));
        incomeLabel->setText(QApplication::translate("BudgetPage", "   Income", 0));
        addIcomeButtom->setText(QApplication::translate("BudgetPage", "Add Income", 0));
        addDebtButton->setText(QApplication::translate("BudgetPage", "Add Debt", 0));
        QTableWidgetItem *___qtablewidgetitem6 = debtTable->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("BudgetPage", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem7 = debtTable->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("BudgetPage", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem8 = debtTable->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("BudgetPage", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem9 = debtTable->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("BudgetPage", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem10 = debtTable->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("BudgetPage", "APR(%)", 0));
        QTableWidgetItem *___qtablewidgetitem11 = debtTable->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("BudgetPage", "Penalty", 0));
        QTableWidgetItem *___qtablewidgetitem12 = debtTable->horizontalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("BudgetPage", "Net Amount", 0));
        debtLabel->setText(QApplication::translate("BudgetPage", "  Debt", 0));
        addExpenseButtom->setText(QApplication::translate("BudgetPage", "Add Expense", 0));
        QTableWidgetItem *___qtablewidgetitem13 = expensesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("BudgetPage", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem14 = expensesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("BudgetPage", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem15 = expensesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("BudgetPage", "Priority Level", 0));
        QTableWidgetItem *___qtablewidgetitem16 = expensesTable->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("BudgetPage", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem17 = expensesTable->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("BudgetPage", "Penalty", 0));
        QTableWidgetItem *___qtablewidgetitem18 = expensesTable->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QApplication::translate("BudgetPage", "Net Amount", 0));
        expensesLabel->setText(QApplication::translate("BudgetPage", "   Expenses", 0));
        saveMoneyButton->setText(QApplication::translate("BudgetPage", "Save Money", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("BudgetPage", "Tab 1", 0));
    } // retranslateUi

};

namespace Ui {
    class BudgetPage: public Ui_BudgetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGET_PAGE_H
