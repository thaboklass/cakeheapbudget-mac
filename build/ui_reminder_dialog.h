/********************************************************************************
** Form generated from reading UI file 'reminder_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDER_DIALOG_H
#define UI_REMINDER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_reminderDialog
{
public:
    QGroupBox *reminderBox;
    QLabel *subjectLabel;
    QLineEdit *subjectLineEdit;
    QLabel *dateTimeLabel;
    QDateTimeEdit *dateTimeEdit;
    QLabel *messageLabel;
    QPlainTextEdit *messageTextEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *reminderDialog)
    {
        if (reminderDialog->objectName().isEmpty())
            reminderDialog->setObjectName(QStringLiteral("reminderDialog"));
        reminderDialog->resize(253, 274);
        QIcon icon;
        icon.addFile(QStringLiteral("cake_heap_icon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        reminderDialog->setWindowIcon(icon);
        reminderBox = new QGroupBox(reminderDialog);
        reminderBox->setObjectName(QStringLiteral("reminderBox"));
        reminderBox->setGeometry(QRect(10, 10, 231, 251));
        subjectLabel = new QLabel(reminderBox);
        subjectLabel->setObjectName(QStringLiteral("subjectLabel"));
        subjectLabel->setGeometry(QRect(20, 30, 46, 13));
        subjectLineEdit = new QLineEdit(reminderBox);
        subjectLineEdit->setObjectName(QStringLiteral("subjectLineEdit"));
        subjectLineEdit->setGeometry(QRect(70, 28, 141, 20));
        dateTimeLabel = new QLabel(reminderBox);
        dateTimeLabel->setObjectName(QStringLiteral("dateTimeLabel"));
        dateTimeLabel->setGeometry(QRect(5, 70, 61, 20));
        dateTimeEdit = new QDateTimeEdit(reminderBox);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(70, 70, 151, 22));
        messageLabel = new QLabel(reminderBox);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        messageLabel->setGeometry(QRect(10, 120, 61, 16));
        messageTextEdit = new QPlainTextEdit(reminderBox);
        messageTextEdit->setObjectName(QStringLiteral("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(7, 150, 218, 64));
        okButton = new QPushButton(reminderBox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(10, 220, 75, 23));
        cancelButton = new QPushButton(reminderBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(140, 220, 75, 23));

        retranslateUi(reminderDialog);

        QMetaObject::connectSlotsByName(reminderDialog);
    } // setupUi

    void retranslateUi(QDialog *reminderDialog)
    {
        reminderDialog->setWindowTitle(QApplication::translate("reminderDialog", "Reminder Info", 0));
        reminderBox->setTitle(QApplication::translate("reminderDialog", "Reminder", 0));
        subjectLabel->setText(QApplication::translate("reminderDialog", "Subject:", 0));
        dateTimeLabel->setText(QApplication::translate("reminderDialog", "Date & Time:", 0));
        messageLabel->setText(QApplication::translate("reminderDialog", "Message:", 0));
        okButton->setText(QApplication::translate("reminderDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("reminderDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class reminderDialog: public Ui_reminderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDER_DIALOG_H
