#include "commands.h"

/**
 The constructor for the AddIncomeCommand class.
 
 @param *mb            a pointer to the MainBudget parent object.
 @param name           the name of the income.
 @param amount         the income amount(double).
 @param lAmount        the income amount(long).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param date           the date the payment is received.
 @param nature         the nature of the income.
 @param tex            the tax rate.
 @param additionalInfo the income metadata.
 @param tabIndex       the index of the tab where the income belongs.
 @param IDCode         the ID code of the income.
 @param *parent        the QUndoCommand parent class.
 */
AddIncomeCommand::AddIncomeCommand(MainBudget *mb, string name, double amount, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, int IDCode,
            QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    if (lAmount > 999999)
        itsIncome = new Income(name, lAmount, hasAPR, APR, receivedDate,
            nature, tax, additionalInfo, tabIndex);
    else
        itsIncome = new Income(name, amount, hasAPR, APR, receivedDate,
            nature, tax, additionalInfo, tabIndex);

    itsIncome->setIDCode(IDCode);
}


/**
 The AddIncomeCommand undo.
 
 @param       none.
 @return      nothing.
 */
void AddIncomeCommand::undo()
{
    itsMb->undoAddIncome();
}


/**
 The AddIncomeCommand redo.
 
 @param       none.
 @return      nothing.
 */
void AddIncomeCommand::redo()
{
    itsMb->reAddIncome(itsIncome);
}


/**
 The constructor for the DeleteIncomeCommand class.
 
 @param *mb            a pointer to the MainBudget parent object
 @param name           the name of the income.
 @param amount         the income amount(double).
 @param lAmount        the income amount(long).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param date           the date the payment is received.
 @param nature         the nature of the income.
 @param tex            the tax rate.
 @param additionalInfo the income metadata.
 @param tabIndex       the index of the tab where the income belongs.
 @param IDCode         the ID code of the income.
 @param *parent        the QUndoCommand parent class.
 */
DeleteIncomeCommand::DeleteIncomeCommand(MainBudget *mb, string name, double amount, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, int IDCode,
            QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    if (lAmount > 999999)
        itsIncome = new Income(name, lAmount, hasAPR, APR, receivedDate,
            nature, tax, additionalInfo, tabIndex);
    else
        itsIncome = new Income(name, amount, hasAPR, APR, receivedDate,
            nature, tax, additionalInfo, tabIndex);

    itsIncome->setIDCode(IDCode);
}


/**
 The DeleteIncomeCommand undo.
 
 @param       none.
 @return      nothing.
 */
void DeleteIncomeCommand::undo()
{
    itsMb->undoDeleteIncome(itsIncome);
}


/**
 The DeleteIncomeCommand redo.
 
 @param       none.
 @return      nothing.
 */
void DeleteIncomeCommand::redo()
{
    itsMb->reDeleteIncome(itsIncome);
}


/**
 The constructor for the AddExpenseCommand class.
 
 @param *mb            a pointer to the MainBudget parent object
 @param name           the name of the expense.
 @param amount         the expense amount(double).
 @param lAmount        the expense amount(long).
 @param pLevel         the priority level of the expense.
 @param penalty        the penalty (if any) of the expense.
 @param dueDate        the date the payment is due.
 @param additionalInfo the expense metadata.
 @param tabIndex       the index of the tab where the expense belongs.
 @param IDCode         the ID code of the expense.
 @param *parent        the QUndoCommand parent class.
 */
AddExpenseCommand::AddExpenseCommand(MainBudget *mb, string name, double amount, long lAmount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, int IDCode,
            QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    if (lAmount > 999999)
        itsExpense = new Expense(name, lAmount, pLevel, penalty,
            dueDate, additionalInfo, tabIndex);
    else
        itsExpense = new Expense(name, amount, pLevel, penalty,
            dueDate, additionalInfo, tabIndex);

    itsExpense->setIDCode(IDCode);
}


