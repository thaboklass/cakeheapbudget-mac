/********************************************************************************
** Form generated from reading UI file 'donate_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DONATE_DIALOG_H
#define UI_DONATE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_donationDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *donationImage;
    QVBoxLayout *verticalLayout;
    QLabel *whyDonate;
    QLabel *label_5;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QPushButton *cancelButton;
    QPushButton *donateButton;

    void setupUi(QDialog *donationDialog)
    {
        if (donationDialog->objectName().isEmpty())
            donationDialog->setObjectName(QStringLiteral("donationDialog"));
        donationDialog->resize(543, 424);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_budget/bin/Debug/images/cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        donationDialog->setWindowIcon(icon);
        horizontalLayoutWidget = new QWidget(donationDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 521, 356));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        donationImage = new QLabel(horizontalLayoutWidget);
        donationImage->setObjectName(QStringLiteral("donationImage"));
        donationImage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(donationImage);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        whyDonate = new QLabel(horizontalLayoutWidget);
        whyDonate->setObjectName(QStringLiteral("whyDonate"));
        QFont font;
        font.setPointSize(18);
        whyDonate->setFont(font);
        whyDonate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(whyDonate);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_5);

        label_17 = new QLabel(horizontalLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout->addWidget(label_17);

        label_16 = new QLabel(horizontalLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout->addWidget(label_16);

        label_15 = new QLabel(horizontalLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout->addWidget(label_15);

        label_14 = new QLabel(horizontalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout->addWidget(label_14);

        label_13 = new QLabel(horizontalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout->addWidget(label_13);

        label_12 = new QLabel(horizontalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout->addWidget(label_12);

        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout->addWidget(label_11);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout->addWidget(label_10);

        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout->addWidget(label_9);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout->addWidget(label_8);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_4);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        cancelButton = new QPushButton(donationDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(380, 390, 61, 23));
        donateButton = new QPushButton(donationDialog);
        donateButton->setObjectName(QStringLiteral("donateButton"));
        donateButton->setGeometry(QRect(90, 390, 61, 23));

        retranslateUi(donationDialog);

        QMetaObject::connectSlotsByName(donationDialog);
    } // setupUi

    void retranslateUi(QDialog *donationDialog)
    {
        donationDialog->setWindowTitle(QApplication::translate("donationDialog", "Donate? Why?", 0));
        donationImage->setText(QString());
        whyDonate->setText(QApplication::translate("donationDialog", "Donate? Why?", 0));
        label_5->setText(QApplication::translate("donationDialog", "\"Who donates for free software anyway?\" The", 0));
        label_17->setText(QApplication::translate("donationDialog", "answer is: Millions upon millions of people. Some of", 0));
        label_16->setText(QApplication::translate("donationDialog", "the greatest innovations in software were", 0));
        label_15->setText(QApplication::translate("donationDialog", "powered by generous donors. Donating benefits", 0));
        label_14->setText(QApplication::translate("donationDialog", "both creators and users. Benefits? What benefits?", 0));
        label_13->setText(QApplication::translate("donationDialog", "1. Donations fund bug fixes,useful additional", 0));
        label_12->setText(QApplication::translate("donationDialog", "features, new and better software. Donations", 0));
        label_11->setText(QApplication::translate("donationDialog", "fund the useful CakeHeap Budget software, which", 0));
        label_10->setText(QApplication::translate("donationDialog", "of course, benefits users.", 0));
        label_9->setText(QApplication::translate("donationDialog", "2. Users become part of a community that suggests", 0));
        label_8->setText(QApplication::translate("donationDialog", "additional features that direct the development of", 0));
        label_4->setText(QApplication::translate("donationDialog", "CakeHeap Budget.Thereby, maximizing benefit to", 0));
        label_7->setText(QApplication::translate("donationDialog", "the end user.", 0));
        label_3->setText(QApplication::translate("donationDialog", "3. Need more incentive. Donators will get discounts ", 0));
        label_2->setText(QApplication::translate("donationDialog", "for the upcoming commercial version called", 0));
        label->setText(QApplication::translate("donationDialog", "CakeHeap Budget On Steroid. ", 0));
        cancelButton->setText(QApplication::translate("donationDialog", "Cancel", 0));
        donateButton->setText(QApplication::translate("donationDialog", "Donate", 0));
    } // retranslateUi

};

namespace Ui {
    class donationDialog: public Ui_donationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DONATE_DIALOG_H
