#include "budget_page.h";

/**
 The 'add reminder' class method - adds a new reminder
 to reminders.
 
 @param dueDate        the date of the reminder
 @param subject        the subject of the reminder.
 @param message        the reminder's message.
 @param pLevel         the priority level.
 @param rList          the reminder list from the reminders page.
 @return               nothing.
 */
void addReminder(Date dueDate, string subject, string message, PriorityLevel pLevel, ReminderList &rList)
{
    Reminder addedReminder(dueDate, subject, message, pLevel);
    // add the income to the vector list
    addedReminder.setIDCode(rList.size() + 1);
    rList.push_back(addedReminder);
}


/**
 The 'edit item' class method - edits an existing item.
 
 @param dueDate        the date of the reminder
 @param subject        the subject of the reminder.
 @param message        the reminder's message.
 @param pLevel         the priority level.
 @param rList          the reminder list from the reminders page.
 @param IDCode         the ID code.
 @return               nothing.
 */
void editReminder(Date dueDate, string subject, string message, PriorityLevel pLevel,
    ReminderList &rList, int IDCode) {
    ReminderList::iterator ci = rList.begin();
    bool found = false;
    Reminder editedReminder(Date(0, 0, 0, 0, 0, 0) , "" , "", pLevel);
    for (int i = 0; i < rList.size(); i++)
    {
        editedReminder = rList.at(i);
        if (IDCode == editedReminder.getIDCode())
        {
            found = true;
            editedReminder.setDueDate(dueDate);
            editedReminder.setSubject(subject);
            editedReminder.setMessage(message);
            editedReminder.setPriority(pLevel);
            rList.erase(ci);
            rList.insert(ci, editedReminder);
            break;
        }
        ci++;
    }
}


/**
 The 'delete item' class method - deletes an existing item.
 
 @param rList          the reminder list from the reminders page.
 @param IDCode         the ID code.
 @return               nothing.
 */
void deleteReminder(ReminderList &rList, int IDCode) {
    int i = 0;
    for (ReminderList::iterator ci = rList.begin();
            ci != rList.end(); ci++)
    {
        Reminder deletedReminder = rList.at(i);
        //cout << inquiredItem.getIDCode() << endl;
        if (IDCode == deletedReminder.getIDCode())
        {
            //cout << deletedSavings.getIDCode() << endl;
            rList.erase(ci);
            break;
        }
        //cout << i << endl;
        i++;
    }

    // re-label the new income list after the deletion
    ReminderList::iterator ci = rList.begin();
    for (int i = 0; i < rList.size(); i++)
    {
        Reminder updatedReminder = rList.at(i);
        updatedReminder.setIDCode(i + 1);
        rList.erase(ci);
        rList.insert(ci, updatedReminder);
        ci++;
    }
}

void addReminderAgain(Date dueDate, string subject, string message, PriorityLevel pLevel, int IDCode, ReminderList &rList)
{
    Reminder addedReminder(dueDate, subject, message, pLevel);
    // add the income to the vector list
    // add the income to the vector list
    ReminderList::iterator ci = rList.begin();
    addedReminder.setIDCode(IDCode);
    rList.insert((ci + IDCode) - 1, addedReminder);

    Reminder editedReminder(Date(0, 0, 0, 0, 0, 0) , "" , "", pLevel);

    ci = ci + IDCode;

    for (int i = IDCode; i < rList.size(); i++)
    {
        editedReminder = rList.at(i);
        int currentIDCode = editedReminder.getIDCode();
        editedReminder.setIDCode(currentIDCode + 1);
        rList.erase(ci);
        rList.insert(ci, editedReminder);
        ci++;
    }
}
