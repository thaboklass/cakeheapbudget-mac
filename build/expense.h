/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Expense class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef EXPENSE_H_INCLUDED
#define EXPENSE_H_INCLUDED
#include "liability.h"
#include "date.h"
#include <string>
using namespace std;

class Expense : public Liability
{
    public:
        Expense(string name, double amount, PriorityLevel pLevel, double penalty, Date dueDate,
            string additionalInfo, int tabIndex);
        Expense(string name, long lAmount, PriorityLevel pLevel, double penalty, Date dueDate,
            string additionalInfo, int tabIndex);
        ~Expense() {}
        string getName() const;
        void setName(string name);
        double getPenalty() const;
        void setPenalty(double penalty);
        Date getDueDate() const;
        void setDueDate(Date dueDate);
        double getNetAmount() const;
        void setNetAmount();
        double getNetLAmount() const;
        void setNetLAmount();
        string getAdditionalInfo() const;
        void setAdditionalInfo(string additionalInfo);
        int getIDCode() const;
        void setIDCode(int IDCode);
        void recalculateValues();
        int getTabIndex();
        void setTabIndex(int tabIndex);
    private:
        string itsName;
        double itsPenalty;
        Date itsDueDate;
        double itsNetAmount;
        long itsNetLAmount;
        string itsAdditionalInfo;
        int itsIDCode;
        int itsTabIndex;
};
#endif // EXPENSE_H_INCLUDED
