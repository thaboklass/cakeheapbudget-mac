/********************************************************************************
** Form generated from reading UI file 'savings_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVINGS_DIALOG_H
#define UI_SAVINGS_DIALOG_H

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

class Ui_savingsDialog
{
public:
    QGroupBox *savingsBox;
    QLineEdit *nameLineEdit;
    QLabel *nameLabel;
    QLabel *natureLabel;
    QLabel *amountLabel;
    QLabel *APRLabel;
    QComboBox *natureComboBox;
    QLineEdit *APRLineEdit;
    QLineEdit *amountLineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *descriptionLabel;
    QTextEdit *descriptionTextEdit;
    QLabel *amountLabel_2;
    QDateEdit *dueDateEdit;

    void setupUi(QDialog *savingsDialog)
    {
        if (savingsDialog->objectName().isEmpty())
            savingsDialog->setObjectName(QStringLiteral("savingsDialog"));
        savingsDialog->resize(401, 296);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        savingsDialog->setWindowIcon(icon);
        savingsBox = new QGroupBox(savingsDialog);
        savingsBox->setObjectName(QStringLiteral("savingsBox"));
        savingsBox->setGeometry(QRect(10, 10, 381, 271));
        nameLineEdit = new QLineEdit(savingsBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(90, 20, 271, 20));
        nameLabel = new QLabel(savingsBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        natureLabel = new QLabel(savingsBox);
        natureLabel->setObjectName(QStringLiteral("natureLabel"));
        natureLabel->setGeometry(QRect(20, 68, 71, 20));
        amountLabel = new QLabel(savingsBox);
        amountLabel->setObjectName(QStringLiteral("amountLabel"));
        amountLabel->setGeometry(QRect(190, 72, 46, 13));
        APRLabel = new QLabel(savingsBox);
        APRLabel->setObjectName(QStringLiteral("APRLabel"));
        APRLabel->setGeometry(QRect(20, 110, 46, 13));
        natureComboBox = new QComboBox(savingsBox);
        natureComboBox->setObjectName(QStringLiteral("natureComboBox"));
        natureComboBox->setGeometry(QRect(90, 66, 69, 22));
        APRLineEdit = new QLineEdit(savingsBox);
        APRLineEdit->setObjectName(QStringLiteral("APRLineEdit"));
        APRLineEdit->setGeometry(QRect(90, 108, 71, 20));
        amountLineEdit = new QLineEdit(savingsBox);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(250, 70, 111, 20));
        okButton = new QPushButton(savingsBox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(20, 230, 75, 23));
        cancelButton = new QPushButton(savingsBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(280, 230, 75, 23));
        descriptionLabel = new QLabel(savingsBox);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        descriptionLabel->setGeometry(QRect(30, 140, 71, 16));
        descriptionTextEdit = new QTextEdit(savingsBox);
        descriptionTextEdit->setObjectName(QStringLiteral("descriptionTextEdit"));
        descriptionTextEdit->setGeometry(QRect(20, 160, 341, 61));
        amountLabel_2 = new QLabel(savingsBox);
        amountLabel_2->setObjectName(QStringLiteral("amountLabel_2"));
        amountLabel_2->setGeometry(QRect(190, 110, 46, 13));
        dueDateEdit = new QDateEdit(savingsDialog);
        dueDateEdit->setObjectName(QStringLiteral("dueDateEdit"));
        dueDateEdit->setGeometry(QRect(260, 120, 111, 22));

        retranslateUi(savingsDialog);

        QMetaObject::connectSlotsByName(savingsDialog);
    } // setupUi

    void retranslateUi(QDialog *savingsDialog)
    {
        savingsDialog->setWindowTitle(QApplication::translate("savingsDialog", "Savings Info", 0));
        savingsBox->setTitle(QApplication::translate("savingsDialog", "Savings", 0));
        nameLabel->setText(QApplication::translate("savingsDialog", "Name:", 0));
        natureLabel->setText(QApplication::translate("savingsDialog", "Nature:", 0));
        amountLabel->setText(QApplication::translate("savingsDialog", "Amount:", 0));
        APRLabel->setText(QApplication::translate("savingsDialog", "APR(%):", 0));
        okButton->setText(QApplication::translate("savingsDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("savingsDialog", "Cancel", 0));
        descriptionLabel->setText(QApplication::translate("savingsDialog", "Description:", 0));
        amountLabel_2->setText(QApplication::translate("savingsDialog", "Date:", 0));
    } // retranslateUi

};

namespace Ui {
    class savingsDialog: public Ui_savingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVINGS_DIALOG_H
