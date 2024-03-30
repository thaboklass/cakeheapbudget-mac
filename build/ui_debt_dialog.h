/********************************************************************************
** Form generated from reading UI file 'debt_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBT_DIALOG_H
#define UI_DEBT_DIALOG_H

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
    QLineEdit *penaltyLineEdit;
    QLabel *penaltyLabel;

    void setupUi(QDialog *debtDialog)
    {
        if (debtDialog->objectName().isEmpty())
            debtDialog->setObjectName(QStringLiteral("debtDialog"));
        debtDialog->resize(407, 352);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        debtDialog->setWindowIcon(icon);
        DebtBox = new QGroupBox(debtDialog);
        DebtBox->setObjectName(QStringLiteral("DebtBox"));
        DebtBox->setGeometry(QRect(10, 10, 381, 321));
        nameLineEdit = new QLineEdit(DebtBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(80, 20, 291, 20));
        nameLabel = new QLabel(DebtBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        dueDateLabel = new QLabel(DebtBox);
        dueDateLabel->setObjectName(QStringLiteral("dueDateLabel"));
        dueDateLabel->setGeometry(QRect(20, 70, 61, 16));
        priorityLevelLabel = new QLabel(DebtBox);
        priorityLevelLabel->setObjectName(QStringLiteral("priorityLevelLabel"));
        priorityLevelLabel->setGeometry(QRect(210, 68, 71, 20));
        amountLabel = new QLabel(DebtBox);
        amountLabel->setObjectName(QStringLiteral("amountLabel"));
        amountLabel->setGeometry(QRect(20, 110, 46, 13));
        APRLabel = new QLabel(DebtBox);
        APRLabel->setObjectName(QStringLiteral("APRLabel"));
        APRLabel->setGeometry(QRect(230, 110, 46, 13));
        dueDateEdit = new QDateEdit(DebtBox);
        dueDateEdit->setObjectName(QStringLiteral("dueDateEdit"));
        dueDateEdit->setGeometry(QRect(90, 66, 101, 22));
        priorityLevelComboBox = new QComboBox(DebtBox);
        priorityLevelComboBox->setObjectName(QStringLiteral("priorityLevelComboBox"));
        priorityLevelComboBox->setGeometry(QRect(280, 66, 69, 22));
        APRLineEdit = new QLineEdit(DebtBox);
        APRLineEdit->setObjectName(QStringLiteral("APRLineEdit"));
        APRLineEdit->setGeometry(QRect(280, 108, 71, 20));
        amountLineEdit = new QLineEdit(DebtBox);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(90, 108, 111, 20));
        additionalInfoTextEdit = new QTextEdit(DebtBox);
        additionalInfoTextEdit->setObjectName(QStringLiteral("additionalInfoTextEdit"));
        additionalInfoTextEdit->setGeometry(QRect(10, 213, 361, 61));
        additionalInfoLabel = new QLabel(DebtBox);
        additionalInfoLabel->setObjectName(QStringLiteral("additionalInfoLabel"));
        additionalInfoLabel->setGeometry(QRect(20, 190, 101, 16));
        okButton = new QPushButton(DebtBox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(20, 280, 75, 23));
        cancelButton = new QPushButton(DebtBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(280, 280, 75, 23));
        penaltyLineEdit = new QLineEdit(DebtBox);
        penaltyLineEdit->setObjectName(QStringLiteral("penaltyLineEdit"));
        penaltyLineEdit->setGeometry(QRect(90, 148, 111, 20));
        penaltyLabel = new QLabel(DebtBox);
        penaltyLabel->setObjectName(QStringLiteral("penaltyLabel"));
        penaltyLabel->setGeometry(QRect(20, 150, 71, 16));

        retranslateUi(debtDialog);

        QMetaObject::connectSlotsByName(debtDialog);
    } // setupUi

    void retranslateUi(QDialog *debtDialog)
    {
        debtDialog->setWindowTitle(QApplication::translate("debtDialog", "Debt Info", 0));
        DebtBox->setTitle(QApplication::translate("debtDialog", "Debt", 0));
        nameLabel->setText(QApplication::translate("debtDialog", "Name:", 0));
        dueDateLabel->setText(QApplication::translate("debtDialog", "Due Date:", 0));
        priorityLevelLabel->setText(QApplication::translate("debtDialog", "Priority Level:", 0));
        amountLabel->setText(QApplication::translate("debtDialog", "Amount:", 0));
        APRLabel->setText(QApplication::translate("debtDialog", "APR(%):", 0));
        additionalInfoLabel->setText(QApplication::translate("debtDialog", "Additional Info:", 0));
        okButton->setText(QApplication::translate("debtDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("debtDialog", "Cancel", 0));
        penaltyLabel->setText(QApplication::translate("debtDialog", "No. og Moths:", 0));
    } // retranslateUi

};

namespace Ui {
    class debtDialog: public Ui_debtDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBT_DIALOG_H
