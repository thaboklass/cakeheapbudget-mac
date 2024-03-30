/********************************************************************************
** Form generated from reading UI file 'reminders_page.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDERS_PAGE_H
#define UI_REMINDERS_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_remindersPage
{
public:
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QCalendarWidget *calendar;
    QProgressBar *progressBar;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *remindersTable;
    QGroupBox *messageBox;
    QLabel *remindersLabel;

    void setupUi(QDialog *remindersPage)
    {
        if (remindersPage->objectName().isEmpty())
            remindersPage->setObjectName(QStringLiteral("remindersPage"));
        remindersPage->resize(825, 600);
        addButton = new QPushButton(remindersPage);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(650, 160, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("add.gif"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 22));
        deleteButton = new QPushButton(remindersPage);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(650, 240, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral("delete.gif"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setIconSize(QSize(30, 18));
        editButton = new QPushButton(remindersPage);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(650, 200, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral("edit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon2);
        editButton->setIconSize(QSize(34, 24));
        calendar = new QCalendarWidget(remindersPage);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setGeometry(QRect(600, 440, 220, 151));
        progressBar = new QProgressBar(remindersPage);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(640, 20, 118, 23));
        progressBar->setValue(24);
        scrollArea = new QScrollArea(remindersPage);
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
        remindersLabel = new QLabel(scrollAreaWidgetContents);
        remindersLabel->setObjectName(QStringLiteral("remindersLabel"));
        remindersLabel->setGeometry(QRect(14, 5, 571, 20));
        remindersLabel->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        QWidget::setTabOrder(scrollArea, remindersTable);
        QWidget::setTabOrder(remindersTable, addButton);
        QWidget::setTabOrder(addButton, editButton);
        QWidget::setTabOrder(editButton, deleteButton);
        QWidget::setTabOrder(deleteButton, calendar);

        retranslateUi(remindersPage);

        QMetaObject::connectSlotsByName(remindersPage);
    } // setupUi

    void retranslateUi(QDialog *remindersPage)
    {
        remindersPage->setWindowTitle(QApplication::translate("remindersPage", "Reminders", 0));
        addButton->setText(QApplication::translate("remindersPage", "Add", 0));
        deleteButton->setText(QApplication::translate("remindersPage", "Delete", 0));
        editButton->setText(QApplication::translate("remindersPage", "Edit", 0));
        QTableWidgetItem *___qtablewidgetitem = remindersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("remindersPage", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = remindersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("remindersPage", "Subject", 0));
        messageBox->setTitle(QApplication::translate("remindersPage", "Message", 0));
        remindersLabel->setText(QApplication::translate("remindersPage", "   Reminders", 0));
    } // retranslateUi

};

namespace Ui {
    class remindersPage: public Ui_remindersPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDERS_PAGE_H
