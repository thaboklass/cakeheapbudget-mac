/********************************************************************************
** Form generated from reading UI file 'income_dialog.ui'
**
** Created: Sat 12. Jun 15:11:47 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOME_DIALOG_H
#define UI_INCOME_DIALOG_H

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
            incomeDialog->setObjectName(QString::fromUtf8("incomeDialog"));
        incomeDialog->resize(440, 300);
        incomeDialog->setMaximumSize(440, 300);
        incomeDialog->setMinimumSize(440, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        incomeDialog->setWindowIcon(icon);
        
        incomeBox = new QGroupBox(incomeDialog);
        incomeBox->setObjectName(QString::fromUtf8("incomeBox"));
        incomeBox->setGeometry(QRect(10, 10, 400, 271));
        incomeBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ececec, stop: 1 #ececec); border: 2px solid #ececec; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        nameLineEdit = new QLineEdit(incomeBox);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(80, 20, 315, 20));
        nameLabel = new QLabel(incomeBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        dateLabel = new QLabel(incomeBox);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(20, 70, 46, 13));
        natureLabel = new QLabel(incomeBox);
        natureLabel->setObjectName(QString::fromUtf8("natureLabel"));
        natureLabel->setGeometry(QRect(220, 70, 46, 13));
        amountLabel = new QLabel(incomeBox);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setGeometry(QRect(20, 110, 46, 13));
        taxLabel = new QLabel(incomeBox);
        taxLabel->setObjectName(QString::fromUtf8("taxLabel"));
        taxLabel->setGeometry(QRect(220, 110, 46, 13));
        dateEdit = new QDateEdit(incomeBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(80, 66, 110, 22));
        natureComboBox = new QComboBox(incomeBox);
        natureComboBox->setObjectName(QString::fromUtf8("natureComboBox"));
        natureComboBox->setGeometry(QRect(270, 66, 130, 22));
        natureComboBox->addItem(QString("SALARY"));
        natureComboBox->addItem(QString("DIVIDEND"));
        natureComboBox->addItem(QString("STOCK_SALE"));
        natureComboBox->addItem(QString("IOU"));
        natureComboBox->addItem(QString("DIP"));
        natureComboBox->addItem(QString("OTHER"));
        taxLineEdt = new QLineEdit(incomeBox);
        taxLineEdt->setObjectName(QString::fromUtf8("taxLineEdt"));
        taxLineEdt->setGeometry(QRect(272, 108, 71, 20));
        amountLineEdit = new QLineEdit(incomeBox);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(80, 108, 111, 20));
        additionalInfoTextEdit = new QTextEdit(incomeBox);
        additionalInfoTextEdit->setObjectName(QString::fromUtf8("additionalInfoTextEdit"));
        additionalInfoTextEdit->setGeometry(QRect(20, 173, 380, 61));
        additionalInfoLabel = new QLabel(incomeBox);
        additionalInfoLabel->setObjectName(QString::fromUtf8("additionalInfoLabel"));
        additionalInfoLabel->setGeometry(QRect(20, 150, 101, 16));
        okButton = new QPushButton(incomeBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(330, 246, 75, 32));
        cancelButton = new QPushButton(incomeBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(258, 246, 75, 32));

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
        okButton->setText(QApplication::translate("incomeDialog", "Done", 0));
        cancelButton->setText(QApplication::translate("incomeDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class incomeDialog: public Ui_incomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOME_DIALOG_H
