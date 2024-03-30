#include "budget_page.h"
#include <iostream>

/**
 The 'add income' class method - adds a new income
 to the budget.
 
 @param name           the name of the income.
 @param amount         the income amount.
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param receivedDate   the date the income is received.
 @param nature         the nature of the income.
 @param tex            the tax rate.
 @param additionalInfo the income metadata.
 @param tabIndex       the index of the tab where the debt belongs.
 @param iList          the budget page income list.
 @return               nothing.
 */
void addIncome(string name, double amount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, IncomeList &iList) {
    Income addedIncome(name, amount, hasAPR, APR, receivedDate, nature, tax, additionalInfo, tabIndex);
    // add the income to the vector list
    addedIncome.setIDCode(iList.size() + 1);
    iList.push_back(addedIncome);
}


/**
 The 'edit income' class method - edits an existing income.
 
 @param name           the name of the income.
 @param amount         the income amount.
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param receivedDate   the date the income is received.
 @param nature         the nature of the income.
 @param tex            the tax rate.
 @param additionalInfo the income metadata.
 @param tabIndex       the index of the tab where the debt belongs.
 @param iList          the budget page income list.
 @param IDCode         the ID code of the existing income
 @return               nothing.
 */
void editIncome(string name, double amount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, IncomeList &iList, int IDCode) {
    IncomeList::iterator ci = iList.begin();
    bool found = false;
    double emptyD = 0;
    Income editedIncome("", emptyD, false, 0, Date(0, 0, 0, 0, 0, 0),
            OTHER, 0, "", 0);
    for (int i = 0; i < iList.size(); i++)
    {
        editedIncome = iList.at(i);
        if (IDCode == editedIncome.getIDCode())
        {
            found = true;
            editedIncome.setName(name);
            editedIncome.setAmount(amount);
            editedIncome.setHasAPR(hasAPR);
            editedIncome.setAPR(APR);
            editedIncome.setReceivedDate(receivedDate);
            editedIncome.setNature(nature);
            editedIncome.setTax(tax);
            editedIncome.setAdditionalInfo(additionalInfo);
            editedIncome.setTabIndex(tabIndex);
            editedIncome.recalculateValues();
            iList.erase(ci);
            iList.insert(ci, editedIncome);
            break;
        }
        ci++;
    }
}

void addLIncome(string name, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, IncomeList &iList) {
    Income addedIncome(name, lAmount, hasAPR, APR, receivedDate, nature, tax, additionalInfo, tabIndex);
    // add the income to the vector list
    addedIncome.setIDCode(iList.size() + 1);
    iList.push_back(addedIncome);
}

void editLIncome(string name, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, IncomeList &iList, int IDCode) {
    IncomeList::iterator ci = iList.begin();
    bool found = false;
    long emptyL = 0;
    Income editedIncome("", emptyL, false, 0, Date(0, 0, 0, 0, 0, 0),
            OTHER, 0, "", 0);
    for (int i = 0; i < iList.size(); i++)
    {
        editedIncome = iList.at(i);
        if (IDCode == editedIncome.getIDCode())
        {
            found = true;
            editedIncome.setName(name);
            editedIncome.setLAmount(lAmount);
            editedIncome.setHasAPR(hasAPR);
            editedIncome.setAPR(APR);
            editedIncome.setReceivedDate(receivedDate);
            editedIncome.setNature(nature);
            editedIncome.setTax(tax);
            editedIncome.setAdditionalInfo(additionalInfo);
            editedIncome.setTabIndex(tabIndex);
            editedIncome.recalculateValues();
            iList.erase(ci);
            iList.insert(ci, editedIncome);
            break;
        }
        ci++;
    }
}


/**
 The 'delete income' class method - deletes an existing income.
 
 @param iList          the budget page income list.
 @param IDCode         the ID code of the existing income
 @return               nothing.
 */
