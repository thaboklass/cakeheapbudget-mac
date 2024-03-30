/********************************************************************************
** Form generated from reading UI file 'get_money.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GET_MONEY_H
#define UI_GET_MONEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_getMoneyDialog
{
public:
    QGroupBox *getMoneyBox;
    QLineEdit *amountLineEdit;
    QLabel *amountLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *getMoneyDialog)
    {
        if (getMoneyDialog->objectName().isEmpty())
            getMoneyDialog->setObjectName(QStringLiteral("getMoneyDialog"));
        getMoneyDialog->resize(237, 115);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        getMoneyDialog->setWindowIcon(icon);
        getMoneyBox = new QGroupBox(getMoneyDialog);
        getMoneyBox->setObjectName(QStringLiteral("getMoneyBox"));
        getMoneyBox->setGeometry(QRect(10, 10, 211, 91));
        amountLineEdit = new QLineEdit(getMoneyBox);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(80, 20, 113, 20));
        amountLabel = new QLabel(getMoneyBox);
        amountLabel->setObjectName(QStringLiteral("amountLabel"));
        amountLabel->setGeometry(QRect(20, 20, 46, 13));
        okButton = new QPushButton(getMoneyBox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(20, 50, 75, 23));
        cancelButton = new QPushButton(getMoneyBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(110, 50, 75, 23));

        retranslateUi(getMoneyDialog);

        QMetaObject::connectSlotsByName(getMoneyDialog);
    } // setupUi

    void retranslateUi(QDialog *getMoneyDialog)
    {
        getMoneyDialog->setWindowTitle(QApplication::translate("getMoneyDialog", "Get Money info", 0));
        getMoneyBox->setTitle(QApplication::translate("getMoneyDialog", "Get Money", 0));
        amountLabel->setText(QApplication::translate("getMoneyDialog", "Amount:", 0));
        okButton->setText(QApplication::translate("getMoneyDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("getMoneyDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class getMoneyDialog: public Ui_getMoneyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GET_MONEY_H
