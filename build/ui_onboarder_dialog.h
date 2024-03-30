/********************************************************************************
** Form generated from reading UI file 'onboarder_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONBOARDER_DIALOG_H
#define UI_ONBOARDER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OnboarderDialog
{
public:
    QPushButton *doneButton;
    QCheckBox *showAgainCheckBox;
    QLabel *welcomeLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *doneButton_2;
    QLabel *label_7;
    QPushButton *doneButton_3;
    QPushButton *doneButton_4;

    void setupUi(QDialog *OnboarderDialog)
    {
        if (OnboarderDialog->objectName().isEmpty())
            OnboarderDialog->setObjectName(QStringLiteral("OnboarderDialog"));
        OnboarderDialog->resize(404, 331);
        doneButton = new QPushButton(OnboarderDialog);
        doneButton->setObjectName(QStringLiteral("doneButton"));
        doneButton->setGeometry(QRect(300, 290, 91, 32));
        showAgainCheckBox = new QCheckBox(OnboarderDialog);
        showAgainCheckBox->setObjectName(QStringLiteral("showAgainCheckBox"));
        showAgainCheckBox->setGeometry(QRect(10, 290, 171, 20));
        welcomeLabel = new QLabel(OnboarderDialog);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(70, 20, 261, 41));
        QFont font;
        font.setPointSize(24);
        welcomeLabel->setFont(font);
        label = new QLabel(OnboarderDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 381, 31));
        label_2 = new QLabel(OnboarderDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 381, 31));
        label_3 = new QLabel(OnboarderDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 100, 381, 31));
        label_4 = new QLabel(OnboarderDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 140, 321, 21));
        label_5 = new QLabel(OnboarderDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 200, 321, 21));
        label_6 = new QLabel(OnboarderDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 240, 211, 21));
        doneButton_2 = new QPushButton(OnboarderDialog);
        doneButton_2->setObjectName(QStringLiteral("doneButton_2"));
        doneButton_2->setGeometry(QRect(300, 160, 91, 32));
        label_7 = new QLabel(OnboarderDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 160, 321, 21));
        doneButton_3 = new QPushButton(OnboarderDialog);
        doneButton_3->setObjectName(QStringLiteral("doneButton_3"));
        doneButton_3->setGeometry(QRect(300, 200, 91, 32));
        doneButton_4 = new QPushButton(OnboarderDialog);
        doneButton_4->setObjectName(QStringLiteral("doneButton_4"));
        doneButton_4->setGeometry(QRect(300, 240, 91, 32));

        retranslateUi(OnboarderDialog);

        QMetaObject::connectSlotsByName(OnboarderDialog);
    } // setupUi

    void retranslateUi(QDialog *OnboarderDialog)
    {
        OnboarderDialog->setWindowTitle(QApplication::translate("OnboarderDialog", "Dialog", 0));
        doneButton->setText(QApplication::translate("OnboarderDialog", "Done", 0));
        showAgainCheckBox->setText(QApplication::translate("OnboarderDialog", "Do not show this again.", 0));
        welcomeLabel->setText(QApplication::translate("OnboarderDialog", "Welcome to CakeHeap!", 0));
        label->setText(QApplication::translate("OnboarderDialog", "Hey! Thanks for purchasing CakeHeap Budget Professional,", 0));
        label_2->setText(QApplication::translate("OnboarderDialog", "a tool to plan your bugdets and keep records of your finances.", 0));
        label_3->setText(QApplication::translate("OnboarderDialog", "CakeHeap files are records that span a one year period.", 0));
        label_4->setText(QApplication::translate("OnboarderDialog", "Download the sample file to see a filled:", 0));
        label_5->setText(QApplication::translate("OnboarderDialog", "View the CakeHeap manual:", 0));
        label_6->setText(QApplication::translate("OnboarderDialog", "Create a new CakeHeap file:", 0));
        doneButton_2->setText(QApplication::translate("OnboarderDialog", "Sample", 0));
        label_7->setText(QApplication::translate("OnboarderDialog", "CakeHeap file: ", 0));
        doneButton_3->setText(QApplication::translate("OnboarderDialog", "Manual", 0));
        doneButton_4->setText(QApplication::translate("OnboarderDialog", "New", 0));
    } // retranslateUi

};

namespace Ui {
    class OnboarderDialog: public Ui_OnboarderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONBOARDER_DIALOG_H