void deleteIncome(IncomeList &iList, int IDCode) {
    int i = 0;
    for (IncomeList::iterator ci = iList.begin();
            ci != iList.end(); ci++)
    {
        Income deletedIncome = iList.at(i);
        //cout << inquiredItem.getIDCode() << endl;
        if (IDCode == deletedIncome.getIDCode())
        {
            cout << deletedIncome.getIDCode() << endl;
            iList.erase(ci);
            break;
        }
        //cout << i << endl;
        i++;
    }

    // re-label the new income list after the deletion
    IncomeList::iterator ci = iList.begin();
    for (int i = 0; i < iList.size(); i++)
    {
        Income updatedIncome = iList.at(i);
        updatedIncome.setIDCode(i + 1);
        iList.erase(ci);
        iList.insert(ci, updatedIncome);
        ci++;
    }
}
/*
extern "C" __declspec(dllexport)

void addOneToTabIndices(IncomeList &iList, int i, string amountType)
{
    IncomeList::iterator ci = iList.begin();
    if (amountType == "double")
    {
        double emptyD = 0;
        Income editedIncome("", emptyD, false, 0, Date(0, 0, 0, 0, 0, 0),
                OTHER, 0, "", 0);
        editedIncome = iList.at(i);
        editedIncome.setTabIndex(editedIncome.getTabIndex() + 1);
        iList.erase(ci + i);
        iList.insert(ci + i, editedIncome);
    }
    else
    {
        long emptyL = 0;
        Income editedIncome("", emptyL, false, 0, Date(0, 0, 0, 0, 0, 0),
                OTHER, 0, "", 0);
        editedIncome = iList.at(i);
        editedIncome.setTabIndex(editedIncome.getTabIndex() + 1);
        iList.erase(ci + i);
        iList.insert(ci + i, editedIncome);
    }
}
*/


/**
 The 'shuffle income tabs' class method - re-orders the tabs
 after editing or deletion occurs.
 
 @param month          the income's month.
 @param year           the income's year.
 @param IDCode         the ID code of the existing income
 @param iList          the budget page income list.
 @return               nothing.
 */
void shuffleIncomeTabs(int month, int year, int tabIndex, IncomeList &iList)
{
    IncomeList::iterator ci = iList.begin();
    double emptyD = 0;
    Income editedIncome("", emptyD, false, 0, Date(0, 0, 0, 0, 0, 0),
            OTHER, 0, "", 0);
    long emptyL = 0;
    Income editedLIncome("", emptyL, false, 0, Date(0, 0, 0, 0, 0, 0),
            OTHER, 0, "", 0);

    for (int i = 0; i < iList.size(); i++)
    {
        if ((iList.at(i).getReceivedDate().getMonth() == month)
            && (iList.at(i).getReceivedDate().getYear() == year))
        {
            if (iList.at(i).getAmountType() == "double")
            {
                editedIncome = iList.at(i);
                editedIncome.setTabIndex(tabIndex);
                iList.erase(ci + i);
                iList.insert(ci + i, editedIncome);
            }
            else
            {
                editedLIncome = iList.at(i);
                editedLIncome.setTabIndex(tabIndex);
                iList.erase(ci + i);
                iList.insert(ci + i, editedLIncome);
            }
        }
    }
}


/**
 The 'shuffle debt tabs' class method - re-orders the tabs
 after editing or deletion occurs.
 
 @param month          the debt's month.
 @param year           the debt's year.
 @param IDCode         the ID code of the existing debt.
 @param dList          the budget page debt list.
 @return               nothing.
 */
void shuffleDebtTabs(int month, int year, int tabIndex, DebtList &dList)
{
    DebtList::iterator ci = dList.begin();
    double emptyD = 0;
    Debt editedDebt("", emptyD, false, 0, NONE, Date(0, 0, 0, 0, 0, 0), "", 0, 0);
    long emptyL = 0;
    Debt editedLDebt("", emptyL, false, 0, NONE, Date(0, 0, 0, 0, 0, 0), "", 0, 0);

    for (int i = 0; i < dList.size(); i++)
    {
        if ((dList.at(i).getDueDate().getMonth() == month)
            && (dList.at(i).getDueDate().getYear() == year))
        {
            if (dList.at(i).getAmountType() == "double")
            {
                editedDebt = dList.at(i);
                editedDebt.setTabIndex(tabIndex);
                dList.erase(ci + i);
                dList.insert(ci + i, editedDebt);
            }
            else
            {
                editedLDebt = dList.at(i);
                editedLDebt.setTabIndex(tabIndex);
                dList.erase(ci + i);
                dList.insert(ci + i, editedLDebt);
            }
        }
    }
}


