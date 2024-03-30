/********************************************************************************
** Form generated from reading UI file 'reminders_dock.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDERS_DOCK_H
#define UI_REMINDERS_DOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemindersDock
{
public:
    QWidget *dockWidgetContents;
    QCalendarWidget *calendar;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *remindersTable;
    QGroupBox *messageBox;
    QTextBrowser *textBrowser;
    QLabel *remindersLabel;
    QProgressBar *progressBar;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;

    void setupUi(QDockWidget *RemindersDock)
    {
        if (RemindersDock->objectName().isEmpty())
            RemindersDock->setObjectName(QStringLiteral("RemindersDock"));
        RemindersDock->resize(825, 620);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        calendar = new QCalendarWidget(dockWidgetContents);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setGeometry(QRect(600, 440, 220, 151));
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 600));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 598, 598));
        remindersTable = new QTableWidget(scrollAreaWidgetContents);
        if (remindersTable->columnCount() < 2)
            remindersTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        remindersTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        remindersTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        remindersTable->setObjectName(QStringLiteral("remindersTable"));
        remindersTable->setGeometry(QRect(10, 40, 581, 311));
        messageBox = new QGroupBox(scrollAreaWidgetContents);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        messageBox->setGeometry(QRect(10, 380, 571, 201));
        textBrowser = new QTextBrowser(messageBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(35, 40, 501, 121));
        remindersLabel = new QLabel(scrollAreaWidgetContents);
        remindersLabel->setObjectName(QStringLiteral("remindersLabel"));
        remindersLabel->setGeometry(QRect(14, 5, 571, 20));
        remindersLabel->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        progressBar = new QProgressBar(dockWidgetContents);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(640, 10, 118, 23));
        progressBar->setValue(24);
        addButton = new QPushButton(dockWidgetContents);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(650, 50, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("add.gif"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 22));
        deleteButton = new QPushButton(dockWidgetContents);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(650, 130, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral("delete.gif"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setIconSize(QSize(30, 18));
        editButton = new QPushButton(dockWidgetContents);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(650, 90, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral("edit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon2);
        editButton->setIconSize(QSize(34, 24));
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
        messageBox->setTitle(QApplication::translate("RemindersDock", "Message", 0));
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
