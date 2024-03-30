/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Debt class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef INCOME_H_INCLUDED
#define INCOME_H_INCLUDED
#include "asset.h"
#include "date.h"
//#include <string>
//using namespace std;

enum Nature { SALARY, DIVIDEND, STOCK_SALE, IOU, DIP, OTHER };

class Income : public Asset
{
    public:
        Income(string name, double amount, bool hasAPR, float APR, Date receivedDate, Nature nature, float tax,
            string additionalInfo, int tabIndex);
        Income(string name, long lAmount, bool hasAPR, float APR, Date receivedDate, Nature nature, float tax,
            string additionalInfo, int tabIndex);
        ~Income() {}
        Nature getNature() const;
        void setNature(Nature nature);
        bool getIsTaxable() const;
        void setIsTaxable(bool isTaxable);
        float getTax() const;
        void setTax(float tax);
        double getNetAmount() const;
        void setNetAmount(float tax);
        double getNetLAmount() const;
        void setNetLAmount(float tax);
        Date getReceivedDate() const;
        void setReceivedDate(Date receivedDate);
        string getName() const;
        void setName(string name);
        string getAdditionalInfo() const;
        void setAdditionalInfo(string additionalInfo);
        int getIDCode() const;
        void setIDCode(int IDCode);
        void recalculateValues();
        int getTabIndex();
        void setTabIndex(int tabIndex);
    private:
        Nature itsNature;
        bool itsIsTaxable;
        float itsTax; // as a percentage
        Date itsReceivedDate;
        string itsName;
        double itsNetAmount;
        long itsNetLAmount;
        string itsAdditionalInfo;
        int itsIDCode;
        int itsTabIndex;
};
#endif // INCOME_H_INCLUDED
