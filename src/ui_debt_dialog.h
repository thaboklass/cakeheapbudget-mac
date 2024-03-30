/********************************************************************************
** Form generated from reading UI file 'debt_dialog.ui'
**
** Created: Sat 12. Jun 14:13:32 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBT_DIALOG_H
#define UI_DEBT_DIALOG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QDateEdit>
#include <QDialog>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_debtDialog
{
public:
    QGroupBox *DebtBox;
    QLineEdit *nameLineEdit;
    QLabel *nameLabel;
    QLabel *dueDateLabel;
    QLabel *priorityLevelLabel;
    QLabel *amountLabel;
    QLabel *APRLabel;
    QDateEdit *dueDateEdit;
    QComboBox *priorityLevelComboBox;
    QLineEdit *APRLineEdit;
    QLineEdit *amountLineEdit;
    QTextEdit *additionalInfoTextEdit;
    QLabel *additionalInfoLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLineEdit *numberOfMonthsLineEdit;
    QLabel *numberOfMonthsLabel;

    void setupUi(QDialog *debtDialog)
    {
        if (debtDialog->objectName().isEmpty())
            debtDialog->setObjectName(QString::fromUtf8("debtDialog"));
        debtDialog->resize(480, 352);
        debtDialog->setMaximumSize(480, 352);
        debtDialog->setMinimumSize(480, 352);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        debtDialog->setWindowIcon(icon);
        
        DebtBox = new QGroupBox(debtDialog);
        DebtBox->setObjectName(QString::fromUtf8("DebtBox"));
        DebtBox->setGeometry(QRect(10, 10, 450, 321));
        DebtBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ececec, stop: 1 #ececec); border: 2px solid #ececec; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        nameLineEdit = new QLineEdit(DebtBox);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(120, 20, 325, 20));
        nameLabel = new QLabel(DebtBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        dueDateLabel = new QLabel(DebtBox);
        dueDateLabel->setObjectName(QString::fromUtf8("dueDateLabel"));
        dueDateLabel->setGeometry(QRect(20, 70, 61, 16));
        priorityLevelLabel = new QLabel(DebtBox);
        priorityLevelLabel->setObjectName(QString::fromUtf8("priorityLevelLabel"));
        priorityLevelLabel->setGeometry(QRect(260, 68, 100, 20));
        amountLabel = new QLabel(DebtBox);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setGeometry(QRect(20, 110, 85, 13));
        APRLabel = new QLabel(DebtBox);
        APRLabel->setObjectName(QString::fromUtf8("APRLabel"));
        APRLabel->setGeometry(QRect(260, 110, 46, 13));
        dueDateEdit = new QDateEdit(DebtBox);
        dueDateEdit->setObjectName(QString::fromUtf8("dueDateEdit"));
        dueDateEdit->setGeometry(QRect(120, 66, 101, 22));
        priorityLevelComboBox = new QComboBox(DebtBox);
        priorityLevelComboBox->setObjectName(QString::fromUtf8("priorityLevelComboBox"));
        priorityLevelComboBox->setGeometry(QRect(355, 66, 90, 22));
        priorityLevelComboBox->addItem(QString("HIGH"));
        priorityLevelComboBox->addItem(QString("MEDIUM"));
        priorityLevelComboBox->addItem(QString("LOW"));
        priorityLevelComboBox->addItem(QString("NONE"));
        APRLineEdit = new QLineEdit(DebtBox);
        APRLineEdit->setObjectName(QString::fromUtf8("APRLineEdit"));
        APRLineEdit->setGeometry(QRect(355, 108, 71, 20));
        amountLineEdit = new QLineEdit(DebtBox);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(120, 108, 111, 20));
        additionalInfoTextEdit = new QTextEdit(DebtBox);
        additionalInfoTextEdit->setObjectName(QString::fromUtf8("additionalInfoTextEdit"));
        additionalInfoTextEdit->setGeometry(QRect(20, 213, 425, 61));
        additionalInfoLabel = new QLabel(DebtBox);
        additionalInfoLabel->setObjectName(QString::fromUtf8("additionalInfoLabel"));
        additionalInfoLabel->setGeometry(QRect(20, 190, 101, 16));
        okButton = new QPushButton(DebtBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(376, 290, 75, 32));
        cancelButton = new QPushButton(DebtBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(304, 290, 75, 32));
        numberOfMonthsLineEdit = new QLineEdit(DebtBox);
        numberOfMonthsLineEdit->setObjectName(QString::fromUtf8("penaltyLineEdit"));
        numberOfMonthsLineEdit->setGeometry(QRect(120, 148, 111, 20));
        //numberOfMonthsLineEdit->setEnabled(false);
        numberOfMonthsLabel = new QLabel(DebtBox);
        numberOfMonthsLabel->setObjectName(QString::fromUtf8("numberOfMonthsLabel"));
        numberOfMonthsLabel->setGeometry(QRect(20, 150, 100, 13));

        retranslateUi(debtDialog);

        QMetaObject::connectSlotsByName(debtDialog);
    } // setupUi

    void retranslateUi(QDialog *debtDialog)
    {
        debtDialog->setWindowTitle(QApplication::translate("debtDialog", "Debt Info", 0));
        DebtBox->setTitle(QApplication::translate("debtDialog", "", 0));
        nameLabel->setText(QApplication::translate("debtDialog", "Name:", 0));
        dueDateLabel->setText(QApplication::translate("debtDialog", "Due Date:", 0));
        priorityLevelLabel->setText(QApplication::translate("debtDialog", "Priority Level:", 0));
        amountLabel->setText(QApplication::translate("debtDialog", "Total Amount:", 0));
        APRLabel->setText(QApplication::translate("debtDialog", "APR(%):", 0));
        additionalInfoLabel->setText(QApplication::translate("debtDialog", "Additional Info:", 0));
        okButton->setText(QApplication::translate("debtDialog", "Done", 0));
        cancelButton->setText(QApplication::translate("debtDialog", "Cancel", 0));
        numberOfMonthsLabel->setText(QApplication::translate("debtDialog", "No. of Months:", 0));
    } // retranslateUi

};

namespace Ui {
    class debtDialog: public Ui_debtDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBT_DIALOG_H
