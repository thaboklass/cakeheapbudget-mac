/********************************************************************************
** Form generated from reading UI file 'save_money_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_MONEY_DIALOG_H
#define UI_SAVE_MONEY_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_saveMoneyDialog
{
public:
    QGroupBox *saveMoneyBox;
    QLabel *selectSavingsLabel;
    QLabel *amountLabel;
    QComboBox *selectSavingsComboBox;
    QLineEdit *amountLineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *saveMoneyDialog)
    {
        if (saveMoneyDialog->objectName().isEmpty())
            saveMoneyDialog->setObjectName(QStringLiteral("saveMoneyDialog"));
        saveMoneyDialog->resize(400, 177);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        saveMoneyDialog->setWindowIcon(icon);
        saveMoneyBox = new QGroupBox(saveMoneyDialog);
        saveMoneyBox->setObjectName(QStringLiteral("saveMoneyBox"));
        saveMoneyBox->setGeometry(QRect(10, 10, 381, 151));
        selectSavingsLabel = new QLabel(saveMoneyBox);
        selectSavingsLabel->setObjectName(QStringLiteral("selectSavingsLabel"));
        selectSavingsLabel->setGeometry(QRect(20, 20, 71, 20));
        amountLabel = new QLabel(saveMoneyBox);
        amountLabel->setObjectName(QStringLiteral("amountLabel"));
        amountLabel->setGeometry(QRect(20, 60, 46, 13));
        selectSavingsComboBox = new QComboBox(saveMoneyBox);
        selectSavingsComboBox->setObjectName(QStringLiteral("selectSavingsComboBox"));
        selectSavingsComboBox->setGeometry(QRect(100, 20, 261, 22));
        amountLineEdit = new QLineEdit(saveMoneyBox);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(100, 56, 111, 20));
        okButton = new QPushButton(saveMoneyBox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(30, 100, 75, 23));
        cancelButton = new QPushButton(saveMoneyBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(290, 100, 75, 23));

        retranslateUi(saveMoneyDialog);

        QMetaObject::connectSlotsByName(saveMoneyDialog);
    } // setupUi

    void retranslateUi(QDialog *saveMoneyDialog)
    {
        saveMoneyDialog->setWindowTitle(QApplication::translate("saveMoneyDialog", "Save Money Info", 0));
        saveMoneyBox->setTitle(QApplication::translate("saveMoneyDialog", "Save Money", 0));
        selectSavingsLabel->setText(QApplication::translate("saveMoneyDialog", "Select Savings:", 0));
        amountLabel->setText(QApplication::translate("saveMoneyDialog", "Amount:", 0));
        okButton->setText(QApplication::translate("saveMoneyDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("saveMoneyDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class saveMoneyDialog: public Ui_saveMoneyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_MONEY_DIALOG_H
