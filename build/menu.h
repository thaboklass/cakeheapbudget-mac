/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Menu class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <fstream>
#include <sstream>
#include <iomanip>
#include "fiscal_record.h"
FiscalRecord createFiscalRecord();
FiscalRecord openFiscalRecord(char * fileName);
void saveFiscalRecord(FiscalRecord saveFiscalRecord);
#endif // MENU_H_INCLUDED
