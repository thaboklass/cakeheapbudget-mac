#include <iostream>
//#include <windows.h>
using namespace std;

int main()
{
    //SYSTEMTIME *p_st = new SYSTEMTIME;
    GetSystemTime(p_st);

    cout << "Year: " << p_st->wYear << endl;
    cout << "Month: " << p_st->wMonth << endl;
    cout << "Day: " << p_st->wDay << endl;
    cout << "Hour: " << p_st->wHour << endl;
    cout << "Minutes: " << p_st->wMinute << endl;
    cout << "Seconds: " << p_st->wSecond << endl;
    cout << "Milliseconds: " << p_st->wMilliseconds << endl;
}
