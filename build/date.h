/**
 CakeHeap Budget for Mac
 date.h
 Purpose: The Date class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
class Date
{
    public:
        Date(int year, int month, int day, int hour, int minute, int second);
        ~Date() {}
        int getCurrentYear();
        int getYear() const;
        void setYear(int year);
        int getCurrentMonth();
        int getMonth() const;
        void setMonth(int month);
        int getCurrentDay();
        int getDay() const;
        void setDay(int day);
        int getCurrentHour();
        int getHour() const;
        void setHour(int hour);
        int getCurrentMinute();
        int getMinute() const;
        void setMinute(int minute);
        int getCurrentSecond();
        int getSecond() const;
        void setSecond(int second);
    private:
        int itsYear;
        int itsCurrentYear;
        int itsMonth;
        int itsCurrentMonth;
        int itsDay;
        int itsCurrentDay;
        int itsHour;
        int itsCurrentHour;
        int itsMinute;
        int itsCurrentMinute;
        int itsSecond;
        int itsCurrentSecond;
};
#endif // DATE_H_INCLUDED
