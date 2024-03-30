#include "savings_apr.h"

/**
 The constructor for the SavingsAPR class.
 
 @param sList          the savings list on the savings page.
 */
SavingsAPR::SavingsAPR(SavingsList *sList):
itsSavingsList(sList)
{
}


/**
 The Savings APR calculator.
 
 @param sList  the savings list.
 @return       nothing.
 */
void SavingsAPR::checkAndDealWithSavingsAndAPR(SavingsList &sList)
{
    SavingsList::iterator ci = sList.begin();
    for (int i = 0; i < sList.size(); i++)
    {
        if (sList.at(i).getAmountType() == "double")
        {
            double emptyD = 0;
            Savings editedSavings("", emptyD, 0, BANK, Date(0, 0, 0, 0, 0, 0), "");
            Date dateToCheck(0, 0, 0, 0, 0, 0);
            dateToCheck = sList.at(i).getDate();

            QDate qCurrentDate = QDate::currentDate();
            if (qCurrentDate.year() >= dateToCheck.getYear() && qCurrentDate.month() > dateToCheck.getMonth())
            {
                if (qCurrentDate.day() >= dateToCheck.getDay())
                {
                    float differenceInMonths = qCurrentDate.month() - dateToCheck.getMonth();
                    double newAmount = sList.at(i).getAmount() + (sList.at(i).getAmount() * ((differenceInMonths / 12) * sList.at(i).getAPR())) / 100;
                    //cout << newAmount << endl;
                    Date newDate(qCurrentDate.year(), qCurrentDate.month(), qCurrentDate.day(), 0, 0, 0);
                    editedSavings.setName(sList.at(i).getName());
                    editedSavings.setAmount(newAmount);
                    editedSavings.setAPR(sList.at(i).getAPR());
                    editedSavings.setNature(sList.at(i).getNature());
                    editedSavings.setDate(newDate);
                    editedSavings.setDescription(sList.at(i).getDescription());
                    sList.erase(ci + i);
                    sList.insert(ci + i, editedSavings);
                }
            }
        }
        else
        {
            double emptyL = 0;
            Savings editedSavings("", emptyL, 0, BANK, Date(0, 0, 0, 0, 0, 0), "");
            Date dateToCheck(0, 0, 0, 0, 0, 0);
            dateToCheck = sList.at(i).getDate();

            QDate qCurrentDate = QDate::currentDate();
            if (qCurrentDate.year() >= dateToCheck.getYear() && qCurrentDate.month() > dateToCheck.getMonth())
            {
                if (qCurrentDate.day() >= dateToCheck.getDay())
                {
                    float differenceInMonths = qCurrentDate.month() - dateToCheck.getMonth();
                    long newAmount = sList.at(i).getLAmount() + (sList.at(i).getLAmount() * ((differenceInMonths / 12) * sList.at(i).getAPR())) / 100;
                    //cout << newAmount << endl;
                    Date newDate(qCurrentDate.year(), qCurrentDate.month(), qCurrentDate.day(), 0, 0, 0);
                    editedSavings.setName(sList.at(i).getName());
                    editedSavings.setLAmount(newAmount);
                    editedSavings.setAPR(sList.at(i).getAPR());
                    editedSavings.setNature(sList.at(i).getNature());
                    editedSavings.setDate(newDate);
                    editedSavings.setDescription(sList.at(i).getDescription());
                    sList.erase(ci + i);
                    sList.insert(ci + i, editedSavings);
                }
            }
        }
    }
}


/**
 The Savings APR calculator thread.
 
 @param sList  none.
 @return       nothing.
 */
void SavingsAPR::run()
{
    while (true)
    {
        checkAndDealWithSavingsAndAPR(*itsSavingsList);
        sleep(5);
    }
}

