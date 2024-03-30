/********************************************************************************
** Form generated from reading UI file 'income_statement_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOME_STATEMENT_DIALOG_H
#define UI_INCOME_STATEMENT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_incomeStatementDialog
{
public:
    QGroupBox *incomeStatementBox;
    QTextBrowser *textBrowser;
    QPushButton *closeButton;

    void setupUi(QDialog *incomeStatementDialog)
    {
        if (incomeStatementDialog->objectName().isEmpty())
            incomeStatementDialog->setObjectName(QStringLiteral("incomeStatementDialog"));
        incomeStatementDialog->resize(1025, 639);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        incomeStatementDialog->setWindowIcon(icon);
        incomeStatementBox = new QGroupBox(incomeStatementDialog);
        incomeStatementBox->setObjectName(QStringLiteral("incomeStatementBox"));
        incomeStatementBox->setGeometry(QRect(10, 10, 1001, 591));
        textBrowser = new QTextBrowser(incomeStatementBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(15, 21, 971, 551));
        closeButton = new QPushButton(incomeStatementDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(910, 610, 75, 23));

        retranslateUi(incomeStatementDialog);

        QMetaObject::connectSlotsByName(incomeStatementDialog);
    } // setupUi

    void retranslateUi(QDialog *incomeStatementDialog)
    {
        incomeStatementDialog->setWindowTitle(QApplication::translate("incomeStatementDialog", "Income Statement", 0));
        incomeStatementBox->setTitle(QApplication::translate("incomeStatementDialog", "Income Statement", 0));
        closeButton->setText(QApplication::translate("incomeStatementDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class incomeStatementDialog: public Ui_incomeStatementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOME_STATEMENT_DIALOG_H
