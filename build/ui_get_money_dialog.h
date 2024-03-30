/********************************************************************************
** Form generated from reading UI file 'get_money.ui'
**
** Created: Sat 12. Jun 14:52:10 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GET_MONEY_DIALOG_H
#define UI_GET_MONEY_DIALOG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

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
            getMoneyDialog->setObjectName(QString::fromUtf8("getMoneyDialog"));
        getMoneyDialog->resize(237, 115);
        getMoneyDialog->setMaximumSize(237, 115);
        getMoneyDialog->setMinimumSize(237, 115);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        getMoneyDialog->setWindowIcon(icon);
        
        getMoneyBox = new QGroupBox(getMoneyDialog);
        getMoneyBox->setObjectName(QString::fromUtf8("getMoneyBox"));
        getMoneyBox->setGeometry(QRect(10, 10, 211, 91));
        getMoneyBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ececec, stop: 1 #ececec); border: 2px solid #ececec; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        amountLineEdit = new QLineEdit(getMoneyBox);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(80, 20, 113, 20));
        amountLabel = new QLabel(getMoneyBox);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setGeometry(QRect(20, 20, 50, 13));
        okButton = new QPushButton(getMoneyBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(20, 50, 75, 23));
        cancelButton = new QPushButton(getMoneyBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(116, 50, 75, 23));

        retranslateUi(getMoneyDialog);

        QMetaObject::connectSlotsByName(getMoneyDialog);
    } // setupUi

    void retranslateUi(QDialog *getMoneyDialog)
    {
        getMoneyDialog->setWindowTitle(QApplication::translate("getMoneyDialog", "Get Money info", 0));
        getMoneyBox->setTitle(QApplication::translate("getMoneyDialog", "", 0));
        amountLabel->setText(QApplication::translate("getMoneyDialog", "Amount:", 0));
        okButton->setText(QApplication::translate("getMoneyDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("getMoneyDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class getMoneyDialog: public Ui_getMoneyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GET_MONEY_DIALOG_H
