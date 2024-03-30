/********************************************************************************
** Form generated from reading UI file 'item_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEM_DIALOG_H
#define UI_ITEM_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

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
            itemDialog->setObjectName(QStringLiteral("itemDialog"));
        itemDialog->resize(400, 214);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        itemDialog->setWindowIcon(icon);
        itemBox = new QGroupBox(itemDialog);
        itemBox->setObjectName(QStringLiteral("itemBox"));
        itemBox->setGeometry(QRect(10, 10, 381, 191));
        nameLineEdit = new QLineEdit(itemBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(90, 20, 271, 20));
        nameLabel = new QLabel(itemBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(20, 23, 46, 13));
        amountLabel = new QLabel(itemBox);
        amountLabel->setObjectName(QStringLiteral("amountLabel"));
        amountLabel->setGeometry(QRect(190, 72, 46, 13));
        priceLabel = new QLabel(itemBox);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));
        priceLabel->setGeometry(QRect(40, 110, 46, 13));
        priceLineEdit = new QLineEdit(itemBox);
        priceLineEdit->setObjectName(QStringLiteral("priceLineEdit"));
        priceLineEdit->setGeometry(QRect(90, 108, 71, 20));
        amountLineEdit = new QLineEdit(itemBox);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(250, 70, 111, 20));
        okButton = new QPushButton(itemBox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(20, 150, 75, 23));
        cancelButton = new QPushButton(itemBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(280, 150, 75, 23));
        IDCodeLabel = new QLabel(itemBox);
        IDCodeLabel->setObjectName(QStringLiteral("IDCodeLabel"));
        IDCodeLabel->setGeometry(QRect(40, 72, 46, 13));
        IDCodeLineEdit = new QLineEdit(itemBox);
        IDCodeLineEdit->setObjectName(QStringLiteral("IDCodeLineEdit"));
        IDCodeLineEdit->setGeometry(QRect(90, 70, 71, 20));

        retranslateUi(itemDialog);

        QMetaObject::connectSlotsByName(itemDialog);
    } // setupUi

    void retranslateUi(QDialog *itemDialog)
    {
        itemDialog->setWindowTitle(QApplication::translate("itemDialog", "Item Info", 0));
        itemBox->setTitle(QApplication::translate("itemDialog", "Item", 0));
        nameLabel->setText(QApplication::translate("itemDialog", "Name:", 0));
        amountLabel->setText(QApplication::translate("itemDialog", "Amount:", 0));
        priceLabel->setText(QApplication::translate("itemDialog", "Price:", 0));
        okButton->setText(QApplication::translate("itemDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("itemDialog", "Cancel", 0));
        IDCodeLabel->setText(QApplication::translate("itemDialog", "IDCode:", 0));
    } // retranslateUi

};

namespace Ui {
    class itemDialog: public Ui_itemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEM_DIALOG_H
