/********************************************************************************
** Form generated from reading UI file 'reminder_dialog.ui'
**
** Created: Sat 12. Jun 15:46:36 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDER_DIALOG_H
#define UI_REMINDER_DIALOG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDateTimeEdit>
#include <QDialog>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>

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
            reminderDialog->setObjectName(QString::fromUtf8("reminderDialog"));
        reminderDialog->resize(306, 274);
        reminderDialog->setMaximumSize(306, 274);
        reminderDialog->setMinimumSize(306, 274);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        reminderDialog->setWindowIcon(icon);
        
        reminderBox = new QGroupBox(reminderDialog);
        reminderBox->setObjectName(QString::fromUtf8("reminderBox"));
        reminderBox->setGeometry(QRect(10, 10, 300, 251));
        reminderBox->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ececec, stop: 1 #ececec); border: 2px solid #ececec; border-radius: 5px; margin-top: 1ex; /* leave space at the top for the title */ } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFOECE, stop: 1 #FFFFFF); }");
        
        subjectLabel = new QLabel(reminderBox);
        subjectLabel->setObjectName(QString::fromUtf8("subjectLabel"));
        subjectLabel->setGeometry(QRect(20, 30, 52, 13));
        subjectLineEdit = new QLineEdit(reminderBox);
        subjectLineEdit->setObjectName(QString::fromUtf8("subjectLineEdit"));
        subjectLineEdit->setGeometry(QRect(110, 28, 151, 20));
        dateTimeLabel = new QLabel(reminderBox);
        dateTimeLabel->setObjectName(QString::fromUtf8("dateTimeLabel"));
        dateTimeLabel->setGeometry(QRect(20, 70, 80, 20));
        dateTimeEdit = new QDateTimeEdit(reminderBox);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(110, 70, 151, 22));
        messageLabel = new QLabel(reminderBox);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setGeometry(QRect(20, 120, 61, 16));
        messageTextEdit = new QPlainTextEdit(reminderBox);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(20, 150, 241, 64));
        okButton = new QPushButton(reminderBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(191, 224, 75, 32));
        cancelButton = new QPushButton(reminderBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(119, 224, 75, 32));

        retranslateUi(reminderDialog);

        QMetaObject::connectSlotsByName(reminderDialog);
    } // setupUi

    void retranslateUi(QDialog *reminderDialog)
    {
        reminderDialog->setWindowTitle(QApplication::translate("reminderDialog", "Reminder Info", 0));
        reminderBox->setTitle(QApplication::translate("reminderDialog", "", 0));
        subjectLabel->setText(QApplication::translate("reminderDialog", "Subject:", 0));
        dateTimeLabel->setText(QApplication::translate("reminderDialog", "Date & Time:", 0));
        messageLabel->setText(QApplication::translate("reminderDialog", "Message:", 0));
        okButton->setText(QApplication::translate("reminderDialog", "Done", 0));
        cancelButton->setText(QApplication::translate("reminderDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class reminderDialog: public Ui_reminderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDER_DIALOG_H
