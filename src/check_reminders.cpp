#include "check_reminders.h"

/**
 The constructor for the Check Reminders class.
 
 @param rList           the reminders list.
 */
CheckReminders::CheckReminders(ReminderList *rList):
itsReminderList(rList)
{
    paused = false;
    //for (int i = 0; i < rList.size(); i++)
    //    itsReminderList.push_back(rList.at(i));
}
string CheckReminders::subject = "";
string CheckReminders::message = "";

/*
void CheckReminders::updateReminders(ReminderList &rList)
{
    for (int i = 0; i < rList.size(); i++)
        itsReminderList.push_back(rList.at(i));
}
*/

/**
 The CheckReminders deal reminders method.
 
 @param  rList  the reminders list.
 @return        nothing.
 */
void CheckReminders::checkAndDealWithReminders(ReminderList &rList)
{
    QDate qCurrentDate = QDate::currentDate();
    QTime qCurrentTime = QTime::currentTime();

    Date currentDate(qCurrentDate.year(), qCurrentDate.month(), qCurrentDate.day(),
        qCurrentTime.hour(), qCurrentTime.minute(), qCurrentTime.second());


    for (int i = 0; i < rList.size(); i++)
    {
        //cout << qCurrentTime.second() << " " << rList.at(i).getDueDate().getSecond() << endl;
        if ((rList.at(i).getDueDate().getYear() == qCurrentDate.year())
            && (rList.at(i).getDueDate().getMonth() == qCurrentDate.month())
            && (rList.at(i).getDueDate().getDay() == qCurrentDate.day())
            && (rList.at(i).getDueDate().getHour() == qCurrentTime.hour())
            && (rList.at(i).getDueDate().getMinute() == qCurrentTime.minute())
            //&& (rList.at(i).getDueDate().getSecond() == qCurrentTime.second()))
            && !(rList.at(i).getIsReminderDealtWith())
            )
        {
            rList.at(i).setIsReminderDealtWith(true);

            CheckReminders::subject = rList.at(i).getSubject();
            CheckReminders::message = rList.at(i).getMessage();

            emit notifyMessageBox();
        }
    }
}


/**
 The CheckReminders thread.
 
 @param name  the name of the debt.
 @return      nothing.
 */
void CheckReminders::run()
{
    while (!paused)
    {
        checkAndDealWithReminders(*itsReminderList);
        sleep(1);
    }
}

void CheckReminders::pause()
{
    paused = true;
}


/**
 The CheckReminders method that converts a string to chars.
 
 @param string           the input string.
 @return convertedChar   the converted characters.
 */
char * CheckReminders::convertStringToChar(string s)
{
    strcpy(convertedChar, s.c_str());
    return convertedChar;
}
