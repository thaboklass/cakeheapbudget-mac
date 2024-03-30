/********************************************************************************
** Form generated from reading UI file 'savings_dock.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVINGS_DOCK_H
#define UI_SAVINGS_DOCK_H

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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SavingsDock
{
public:
    QWidget *dockWidgetContents;
    QCalendarWidget *calendar;
    QPushButton *pushButton;
    QGroupBox *balanceBox;
    QLabel *currentBalanceLabel;
    QLineEdit *currentBalanceLineEdit;
    QPushButton *deleteButton;
    QProgressBar *progressBar;
    QPushButton *editButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *savingsTable;
    QLabel *savingsLabel;
    QGroupBox *descriptionBox;
    QTextBrowser *textBrowser;
    QPushButton *addButton;

    void setupUi(QDockWidget *SavingsDock)
    {
        if (SavingsDock->objectName().isEmpty())
            SavingsDock->setObjectName(QStringLiteral("SavingsDock"));
        SavingsDock->resize(825, 620);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        calendar = new QCalendarWidget(dockWidgetContents);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setGeometry(QRect(600, 440, 220, 151));
        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(650, 170, 75, 23));
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
        deleteButton = new QPushButton(dockWidgetContents);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(650, 130, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("delete.gif"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon);
        deleteButton->setIconSize(QSize(30, 18));
        progressBar = new QProgressBar(dockWidgetContents);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(640, 10, 118, 23));
        progressBar->setValue(24);
        editButton = new QPushButton(dockWidgetContents);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(650, 90, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral("edit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon1);
        editButton->setIconSize(QSize(34, 24));
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 600));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 598, 598));
        savingsTable = new QTableWidget(scrollAreaWidgetContents);
        if (savingsTable->columnCount() < 4)
            savingsTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        savingsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        savingsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        savingsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        savingsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        savingsTable->setObjectName(QStringLiteral("savingsTable"));
        savingsTable->setGeometry(QRect(10, 40, 581, 311));
        savingsLabel = new QLabel(scrollAreaWidgetContents);
        savingsLabel->setObjectName(QStringLiteral("savingsLabel"));
        savingsLabel->setGeometry(QRect(14, 0, 571, 31));
        savingsLabel->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        descriptionBox = new QGroupBox(scrollAreaWidgetContents);
        descriptionBox->setObjectName(QStringLiteral("descriptionBox"));
        descriptionBox->setGeometry(QRect(10, 380, 571, 201));
        textBrowser = new QTextBrowser(descriptionBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 40, 491, 131));
        scrollArea->setWidget(scrollAreaWidgetContents);
        addButton = new QPushButton(dockWidgetContents);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(650, 50, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral("add.gif"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon2);
        addButton->setIconSize(QSize(32, 22));
        SavingsDock->setWidget(dockWidgetContents);

        retranslateUi(SavingsDock);

        QMetaObject::connectSlotsByName(SavingsDock);
    } // setupUi

    void retranslateUi(QDockWidget *SavingsDock)
    {
        SavingsDock->setWindowTitle(QApplication::translate("SavingsDock", "Savings", 0));
        pushButton->setText(QApplication::translate("SavingsDock", "Get Money", 0));
        balanceBox->setTitle(QApplication::translate("SavingsDock", "Balance", 0));
        currentBalanceLabel->setText(QApplication::translate("SavingsDock", "Current Savings Balance:", 0));
        deleteButton->setText(QApplication::translate("SavingsDock", "Delete", 0));
        editButton->setText(QApplication::translate("SavingsDock", "Edit", 0));
        QTableWidgetItem *___qtablewidgetitem = savingsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SavingsDock", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = savingsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SavingsDock", "Nature", 0));
        QTableWidgetItem *___qtablewidgetitem2 = savingsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SavingsDock", "APR", 0));
        QTableWidgetItem *___qtablewidgetitem3 = savingsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SavingsDock", "Amount", 0));
        savingsLabel->setText(QApplication::translate("SavingsDock", "   Savings", 0));
        descriptionBox->setTitle(QApplication::translate("SavingsDock", "Description", 0));
        addButton->setText(QApplication::translate("SavingsDock", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class SavingsDock: public Ui_SavingsDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVINGS_DOCK_H
