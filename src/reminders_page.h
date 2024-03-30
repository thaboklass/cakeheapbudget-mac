/**
 CakeHeap Budget for Mac
 reminders_page.h
 Purpose: The Reminders Page model: deals
 with all the commands on the reminders page
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef REMINDERS_PAGE_H_INCLUDED
#define REMINDERS_PAGE_H_INCLUDED

#include "menu.h"

void addReminder(Date * dueDate, string subject, string message, PriorityLevel pLevel, ReminderList &rList);

void editReminder(Date * dueDate, string subject, string message, PriorityLevel pLevel,
    ReminderList &rList, int IDCode);

void deleteReminder(ReminderList &rList, int IDCode);

#endif // REMINDERS_PAGE_H_INCLUDED
