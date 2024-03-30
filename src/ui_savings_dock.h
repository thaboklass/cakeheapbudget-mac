/********************************************************************************
** Form generated from reading UI file 'savings_dock.ui'
**
** Created: Mon 21. Jun 15:39:16 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVINGS_DOCK_H
#define UI_SAVINGS_DOCK_H

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
#include <QProgressBar>
#include <QPushButton>
#include <QScrollArea>
#include <QTableWidget>
#include <QTextBrowser>
#include <QWidget>
#include "cake_calenderwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SavingsDock
{
public:
    QWidget *dockWidgetContents;
    CakeCalendarWidget *calendar;
    QPushButton *pushButton;
    QGroupBox *balanceBox;
    QLabel *currentBalanceLabel;
    QLineEdit *currentBalanceLineEdit;
    QPushButton *deleteButton;
    //QProgressBar *progressBar;
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
            SavingsDock->setObjectName(QString::fromUtf8("SavingsDock"));
        SavingsDock->resize(825, 620);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        calendar = new CakeCalendarWidget(dockWidgetContents);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setGeometry(QRect(600, 460, 221, 151));
        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 170, 75, 32));
        pushButton->setVisible(false);
        
        balanceBox = new QGroupBox(dockWidgetContents);
        balanceBox->setObjectName(QString::fromUtf8("balanceBox"));
        balanceBox->setGeometry(QRect(610, 350, 201, 71));
        balanceBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f8bbd0, stop: 1 #f8bbd0); border: 2px solid #f8bbd0; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        currentBalanceLabel = new QLabel(balanceBox);
        currentBalanceLabel->setObjectName(QString::fromUtf8("currentBalanceLabel"));
        currentBalanceLabel->setGeometry(QRect(20, 20, 121, 16));
        currentBalanceLineEdit = new QLineEdit(balanceBox);
        currentBalanceLineEdit->setObjectName(QString::fromUtf8("currentBalanceLineEdit"));
        currentBalanceLineEdit->setEnabled(false);
        currentBalanceLineEdit->setGeometry(QRect(20, 40, 161, 20));
        deleteButton = new QPushButton(dockWidgetContents);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(670, 130, 75, 32));
        /*QIcon icon;
        icon.addFile(QString::fromUtf8("images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon);
        deleteButton->setIconSize(QSize(30, 18));*/
        /*progressBar = new QProgressBar(dockWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(640, 10, 118, 32));
        progressBar->setValue(24);*/
        editButton = new QPushButton(dockWidgetContents);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(670, 90, 75, 32));
        /*QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon1);
        editButton->setIconSize(QSize(34, 24));*/
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 620));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
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
        savingsTable->setObjectName(QString::fromUtf8("savingsTable"));
        savingsTable->setGeometry(QRect(10, 40, 581, 311));
        savingsTable->setColumnWidth(0, 278);
        savingsTable->setColumnWidth(1, 100);
        savingsTable->setColumnWidth(2, 100);
        savingsTable->setColumnWidth(3, 100);
        savingsLabel = new QLabel(scrollAreaWidgetContents);
        savingsLabel->setObjectName(QString::fromUtf8("savingsLabel"));
        savingsLabel->setGeometry(QRect(18, 5, 571, 31));
        savingsLabel->setStyleSheet(QString::fromUtf8("font: 18pt \"Helvetica Neue\";"));
        
        descriptionBox = new QGroupBox(scrollAreaWidgetContents);
        descriptionBox->setObjectName(QString::fromUtf8("descriptionBox"));
        descriptionBox->setGeometry(QRect(20, 380, 571, 201));
        descriptionBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ff857c, stop: 1 #ff857c); border: 2px solid #f8bbd0; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        textBrowser = new QTextBrowser(descriptionBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 40, 491, 131));
        scrollArea->setWidget(scrollAreaWidgetContents);
        addButton = new QPushButton(dockWidgetContents);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(670, 50, 75, 32));
        /*QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon2);
        addButton->setIconSize(QSize(32, 22));*/
        SavingsDock->setWidget(dockWidgetContents);

        retranslateUi(SavingsDock);

        QMetaObject::connectSlotsByName(SavingsDock);
    } // setupUi

    void retranslateUi(QDockWidget *SavingsDock)
    {
        SavingsDock->setWindowTitle(QApplication::translate("SavingsDock", "Savings", 0));
        pushButton->setText(QApplication::translate("SavingsDock", "Get", 0));
        balanceBox->setTitle(QApplication::translate("SavingsDock", "", 0));
        currentBalanceLabel->setText(QApplication::translate("SavingsDock", "Savings Balance:", 0));
        deleteButton->setText(QApplication::translate("SavingsDock", "Delete", 0));
        editButton->setText(QApplication::translate("SavingsDock", "Edit", 0));
        QTableWidgetItem *___qtablewidgetitem = savingsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SavingsDock", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = savingsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SavingsDock", "Nature", 0));
        QTableWidgetItem *___qtablewidgetitem2 = savingsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SavingsDock", "APR(%)", 0));
        QTableWidgetItem *___qtablewidgetitem3 = savingsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SavingsDock", "Amount", 0));
        savingsLabel->setText(QApplication::translate("SavingsDock", "   Savings", 0));
        descriptionBox->setTitle(QApplication::translate("SavingsDock", "", 0));
        addButton->setText(QApplication::translate("SavingsDock", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class SavingsDock: public Ui_SavingsDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVINGS_DOCK_H
