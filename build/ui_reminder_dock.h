/********************************************************************************
** Form generated from reading UI file 'reminders_dock.ui'
**
** Created: Mon 21. Jun 15:39:50 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDERS_DOCK_H
#define UI_REMINDERS_DOCK_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCalendarWidget>
#include <QDockWidget>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QScrollArea>
#include <QTableWidget>
#include <QTextBrowser>
#include <QWidget>
#include "cake_calenderwidget.h"

QT_BEGIN_NAMESPACE

class Ui_RemindersDock
{
public:
    QWidget *dockWidgetContents;
    CakeCalendarWidget *calendar;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *remindersTable;
    QGroupBox *messageBox;
    QTextBrowser *textBrowser;
    QLabel *remindersLabel;
    //QProgressBar *progressBar;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;

    void setupUi(QDockWidget *RemindersDock)
    {
        if (RemindersDock->objectName().isEmpty())
            RemindersDock->setObjectName(QString::fromUtf8("RemindersDock"));
        RemindersDock->resize(825, 620);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        calendar = new CakeCalendarWidget(dockWidgetContents);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setGeometry(QRect(600, 440, 221, 151));
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 600));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 598, 598));
        remindersTable = new QTableWidget(scrollAreaWidgetContents);
        if (remindersTable->columnCount() < 2)
            remindersTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        remindersTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        remindersTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        remindersTable->setObjectName(QString::fromUtf8("remindersTable"));
        remindersTable->setGeometry(QRect(10, 40, 581, 311));
        remindersTable->setColumnWidth(0, 150);
        remindersTable->setColumnWidth(1, 428);
        
        messageBox = new QGroupBox(scrollAreaWidgetContents);
        messageBox->setObjectName(QString::fromUtf8("messageBox"));
        messageBox->setGeometry(QRect(10, 380, 571, 201));
        messageBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ff857c, stop: 1 #ff857c); border: 2px solid #f8bbd0; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        textBrowser = new QTextBrowser(messageBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(35, 40, 501, 121));
        remindersLabel = new QLabel(scrollAreaWidgetContents);
        remindersLabel->setObjectName(QString::fromUtf8("remindersLabel"));
        remindersLabel->setGeometry(QRect(18, 5, 571, 31));
        remindersLabel->setStyleSheet(QString::fromUtf8("font: 18pt \"Helvetica Neue\";"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        /*progressBar = new QProgressBar(dockWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(640, 10, 118, 32));
        progressBar->setValue(24);*/
        addButton = new QPushButton(dockWidgetContents);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(670, 50, 75, 32));
        /*QIcon icon;
        icon.addFile(QString::fromUtf8("images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 22));*/
        deleteButton = new QPushButton(dockWidgetContents);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(670, 130, 75, 32));
        /*QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setIconSize(QSize(30, 18));*/
        editButton = new QPushButton(dockWidgetContents);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(670, 90, 75, 32));
        /*QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon2);
        editButton->setIconSize(QSize(34, 24));*/
        RemindersDock->setWidget(dockWidgetContents);

        retranslateUi(RemindersDock);

        QMetaObject::connectSlotsByName(RemindersDock);
    } // setupUi

    void retranslateUi(QDockWidget *RemindersDock)
    {
        RemindersDock->setWindowTitle(QApplication::translate("RemindersDock", "Reminders", 0));
        QTableWidgetItem *___qtablewidgetitem = remindersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RemindersDock", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = remindersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RemindersDock", "Subject", 0));
        messageBox->setTitle(QApplication::translate("RemindersDock", "", 0));
        remindersLabel->setText(QApplication::translate("RemindersDock", "   Reminders", 0));
        addButton->setText(QApplication::translate("RemindersDock", "Add", 0));
        deleteButton->setText(QApplication::translate("RemindersDock", "Delete", 0));
        editButton->setText(QApplication::translate("RemindersDock", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class RemindersDock: public Ui_RemindersDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDERS_DOCK_H
