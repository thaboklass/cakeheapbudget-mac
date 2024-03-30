/**
 CakeHeap Budget for Mac
 main_budget.h
 Purpose: The MainBudget class - this docks in the
 MainWin class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef MAINBUDGET_H_INCLUDED
#define MAINBUDGET_H_INCLUDED
#include "budget_dock.h"
#include "savings_dock.h"
#include "inventory_dock.h"
#include "reminders_dock.h"
#include "income_dialog.h"
#include "edited_income_dialog.h"
#include "debt_dialog.h"
#include "edited_debt_dialog.h"
#include "expenses_dialog.h"
#include "edited_expenses_dialog.h"
#include "save_money_dialog.h"
#include "savings_dialog.h"
#include "edited_savings_dialog.h"
#include "item_dialog.h"
#include "reminder_dialog.h"
#include "budget_page.h"
#include "savings_page.h"
#include "get_money_dialog.h"
#include "about_dialog.h"
#include "donate_dialog.h"
#include "inventory_page.h"
#include "budget_tab.h"
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include <QMouseEvent>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QTabBar>
#include <QtGui>
#include <QtXml>
#include <QDomDocument>
#include <QDesktopServices>
#include <QtNetwork>
//#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "mainwindow.h"
#include "income_statement_dialog.h"
#include "check_reminders.h"
//#include "cake_message_box.h"
#include "budget_frame.h"
#include "cake_tab_widget.h"
#include "merge_sort_budget.h"
#include "savings_apr.h"
//#include "cake_spacer_wigdet.h"
//#include "commands.h"
#include <QUndoStack>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPrintDialog>
#include <QToolButton>
#include <QApplication>
#include <QStatusBar>
#include <QChartView>
#include "donutbreakdownchart.h"
#include <iostream>
#include <QDesktopWidget>
#include <QFontMetrics>
#include "cake_tool_bar.h"
#include "onboaderdialog.h"
//#include <QWebView>

using namespace std;

typedef vector<QDate> QDateList;
//typedef vector<BudgetTabItem> BudgetTabList;

class MainBudget : public QMainWindow
{
    Q_OBJECT
    public:
        //friend class CakeMessageBox;
        friend class MainWin;
        friend class AddIncomeCommand;
        MainBudget(QWidget *parent = 0);
        ~MainBudget();
        char * getCharNameForIncome(string name);
        char * getCharDateForIncome(Date date);
        char * getCharNatureForIncome(Nature nature);
        char * getCharAmountForIncome(double amount);
        char * getCharAmountForLIncome(long lAmount);
        char * getCharTaxForIncome(float tax);
        char * getCharNetAmountForIncome(double netAmount);
        char * getCharNetAmountForLIncome(long netLAmount);
        char * getCharIDCodeForIncome(int IDCode);
        void insertIncomeValues(int i, Income * income);
        void populateIncomeTable(IncomeList iList);
        void populateDebtTable(DebtList dList);
        void populateExpensesTable(ExpenseList eList);
        void insertDebtValues(int i, Debt * debt);
        char * getCharNameForDebt(string name);
        char * getCharDateForDebt(Date date);
        char * getCharPriorityLevelForDebt(PriorityLevel pLevel);
        char * getCharAmountForDebt(double amount);
        char * getCharAmountForLDebt(long lAmount);
        char * getCharAPRForDebt(float APR);
        char * getCharNetAmountForDebt(double netAmount);
        char * getCharNetAmountForLDebt(long netLAmount);
        char * getCharIDCodeForDebt(int IDCode);
        void insertExpenseValues(int i, Expense * expense);
        char * getCharNameForExpenses(string name);
        char * getCharDateForExpenses(Date date);
        char * getCharPriorityLevelForExpenses(PriorityLevel pLevel);
        char * getCharAmountForExpenses(double amount);
        char * getCharAmountForLExpenses(long lAmount);
        char * getCharPenaltyForExpenses(double penalty);
        char * getCharNetAmountForExpenses(double netAmount);
        char * getCharNetAmountForLExpenses(long netLAmount);
        char * getCharAmountForMonthlyIncome(double amount);
        char * getCharAmountForMonthlyLIncome(long lAmount);
        char * getCharAmountForMonthlyDebt(double amount);
        char * getCharAmountForMonthlyLDebt(long lAmount);
        char * getCharAmountForMonthlyExpenses(double amount);
        char * getCharAmountForMonthlyLExpenses(long lAmount);
        char * getCharAmountForCurrentBalance(double amount);
        char * getCharAmountForCurrentLBalance(long lAmount);
        char * getCharIDCodeForExpenses(int IDCode);
        void setCurrentBalance();
        void populateSavingsTable(SavingsList sList);
        void insertSavingsValues(int i, Savings * savings);
        char * getCharNameForSavings(string name);
        char * getCharNatureForSavings(SavingsNature nature);
        char * getCharAmountForSavings(double amount);
        char * getCharAmountForLSavings(long lAmount);
        char * getCharAPRForSavings(float APR);
        void populateInventoryTable(ItemList itList);
        char * getCharIDCodeForInventory(string itemID);
        char * getCharNameForInventory(string name);
        char * getCharNoOfItemsForInventory(int number);
        char * getCharPriceForInventory(double price);
        void insertInventoryValues(int i, Items * item);
        char * getCharAmountForSavingsCurrentBalance(double amount);
        char * getCharAmountForSavingsCurrentLBalance(long lAmount);
        void populateReminderTable(ReminderList rList);
        char * getCharDateForReminders(Date date);
        void insertReminderValues(int i, Reminder * reminder);
        char * getCharSubjectForReminders(string subject);
        void writeSpendingToFile();
        char * getCharNumberOfMonthsForDebt(int numberOfMonths);
        QString getTabBarDate(QDate date);
        bool allowBudgetAddition(QDate entryDate);
        void sortIncomeList(IncomeList &iList, int sortType);
        bool tabTitleExists(QDate subjectDate);
        string convertQStringToString(QString qString);
        QString convertStringToQString(string actualString);
        QString convertStringToQStringNoTab(string actualString);
        QString getQStringForSecondsSave(int seconds);
        QString getQStringForMinutesSave(int minutes);
        QString getQStringForHourSave(int hour);
        QString getQStringForDaySave(int day);
        QString getQStringForMonthSave(int month);
        QString getQStringForYearSave(int month);
        QString getQStringForNameSave(string name);
        QString getQStringForNatureSave(Nature nature);
        QString getQStringForAmountSave(double amount);
        QString getQStringForLAmountSave(long lAmount);
        QString getQStringForTaxSave(float tax);
        QString getQStringForNetAmountSave(double amount);
        QString getQStringForNetLAmountSave(long lAmount);
        QString getQStringForIDCodeSave(int IDCode);
        QString getQStringForAdditionalInfoSave(string additionalInfo);
        QString getQStringForTabIndexSave(int tabIndex);
        QString getQStringForPriorityLevelSave(PriorityLevel priorityLevel);
        QString getQStringForAPRSave(float APR);
        QString getQStringForPenaltySave(double penalty);
        QString getQStringForSavingsNatureSave(SavingsNature savingsNature);
        QString getQStringForDescriptionSave(string description);
        QString getQStringForItemIDSave(string itemID);
        QString getQStringForNumberSave(int number);
        QString getQStringForPriceSave(double price);
        QString getQStringForSubjectSave(string subject);
        QString getQStringForMessageSave(string message);
        QString getQStringForNumberOfMonthsSave(int numberOfMonths);
        void getIncomeStatement();
        void getBalanceSheet();
        char * convertStringToChar(string s);
        static QString reminderSubject;
        static QString reminderMessage;
        static bool reminderTimeReached;
        void reAddIncome(Income *income);
        void undoAddIncome();
        void reDeleteIncome(Income *income);
        void undoDeleteIncome(Income *income);
        void reAddExpense(Expense *expense);
        void undoAddExpense();
        void reDeleteExpense(Expense *expense);
        void undoDeleteExpense(Expense *expense);
        void reAddDebt(Debt *debt);
        void undoAddDebt();
        void reDeleteDebt(Debt *debt);
        void undoDeleteDebt(Debt *debt);
        void reAddSavings(Savings *savings);
        void undoAddSavings();
        void reDeleteSavings(Savings *savings);
        void undoDeleteSavings(Savings *savings);
        void reAddItem(Items *item);
        void undoAddItem();
        void reDeleteItem(Items *item);
        void undoDeleteItem(Items *items);
        void reAddReminder(Reminder *reminder);
        void undoAddReminder();
        void reDeleteReminder(Reminder *reminder);
        void undoDeleteReminder(Reminder *reminder);
    public slots:
        void updateRecentFileActions();
        void openDragAndDrop(QString fileName);
        //Qstring formatNameForStatement(QString originalQString);
        //void move(int x, int y);

    protected:
        //void mousePressEvent(QMouseEvent * event);
        //void enterEvent(QEvent * e);
        void closeEvent(QCloseEvent *e);
        //void mouseMoveEvent(QMouseEvent *event);
        void contextMenuEvent(QContextMenuEvent *event);

    private:
        BudgetDock * bd;
        SavingsDock * sd;
        InventoryDock * id;
        RemindersDock * rd;
        QToolBar *tbSide;
        QToolBar *tbTop;
        IncomeDialog *iDialog;
        EditedIncomeDialog *eiDialog;
        DebtDialog *dDialog;
        EditedDebtDialog *edDialog;
        ExpensesDialog *eDialog;
        EditedExpensesDialog *eeDialog;
        SaveMoneyDialog *smDialog;
        SavingsDialog *svDialog;
        OnboaderDialog *obDialog;
        EditedSavingsDialog *esvDialog;
        ItemDialog *itDialog;
        ItemDialog *eitDialog;
        ReminderDialog *rmDialog;
        ReminderDialog *ermDialog;
        GetMoneyDialog * gmDialog;
        IncomeStatementDialog *isDialog;
        AboutDialog *aDialog;
        DonateDialog *donDialog;
        BudgetTab bt;
        BudgetTab bt2;
        CakeTabWidget mainBudgetTab;
        BudgetFrame bf;
        BudgetFrame bf2;
        BudgetFrame *selectedBudgetFrame;
        IncomeList iList;
        DebtList dList;
        ExpenseList eList;
        SavingsList sList;
        ItemList itList;
        ReminderList rList;
        char cName[100];
        char cTheDate[11];
        char * cNature;
        char * cPriorityLevel;
        char cAmount[16];
        char cNumber[16];
        char cPrice[16];
        char cTax[11];
        char cAPR[11];
        char cNumberOfMonths[16];
        char cNetAmount[16];
        char cIDCode[16];
        char cAdditionalInfo[1000];
        char cPenalty[16];
        char cMonthlyIncome[16];
        char cMonthlyDebt[16];
        char cMonthlyExpenses[16];
        char cCurrentBalance[16];
        char cSavingsCurrentBalance[16];
        char cDescription[1000];
        char cSelectedSaving[100];
        char cSubject[200];
        char cMessage[1000];
        char cIncomeStatement[2000];
        char cTabTitle[8];
        char cSecondsForSave[3];
        char cMinutesForSave[3];
        char cHourForSave[3];
        char cDayForSave[3];
        char cMonthForSave[3];
        char cYearForSave[5];
        char cNameForSave[100];
        char cAmountForSave[16];
        char cTaxForSave[11];
        char cNetAmountForSave[16];
        char cIDCodeForSave[16];
        char cAdditionalInfoForSave[1000];
        char cTabIndexForSave[10];
        char cAPRForSave[11];
        char cPenaltyForSave[16];
        char cItemIDForSave[100];
        char * cNatureForSave;
        char * cPriorityLevelForSave;
        char * cSavingsNatureForSave;
        char cDescriptionForSave[1000];
        char cNumberForSave[10];
        char cNumberOfMonthsForSave[10];
        char cPriceForSave[16];
        char cSubjectForSave[200];
        char cMessageForSave[1000];
        int IDCode;
        char cItemID[100];
        string tableFocus;
        double monthlyIncome, monthlyDebt, monthlyExpenses, currentBalance, savingsBalance;
        long monthlyLIncome, monthlyLDebt, monthlyLExpenses, currentLBalance, savingsLBalance;
        //FiscalRecord *record;
        //MainWindow *window;
        char cPieName[100];
        int reminderIndex;
        CheckReminders *cr;
        BudgetTabList btl;
        //BudgetTabList btl2;
        MergeSortBudget *msBudget;
        bool workSpaceActive;
        bool documentSaved;
        bool documentModified;
        //bool documentOpen;
        QString saveFileName;
        QString fileName;
        SavingsAPR *sA;
        bool openCanceled;
        //CakeMessageBox *cmb;
        char convertedChar[1000];
        //QHttpResponseHeader itsResponse;
        bool containsLongIncome, containsLongDebt, containsLongExpense, containsLongAssSaving;
        string entryType;
        char cIncomeEntryName[100];
        int incomeEntryLocalIDCode;
        int incomeEntryYear;
        int incomeEntryMonth;
        int incomeEntryDay;
        Nature incomeEntryNature;
        double dIncomeEntryAmount;
        long lIncomeEntryAmount;
        float incomeEntryTax;
        char cIncomeEntryAdditionalInfo[1000];
        int debtEntryLocalIDCode;
        char cDebtEntryName[1000];
        int debtEntryYear;
        int debtEntryMonth;
        int debtEntryDay;
        PriorityLevel debtEntryPLevel;
        double dDebtEntryAmount;
        long lDebtEntryAmount;
        float debtEntryAPR;
        char cDebtEntryAdditionalInfo[1000];
        int debtEntryNumberOfMonths;
        int expensesEntryLocalIDCode;
        char cExpensesEntryName[100];
        int expensesEntryYear;
        int expensesEntryMonth;
        int expensesEntryDay;
        PriorityLevel expensesEntryPLevel;
        double dExpensesEntryAmount;
        long lExpensesEntryAmount;
        double expensesEntryPenalty;
        char cExpensesEntryAdditionalInfo[1000];
        char cSavingsEntryName[100];
        SavingsNature savingsEntryNature;
        double dSavingsEntryAmount;
        long lSavingsEntryAmount;
        float savingsEntryAPR;
        int savingsEntryYear;
        int savingsEntryMonth;
        int savingsEntryDay;
        char cSavingsEntryDescription[1000];
        char cItemEntryName[100];
        char cItemEntryItemID[100];
        int itemEntryNumber;
        double itemEntryPrice;
        char cRemindersEntrySubject[200];
        int remindersEntryYear;
        int remindersEntryMonth;
        int remindersEntryDay;
        int remindersEntryHour;
        int remindersEntryMinute;
        int remindersEntrySecond;
        char cRemidersEntryMessage[1000];
        QMenu *popupMenu;
        //QPoint popupPoint;
        QMenu *fileMenu;
        QMenu *editMenu;
        QMenu *viewMenu;
        QMenu *toolsMenu;
        QMenu *helpMenu;
        QUndoStack undoStack;
        //const AddIncomeCommand *aic;
        int IDForIncomeOnStack;
        QAction* clickCut;
        QAction* clickCopy;
        QAction* clickPaste;
        QAction *cutPopupAction;
        QAction *copyPopupAction;
        QAction *pastePopupAction;
        int IDForExpenseOnStack;
        int IDForDebtOnStack;
        int IDForSavingsOnStack;
        int IDForItemOnStack;
        int IDForReminderOnStack;
        QAction* clickBudget;
        QAction* clickSavings;
        QAction* clickInventory;
        QAction* clickReminders;
        enum { MaxRecentFiles = 5 };
        QAction *recentFileActs[MaxRecentFiles];
        QAction *separatorAct;
        QString curFile;
        QString fileNameWithoutFullPath;
        QAction *onboaderAction;

    private slots:
        void showOnboarder();
        void disableAffectedMenus();
        void enableAffectedMenus();
        void closeOnboaderDialog();
        void viewBudget();
        void viewSavings();
        void selectedSavingsIcon();
        void viewInventory();
        void viewReminders();
        void saveMoneyClick();
        void editSelectedItem();
        void insertEditedIncomeDialogValues();
        void closeEditedIncomeDialog();
        //void addOnSelectedItem();
        void setIncomeTableFocus();
        void setDebtTableFocus();
        void insertEditedDebtDialogValues();
        void closeEditedDebtDialog();
        void setExpensesTableFocus();
        void closeEditedExpensesDialog();
        void insertEditedExpensesDialogValues();
        void editSelectedSavings();
        void setSavingsTableFocus();
        void closeEditedSavingsDialog();
        void insertEditedSavingsDialogValues();
        void closeSaveMoneyDialog();
        void insertSaveMoneyValues();
        void getMoneyClick();
        void closeGetMoneyDialog();
        void insertGetMoneyValues();
        void setInventoryTableFocus();
        void editSelectedInventoryItem();
        void closeEditedItemDialog();
        void insertEditedItemDialogValues();
        void setRemindersTableFocus();
        void editSelectedReminder();
        void insertEditedReminderDialogValues();
        void closeEditedReminderDialog();
        void save();
        void saveAs();
        void open(QString localfileName, QSettings *mySettings);
        void openGeneric();
        void openFromFileName(QString fileName);
        void close();
        void quit();
        void newFiscalRecord();
        void loadPieChart();
        void showIncomeStatement();
        void showCashFlowStatement();
        void showBalanceSheet();
        void closeIncomeStatement();
        void selectClickedReminderBudget();
        void selectClickedReminderSavings();
        void selectClickedReminderInventory();
        void selectClickedReminderReminders();
        void activateCurrentBudgetTab();
        void incomeStatementFilePrintPreview();
        void incomeStatementPrintPreview(QPrinter *);
        void incomeStatementFilePrint();
        void balanceSheetFilePrintPreview();
        void balanceSheetPrintPreview(QPrinter *);
        void balanceSheetFilePrint();
        void popCakeMessageBox();
        void popAboutMessageBox();
        void closeAboutDialog();
        void popDonateMessageBox();
        void closeDonateDialog();
        void openManual();
        void openLicense();
        void openSample();
        void openSupport();
        void runDonate();
        //void readResponseHeader(const QHttpResponseHeader & response);
        void showContextMenu(const QPoint &);
        void editEntry();
        void copyEntry();
        void pasteEntry();
        void cutEntry();
        void openRecentFile();
        void setCurrentFile(const QString &fileName);
        void loadFile(const QString &fileName);
        QString strippedName(const QString &fullFileName);
        void dragEnterEvent(QDragEnterEvent *e);
        void dropEvent(QDropEvent *e);
        bool eventFilter(QObject* o, QEvent* e);
        // FOR MAINWIN void deleteEntry();
};

#endif // MAINBUDGET_H_INCLUDED
