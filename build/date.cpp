#include "date.h"

/**
 The constructor for the Debt class.
 
 @param year           the year.
 @param month          the month.
 @param day            the day.
 @param hour           the hour.
 @param minute         the minute.
 @param second         the second.
 */
Date::Date(int year, int month, int day, int hour, int minute, int second):
itsYear(year),
itsMonth(month),
itsDay(day),
itsHour(hour),
itsMinute(minute),
itsSecond(second)
{
}
/*
int Date::getCurrentYear()
{
    SYSTEMTIME *p_st = new SYSTEMTIME;
    GetSystemTime(p_st);

    itsYear = p_st->wYear;

    delete p_st;
    p_st = 0;

    return itsCurrentYear;
}
*/


/**
 The year getter.
 
 @param           none.
 @return itsYear  the year.
 */
int Date::getYear() const
{
    return itsYear;
}


/**
 The year setter.
 
 @param  itsYear  the year.
 @return          nothing.
 */
void Date::setYear(int year)
{
    itsYear = year;
}
/*
int Date::getCurrentMonth()
{
    SYSTEMTIME *p_st = new SYSTEMTIME;
    GetSystemTime(p_st);

    itsMonth = p_st->wMonth;

    delete p_st;
    p_st = 0;

    return itsCurrentMonth;
}
*/


/**
 The month getter.
 
 @param            none.
 @return itsMonth  the month.
 */
int Date::getMonth() const
{
    return itsMonth;
}


/**
 The year setter.
 
 @param  itsYear  the year.
 @return          nothing.
 */
void Date::setMonth(int month)
{
    itsMonth = month;
}
/*
int Date::getCurrentDay()
{
    SYSTEMTIME *p_st = new SYSTEMTIME;
    GetSystemTime(p_st);

    itsDay = p_st->wDay;

    delete p_st;
    p_st = 0;

    return itsCurrentDay;
}
*/


/**
 The year getter.
 
 @param  itsYear  the year.
 @return          nothing.
 */
int Date::getDay() const
{
    return itsDay;
}


/**
 The day setter.
 
 @param  day  the year.
 @return          nothing.
 */
void Date::setDay(int day)
{
    itsDay = day;
}
/*
int Date::getCurrentHour()
{
    SYSTEMTIME *p_st = new SYSTEMTIME;
    GetSystemTime(p_st);

    itsHour = p_st->wHour;

    delete p_st;
    p_st = 0;

    return itsCurrentHour;
}
*/


/**
The hour getter.

@param            none.
@return itsHour   the hour.
*/
int Date::getHour() const
{
    return itsHour;
}


/**
 The hour setter.
 
 @param hour       none.
 @return           nothing.
 */
void Date::setHour(int hour)
{
    itsHour = hour;
}
/*
int Date::getCurrentMinute()
{
    SYSTEMTIME *p_st = new SYSTEMTIME;
    GetSystemTime(p_st);

    itsMinute = p_st->wMinute;

    delete p_st;
    p_st = 0;

    return itsCurrentMinute;
}
*/


/**
 The minute getter.
 
 @param            none.
 @return itsMinute   the minute.
 */
int Date::getMinute() const
{
    return itsMinute;
}


/**
 The minute setter.
 
 @param minute     the ninute.
 @return           nothing.
 */
void Date::setMinute(int minute)
{
    itsMinute = minute;
}
/*
int Date::getCurrentSecond()
{
    SYSTEMTIME *p_st = new SYSTEMTIME;
    GetSystemTime(p_st);

    itsSecond = p_st->wSecond;

    delete p_st;
    p_st = 0;

    return itsCurrentSecond;
}
*/


/**
 The second getter.
 
 @param              none.
 @return itsSecond   the second.
 */
int Date::getSecond() const
{
    return itsSecond;
}


/**
 The second setter.
 
 @param second     the second.
 @return           nothing.
 */
void Date::setSecond(int second)
{
    itsSecond = second;
}
