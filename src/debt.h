/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Debt class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef DEBT_H_INCLUDED
#define DEBT_H_INCLUDED
#include <string>
#include "priority.h"
#include "liability.h"
#include "date.h"
using namespace std;
class Debt : public Liability
{
    public:
        Debt(string name, double amount, bool hasAPR, float APR, PriorityLevel pLevel, Date dueDate,
            string additionalInfo, int numberOfMonths, int tabIndex);
        Debt(string name, long lAmount, bool hasAPR, float APR, PriorityLevel pLevel, Date dueDate,
            string additionalInfo, int numberOfMonths, int tabIndex);
        ~Debt() {}
        string getName() const;
        void setName(string name);
        double getPenalty() const;
        void setPenalty(double penalty);
        Date getDueDate() const;
        void setDueDate(Date dueDate);
        string getAdditionalInfo() const;
        void setAdditionalInfo(string additionalInfo);
        double getNetAmount(); // gets the current month's net amount
        void setNetAmount(); // sets the current month's net amount
        void setNetAmount(double netAmount);
        double getNetLAmount(); // gets the current month's net amount
        void setNetLAmount();
        void setNetLAmount(long netLAmount);
        int getIDCode() const;
        void setIDCode(int IDCode);
        int getNumberOfMonths();
        void setNumberOfMonths(int numberOfMonths);
        int getTabIndex();
        void setTabIndex(int tabIndex);
    private:
        string itsName;
        double itsPenalty;
        Date itsDueDate;
        string itsAdditionalInfo;
        double itsNetAmount;
        long itsNetLAmount;
        int itsIDCode;
        int itsNumberOfMonths;
        int itsTabIndex;
};
#endif // DEBT_H_INCLUDED
