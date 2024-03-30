/********************************************************************************
** Form generated from reading UI file 'income_statement_dialog.ui'
**
** Created: Wed 30. Jun 17:09:26 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOME_STATEMENT_H
#define UI_INCOME_STATEMENT_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QGroupBox>
#include <QHeaderView>
#include <QPushButton>
#include <QTextBrowser>

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
            incomeStatementDialog->setObjectName(QString::fromUtf8("incomeStatementDialog"));
        incomeStatementDialog->resize(1025, 639);
        incomeStatementDialog->setMaximumSize(1025, 639);
        incomeStatementDialog->setMinimumSize(1025, 639);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        incomeStatementDialog->setWindowIcon(icon);
        incomeStatementBox = new QGroupBox(incomeStatementDialog);
        incomeStatementBox->setObjectName(QString::fromUtf8("incomeStatementBox"));
        incomeStatementBox->setGeometry(QRect(10, 10, 1001, 591));
        incomeStatementBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ececec, stop: 1 #ececec); border: 2px solid #ececec; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        textBrowser = new QTextBrowser(incomeStatementBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(15, 21, 971, 551));
        closeButton = new QPushButton(incomeStatementDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(925, 596, 75, 23));

        retranslateUi(incomeStatementDialog);

        QMetaObject::connectSlotsByName(incomeStatementDialog);
    } // setupUi

    void retranslateUi(QDialog *incomeStatementDialog)
    {
        incomeStatementDialog->setWindowTitle(QApplication::translate("incomeStatementDialog", "Income Statement", 0));
        incomeStatementBox->setTitle(QApplication::translate("incomeStatementDialog", "", 0));
        closeButton->setText(QApplication::translate("incomeStatementDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class incomeStatementDialog: public Ui_incomeStatementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOME_STATEMENT_H
