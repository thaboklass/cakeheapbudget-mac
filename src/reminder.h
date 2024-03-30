/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Reminder class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef REMINDER_H_INCLUDED
#define REMINDER_H_INCLUDED
#include "date.h"
#include "priority.h"
#include <string>
using namespace std;
class Reminder : public Priority
{
    public:
        Reminder(Date dueDate, string subject, string message, PriorityLevel pLevel);
        ~Reminder() {}
        Date getDueDate() const;
        void setDueDate(Date dueDate);
        string getMessage() const;
        void setMessage(string message);
        string getSubject() const;
        void setSubject(string subject);
        int getIDCode() const;
        void setIDCode(int IDCode);
        bool getIsReminderDealtWith() const;
        void setIsReminderDealtWith(bool dealtWith);
    private:
        Date itsDueDate;
        string itsMessage;
        string itsSubject;
        int itsIDCode;
        bool itsIsReminderDealtWith;
};
#endif // REMINDER_H_INCLUDED
