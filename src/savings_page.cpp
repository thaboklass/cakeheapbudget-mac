//#include "savings_page.h";
#include "budget_page.h"

/**
 The 'add savings' class method - adds a new saving
 to the savings.
 
 @param name           the name of the savings.
 @param amount         the savings amount(double).
 @param APR            the APR.
 @param nature         the nature of the savings.
 @param date           the date.
 @param description    the description.
 @param sList          the savings list on the savings page.
 @return               nothing
 */
void addSavings(string name, double amount, float APR, SavingsNature nature, Date date, string description, SavingsList &sList)
{
    Savings addedSavings(name, amount, APR, nature, date, description);
    // add the savings to the vector list
    addedSavings.setIDCode(sList.size() + 1);
    sList.push_back(addedSavings);
}


/**
 The 'edit savings' class method - edits an existing savings.
 
 @param name           the name of the savings.
 @param amount         the savings amount(double).
 @param APR            the APR.
 @param nature         the nature of the savings.
 @param date           the date.
 @param description    the description.
 @param sList          the savings list on the savings page.
 @param IDCode         the ID code of the existing income
 @return               nothing
 */
void editSavings(string name, double amount, float APR, SavingsNature nature, Date date,
    string description, SavingsList &sList, int IDCode) {
    SavingsList::iterator ci = sList.begin();
    bool found = false;
    double emptyD = 0;
    Savings editedSavings("", emptyD, 0, BANK, Date(0, 0, 0, 0, 0, 0), "");
    for (int i = 0; i < sList.size(); i++)
    {
        editedSavings = sList.at(i);
        if (IDCode == editedSavings.getIDCode())
        {
            found = true;
            editedSavings.setName(name);
            editedSavings.setAmount(amount);
            editedSavings.setAPR(APR);
            editedSavings.setNature(nature);
            editedSavings.setDate(date);
            editedSavings.setDescription(description);
            sList.erase(ci);
            sList.insert(ci, editedSavings);
            break;
        }
        ci++;
    }
}

void addLSavings(string name, long lAmount, float APR, SavingsNature nature, Date date, string description, SavingsList &sList)
{
    Savings addedSavings(name, lAmount, APR, nature, date, description);
    // add the income to the vector list
    addedSavings.setIDCode(sList.size() + 1);
    sList.push_back(addedSavings);
}

void editLSavings(string name, long lAmount, float APR, SavingsNature nature, Date date,
    string description, SavingsList &sList, int IDCode) {
    SavingsList::iterator ci = sList.begin();
    bool found = false;
    long emptyL = 0;
    Savings editedSavings("", emptyL, 0, BANK, Date(0, 0, 0, 0, 0, 0), "");
    for (int i = 0; i < sList.size(); i++)
    {
        editedSavings = sList.at(i);
        if (IDCode == editedSavings.getIDCode())
        {
            found = true;
            editedSavings.setName(name);
            editedSavings.setLAmount(lAmount);
            editedSavings.setAPR(APR);
            editedSavings.setNature(nature);
            editedSavings.setDate(date);
            editedSavings.setDescription(description);
            sList.erase(ci);
            sList.insert(ci, editedSavings);
            break;
        }
        ci++;
    }
}


/**
 The 'delete savings' class method - deletes an existing savings.
 
 @param sList          the savings list on the savings page.
 @param IDCode         the ID code of the existing savings
 @return               nothing
 */
void deleteSavings(SavingsList &sList, int IDCode) {
    int i = 0;
    for (SavingsList::iterator ci = sList.begin();
            ci != sList.end(); ci++)
    {
        Savings deletedSavings = sList.at(i);
        //cout << inquiredItem.getIDCode() << endl;
        if (IDCode == deletedSavings.getIDCode())
        {
            //cout << deletedSavings.getIDCode() << endl;
            sList.erase(ci);
            break;
        }
        //cout << i << endl;
        i++;
    }

    // re-label the new income list after the deletion
    SavingsList::iterator ci = sList.begin();
    for (int i = 0; i < sList.size(); i++)
    {
        Savings updatedSavings = sList.at(i);
        updatedSavings.setIDCode(i + 1);
        sList.erase(ci);
        sList.insert(ci, updatedSavings);
        ci++;
    }
}


/**
 The 'delete savings' class method - deletes an existing savings.
 
 @param sList          the savings list on the savings page.
 @param sList          the income list on the budget page.
 @param savingsIDCode  the ID code of the existing savings.
 @param amount         the amount withdrawn.
 @param receivedDate   the date the money is withdrawn.
 @return               nothing
 */
