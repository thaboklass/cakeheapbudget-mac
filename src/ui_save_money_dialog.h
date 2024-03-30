/********************************************************************************
** Form generated from reading UI file 'save_money_dialog.ui'
**
** Created: Sat 12. Jun 16:58:55 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_MONEY_DIALOH_H
#define UI_SAVE_MONEY_DIALOH_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QDialog>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class Ui_saveMoneyDialog
{
public:
    QGroupBox *saveMoneyBox;
    QLabel *selectSavingsLabel;
    QLabel *amountLabel;
    QComboBox *selectSavingsComboBox;
    QLineEdit *amountLineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *saveMoneyDialog)
    {
        if (saveMoneyDialog->objectName().isEmpty())
            saveMoneyDialog->setObjectName(QString::fromUtf8("saveMoneyDialog"));
        saveMoneyDialog->resize(435, 177);
        saveMoneyDialog->setMaximumSize(435, 177);
        saveMoneyDialog->setMinimumSize(435, 177);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveMoneyDialog->setWindowIcon(icon);
        
        saveMoneyBox = new QGroupBox(saveMoneyDialog);
        saveMoneyBox->setObjectName(QString::fromUtf8("saveMoneyBox"));
        saveMoneyBox->setGeometry(QRect(10, 10, 420, 151));
        saveMoneyBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ececec, stop: 1 #ececec); border: 2px solid #ececec; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        selectSavingsLabel = new QLabel(saveMoneyBox);
        selectSavingsLabel->setObjectName(QString::fromUtf8("selectSavingsLabel"));
        selectSavingsLabel->setGeometry(QRect(20, 20, 90, 20));
        amountLabel = new QLabel(saveMoneyBox);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setGeometry(QRect(20, 60, 70, 13));
        selectSavingsComboBox = new QComboBox(saveMoneyBox);
        selectSavingsComboBox->setObjectName(QString::fromUtf8("selectSavingsComboBox"));
        selectSavingsComboBox->setGeometry(QRect(130, 20, 261, 22));
        amountLineEdit = new QLineEdit(saveMoneyBox);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(130, 56, 111, 20));
        okButton = new QPushButton(saveMoneyBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(316, 115, 75, 32));
        cancelButton = new QPushButton(saveMoneyBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(244, 115, 75, 32));

        retranslateUi(saveMoneyDialog);

        QMetaObject::connectSlotsByName(saveMoneyDialog);
    } // setupUi

    void retranslateUi(QDialog *saveMoneyDialog)
    {
        saveMoneyDialog->setWindowTitle(QApplication::translate("saveMoneyDialog", "Save Money Info", 0));
        saveMoneyBox->setTitle(QApplication::translate("saveMoneyDialog", "", 0));
        selectSavingsLabel->setText(QApplication::translate("saveMoneyDialog", "Select Savings:", 0));
        amountLabel->setText(QApplication::translate("saveMoneyDialog", "Amount:", 0));
        okButton->setText(QApplication::translate("saveMoneyDialog", "Done", 0));
        cancelButton->setText(QApplication::translate("saveMoneyDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class saveMoneyDialog: public Ui_saveMoneyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_MONEY_DIALOH_H
