/********************************************************************************
** Form generated from reading UI file 'expenses_dialog.ui'
**
** Created: Sat 12. Jun 14:34:55 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSES_DIALOG_H
#define UI_EXPENSES_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_editedExpensesDialog
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
            expensesDialog->setObjectName(QString::fromUtf8("expensesDialog"));
        expensesDialog->resize(440, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        expensesDialog->setWindowIcon(icon);
        ExpensesBox = new QGroupBox(expensesDialog);
        ExpensesBox->setObjectName(QString::fromUtf8("ExpensesBox"));
        ExpensesBox->setGeometry(QRect(10, 10, 381, 271));
        nameLineEdit = new QLineEdit(ExpensesBox);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(90, 20, 291, 20));
        nameLabel = new QLabel(ExpensesBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        dueDateLabel = new QLabel(ExpensesBox);
        dueDateLabel->setObjectName(QString::fromUtf8("dueDateLabel"));
        dueDateLabel->setGeometry(QRect(20, 70, 61, 16));
        priorityLevelLabel = new QLabel(ExpensesBox);
        priorityLevelLabel->setObjectName(QString::fromUtf8("priorityLevelLabel"));
        priorityLevelLabel->setGeometry(QRect(210, 68, 71, 20));
        amountLabel = new QLabel(ExpensesBox);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setGeometry(QRect(20, 110, 46, 13));
        penaltyLabel = new QLabel(ExpensesBox);
        penaltyLabel->setObjectName(QString::fromUtf8("penaltyLabel"));
        penaltyLabel->setGeometry(QRect(230, 110, 46, 13));
        dueDateEdit = new QDateEdit(ExpensesBox);
        dueDateEdit->setObjectName(QString::fromUtf8("dueDateEdit"));
        dueDateEdit->setGeometry(QRect(90, 66, 101, 22));
        priorityLevelComboBox = new QComboBox(ExpensesBox);
        priorityLevelComboBox->setObjectName(QString::fromUtf8("priorityLevelComboBox"));
        priorityLevelComboBox->setGeometry(QRect(280, 66, 69, 22));
        penaltyLineEdit = new QLineEdit(ExpensesBox);
        penaltyLineEdit->setObjectName(QString::fromUtf8("penaltyLineEdit"));
        penaltyLineEdit->setGeometry(QRect(280, 108, 71, 20));
        amountLineEdit = new QLineEdit(ExpensesBox);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(90, 108, 111, 20));
        additionalInfoTextEdit = new QTextEdit(ExpensesBox);
        additionalInfoTextEdit->setObjectName(QString::fromUtf8("additionalInfoTextEdit"));
        additionalInfoTextEdit->setGeometry(QRect(20, 173, 361, 61));
        additionalInfoLabel = new QLabel(ExpensesBox);
        additionalInfoLabel->setObjectName(QString::fromUtf8("additionalInfoLabel"));
        additionalInfoLabel->setGeometry(QRect(20, 150, 101, 16));
        okButton = new QPushButton(ExpensesBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(20, 240, 75, 23));
        cancelButton = new QPushButton(ExpensesBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(280, 240, 75, 23));

        retranslateUi(expensesDialog);

        QMetaObject::connectSlotsByName(expensesDialog);
    } // setupUi

    void retranslateUi(QDialog *expensesDialog)
    {
        expensesDialog->setWindowTitle(QApplication::translate("expensesDialog", "Expense Info", 0, QApplication::UnicodeUTF8));
        ExpensesBox->setTitle(QApplication::translate("expensesDialog", "Expenses", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("expensesDialog", "Name:", 0, QApplication::UnicodeUTF8));
        dueDateLabel->setText(QApplication::translate("expensesDialog", "Due Date:", 0, QApplication::UnicodeUTF8));
        priorityLevelLabel->setText(QApplication::translate("expensesDialog", "Priority Level:", 0, QApplication::UnicodeUTF8));
        amountLabel->setText(QApplication::translate("expensesDialog", "Amount:", 0, QApplication::UnicodeUTF8));
        penaltyLabel->setText(QApplication::translate("expensesDialog", "Penalty:", 0, QApplication::UnicodeUTF8));
        additionalInfoLabel->setText(QApplication::translate("expensesDialog", "Additional Info:", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("expensesDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("expensesDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExpensesDialog: public Ui_editedExpensesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSES_DIALOG_H
