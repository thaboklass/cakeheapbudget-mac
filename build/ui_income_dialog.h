/********************************************************************************
** Form generated from reading UI file 'income_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOME_DIALOG_H
#define UI_INCOME_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_incomeDialog
{
public:
    QGroupBox *incomeBox;
    QLineEdit *nameLineEdit;
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLabel *natureLabel;
    QLabel *amountLabel;
    QLabel *taxLabel;
    QDateEdit *dateEdit;
    QComboBox *natureComboBox;
    QLineEdit *taxLineEdt;
    QLineEdit *amountLineEdit;
    QTextEdit *additionalInfoTextEdit;
    QLabel *additionalInfoLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *incomeDialog)
    {
        if (incomeDialog->objectName().isEmpty())
            incomeDialog->setObjectName(QStringLiteral("incomeDialog"));
        incomeDialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        incomeDialog->setWindowIcon(icon);
        incomeBox = new QGroupBox(incomeDialog);
        incomeBox->setObjectName(QStringLiteral("incomeBox"));
        incomeBox->setGeometry(QRect(10, 10, 381, 271));
        nameLineEdit = new QLineEdit(incomeBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(70, 20, 301, 20));
        nameLabel = new QLabel(incomeBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        dateLabel = new QLabel(incomeBox);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setGeometry(QRect(20, 70, 46, 13));
        natureLabel = new QLabel(incomeBox);
        natureLabel->setObjectName(QStringLiteral("natureLabel"));
        natureLabel->setGeometry(QRect(220, 70, 46, 13));
        amountLabel = new QLabel(incomeBox);
        amountLabel->setObjectName(QStringLiteral("amountLabel"));
        amountLabel->setGeometry(QRect(20, 110, 46, 13));
        taxLabel = new QLabel(incomeBox);
        taxLabel->setObjectName(QStringLiteral("taxLabel"));
        taxLabel->setGeometry(QRect(220, 110, 46, 13));
        dateEdit = new QDateEdit(incomeBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(70, 66, 110, 22));
        natureComboBox = new QComboBox(incomeBox);
        natureComboBox->setObjectName(QStringLiteral("natureComboBox"));
        natureComboBox->setGeometry(QRect(270, 66, 69, 22));
        taxLineEdt = new QLineEdit(incomeBox);
        taxLineEdt->setObjectName(QStringLiteral("taxLineEdt"));
        taxLineEdt->setGeometry(QRect(270, 108, 71, 20));
        amountLineEdit = new QLineEdit(incomeBox);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(70, 108, 111, 20));
        additionalInfoTextEdit = new QTextEdit(incomeBox);
        additionalInfoTextEdit->setObjectName(QStringLiteral("additionalInfoTextEdit"));
        additionalInfoTextEdit->setGeometry(QRect(10, 173, 361, 61));
        additionalInfoLabel = new QLabel(incomeBox);
        additionalInfoLabel->setObjectName(QStringLiteral("additionalInfoLabel"));
        additionalInfoLabel->setGeometry(QRect(20, 150, 101, 16));
        okButton = new QPushButton(incomeBox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(20, 240, 75, 23));
        cancelButton = new QPushButton(incomeBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(280, 240, 75, 23));

        retranslateUi(incomeDialog);

        QMetaObject::connectSlotsByName(incomeDialog);
    } // setupUi

    void retranslateUi(QDialog *incomeDialog)
    {
        incomeDialog->setWindowTitle(QApplication::translate("incomeDialog", "Income Info", 0));
        incomeBox->setTitle(QApplication::translate("incomeDialog", "Income", 0));
        nameLabel->setText(QApplication::translate("incomeDialog", "Name:", 0));
        dateLabel->setText(QApplication::translate("incomeDialog", "Date:", 0));
        natureLabel->setText(QApplication::translate("incomeDialog", "Nature:", 0));
        amountLabel->setText(QApplication::translate("incomeDialog", "Amount:", 0));
        taxLabel->setText(QApplication::translate("incomeDialog", "Tax(%):", 0));
        additionalInfoLabel->setText(QApplication::translate("incomeDialog", "Additional Info:", 0));
        okButton->setText(QApplication::translate("incomeDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("incomeDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class incomeDialog: public Ui_incomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOME_DIALOG_H