/**
 The AddExpenseCommand undo.
 
 @param       none.
 @return      nothing.
 */
void AddExpenseCommand::undo()
{
    itsMb->undoAddExpense();
}


/**
 The AddExpenseCommand redo.
 
 @param       none.
 @return      nothing.
 */
void AddExpenseCommand::redo()
{
    itsMb->reAddExpense(itsExpense);
}


/**
 The constructor for the DeleteExpenseCommand class.
 
 @param *mb            a pointer to the MainBudget parent object
 @param name           the name of the expense.
 @param amount         the expense amount(double).
 @param lAmount        the expense amount(long).
 @param pLevel         the priority level of the expense.
 @param penalty        the penalty (if any) of the expense.
 @param dueDate        the date the payment is due.
 @param additionalInfo the expense metadata.
 @param tabIndex       the index of the tab where the expense belongs.
 @param IDCode         the ID code of the expense.
 @param *parent        the QUndoCommand parent class.
 */
DeleteExpenseCommand::DeleteExpenseCommand(MainBudget *mb, string name, double amount, long lAmount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, int IDCode,
            QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    if (lAmount > 999999)
        itsExpense = new Expense(name, lAmount, pLevel, penalty,
            dueDate, additionalInfo, tabIndex);
    else
        itsExpense = new Expense(name, amount, pLevel, penalty,
            dueDate, additionalInfo, tabIndex);

    itsExpense->setIDCode(IDCode);
}


/**
 The DeleteExpenseCommand undo.
 
 @param       none.
 @return      nothing.
 */
void DeleteExpenseCommand::undo()
{
    itsMb->undoDeleteExpense(itsExpense);
}


/**
 The DeleteExpenseCommand redo.
 
 @param       none.
 @return      nothing.
 */
void DeleteExpenseCommand::redo()
{
    itsMb->reDeleteExpense(itsExpense);
}


/**
 The constructor for the AddDebtCommand class.
 
 @param *mb            a pointer to the MainBudget parent object
 @param name           the name of the debt.
 @param amount         the debt amount(double).
 @param lAmount        the debt amount(long).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param pLevel         the priority level of the debt.
 @param date           the date the payment is due.
 @param additionalInfo the debt metadata.
 @param numberOfMonths the number of months the payment is spread across.
 @param tabIndex       the index of the tab where the debt belongs.
 @param IDCode         the ID Code of the income.
 @param *parent        the QUndoCommand parent class.
 */
AddDebtCommand::AddDebtCommand(MainBudget *mb, string name, double amount, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel, Date dueDate,
    string additionalInfo, int numberOfMonths, int tabIndex, int IDCode,
            QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    if (lAmount > 999999)
        itsDebt = new Debt(name, lAmount, hasAPR, APR, pLevel, dueDate,
            additionalInfo, numberOfMonths, tabIndex);
    else
        itsDebt = new Debt(name, amount, hasAPR, APR, pLevel, dueDate,
            additionalInfo, numberOfMonths, tabIndex);

    itsDebt->setIDCode(IDCode);
}

/**
 The AddDebtCommand undo.
 
 @param       none.
 @return      nothing.
 */
void AddDebtCommand::undo()
{
    itsMb->undoAddDebt();
}


/**
 The AddDebtCommand redo.
 
 @param       none.
 @return      nothing.
 */
void AddDebtCommand::redo()
{
    itsMb->reAddDebt(itsDebt);
}


/**
 The constructor for the DeleteDebtCommand class.
 
 @param *mb            a pointer to the MainBudget parent object
 @param name           the name of the debt.
 @param amount         the debt amount(double).
 @param lAmount        the debt amount(long).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param pLevel         the priority level of the debt.
 @param date           the date the payment is due.
 @param additionalInfo the debt metadata.
 @param numberOfMonths the number of months the payment is spread across.
 @param tabIndex       the index of the tab where the debt belongs.
 @param IDCode         the ID Code of the income.
 @param *parent        the QUndoCommand parent class.
 */
