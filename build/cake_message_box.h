#ifndef CAKE_MESSAGE_BOX_H_INCLUDED
#define CAKE_MESSAGE_BOX_H_INCLUDED

#include <QMessageBox>
#include "check_reminders.h"

class CakeMessageBox : public QMessageBox
{
    Q_OBJECT
    public:
        CakeMessageBox();
    //private:
        //CheckReminders *cr;
        //ReminderList rList;
};


#endif // CAKE_MESSAGE_BOX_H_INCLUDED
