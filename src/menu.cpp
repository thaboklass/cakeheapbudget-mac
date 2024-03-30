#include "menu.h"

// A vector that holds incomes
IncomeList income;

// A vector that holds debts
DebtList debt;

// A vector that holds expense
ExpenseList expenses;

// A vector that holds savings
SavingsList savings;

// A vector that holds items
ItemList items;

// A vector that holds reminders
ReminderList reminders;


/**
 Create a new fiscal record.
 
 @param  none.
 @return newRecord  a new fiscal record.
 */
FiscalRecord createFiscalRecord()
{
    FiscalRecord newRecord("", "", income,
                    debt, expenses, savings,
                    items, reminders);
    return newRecord;
}


/**
 Open a fiscal record from file.
 
 @param  fileName    the file name of the saved record.
 @return newRecord   a saved fiscal record.
 */
FiscalRecord openFiscalRecord(char * fileName)
{
    FiscalRecord openedRecord(fileName, "", income,
                    debt, expenses, savings,
                    items, reminders);
    ifstream inputRecord(fileName, ios::binary);
    inputRecord.read((char *)&openedRecord, sizeof(openedRecord));
    return openedRecord;
    // then set the values in the record onto the GUI
}


/**
 Save a fiscal record to file.
 
 @param  savedFiscalRecord    the file name of the saved record.
 @return                      nothing.
 */
void saveFiscalRecord(FiscalRecord savedFiscalRecord)
{
    // get all the values from the vectors in the fiscal record
    string sFileName = savedFiscalRecord.getFileName();
    char fileName[sFileName.size() + 1];
    strcpy(fileName, sFileName.c_str());
    ofstream outputRecord(fileName, ios::binary);
    outputRecord.write((char *)&savedFiscalRecord, sizeof(savedFiscalRecord));
}
