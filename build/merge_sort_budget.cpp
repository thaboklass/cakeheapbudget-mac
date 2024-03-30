// MergeSort.cpp
// Class MergeSort member-function definition.

#include <vector>
using std::vector;

#include "merge_sort_budget.h" // class MergeSoft definition

/**
 The constructor for the MergeSort class.
 
 @param btList           btList the budget tab list.
 */
MergeSortBudget::MergeSortBudget(BudgetTabList btList)
{
    size = btList.size(); //validate vectorSize

    // fill the vector with random BudgetTabItems with different dates
    for (int i = 0; i < btList.size(); i++)
    {
        data.push_back(btList.at(i));
    }
} // end MergeSort constructor

//

/**
 Split vector, sort subvectors and merge subvectors into sorted vector
 
 @param  btList the budget tab list.
 @return        nothing.
 */
void MergeSortBudget::sort(BudgetTabList btList)
{
    sortSubVector(0, size - 1, btList); // recursively sort entire vector
} // end function sort


/**
 Recursive function to sort subvectors
 
 @param  low    the low tab.
 @param  high   the high tab.
 @param  btList the budget tab list.
 @return        nothing.
 */
void MergeSortBudget::sortSubVector(int low, int high, BudgetTabList btList)
{
    // test base case; size of vector equals 1
    if ((high - low) >= 1) // if not base case
    {
        int middle1 = (low + high) / 2; // calculate middle of vector
        int middle2 = middle1 + 1; // calculate next element over

        // split vector in half; sort each half (recursive calls)
        sortSubVector(low, middle1, btList); // first half of vector
        sortSubVector(middle2, high, btList); // second half of vector

        // merge two sorted vectors after split calls return
        merge(low, middle1, middle2, high, btList);
    } // end if
} // end function sortSubVector


/**
 Merge two sorted subvectors into one sorted subvector
 
 @param  left      the left.
 @param  middle1   the high tab.
 @param  middle2   the high tab.
 @param  right     the high tab.
 @param  btList    the budget tab list.
 @return        nothing.
 */
void MergeSortBudget::merge(int left, int middle1, int middle2, int right, BudgetTabList btList)
{
    int leftIndex = left; // index into left subvector
    int rightIndex = middle2; // index into right subvector
    int combinedIndex = left; // index into temporary working vector
    vector<BudgetTabItem> combined; // working vector
    for (int i = 0; i < size; i++)
        combined.push_back(BudgetTabItem("", 0, 0, 0));

    // merge vectors until reaching end of either
    while (leftIndex <= middle1 && rightIndex <= right)
    {
        // place smaller of current elements into result
        // and move to next space in vector
        if ((data[leftIndex].getYear() >= data[rightIndex].getYear()
            && data[leftIndex].getMonth() > data[rightIndex].getMonth()) ||
            (data[leftIndex].getYear() > data[rightIndex].getYear()
            && data[leftIndex].getMonth() >= data[rightIndex].getMonth()) ||
            (data[leftIndex].getYear() > data[rightIndex].getYear()
            && data[leftIndex].getMonth() < data[rightIndex].getMonth()))
            combined[combinedIndex++] = data[leftIndex++];
        else
            combined[combinedIndex++] = data[rightIndex++];
    } // end while

    if (leftIndex == middle2) // if at end of left vector
    {
        while (rightIndex <= right) //copy in rest of right vector
            combined[combinedIndex++] = data[rightIndex++];
    } // end if
    else // at end of right vector
    {
        while (leftIndex <= middle1) // copy in rest of left vector
            combined[combinedIndex++] = data[leftIndex++];
    } // end else

    // copy values back into original vector
    for (int i = left; i <= right; i++)
    {
        BudgetTabItem item = combined[i];
        item.setTabIndex(i);
        data[i] = item;
    }
} // end function merge


/**
 Display elements in vector
 
 @param         none.
 @return        nothing.
 */
void MergeSortBudget::displayElements() const
{
    displaySubVector(0, size - 1);
} // end function displatElements


/**
 Display certain values in vector
 
 @param         none.
 @return        nothing.
 */
void MergeSortBudget::displaySubVector(int low, int high) const
{
    // output spaces for alignment
    for (int i = 0; i < low; i++)
        //cout << "   ";

    // output elements left in vector
    for (int i = low; i <= high; i++)
    {
        BudgetTabItem item = data[i];
    }
} // end function displatSubVector


/**
 Gets the sorted index.
 
 @param  month.       the month of the tab.
 @param  year.        the year of tab.
 @return sortedIndex  
 */
int MergeSortBudget::getSortedTabIndex(int month, int year)
{
    int sortedIndex;
    for (int i = 0; i < size; i++)
    {
        if ((data[i].getYear() == year) && (data[i].getMonth() == month))
        {
            sortedIndex = data[i].getTabIndex();
        }
    }
    return sortedIndex;
}
