/********************************************************************************
** Form generated from reading UI file 'item_dialog.ui'
**
** Created: Sat 12. Jun 15:28:43 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEM_DIALOG_H
#define UI_ITEM_DIALOG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class Ui_itemDialog
{
public:
    QGroupBox *itemBox;
    QLineEdit *nameLineEdit;
    QLabel *nameLabel;
    QLabel *amountLabel;
    QLabel *priceLabel;
    QLineEdit *priceLineEdit;
    QLineEdit *amountLineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *IDCodeLabel;
    QLineEdit *IDCodeLineEdit;

    void setupUi(QDialog *itemDialog)
    {
        if (itemDialog->objectName().isEmpty())
            itemDialog->setObjectName(QString::fromUtf8("itemDialog"));
        itemDialog->resize(400, 214);
        itemDialog->setMaximumSize(400, 214);
        itemDialog->setMinimumSize(400, 214);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        itemDialog->setWindowIcon(icon);
        
        itemBox = new QGroupBox(itemDialog);
        itemBox->setObjectName(QString::fromUtf8("itemBox"));
        itemBox->setGeometry(QRect(10, 10, 381, 191));
        itemBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ececec, stop: 1 #ececec); border: 2px solid #ececec; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        nameLineEdit = new QLineEdit(itemBox);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(90, 20, 271, 20));
        nameLabel = new QLabel(itemBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        amountLabel = new QLabel(itemBox);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setGeometry(QRect(190, 72, 52, 13));
        priceLabel = new QLabel(itemBox);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));
        priceLabel->setGeometry(QRect(34, 110, 46, 13));
        priceLineEdit = new QLineEdit(itemBox);
        priceLineEdit->setObjectName(QString::fromUtf8("priceLineEdit"));
        priceLineEdit->setGeometry(QRect(90, 108, 71, 20));
        amountLineEdit = new QLineEdit(itemBox);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(250, 70, 111, 20));
        okButton = new QPushButton(itemBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(290, 160, 75, 32));
        cancelButton = new QPushButton(itemBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(218, 160, 75, 32));
        IDCodeLabel = new QLabel(itemBox);
        IDCodeLabel->setObjectName(QString::fromUtf8("IDCodeLabel"));
        IDCodeLabel->setGeometry(QRect(34, 72, 52, 13));
        IDCodeLineEdit = new QLineEdit(itemBox);
        IDCodeLineEdit->setObjectName(QString::fromUtf8("IDCodeLineEdit"));
        IDCodeLineEdit->setGeometry(QRect(90, 70, 71, 20));

        retranslateUi(itemDialog);

        QMetaObject::connectSlotsByName(itemDialog);
    } // setupUi

    void retranslateUi(QDialog *itemDialog)
    {
        itemDialog->setWindowTitle(QApplication::translate("itemDialog", "Item Info", 0));
        itemBox->setTitle(QApplication::translate("itemDialog", "", 0));
        nameLabel->setText(QApplication::translate("itemDialog", "Name:", 0));
        amountLabel->setText(QApplication::translate("itemDialog", "Number:", 0));
        priceLabel->setText(QApplication::translate("itemDialog", "Price:", 0));
        okButton->setText(QApplication::translate("itemDialog", "Done", 0));
        cancelButton->setText(QApplication::translate("itemDialog", "Cancel", 0));
        IDCodeLabel->setText(QApplication::translate("itemDialog", "IDCode:", 0));
    } // retranslateUi

};

namespace Ui {
    class itemDialog: public Ui_itemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEM_DIALOG_H
