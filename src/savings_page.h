/**
 CakeHeap Budget for Mac
 savings.h
 Purpose: The Savings Page model: deals
 with all the commands on the savings page
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef SAVINGS_PAGE_H_INCLUDED
#define SAVINGS_PAGE_H_INCLUDED

#include "menu.h"

void addSavings(string name, double amount, float APR, SavingsNature nature, SavingsList &sList);

void editSavings(string name, double amount, float APR, SavingsNature nature,
    SavingsList &sList, int IDCode);

void deleteSavings(SavingsList &sList, int IDCode);

void getMoney(SavingsList &sList, IncomeList &iList, int savingsIDCode,
    double amount, Date * receivedDate);

float getBalance(SavingsList sList);

#endif // SAVINGS_PAGE_H_INCLUDED
