/********************************************************************************
** Form generated from reading UI file 'expenses_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSES_DIALOG_H
#define UI_EXPENSES_DIALOG_H

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

class Ui_expensesDialog
{
public:
    QGroupBox *ExpensesBox;
    QLineEdit *nameLineEdit;
    QLabel *nameLabel;
    QLabel *dueDateLabel;
    QLabel *priorityLevelLabel;
    QLabel *amountLabel;
    QLabel *penaltyLabel;
    QDateEdit *dueDateEdit;
    QComboBox *priorityLevelComboBox;
    QLineEdit *penaltyLineEdit;
    QLineEdit *amountLineEdit;
    QTextEdit *additionalInfoTextEdit;
    QLabel *additionalInfoLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *expensesDialog)
    {
        if (expensesDialog->objectName().isEmpty())
            expensesDialog->setObjectName(QStringLiteral("expensesDialog"));
        expensesDialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        expensesDialog->setWindowIcon(icon);
        ExpensesBox = new QGroupBox(expensesDialog);
        ExpensesBox->setObjectName(QStringLiteral("ExpensesBox"));
        ExpensesBox->setGeometry(QRect(10, 10, 381, 271));
        nameLineEdit = new QLineEdit(ExpensesBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(80, 20, 291, 20));
        nameLabel = new QLabel(ExpensesBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        dueDateLabel = new QLabel(ExpensesBox);
        dueDateLabel->setObjectName(QStringLiteral("dueDateLabel"));
        dueDateLabel->setGeometry(QRect(20, 70, 61, 16));
        priorityLevelLabel = new QLabel(ExpensesBox);
        priorityLevelLabel->setObjectName(QStringLiteral("priorityLevelLabel"));
        priorityLevelLabel->setGeometry(QRect(210, 68, 71, 20));
        amountLabel = new QLabel(ExpensesBox);
        amountLabel->setObjectName(QStringLiteral("amountLabel"));
        amountLabel->setGeometry(QRect(20, 110, 46, 13));
        penaltyLabel = new QLabel(ExpensesBox);
        penaltyLabel->setObjectName(QStringLiteral("penaltyLabel"));
        penaltyLabel->setGeometry(QRect(230, 110, 46, 13));
        dueDateEdit = new QDateEdit(ExpensesBox);
        dueDateEdit->setObjectName(QStringLiteral("dueDateEdit"));
        dueDateEdit->setGeometry(QRect(79, 66, 101, 22));
        priorityLevelComboBox = new QComboBox(ExpensesBox);
        priorityLevelComboBox->setObjectName(QStringLiteral("priorityLevelComboBox"));
        priorityLevelComboBox->setGeometry(QRect(280, 66, 69, 22));
        penaltyLineEdit = new QLineEdit(ExpensesBox);
        penaltyLineEdit->setObjectName(QStringLiteral("penaltyLineEdit"));
        penaltyLineEdit->setGeometry(QRect(280, 108, 71, 20));
        amountLineEdit = new QLineEdit(ExpensesBox);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(80, 108, 111, 20));
        additionalInfoTextEdit = new QTextEdit(ExpensesBox);
        additionalInfoTextEdit->setObjectName(QStringLiteral("additionalInfoTextEdit"));
        additionalInfoTextEdit->setGeometry(QRect(10, 173, 361, 61));
        additionalInfoLabel = new QLabel(ExpensesBox);
        additionalInfoLabel->setObjectName(QStringLiteral("additionalInfoLabel"));
        additionalInfoLabel->setGeometry(QRect(20, 150, 101, 16));
        okButton = new QPushButton(ExpensesBox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(20, 240, 75, 23));
        cancelButton = new QPushButton(ExpensesBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(280, 240, 75, 23));

        retranslateUi(expensesDialog);

        QMetaObject::connectSlotsByName(expensesDialog);
    } // setupUi

    void retranslateUi(QDialog *expensesDialog)
    {
        expensesDialog->setWindowTitle(QApplication::translate("expensesDialog", "Expense Info", 0));
        ExpensesBox->setTitle(QApplication::translate("expensesDialog", "Expenses", 0));
        nameLabel->setText(QApplication::translate("expensesDialog", "Name:", 0));
        dueDateLabel->setText(QApplication::translate("expensesDialog", "Due Date:", 0));
        priorityLevelLabel->setText(QApplication::translate("expensesDialog", "Priority Level:", 0));
        amountLabel->setText(QApplication::translate("expensesDialog", "Amount:", 0));
        penaltyLabel->setText(QApplication::translate("expensesDialog", "Penalty:", 0));
        additionalInfoLabel->setText(QApplication::translate("expensesDialog", "Additional Info:", 0));
        okButton->setText(QApplication::translate("expensesDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("expensesDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class expensesDialog: public Ui_expensesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSES_DIALOG_H
