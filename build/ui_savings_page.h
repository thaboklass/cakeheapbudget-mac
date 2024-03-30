/********************************************************************************
** Form generated from reading UI file 'savings_page.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVINGS_PAGE_H
#define UI_SAVINGS_PAGE_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_savingsPage
{
public:
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QCalendarWidget *calendar;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QGroupBox *balanceBox;
    QLabel *currentBalanceLabel;
    QLineEdit *currentBalanceLineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *savingsLabel_2;
    QLabel *savingsLabel;
    QGroupBox *descriptionBox;

    void setupUi(QDialog *savingsPage)
    {
        if (savingsPage->objectName().isEmpty())
            savingsPage->setObjectName(QStringLiteral("savingsPage"));
        savingsPage->resize(825, 600);
        addButton = new QPushButton(savingsPage);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(650, 160, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("add.gif"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 22));
        deleteButton = new QPushButton(savingsPage);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(650, 240, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral("delete.gif"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setIconSize(QSize(30, 18));
        editButton = new QPushButton(savingsPage);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(650, 200, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral("edit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon2);
        editButton->setIconSize(QSize(34, 24));
        calendar = new QCalendarWidget(savingsPage);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setGeometry(QRect(600, 440, 220, 151));
        progressBar = new QProgressBar(savingsPage);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(650, 20, 118, 23));
        progressBar->setValue(24);
        pushButton = new QPushButton(savingsPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(650, 280, 75, 23));
        balanceBox = new QGroupBox(savingsPage);
        balanceBox->setObjectName(QStringLiteral("balanceBox"));
        balanceBox->setGeometry(QRect(610, 340, 201, 71));
        currentBalanceLabel = new QLabel(balanceBox);
        currentBalanceLabel->setObjectName(QStringLiteral("currentBalanceLabel"));
        currentBalanceLabel->setGeometry(QRect(20, 20, 121, 16));
        currentBalanceLineEdit = new QLineEdit(balanceBox);
        currentBalanceLineEdit->setObjectName(QStringLiteral("currentBalanceLineEdit"));
        currentBalanceLineEdit->setEnabled(false);
        currentBalanceLineEdit->setGeometry(QRect(20, 40, 161, 20));
        scrollArea = new QScrollArea(savingsPage);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 600));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 598, 598));
        savingsLabel_2 = new QTableWidget(scrollAreaWidgetContents);
        if (savingsLabel_2->columnCount() < 4)
            savingsLabel_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        savingsLabel_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        savingsLabel_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        savingsLabel_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        savingsLabel_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        savingsLabel_2->setObjectName(QStringLiteral("savingsLabel_2"));
        savingsLabel_2->setGeometry(QRect(10, 40, 581, 311));
        savingsLabel = new QLabel(scrollAreaWidgetContents);
        savingsLabel->setObjectName(QStringLiteral("savingsLabel"));
        savingsLabel->setGeometry(QRect(14, 0, 571, 31));
        savingsLabel->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        descriptionBox = new QGroupBox(scrollAreaWidgetContents);
        descriptionBox->setObjectName(QStringLiteral("descriptionBox"));
        descriptionBox->setGeometry(QRect(10, 380, 571, 201));
        scrollArea->setWidget(scrollAreaWidgetContents);
        QWidget::setTabOrder(scrollArea, savingsLabel_2);
        QWidget::setTabOrder(savingsLabel_2, addButton);
        QWidget::setTabOrder(addButton, editButton);
        QWidget::setTabOrder(editButton, deleteButton);
        QWidget::setTabOrder(deleteButton, pushButton);
        QWidget::setTabOrder(pushButton, currentBalanceLineEdit);
        QWidget::setTabOrder(currentBalanceLineEdit, calendar);

        retranslateUi(savingsPage);

        QMetaObject::connectSlotsByName(savingsPage);
    } // setupUi

    void retranslateUi(QDialog *savingsPage)
    {
        savingsPage->setWindowTitle(QApplication::translate("savingsPage", "Savings", 0));
        addButton->setText(QApplication::translate("savingsPage", "Add", 0));
        deleteButton->setText(QApplication::translate("savingsPage", "Delete", 0));
        editButton->setText(QApplication::translate("savingsPage", "Edit", 0));
        pushButton->setText(QApplication::translate("savingsPage", "Get Money", 0));
        balanceBox->setTitle(QApplication::translate("savingsPage", "Balance", 0));
        currentBalanceLabel->setText(QApplication::translate("savingsPage", "Current Budget Balance:", 0));
        QTableWidgetItem *___qtablewidgetitem = savingsLabel_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("savingsPage", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = savingsLabel_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("savingsPage", "Nature", 0));
        QTableWidgetItem *___qtablewidgetitem2 = savingsLabel_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("savingsPage", "APR", 0));
        QTableWidgetItem *___qtablewidgetitem3 = savingsLabel_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("savingsPage", "Amount", 0));
        savingsLabel->setText(QApplication::translate("savingsPage", "   Savings", 0));
        descriptionBox->setTitle(QApplication::translate("savingsPage", "Description", 0));
    } // retranslateUi

};

namespace Ui {
    class savingsPage: public Ui_savingsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVINGS_PAGE_H