void getMoney(SavingsList &sList, IncomeList &iList, int savingsIDCode,
    double amount, Date receivedDate)
{
    SavingsList::iterator ci = sList.begin();
    double emptyD = 0;
    Savings newSaving("", emptyD, 0, BANK, Date(0, 0, 0, 0, 0, 0), "");
    string savingsName;
    for (int i = 0; i < sList.size(); i++)
    {
        newSaving = sList.at(i);
        if (savingsIDCode == newSaving.getIDCode())
        {
            if (newSaving.getLAmount() > 0)
            {
                double leftOverAmount = newSaving.getAmount() + newSaving.getLAmount() - amount;
                savingsName = newSaving.getName();
                if (leftOverAmount > 999999)
                {
                    newSaving.setLAmount(leftOverAmount);
                    newSaving.setAmount(0);
                    newSaving.setAmountType("long");
                }
                else
                {
                    newSaving.setAmount(leftOverAmount);
                    newSaving.setLAmount(0);
                    newSaving.setAmountType("double");
                }
                sList.erase(ci);
                sList.insert(ci, newSaving);
            }
            else
            {
                double leftOverAmount = newSaving.getAmount() - amount;
                savingsName = newSaving.getName();
                newSaving.setAmount(leftOverAmount);
                newSaving.setLAmount(0);
                newSaving.setAmountType("double");
                sList.erase(ci);
                sList.insert(ci, newSaving);
            }
            break;
        }
        ci++;
    }
    addIncome(savingsName, amount, false, 0, receivedDate, DIP, 0, "", 0, iList);
}

void getLMoney(SavingsList &sList, IncomeList &iList, int savingsIDCode,
    long lAmount, Date receivedDate)
{
    SavingsList::iterator ci = sList.begin();
    long emptyL = 0;
    Savings newSaving("", emptyL, 0, BANK, Date(0, 0, 0, 0, 0, 0), "");
    string savingsName;
    for (int i = 0; i < sList.size(); i++)
    {
        newSaving = sList.at(i);
        if (savingsIDCode == newSaving.getIDCode())
        {
            if (newSaving.getAmount() > 0)
            {
                long leftOverAmount = newSaving.getLAmount() + newSaving.getAmount() - lAmount;
                savingsName = newSaving.getName();
                if (leftOverAmount > 999999)
                {
                    newSaving.setLAmount(leftOverAmount);
                    newSaving.setAmount(0);
                    newSaving.setAmountType("long");
                }
                else
                {
                    newSaving.setAmount(leftOverAmount);
                    newSaving.setLAmount(0);
                    newSaving.setAmountType("double");
                }
                sList.erase(ci);
                sList.insert(ci, newSaving);
            }
            else
            {
                long leftOverAmount = newSaving.getLAmount() - lAmount;
                savingsName = newSaving.getName();
                newSaving.setLAmount(leftOverAmount);
                newSaving.setAmount(0);
                newSaving.setAmountType("long");
                sList.erase(ci);
                sList.insert(ci, newSaving);
            }
            break;
        }
        ci++;
    }
    addLIncome(savingsName, lAmount, false, 0, receivedDate, DIP, 0, "", 0, iList);
}


/**
 The savings getter.
 
 @param sList          the savings list on the savings page.
 @return totalSavings  the total savings.
 */
float getSavingsBalance(SavingsList sList)
{
    float totalSavings = 0;
    for (int i = 0; i < sList.size(); i++)
        totalSavings += sList.at(i).getAmount();
    return totalSavings;
}

void addSavingsAgain(string name, double amount, float APR, SavingsNature nature, Date date, string description, int IDCode, SavingsList &sList)
{
    Savings addedSavings(name, amount, APR, nature, date, description);
    // add the income to the vector list
    SavingsList::iterator ci = sList.begin();
    addedSavings.setIDCode(IDCode);
    sList.insert((ci + IDCode) - 1, addedSavings);

    double emptyD = 0;
    Savings editedSavings("", emptyD, 0, BANK, Date(0, 0, 0, 0, 0, 0), "");

    ci = ci + IDCode;

    for (int i = IDCode; i < sList.size(); i++)
    {
        editedSavings = sList.at(i);
        int currentIDCode = editedSavings.getIDCode();
        editedSavings.setIDCode(currentIDCode + 1);
        sList.erase(ci);
        sList.insert(ci, editedSavings);
        ci++;
    }
}

void addLSavingsAgain(string name, long lAmount, float APR, SavingsNature nature, Date date, string description, int IDCode, SavingsList &sList)
{
    Savings addedSavings(name, lAmount, APR, nature, date, description);
    // add the income to the vector list
    SavingsList::iterator ci = sList.begin();
    addedSavings.setIDCode(IDCode);
    sList.insert((ci + IDCode) - 1, addedSavings);

    long emptyL = 0;
    Savings editedSavings("", emptyL, 0, BANK, Date(0, 0, 0, 0, 0, 0), "");

    ci = ci + IDCode;

    for (int i = IDCode; i < sList.size(); i++)
    {
        editedSavings = sList.at(i);
        int currentIDCode = editedSavings.getIDCode();
        editedSavings.setIDCode(currentIDCode + 1);
        sList.erase(ci);
        sList.insert(ci, editedSavings);
        ci++;
    }
}