/**
 The 'shuffle expense tabs' class method - re-orders the tabs
 after editing or deletion occurs.
 
 @param month          the expense's month.
 @param year           the expense's year.
 @param IDCode         the ID code of the existing expense.
 @param eList          the budget page expense list.
 @return               nothing.
 */
void shuffleExpenseTabs(int month, int year, int tabIndex, ExpenseList &eList)
{
    ExpenseList::iterator ci = eList.begin();
    double emptyD = 0;
    Expense editedExpense("", emptyD, NONE, 0, Date(0, 0, 0, 0, 0, 0), "", 0);
    long emptyL = 0;
    Expense editedLExpense("", emptyL, NONE, 0, Date(0, 0, 0, 0, 0, 0), "", 0);

    for (int i = 0; i < eList.size(); i++)
    {
        if ((eList.at(i).getDueDate().getMonth() == month)
            && (eList.at(i).getDueDate().getYear() == year))
        {
            if (eList.at(i).getAmountType() == "double")
            {
                editedExpense = eList.at(i);
                editedExpense.setTabIndex(tabIndex);
                eList.erase(ci + i);
                eList.insert(ci + i, editedExpense);
            }
            else
            {
                editedLExpense = eList.at(i);
                editedLExpense.setTabIndex(tabIndex);
                eList.erase(ci + i);
                eList.insert(ci + i, editedLExpense);
            }
        }
    }
}


/**
 The 'add debt' class method - adds a new debt
 to the budget.
 
 @param name           the name of the debt.
 @param amount         the debt amount(double).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param pLevel         the priority level of the debt.
 @param date           the date the payment is due.
 @param additionalInfo the debt metadata.
 @param numberOfMonths the number of months the payment is spread across.
 @param tabIndex       the index of the tab where the debt belongs.
 @param dList          the budget page debt list.
 @return               nothing
 */
void addDebt(string name, double amount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, DebtList &dList) {
    Debt addedDebt(name, amount, hasAPR, APR, pLevel, dueDate, additionalInfo, numberOfMonths, tabIndex);
    // add the income to the vector list
    addedDebt.setIDCode(dList.size() + 1);
    dList.push_back(addedDebt);
}


/**
 The 'edit debt' class method - edits an existing debt.
 
 @param name           the name of the debt.
 @param amount         the debt amount(double).
 @param hasAPR         a boolean that controls whether the amount has an APR.
 @param APR            the APR.
 @param pLevel         the priority level of the debt.
 @param date           the date the payment is due.
 @param additionalInfo the debt metadata.
 @param numberOfMonths the number of months the payment is spread across.
 @param tabIndex       the index of the tab where the debt belongs.
 @param dList          the budget page debt list.
 @param IDCode         the ID code of the existing income.
 @return               nothing
 */
void editDebt(string name, double amount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, DebtList &dList, int IDCode) {
    DebtList::iterator ci = dList.begin();
    bool found = false;
    double emptyD = 0;
    Debt editedDebt("", emptyD, false, 0, NONE, Date(0, 0, 0, 0, 0, 0), "", 0, 0);
    for (int i = 0; i < dList.size(); i++)
    {
        editedDebt = dList.at(i);
        if (IDCode == editedDebt.getIDCode())
        {
            found = true;
            editedDebt.setName(name);
            editedDebt.setAmount(amount);
            editedDebt.setHasAPR(hasAPR);
            editedDebt.setAPR(APR);
            editedDebt.setPriorityLevel(pLevel);
            editedDebt.setDueDate(dueDate);
            editedDebt.setAdditionalInfo(additionalInfo);
            editedDebt.setNumberOfMonths(numberOfMonths);
            editedDebt.setNetAmount();
            editedDebt.setTabIndex(tabIndex);
            dList.erase(ci);
            dList.insert(ci, editedDebt);
            break;
        }
        ci++;
    }
}

