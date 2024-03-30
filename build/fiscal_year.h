#ifndef FISCAL_YEAR_H_INCLUDED
#define FISCAL_YEAR_H_INCLUDED
#include "date.h"
#include "balance.h"
class FiscalYear
{
    public:
        FiscalYear(Date * startDate, Date * endDate, Balance * startOfYearBalance, bool isFirstYear);
        ~FiscalYear();
        Date*  getStartDate() const;
        void setStartDate(Date * startDate);
        Date * getEndDate() const;
        void setEndDate(Date * endDate);
        Balance * getStartOfYearBalance() const;
        void setStartOfYearBalance(Balance * startOfYearBalances);
        Balance * getEndOfYearBalance() const;
        void setEndOfYearBalance(Balance * endOfYearBalance);
        bool getIsFirstYear() const;
        void setIsFirstYear(bool isFirstYear);
    private:
        Date * itsStartDate;
        Date * itsEndDate;
        Balance * itsStartOfYearBalance;
        Balance * itsEndOfYearBalance;
        bool itsIsFirstYear;
};
#endif // FISCAL_YEAR_H_INCLUDED
