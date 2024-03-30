/********************************************************************************
** Form generated from reading UI file 'savings_dialog.ui'
**
** Created: Mon 9. Aug 15:32:07 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVINGS_DIALOG_H
#define UI_SAVINGS_DIALOG_H

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
            savingsDialog->setObjectName(QString::fromUtf8("savingsDialog"));
        savingsDialog->resize(401, 296);
        savingsDialog->setMaximumSize(401, 296);
        savingsDialog->setMinimumSize(401, 296);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        savingsDialog->setWindowIcon(icon);
        
        savingsBox = new QGroupBox(savingsDialog);
        savingsBox->setObjectName(QString::fromUtf8("savingsBox"));
        savingsBox->setGeometry(QRect(10, 10, 381, 271));
        savingsBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ececec, stop: 1 #ececec); border: 2px solid #ececec; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        nameLineEdit = new QLineEdit(savingsBox);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(90, 20, 271, 20));
        nameLabel = new QLabel(savingsBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        natureLabel = new QLabel(savingsBox);
        natureLabel->setObjectName(QString::fromUtf8("natureLabel"));
        natureLabel->setGeometry(QRect(20, 68, 71, 20));
        amountLabel = new QLabel(savingsBox);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setGeometry(QRect(190, 72, 50, 13));
        APRLabel = new QLabel(savingsBox);
        APRLabel->setObjectName(QString::fromUtf8("APRLabel"));
        APRLabel->setGeometry(QRect(20, 110, 46, 13));
        natureComboBox = new QComboBox(savingsBox);
        natureComboBox->setObjectName(QString::fromUtf8("natureComboBox"));
        natureComboBox->setGeometry(QRect(88, 66, 90, 22));
        natureComboBox->addItem(QString("STOCK"));
        natureComboBox->addItem(QString("BANK"));
        APRLineEdit = new QLineEdit(savingsBox);
        APRLineEdit->setObjectName(QString::fromUtf8("APRLineEdit"));
        APRLineEdit->setGeometry(QRect(90, 108, 71, 20));
        amountLineEdit = new QLineEdit(savingsBox);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(250, 70, 111, 20));
        okButton = new QPushButton(savingsBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(290, 238, 75, 32));
        cancelButton = new QPushButton(savingsBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(218, 238, 75, 32));
        descriptionLabel = new QLabel(savingsBox);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));
        descriptionLabel->setGeometry(QRect(30, 140, 71, 16));
        descriptionTextEdit = new QTextEdit(savingsBox);
        descriptionTextEdit->setObjectName(QString::fromUtf8("descriptionTextEdit"));
        descriptionTextEdit->setGeometry(QRect(20, 160, 341, 61));
        amountLabel_2 = new QLabel(savingsBox);
        amountLabel_2->setObjectName(QString::fromUtf8("amountLabel_2"));
        amountLabel_2->setGeometry(QRect(190, 110, 46, 13));
        dueDateEdit = new QDateEdit(savingsDialog);
        dueDateEdit->setObjectName(QString::fromUtf8("dueDateEdit"));
        dueDateEdit->setGeometry(QRect(260, 120, 111, 22));

        retranslateUi(savingsDialog);

        QMetaObject::connectSlotsByName(savingsDialog);
    } // setupUi

    void retranslateUi(QDialog *savingsDialog)
    {
        savingsDialog->setWindowTitle(QApplication::translate("savingsDialog", "Savings Info", 0));
        savingsBox->setTitle(QApplication::translate("savingsDialog", "", 0));
        nameLabel->setText(QApplication::translate("savingsDialog", "Name:", 0));
        natureLabel->setText(QApplication::translate("savingsDialog", "Nature:", 0));
        amountLabel->setText(QApplication::translate("savingsDialog", "Amount:", 0));
        APRLabel->setText(QApplication::translate("savingsDialog", "APR(%):", 0));
        okButton->setText(QApplication::translate("savingsDialog", "Done", 0));
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