void addLDebt(string name, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, DebtList &dList) {
    Debt addedDebt(name, lAmount, hasAPR, APR, pLevel, dueDate, additionalInfo, numberOfMonths, tabIndex);
    // add the income to the vector list
    addedDebt.setIDCode(dList.size() + 1);
    dList.push_back(addedDebt);
}

void editLDebt(string name, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, DebtList &dList, int IDCode) {
    DebtList::iterator ci = dList.begin();
    bool found = false;
    long emptyL = 0;
    Debt editedDebt("", emptyL, false, 0, NONE, Date(0, 0, 0, 0, 0, 0), "", 0, 0);
    for (int i = 0; i < dList.size(); i++)
    {
        editedDebt = dList.at(i);
        if (IDCode == editedDebt.getIDCode())
        {
            found = true;
            editedDebt.setName(name);
            editedDebt.setLAmount(lAmount);
            editedDebt.setHasAPR(hasAPR);
            editedDebt.setAPR(APR);
            editedDebt.setPriorityLevel(pLevel);
            editedDebt.setDueDate(dueDate);
            editedDebt.setAdditionalInfo(additionalInfo);
            editedDebt.setNumberOfMonths(numberOfMonths);
            editedDebt.setNetAmount();
            editedDebt.setTabIndex(tabIndex);
            dList.erase(ci);
            dList.insert(ci, editedDebt);
            break;
        }
        ci++;
    }
}


/**
 The 'delete debt' class method - deletes an existing debt.
 
 @param dList          the budget page debt list.
 @param IDCode         the ID code of the existing debt
 @return               nothing.
 */
void deleteDebt(DebtList &dList, int IDCode) {
    int i = 0;
    for (DebtList::iterator ci = dList.begin();
            ci != dList.end(); ci++)
    {
        Debt deletedDebt = dList.at(i);
        //cout << inquiredItem.getIDCode() << endl;
        if (IDCode == deletedDebt.getIDCode())
        {
            cout << deletedDebt.getIDCode() << endl;
            dList.erase(ci);
            break;
        }
        //cout << i << endl;
        i++;
    }

    // re-label the new income list after the deletion
    DebtList::iterator ci = dList.begin();
    for (int i = 0; i < dList.size(); i++)
    {
        Debt updatedDebt = dList.at(i);
        updatedDebt.setIDCode(i + 1);
        dList.erase(ci);
        dList.insert(ci, updatedDebt);
        ci++;
    }
}


/**
 The 'edit debt' class method - edits an existing debt.
 
 @param name           the name of the expense.
 @param amount         the expense amount.
 @param pLevel         the priority level of the expense.
 @param penalty        the penalty (if any) of the expense.
 @param dueDate        the date the payment is due.
 @param additionalInfo the expense metadata.
 @param tabIndex       the index of the tab where the expense belongs.
 @param eList          the budget page expense list.
 @return               nothing
 */
void addExpense(string name, double amount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, ExpenseList &eList) {
    Expense addedExpense(name, amount, pLevel, penalty, dueDate, additionalInfo, tabIndex);
    // add the income to the vector list
    addedExpense.setIDCode(eList.size() + 1);
    eList.push_back(addedExpense);
}


/**
 The 'edit expense' class method - edits an existing expense.
 
 @param name           the name of the expense.
 @param amount         the expense amount.
 @param pLevel         the priority level of the expense.
 @param penalty        the penalty (if any) of the expense.
 @param dueDate        the date the payment is due.
 @param additionalInfo the expense metadata.
 @param tabIndex       the index of the tab where the expense belongs.
 @param eList          the budget page expense list.
 @param IDCode         the ID code of the existing expense.
 @return               nothing
 */
void editExpense(string name, double amount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, ExpenseList &eList, int IDCode) {
    ExpenseList::iterator ci = eList.begin();
    bool found = false;
    double emptyD = 0;
    Expense editedExpense("", emptyD, NONE, 0, Date(0, 0, 0, 0, 0, 0), "", 0);
    for (int i = 0; i < eList.size(); i++)
    {
        editedExpense = eList.at(i);
        if (IDCode == editedExpense.getIDCode())
        {
            found = true;
            editedExpense.setName(name);
            editedExpense.setAmount(amount);
            editedExpense.setPriorityLevel(pLevel);
            editedExpense.setPenalty(penalty);
            editedExpense.setDueDate(dueDate);
            editedExpense.setAdditionalInfo(additionalInfo);
            editedExpense.setTabIndex(tabIndex);
            editedExpense.recalculateValues();
            eList.erase(ci);
            eList.insert(ci, editedExpense);
            break;
        }
        ci++;
    }
}

