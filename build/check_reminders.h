/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Check Reminders class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef CHECK_REMINDERS_H_INCLUDED
#define CHECK_REMINDERS_H_INCLUDED

#include <QtCore/QThread>
#include <QtCore/QDate>
#include <QMessageBox>
#include <QIcon>
//#include <iostream>
#include <string>
//#include "budget_page.h"
#include <QtCore/QEventLoop>
//#include "main_budget.h"
#include "fiscal_record.h"

using namespace std;

class CheckReminders : public QThread
{
    Q_OBJECT
    public:
        CheckReminders(ReminderList *rList);
        ~CheckReminders() {}
        void checkAndDealWithReminders(ReminderList &rList);
        void run();
        void pause();
        void updateReminders(ReminderList rList);
        char * convertStringToChar(string s);
        static string subject;
        static string message;
    signals:
        void notifyMessageBox();
    private:
        ReminderList *itsReminderList;
        char convertedChar[1000];
        volatile bool paused;
};

#endif // CHECK_REMINDERS_H_INCLUDED
