/********************************************************************************
** Form generated from reading UI file 'about_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_DIALOG_H
#define UI_ABOUT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QPushButton *okButton;
    QLabel *label_16;
    QLabel *whyDonate;
    QLabel *label_17;
    QLabel *label_5;
    QLabel *label_15;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QStringLiteral("aboutDialog"));
        aboutDialog->resize(303, 186);
        aboutDialog->setMaximumSize(303, 186);
        aboutDialog->setMinimumSize(303, 186);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_budget/bin/Debug/images/cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        aboutDialog->setWindowIcon(icon);
        okButton = new QPushButton(aboutDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(125, 140, 61, 32));
        label_16 = new QLabel(aboutDialog);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 88, 254, 15));
        whyDonate = new QLabel(aboutDialog);
        whyDonate->setObjectName(QStringLiteral("whyDonate"));
        whyDonate->setGeometry(QRect(27, 13, 254, 29));
        QFont font;
        font.setPointSize(18);
        whyDonate->setFont(font);
        whyDonate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_17 = new QLabel(aboutDialog);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(30, 68, 254, 14));
        label_5 = new QLabel(aboutDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 48, 254, 18));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_15 = new QLabel(aboutDialog);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 109, 254, 18));

        retranslateUi(aboutDialog);

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QApplication::translate("aboutDialog", "About", 0));
        okButton->setText(QApplication::translate("aboutDialog", "OK", 0));
        label_16->setText(QString());
        whyDonate->setText(QApplication::translate("aboutDialog", "CakeHeap Budget Professional", 0));
        label_17->setText(QApplication::translate("aboutDialog", "version 1.0", 0));
        label_5->setText(QApplication::translate("aboutDialog", "Budgeting and fiscal recording software.", 0));
        label_15->setText(QApplication::translate("aboutDialog", "Copyright(C) 2016 Thabo David Klass.", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_DIALOG_H