void addLExpense(string name, long lAmount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, ExpenseList &eList) {
    Expense addedExpense(name, lAmount, pLevel, penalty, dueDate, additionalInfo, tabIndex);
    // add the income to the vector list
    addedExpense.setIDCode(eList.size() + 1);
    eList.push_back(addedExpense);
}

void editLExpense(string name, long lAmount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, ExpenseList &eList, int IDCode) {
    ExpenseList::iterator ci = eList.begin();
    bool found = false;
    long emptyL = 0;
    Expense editedExpense("", emptyL, NONE, 0, Date(0, 0, 0, 0, 0, 0), "", 0);
    for (int i = 0; i < eList.size(); i++)
    {
        editedExpense = eList.at(i);
        if (IDCode == editedExpense.getIDCode())
        {
            found = true;
            editedExpense.setName(name);
            editedExpense.setLAmount(lAmount);
            editedExpense.setPriorityLevel(pLevel);
            editedExpense.setPenalty(penalty);
            editedExpense.setDueDate(dueDate);
            editedExpense.setAdditionalInfo(additionalInfo);
            editedExpense.setTabIndex(tabIndex);
            editedExpense.recalculateValues();
            eList.erase(ci);
            eList.insert(ci, editedExpense);
            break;
        }
        ci++;
    }
}


/**
 The 'delete expense' class method - deletes an existing expense.
 
 @param eList          the budget page expense list.
 @param IDCode         the ID code of the existing expense
 @return               nothing.
 */
void deleteExpense(ExpenseList &eList, int IDCode) {
    int i = 0;
    for (ExpenseList::iterator ci = eList.begin();
            ci != eList.end(); ci++)
    {
        Expense deletedExpense = eList.at(i);
        //cout << inquiredItem.getIDCode() << endl;
        if (IDCode == deletedExpense.getIDCode())
        {
            cout << deletedExpense.getIDCode() << endl;
            eList.erase(ci);
            break;
        }
        //cout << i << endl;
        i++;
    }

    // re-label the new income list after the deletion
    ExpenseList::iterator ci = eList.begin();
    for (int i = 0; i < eList.size(); i++)
    {
        Expense updatedExpense = eList.at(i);
        updatedExpense.setIDCode(i + 1);
        eList.erase(ci);
        eList.insert(ci, updatedExpense);
        ci++;
    }
}


/**
 The 'save money' class method - saves money by removing it from the
 income to the savings.
 
 @param eList          the budget page expense list.
 @param sList          the savings page savings list.
 @param savingsIDCode  the ID code of the existing savings.
 @param amount         the savings amount.
 @param pLevel         the priority level of the expense.
 @param dueDate        the date the payment is due.
 @param additionalInfo the expense metadata.
 @param tabIndex       the index of the tab where the expense belongs.
 @return               nothing
 */
void saveMoney(ExpenseList &eList, SavingsList &sList, int savingsIDCode,
    double amount, PriorityLevel pLevel, Date dueDate, string additionalInfo, int tabIndex)
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
            if ((newSaving.getAmount() > 999999) || (newSaving.getLAmount() > 999999))
            {
                long totalAmount = newSaving.getAmount() + newSaving.getLAmount() + amount;
                savingsName = newSaving.getName();
                newSaving.setLAmount(totalAmount);
                newSaving.setAmount(0);
                newSaving.setAmountType("long");
                sList.erase(ci);
                sList.insert(ci, newSaving);
                //cout << "i'm at 1" << endl;
            }
            else
            {
                double totalAmount = newSaving.getAmount() + amount;
                long totalLAmount = newSaving.getAmount() + amount;
                savingsName = newSaving.getName();
                if (totalLAmount > 999999)
                {
                    newSaving.setLAmount(totalLAmount);
                    newSaving.setAmount(0);
                    newSaving.setAmountType("long");
                    //cout << "i'm at 2" << endl;
                }
                else
                {
                    newSaving.setAmount(totalAmount);
                    newSaving.setLAmount(0);
                    newSaving.setAmountType("double");
                    //cout << "i'm at 3" << endl;
                }
                sList.erase(ci);
                sList.insert(ci, newSaving);
            }
            break;
        }
        ci++;
    }
    addExpense(savingsName, amount, pLevel, 0, dueDate, additionalInfo, tabIndex, eList);

}

