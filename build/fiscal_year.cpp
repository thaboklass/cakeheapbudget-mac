#include "fiscal_year.h"

FiscalYear::FiscalYear(Date * startDate, Date * endDate, Balance * startOfYearBalance, bool isFirstYear):
itsStartDate(startDate),
itsEndDate(endDate),
itsStartOfYearBalance(startOfYearBalance),
itsIsFirstYear(isFirstYear)
{
}

FiscalYear::~FiscalYear()
{
    delete itsStartDate;
    itsStartDate = 0;
    delete itsEndDate;
    itsEndDate = 0;
    delete itsStartOfYearBalance;
    itsStartOfYearBalance = 0;
}

Date * FiscalYear::getStartDate() const
{
    return itsStartDate;
}

void FiscalYear::setStartDate(Date * startDate)
{
    itsStartDate = startDate;
}

Date * FiscalYear::getEndDate() const
{
    return itsEndDate;
}

void FiscalYear::setEndDate(Date * endDate)
{
    itsEndDate = endDate;
}

Balance * FiscalYear::getStartOfYearBalance() const
{
    return itsStartOfYearBalance;
}

void FiscalYear::setStartOfYearBalance(Balance * startOfYearBalance)
{
    itsStartOfYearBalance = startOfYearBalance;
}

Balance * FiscalYear::getEndOfYearBalance() const
{
    return itsEndOfYearBalance;
}

void FiscalYear::setEndOfYearBalance(Balance * endOfYearBalance)
{
    itsEndOfYearBalance = endOfYearBalance;
}

bool FiscalYear::getIsFirstYear() const
{
    return itsIsFirstYear;
}

void FiscalYear::setIsFirstYear(bool isFirstYear)
{
    itsIsFirstYear = isFirstYear;
}
