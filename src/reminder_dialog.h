#ifndef REMINDER_DIALOG_H_INCLUDED
#define REMINDER_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_reminder_dialog.h"
class ReminderDialog : public QDialog, public Ui::reminderDialog
{
    Q_OBJECT
public:
    ReminderDialog(QWidget *parent = 0);
};

#endif // REMINDER_DIALOG_H_INCLUDED