DeleteDebtCommand::DeleteDebtCommand(MainBudget *mb, string name, double amount, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel, Date dueDate,
    string additionalInfo, int numberOfMonths, int tabIndex, int IDCode,
            QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    if (lAmount > 999999)
        itsDebt = new Debt(name, lAmount, hasAPR, APR, pLevel, dueDate,
            additionalInfo, numberOfMonths, tabIndex);
    else
        itsDebt = new Debt(name, amount, hasAPR, APR, pLevel, dueDate,
            additionalInfo, numberOfMonths, tabIndex);

    itsDebt->setIDCode(IDCode);
}


/**
 The DeleteDebtCommand undo.
 
 @param       none.
 @return      nothing.
 */
void DeleteDebtCommand::undo()
{
    itsMb->undoDeleteDebt(itsDebt);
}


/**
 The DeleteDebtCommand redo.
 
 @param       none.
 @return      nothing.
 */
void DeleteDebtCommand::redo()
{
    itsMb->reDeleteDebt(itsDebt);
}


/**
 The constructor for the AddSavingsCommand class.
 
 @param *mb            a pointer to the MainBudget parent object
 @param name           the name of the savings.
 @param amount         the savings amount(double).
 @param lAmount        the savings amount(long).
 @param APR            the APR.
 @param nature         the nature of the savings.
 @param date           the date.
 @param description    the description.
 @param IDCode         the ID Code of the savings.
 @param *parent        the QUndoCommand parent class.
 */
AddSavingsCommand::AddSavingsCommand(MainBudget *mb, string name, double amount, long lAmount, float APR, SavingsNature nature, Date date, string description, int IDCode, QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    if (lAmount > 999999)
        itsSavings = new Savings(name, lAmount, APR, nature, date, description);
    else
        itsSavings = new Savings(name, amount, APR, nature, date, description);

    itsSavings->setIDCode(IDCode);
}


/**
 The AddSavingsCommand undo.
 
 @param       none.
 @return      nothing.
 */
void AddSavingsCommand::undo()
{
    itsMb->undoAddSavings();
}


/**
 The AddSavingsCommand redo.
 
 @param       none.
 @return      nothing.
 */
void AddSavingsCommand::redo()
{
    itsMb->reAddSavings(itsSavings);
}


/**
 The constructor for the DeleteSavingsCommand class.
 
 @param *mb            a pointer to the MainBudget parent object
 @param name           the name of the savings.
 @param amount         the savings amount(double).
 @param lAmount        the savings amount(long).
 @param APR            the APR.
 @param nature         the nature of the savings.
 @param date           the date.
 @param description    the description.
 @param IDCode         the ID Code of the savings.
 @param *parent        the QUndoCommand parent class.
 */
DeleteSavingsCommand::DeleteSavingsCommand(MainBudget *mb, string name, double amount, long lAmount, float APR, SavingsNature nature, Date date, string description, int IDCode, QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    if (lAmount > 999999)
        itsSavings = new Savings(name, lAmount, APR, nature, date, description);
    else
        itsSavings = new Savings(name, amount, APR, nature, date, description);

    itsSavings->setIDCode(IDCode);
}


/**
 The DeleteSavingsCommand undo.
 
 @param       none.
 @return      nothing.
 */
void DeleteSavingsCommand::undo()
{
    itsMb->undoDeleteSavings(itsSavings);
}


/**
 The DeleteSavingsCommand redo.
 
 @param       none.
 @return      nothing.
 */
void DeleteSavingsCommand::redo()
{
    itsMb->reDeleteSavings(itsSavings);
}


/**
 The constructor for the AddItemCommand class.
 
 @param *mb            a pointer to the MainBudget parent object
 @param name           the name of the savings.
 @param price          the item's price.
 @param number         the number of items.
 @param itemID         the user generated item ID.
 @param IDCode         the ID Code of the savings.
 @param *parent        the QUndoCommand parent class.
 */
