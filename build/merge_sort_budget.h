/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The MergeSort class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef MERGE_SORT_BUDGET_H_INCLUDED
#define MERGE_SORT_BUDGET_H_INCLUDED

#include <vector>
#include <string>
using namespace std;

class BudgetTabItem
{
    public:
        BudgetTabItem(string tabTitle, int month, int year, int tabIndex):
            itsTabTitle(tabTitle), itsMonth(month), itsYear(year), itsTabIndex(tabIndex) {}
        string getTabTitle() { return itsTabTitle; }
        void setTabTitle(string tabTitle) { itsTabTitle = tabTitle; }
        int getMonth() { return itsMonth; }
        void setMonth(int month) { itsMonth = month; }
        int getYear() { return itsYear; }
        void setYear(int year) { itsYear = year; }
        int getTabIndex() { return itsTabIndex; }
        void setTabIndex(int tabIndex) { itsTabIndex = tabIndex; }
    private:
        string itsTabTitle;
        int itsMonth;
        int itsYear;
        int itsTabIndex;
};

typedef vector<BudgetTabItem> BudgetTabList;

// MergeSof class definition
class MergeSortBudget
{
    public:
        MergeSortBudget(BudgetTabList btList); // constructor initializes vector
        void sort(BudgetTabList btList); // sort vector using merge sort
        void displayElements() const; // display vector elements
        int getSortedTabIndex(int year, int month);
        BudgetTabList data; // vector of BudgetItems
    private:
        int size; // vector size
        void sortSubVector(int, int, BudgetTabList btList); // sort subvector
        void merge(int, int, int, int, BudgetTabList btList); // merge two sorted vectors
        void displaySubVector(int, int) const; // display subvector
}; // end class SelectionSort

#endif // MERGE_SORT_BUDGET_H_INCLUDED