void saveLMoney(ExpenseList &eList, SavingsList &sList, int savingsIDCode,
    long lAmount, PriorityLevel pLevel, Date dueDate, string additionalInfo, int tabIndex)
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
            long totalAmount = newSaving.getLAmount() + newSaving.getAmount() + lAmount;
            if (totalAmount > 999999)
            {
                savingsName = newSaving.getName();
                newSaving.setLAmount(totalAmount);
                newSaving.setAmount(0);
                newSaving.setAmountType("long");
                sList.erase(ci);
                sList.insert(ci, newSaving);
            }
            else
            {
                savingsName = newSaving.getName();
                newSaving.setAmount(totalAmount);
                newSaving.setLAmount(0);
                newSaving.setAmountType("double");
                sList.erase(ci);
                sList.insert(ci, newSaving);
            }
            break;
        }
        ci++;
    }
    addLExpense(savingsName, lAmount, pLevel, 0, dueDate, additionalInfo, tabIndex, eList);

}


/**
 The 'save money' class method - saves money by removing it from the
 income to the savings.
 
 @param eList          the budget page expense list.
 @param sList          the savings page savings list.
 @param savingsIDCode  the ID code of the existing savings.
 @param amount         the savings amount.
 @param pLevel         the priority level of the expense.
 @param dueDate        the date the payment is due.
 @param additionalInfo the expense metadata.
 @param tabIndex       the index of the tab where the expense belongs.
 @return               nothing
 */
float getBudgetBalance(IncomeList iList, DebtList dList, ExpenseList eList)
{
    float totalIncome = 0;
    for (int i = 0; i < iList.size(); i++)
        totalIncome += iList.at(i).getNetAmount();

    float totalDebt = 0;
    for (int i = 0; i < dList.size(); i++)
        totalDebt += dList.at(1).getNetAmount();

    float totalExpense = 0;
    for (int i = 0; i < eList.size(); i++)
        totalExpense += eList.at(i).getNetAmount();

    float balance = totalIncome - totalDebt - totalExpense;
    return balance;
}

void addIncomeAgain(string name, double amount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, int IDCode, IncomeList &iList) {
    Income addedIncome(name, amount, hasAPR, APR, receivedDate, nature, tax, additionalInfo, tabIndex);
    // re-add the income to the vector list
    IncomeList::iterator ci = iList.begin();
    addedIncome.setIDCode(IDCode);
    iList.insert((ci + IDCode) - 1, addedIncome);

    double emptyD = 0;
    Income editedIncome("", emptyD, false, 0, Date(0, 0, 0, 0, 0, 0),
            OTHER, 0, "", 0);

    ci = ci + IDCode;

    for (int i = IDCode; i < iList.size(); i++)
    {
        editedIncome = iList.at(i);
        int currentIDCode = editedIncome.getIDCode();
        editedIncome.setIDCode(currentIDCode + 1);
        iList.erase(ci);
        iList.insert(ci, editedIncome);
        ci++;
    }
}

void addLIncomeAgain(string name, long lAmount, bool hasAPR, float APR, Date receivedDate,
            Nature nature, float tax, string additionalInfo, int tabIndex, int IDCode, IncomeList &iList) {
    Income addedIncome(name, lAmount, hasAPR, APR, receivedDate, nature, tax, additionalInfo, tabIndex);
    // re-add the income to the vector list
    IncomeList::iterator ci = iList.begin();
    addedIncome.setIDCode(IDCode);
    iList.insert((ci + IDCode) - 1, addedIncome);

    long emptyL = 0;
    Income editedIncome("", emptyL, false, 0, Date(0, 0, 0, 0, 0, 0),
            OTHER, 0, "", 0);

    ci = ci + IDCode;

    for (int i = IDCode; i < iList.size(); i++)
    {
        editedIncome = iList.at(i);
        int currentIDCode = editedIncome.getIDCode();
        editedIncome.setIDCode(currentIDCode + 1);
        iList.erase(ci);
        iList.insert(ci, editedIncome);
        ci++;
    }
}

