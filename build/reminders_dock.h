#ifndef REMINDERS_DOCK_H_INCLUDED
#define REMINDERS_DOCK_H_INCLUDED
#include <QDockWidget>
#include "ui_reminder_dock.h"
class RemindersDock : public QDockWidget, public Ui::RemindersDock
{
    Q_OBJECT
public:
    RemindersDock(QWidget *parent = 0);
    void resizeEvent(QResizeEvent * event);
private:
    int originalWidth;
    int originalHeight;

    int remindersDateColumnWidth;
    int remindersSubjectColumnWidth;
};

#endif // REMINDERS_DOCK_H_INCLUDED
