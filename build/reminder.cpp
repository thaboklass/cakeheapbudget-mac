#include "reminder.h"

/**
 The constructor for the Reminder class.
 
 @param dueDate        the reminder's date.
 @param subject        the subject matter.
 @param message        the message.
 @param pLevel         the priority level of the reminder.
 */
Reminder::Reminder(Date dueDate, string subject, string message, PriorityLevel pLevel):
itsDueDate(dueDate),
itsSubject(subject),
itsMessage(message),
itsIDCode(0),
itsIsReminderDealtWith(false),
Priority(pLevel)
{
}
/*
Reminder::~Reminder()
{
    delete itsDueDate;
    itsDueDate = 0;
    delete itsMessage;
    itsMessage = 0;
    delete itsSubject;
    itsSubject = 0;
}
*/


/**
 The Reminder date getter.
 
 @param              nothing.
 @return itsDueDate  the date of the reminder.
 */
Date Reminder::getDueDate() const
{
    return itsDueDate;
}


/**
 The Reminder date setter.
 
 @param dueDate  the penalty amount.
 @return         nothing.
 */
void Reminder::setDueDate(Date dueDate)
{/*
    if (itsDueDate)
    {
        //delete itsDueDate;
        itsDueDate = dueDate;
    }
    else*/
        itsDueDate = dueDate;
}


/**
 The Reminder message getter.
 
 @param              nothing.
 @return itsMessage  the reminder's message.
 */
string Reminder::getMessage() const
{
    return itsMessage;
}


/**
 The Reminder message setter.
 
 @param message  the message.
 @return         nothing.
 */
void Reminder::setMessage(string message)
{
    itsMessage = message;
}


/**
 The Reminder subject getter.
 
 @param              nothing.
 @return itsSubject  the reminder's subject.
 */
string Reminder::getSubject() const
{
    return itsSubject;
}


/**
 The Reminder subject setter.
 
 @param subject  the subject.
 @return         nothing.
 */
void Reminder::setSubject(string subject)
{
    itsSubject = subject;
}


/**
 The Reminder 'ID code' getter.
 
 @param             nothing.
 @return itsIDCode  the reminder's ID code.
 */
int Reminder::getIDCode() const
{
    return itsIDCode;
}


/**
 The Reminder 'ID Code' setter.
 
 @param IDCode   the ID code.
 @return         nothing.
 */
void Reminder::setIDCode(int IDCode)
{
    itsIDCode = IDCode;
}


/**
 The Reminder 'ID code' getter.
 
 @param             nothing.
 @return itsIDCode  the reminder's ID code.
 */
bool Reminder::getIsReminderDealtWith() const
{
    return itsIsReminderDealtWith;
}


/**
 The Reminder 'ID Code' setter.
 
 @param IDCode   the ID code.
 @return         nothing.
 */
void Reminder::setIsReminderDealtWith(bool dealtWith)
{
    itsIsReminderDealtWith = dealtWith;
}