void addExpenseAgain(string name, double amount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, int IDCode, ExpenseList &eList) {
    Expense addedExpense(name, amount, pLevel, penalty, dueDate, additionalInfo, tabIndex);
    // add the income to the vector list
    ExpenseList::iterator ci = eList.begin();
    addedExpense.setIDCode(IDCode);
    eList.insert((ci + IDCode) - 1, addedExpense);

    double emptyD = 0;
    Expense editedExpense("", emptyD, NONE, 0, Date(0, 0, 0, 0, 0, 0), "", 0);

    ci = ci + IDCode;

    for (int i = IDCode; i < eList.size(); i++)
    {
        editedExpense = eList.at(i);
        int currentIDCode = editedExpense.getIDCode();
        editedExpense.setIDCode(currentIDCode + 1);
        eList.erase(ci);
        eList.insert(ci, editedExpense);
        ci++;
    }
}

void addLExpenseAgain(string name, long lAmount, PriorityLevel pLevel, double penalty,
        Date dueDate, string additionalInfo, int tabIndex, int IDCode, ExpenseList &eList) {
    Expense addedExpense(name, lAmount, pLevel, penalty, dueDate, additionalInfo, tabIndex);
    // add the income to the vector list
    ExpenseList::iterator ci = eList.begin();
    addedExpense.setIDCode(IDCode);
    eList.insert((ci + IDCode) - 1, addedExpense);

    long emptyL = 0;
    Expense editedExpense("", emptyL, NONE, 0, Date(0, 0, 0, 0, 0, 0), "", 0);

    ci = ci + IDCode;

    for (int i = IDCode; i < eList.size(); i++)
    {
        editedExpense = eList.at(i);
        int currentIDCode = editedExpense.getIDCode();
        editedExpense.setIDCode(currentIDCode + 1);
        eList.erase(ci);
        eList.insert(ci, editedExpense);
        ci++;
    }
}

void addDebtAgain(string name, double amount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, int IDCode, DebtList &dList) {
    Debt addedDebt(name, amount, hasAPR, APR, pLevel, dueDate, additionalInfo, numberOfMonths, tabIndex);
    // add the income to the vector list
    DebtList::iterator ci = dList.begin();
    addedDebt.setIDCode(IDCode);
    dList.insert((ci + IDCode) - 1, addedDebt);

    double emptyD = 0;
    Debt editedDebt("", emptyD, false, 0, NONE, Date(0, 0, 0, 0, 0, 0), "", 0, 0);

    ci = ci + IDCode;

    for (int i = IDCode; i < dList.size(); i++)
    {
        editedDebt = dList.at(i);
        int currentIDCode = editedDebt.getIDCode();
        editedDebt.setIDCode(currentIDCode + 1);
        dList.erase(ci);
        dList.insert(ci, editedDebt);
        ci++;
    }
}

void addLDebtAgain(string name, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel,
        Date dueDate, string additionalInfo, int numberOfMonths, int tabIndex, int IDCode, DebtList &dList) {
    Debt addedDebt(name, lAmount, hasAPR, APR, pLevel, dueDate, additionalInfo, numberOfMonths, tabIndex);
    // add the income to the vector list
    DebtList::iterator ci = dList.begin();
    addedDebt.setIDCode(IDCode);
    dList.insert((ci + IDCode) - 1, addedDebt);

    long emptyL = 0;
    Debt editedDebt("", emptyL, false, 0, NONE, Date(0, 0, 0, 0, 0, 0), "", 0, 0);

    ci = ci + IDCode;

    for (int i = IDCode; i < dList.size(); i++)
    {
        editedDebt = dList.at(i);
        int currentIDCode = editedDebt.getIDCode();
        editedDebt.setIDCode(currentIDCode + 1);
        dList.erase(ci);
        dList.insert(ci, editedDebt);
        ci++;
    }
}