AddItemCommand::AddItemCommand(MainBudget *mb, string name, double price, int number, string itemID, int IDCode, QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    itsItem = new Items(name, price, number, itemID);
    itsItem->setIDCode(IDCode);
}


/**
 The AddItemCommand undo.
 
 @param       none.
 @return      nothing.
 */
void AddItemCommand::undo()
{
    itsMb->undoAddItem();
}


/**
 The AddItemCommand redo.
 
 @param       none.
 @return      nothing.
 */
void AddItemCommand::redo()
{
    itsMb->reAddItem(itsItem);
}


/**
 The constructor for the DeleteItemCommand class.
 
 @param *mb            a pointer to the MainBudget parent object.
 @param name           the name of the savings.
 @param price          the item's price.
 @param number         the number of items.
 @param itemID         the user generated item ID.
 @param IDCode         the ID Code of the savings.
 @param *parent        the QUndoCommand parent class.
 */
DeleteItemCommand::DeleteItemCommand(MainBudget *mb, string name, double price, int number, string itemID, int IDCode, QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    itsItem = new Items(name, price, number, itemID);
    itsItem->setIDCode(IDCode);
}


/**
 The DeleteItemCommand undo.
 
 @param       none.
 @return      nothing.
 */
void DeleteItemCommand::undo()
{
    itsMb->undoDeleteItem(itsItem);
}


/**
 The DeleteItemCommand redo.
 
 @param       none.
 @return      nothing.
 */
void DeleteItemCommand::redo()
{
    itsMb->reDeleteItem(itsItem);
}


/**
 The constructor for the AddReminderCommand class.
 
 @param *mb            a pointer to the MainBudget parent object.
 @param dueDate        the reminder's date.
 @param subject        the subject matter.
 @param message        the message.
 @param pLevel         the priority level of the reminder.
 @param IDCode         the ID code of the reminder.
 @param *parent        the QUndoCommand parent class.
 */
AddReminderCommand::AddReminderCommand(MainBudget *mb, Date dueDate, string subject, string message, PriorityLevel pLevel, int IDCode, QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    itsReminder = new Reminder(dueDate, subject, message, pLevel);
    itsReminder->setIDCode(IDCode);
}


/**
 The AddReminderCommand undo.
 
 @param       none.
 @return      nothing.
 */
void AddReminderCommand::undo()
{
    itsMb->undoAddReminder();
}


/**
 The AddReminderCommand redo.
 
 @param       none.
 @return      nothing.
 */
void AddReminderCommand::redo()
{
    itsMb->reAddReminder(itsReminder);
}


/**
 The constructor for the DeleteReminderCommand class.
 
 @param *mb            a pointer to the MainBudget parent object.
 @param dueDate        the reminder's date.
 @param subject        the subject matter.
 @param message        the message.
 @param pLevel         the priority level of the reminder.
 @param IDCode         the ID code of the reminder.
 @param *parent        the QUndoCommand parent class.
 */
DeleteReminderCommand::DeleteReminderCommand(MainBudget *mb, Date dueDate, string subject, string message, PriorityLevel pLevel, int IDCode, QUndoCommand *parent)
    : QUndoCommand(parent)
{
    itsMb = mb;
    itsReminder = new Reminder(dueDate, subject, message, pLevel);
    itsReminder->setIDCode(IDCode);
}


/**
 The DeleteReminderCommand undo.
 
 @param       none.
 @return      nothing.
 */
void DeleteReminderCommand::undo()
{
    itsMb->undoDeleteReminder(itsReminder);
}


/**
 The DeleteReminderCommand redo.
 
 @param       none.
 @return      nothing.
 */
void DeleteReminderCommand::redo()
{
    itsMb->reDeleteReminder(itsReminder);
}

