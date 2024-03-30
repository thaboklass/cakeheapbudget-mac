#include "main_window.h"

/**
 The constructor for the MainWin class.
 
 @param  none.
 */
MainWin::MainWin()
{
    // Create the MainBudget UI and display it.
    mb = new MainBudget;
    mb->show();
    
    //setUnifiedTitleAndToolBarOnMac(true);
    
    // Connect the side 'add' and 'delete' buttons with
    // their relevant slots
    connect(mb->bd->addButton, SIGNAL(clicked()), this, SLOT(addOnSelectedItem()));
    connect(mb->bd->deleteButton, SIGNAL(clicked()), this, SLOT(deleteSelectedItem()));
    
    // Connect the 'Add Income', 'Add Debt' and 'Add Expenses'
    // buttons with their slots
    connect(mb->selectedBudgetFrame->addIcomeButtom_2, SIGNAL(clicked()), this, SLOT(addIncomeClick()));
    connect(mb->selectedBudgetFrame->addExpenseButtom_2, SIGNAL(clicked()), this, SLOT(addExpenseClick()));
    connect(mb->selectedBudgetFrame->addDebtButton_2, SIGNAL(clicked()), this, SLOT(addDebtClick()));

    // Connect the 'Add Savings' and 'Delete Savings'
    // buttons with their slots
    connect(mb->sd->addButton, SIGNAL(clicked()), this, SLOT(addSavingsClick()));
    connect(mb->sd->deleteButton, SIGNAL(clicked()), this, SLOT(deleteSelectedSavings()));

    // Connect the 'Add Item' and 'Delete Item'
    // buttons with their slots
    connect(mb->id->addButton, SIGNAL(clicked()), this, SLOT(addItemClick()));
    connect(mb->id->deleteButton, SIGNAL(clicked()), this, SLOT(deleteSelectedInventoryItem()));

    // Connect the 'Add Item' and 'Delete Item'
    // buttons with their slots
    connect(mb->rd->addButton, SIGNAL(clicked()), this, SLOT(addReminderClick()));
    connect(mb->rd->deleteButton, SIGNAL(clicked()), this, SLOT(deleteSelectedReminder()));

    // Connect the 'Add Item' and 'Delete Item'
    // buttons with their slots
    connect(&mb->mainBudgetTab, SIGNAL(currentChanged(int)), this, SLOT(activateCurrentBudgetTabForMainWin()));
    
    // Add actions and separators to the edit
    // menu
    mb->editMenu->addSeparator();
    QAction *undoAction = mb->undoStack.createUndoAction(this);
    undoAction->setText(QString("Undo"));
    mb->editMenu->addAction(undoAction);
    undoAction->setShortcut(QKeySequence(tr("Ctrl+Z")));
    /*QAction *redoAction = mb->undoStack.createRedoAction(this);
    redoAction->setText(QString("Redo"));
    mb->editMenu->addAction(redoAction);
    redoAction->setShortcut(QKeySequence(tr("Ctrl+Y")));*/
    mb->editMenu->addSeparator();
}


/**
 The destructor for the MainWin class.
 */
MainWin::~MainWin()
{
    delete mb;
    mb = 0;
}


/**
 This opens a dialog that adds a new income.
 
 @param  none.
 @return nothing.
 */
void MainWin::addIncomeClick()
{
    mb->iDialog = new IncomeDialog(mb);
    QDate qCurrentDate = QDate::currentDate();
    mb->iDialog->dateEdit->setDate(qCurrentDate);
    mb->iDialog->setModal(true);
    //mb->iDialog->setVisible(true);
    mb->iDialog->setWindowFlags(Qt::Sheet);
    mb->iDialog->setWindowTitle("Income Info");
    mb->iDialog->show();
    connect(mb->iDialog->okButton, SIGNAL(clicked()), this, SLOT(insertIncomeDialogValues()));
    connect(mb->iDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeIncomeDialog()));
}


/**
 Inserts an income from dialog values.
 
 @param  none.
 @return nothing.
 */
void MainWin::insertIncomeDialogValues()
{
    QDate qdDate = mb->iDialog->dateEdit->date();
    
    if (mb->allowBudgetAddition(qdDate)) {
        QString qsName = mb->iDialog->nameLineEdit->displayText();
        QChar * qcName = qsName.data();
        char cName[qsName.size() + 1];
        
        for (int i = 0; i < qsName.size() + 1; i++)
        {
            cName[i] = qcName->toAscii();
            ++qcName;
        }
        
        string name = string(cName);
        
        int year = qdDate.year();
        int month = qdDate.month();
        int day = qdDate.day();
        Date date(year, month, day, 0, 0, 0);
        
        if (!mb->tabTitleExists(qdDate))
        {
            mb->mainBudgetTab.insertTab(0, new BudgetFrame, mb->getTabBarDate(qdDate));
            mb->mainBudgetTab.setCurrentIndex(0);
            mb->selectedBudgetFrame->setMonth(month);
            mb->selectedBudgetFrame->setYear(year);
            if (mb->btl.size() > 0)
                mb->btl.clear();
            
            for (int i = 0; i < mb->mainBudgetTab.count(); i++)
            {
                mb->mainBudgetTab.setCurrentIndex(i);
                mb->btl.push_back(BudgetTabItem(mb->convertQStringToString(mb->mainBudgetTab.tabText(i)), mb->selectedBudgetFrame->getMonth(),
                                                mb->selectedBudgetFrame->getYear(), i));
            }
            
            mb->msBudget = new MergeSortBudget(mb->btl);
            mb->msBudget->displayElements();
            mb->msBudget->sort(mb->btl);
            mb->msBudget->displayElements();
            
            for (int i = 0; i < mb->btl.size(); i++)
            {
                mb->mainBudgetTab.setCurrentIndex(i);
                mb->mainBudgetTab.setTabText(i, mb->convertStringToQString(mb->msBudget->data.at(i).getTabTitle()));
                mb->selectedBudgetFrame->setMonth(mb->msBudget->data.at(i).getMonth());
                mb->selectedBudgetFrame->setYear(mb->msBudget->data.at(i).getYear());
            }
        }
        
        QString qsNature = mb->iDialog->natureComboBox->currentText();
        QChar * qcNature = qsNature.data();
        char cNature[qsNature.size() + 1];
        
        for (int j = 0; j < qsNature.size() + 1; j++)
        {
            cNature[j] = qcNature->toAscii();
            ++qcNature;
        }
        
        Nature nature;
        switch (cNature[2]) {
            case 'L': nature = SALARY; break;
            case 'V': nature = DIVIDEND; break;
            case 'O': nature = STOCK_SALE; break;
            case 'U': nature = IOU; break;
            case 'P': nature = DIP; break;
            case 'H': nature = OTHER; break;
            default: ;
        }
        
        
        QString qsAmount = mb->iDialog->amountLineEdit->text();
        QChar * qcAmount = qsAmount.data();
        char cAmount[100];
        int k = 0;
        while (!qcAmount->isNull())
        {
            cAmount[k] = qcAmount->toAscii();
            ++qcAmount;
            k++;
        }
        
        double amount = atof(cAmount);
        long lAmount = strtold(cAmount, NULL);
        
        QString qsTax = mb->iDialog->taxLineEdt->text();
        QChar * qcTax = qsTax.data();
        char cTax[100];
        int l = 0;
        while (!qcTax->isNull())
        {
            cTax[l] = qcTax->toAscii();
            ++qcTax;
            l++;
        }
        float tax = atof(cTax);
        
        QString qsAdditionalInfo = mb->iDialog->additionalInfoTextEdit->toPlainText();
        QChar * qcAdditionalInfo = qsAdditionalInfo.data();
        char cAdditionalInfo[qsAdditionalInfo.size() + 1];
        
        for (int m = 0; m < qsAdditionalInfo.size() + 1; m++)
        {
            cAdditionalInfo[m] = qcAdditionalInfo->toAscii();
            ++qcAdditionalInfo;
        }
        
        string additionalInfo = string(cAdditionalInfo);
        
        mb->undoStack.push(new AddIncomeCommand(mb, name, amount, lAmount, false, 0, date,
                                                nature, tax, additionalInfo , mb->mainBudgetTab.currentIndex(), mb->iList.size()));
        
        mb->IDForIncomeOnStack = mb->iList.size();
        
        //mb->iDialog->setModal(false);
        mb->iDialog->done(0);
        
        for (int j = 0; j < mb->btl.size(); j++)
        {
            shuffleIncomeTabs(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear(),
                              mb->msBudget->getSortedTabIndex(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear()), mb->iList);
            shuffleDebtTabs(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear(),
                            mb->msBudget->getSortedTabIndex(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear()), mb->dList);
            shuffleExpenseTabs(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear(),
                               mb->msBudget->getSortedTabIndex(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear()), mb->eList);
        }
        
        mb->populateIncomeTable(mb->iList);
        mb->populateDebtTable(mb->dList);
        mb->populateExpensesTable(mb->eList);
        
        mb->monthlyIncome = 0;
        mb->monthlyLIncome = 0;
        for (int i = 0; i < mb->iList.size(); i++)
        {
            if (mb->iList.at(i).getTabIndex() == mb->mainBudgetTab.currentIndex())
            {
                if (mb->iList.at(i).getAmountType() == "long")
                    mb->containsLongIncome = true;
                mb->monthlyIncome += mb->iList.at(i).getNetAmount();
                mb->monthlyLIncome += mb->iList.at(i).getNetAmount() + mb->iList.at(i).getNetLAmount();
            }
        }
        //if (mb->containsLongIncome)
            mb->bd->totalMonthlyIncomeLineEdit->setText(mb->getCharAmountForMonthlyLIncome(mb->monthlyLIncome));
        //else
        //    mb->bd->totalMonthlyIncomeLineEdit->setText(mb->getCharAmountForMonthlyIncome(mb->monthlyIncome));
        mb->setCurrentBalance();
        
        mb->documentModified = true;
        if (mb->fileNameWithoutFullPath == "")
            mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
        else
            mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
    } else {
        mb->iDialog->done(0);
        cout << "Wrong date" << endl;
        QMessageBox *msgBox = new QMessageBox(mb);
        msgBox->setText("The date you entered exceeds the 1 year limit for a fiscal year record. Create a new fiscal year record.");
        msgBox->setWindowModality(Qt::WindowModal);
        msgBox->exec();
    }
}


/**
 Adds a new entity on the selected type.
 
 @param  none.
 @return nothing.
 */
void MainWin::addOnSelectedItem()
{
    if (mb->selectedBudgetFrame->incomeTable_2->currentItem() && (mb->tableFocus == "income"))
        addIncomeClick();
    if (mb->selectedBudgetFrame->debtTable_2->currentItem() && (mb->tableFocus == "debt"))
        addDebtClick();
    if (mb->selectedBudgetFrame->expensesTable_2->currentItem() && (mb->tableFocus == "expenses"))
        addExpenseClick();
}


/**
 This closes the income dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::closeIncomeDialog()
{
    //mb->iDialog->setModal(false);
    //mb->documentModified = false;
    mb->iDialog->done(0);
}


/**
 Deletes the selected item.
 
 @param  none.
 @return nothing.
 */
void MainWin::deleteSelectedItem()
{
    if (mb->selectedBudgetFrame->incomeTable_2->currentItem() && (mb->tableFocus == "income"))
    {
        QMessageBox *msgBox = new QMessageBox(mb);
        msgBox->setWindowTitle("Income item deletion");
        msgBox->setWindowIcon(QIcon("images/cake_heap_icon.png"));
        msgBox->setText("You are about to delete an income item.");
        msgBox->setInformativeText("Are you sure you want to delete this item?");
        msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox->setDefaultButton(QMessageBox::No);
        msgBox->setWindowModality(Qt::WindowModal);
        int ret = msgBox->exec();
        
        if (ret == QMessageBox::Yes)
        {
            int index = mb->selectedBudgetFrame->incomeTable_2->currentRow();
            QString qsLocalIDCode = mb->selectedBudgetFrame->incomeTable_2->item(index, 6)->text();
            QChar * qcLocalIDCode = qsLocalIDCode.data();
            char cLocalIDCode[16];
            int i = 0;
            while (!qcLocalIDCode->isNull())
            {
                cLocalIDCode[i] = qcLocalIDCode->toAscii();
                ++qcLocalIDCode;
                i++;
            }
            
            int localIDCode = atoi(cLocalIDCode);
            double emptyD = 0;
            Income income("", emptyD, false, 0, Date(0, 0, 0, 0, 0, 0),
                OTHER, 0, "", 0);

            for (int j = 0; j < mb->iList.size(); j++)
            {
                if (mb->iList.at(j).getIDCode() == localIDCode)
                {
                    income = mb->iList.at(j);
                }
            }

            mb->undoStack.push(new DeleteIncomeCommand(mb, income.getName(), income.getAmount(), income.getLAmount(), false, 0, income.getReceivedDate(),
                income.getNature(), income.getTax(), income.getAdditionalInfo(), mb->mainBudgetTab.currentIndex(), localIDCode));

            mb->populateIncomeTable(mb->iList);
            mb->monthlyIncome = 0;
            mb->monthlyLIncome = 0;
            for (int i = 0; i < mb->iList.size(); i++)
            {
                if (mb->iList.at(i).getTabIndex() == mb->mainBudgetTab.currentIndex())
                {
                    if (mb->iList.at(i).getAmountType() == "long")
                        mb->containsLongIncome = true;
                    mb->monthlyIncome += mb->iList.at(i).getNetAmount();
                    mb->monthlyLIncome += mb->iList.at(i).getNetAmount() + mb->iList.at(i).getNetLAmount();
                }
            }
            //if (mb->containsLongIncome)
                mb->bd->totalMonthlyIncomeLineEdit->setText(mb->getCharAmountForMonthlyLIncome(mb->monthlyLIncome));
            //else
            //    mb->bd->totalMonthlyIncomeLineEdit->setText(mb->getCharAmountForMonthlyIncome(mb->monthlyIncome));
            mb->setCurrentBalance();
            
            mb->documentModified = true;
            if (mb->fileNameWithoutFullPath == "")
                mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
            else
                mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
        }
    }

    if (mb->selectedBudgetFrame->debtTable_2->currentItem() && (mb->tableFocus == "debt"))
    {
        QMessageBox *msgBox = new QMessageBox(mb);
        msgBox->setWindowTitle("Debt item deletion");
        msgBox->setWindowIcon(QIcon("images/cake_heap_icon.png"));
        msgBox->setText("You are about to delete a debt item.");
        msgBox->setInformativeText("Are you sure you want to delete this item?");
        msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox->setDefaultButton(QMessageBox::No);
        msgBox->setWindowModality(Qt::WindowModal);
        int ret = msgBox->exec();
        
        if (ret == QMessageBox::Yes)
        {
            int index = mb->selectedBudgetFrame->debtTable_2->currentRow();
            QString qsLocalIDCode = mb->selectedBudgetFrame->debtTable_2->item(index, 6)->text();
            QChar * qcLocalIDCode = qsLocalIDCode.data();
            char cLocalIDCode[16];
            int i = 0;
            while (!qcLocalIDCode->isNull())
            {
                cLocalIDCode[i] = qcLocalIDCode->toAscii();
                ++qcLocalIDCode;
                i++;
            }
            
            int localIDCode = atoi(cLocalIDCode);
            double emptyD = 0;
            Debt debt("", emptyD, false, 0, NONE, Date(0, 0, 0, 0, 0, 0), "", 0, 0);

            for (int j = 0; j < mb->dList.size(); j++)
            {
                if (mb->dList.at(j).getIDCode() == localIDCode)
                {
                    debt = mb->dList.at(j);
                }
            }

            mb->undoStack.push(new DeleteDebtCommand(mb, debt.getName(), debt.getAmount(), debt.getLAmount(), true, debt.getAPR(), debt.getPriorityLevel(),
                debt.getDueDate(), debt.getAdditionalInfo(), debt.getNumberOfMonths(), mb->mainBudgetTab.currentIndex(), localIDCode));

            mb->populateDebtTable(mb->dList);

            mb->monthlyDebt = 0;
            mb->monthlyLDebt = 0;
            for (int i = 0; i < mb->dList.size(); i++)
            {
                if (mb->dList.at(i).getTabIndex() == mb->mainBudgetTab.currentIndex())
                {
                    if (mb->dList.at(i).getAmountType() == "long")
                        mb->containsLongDebt = true;
                    mb->monthlyDebt += mb->dList.at(i).getNetAmount();
                    mb->monthlyLDebt += mb->dList.at(i).getNetAmount() + mb->dList.at(i).getNetLAmount();
                }
            }
            //if (mb->containsLongDebt)
                mb->bd->totalMonthlyDebtLineEdit->setText(mb->getCharAmountForMonthlyLDebt(mb->monthlyLDebt));
            //else
            //    mb->bd->totalMonthlyDebtLineEdit->setText(mb->getCharAmountForMonthlyDebt(mb->monthlyDebt));
            mb->setCurrentBalance();
            
            mb->documentModified = true;
            if (mb->fileNameWithoutFullPath == "")
                mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
            else
                mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
        }
    }

    if (mb->selectedBudgetFrame->expensesTable_2->currentItem() && (mb->tableFocus == "expenses"))
    {
        QMessageBox *msgBox = new QMessageBox(mb);
        msgBox->setWindowTitle("Expenses item deletion");
        msgBox->setWindowIcon(QIcon("images/cake_heap_icon.png"));
        msgBox->setText("You are about to delete an expense item.");
        msgBox->setInformativeText("Are you sure you want to delete this item?");
        msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox->setDefaultButton(QMessageBox::No);
        msgBox->setWindowModality(Qt::WindowModal);
        int ret = msgBox->exec();
        
        if (ret == QMessageBox::Yes)
        {
            int index = mb->selectedBudgetFrame->expensesTable_2->currentRow();
            QString qsLocalIDCode = mb->selectedBudgetFrame->expensesTable_2->item(index, 6)->text();
            QChar * qcLocalIDCode = qsLocalIDCode.data();
            char cLocalIDCode[16];
            int i = 0;
            while (!qcLocalIDCode->isNull())
            {
                cLocalIDCode[i] = qcLocalIDCode->toAscii();
                ++qcLocalIDCode;
                i++;
            }
            
            int localIDCode = atoi(cLocalIDCode);
            double emptyD = 0;
            Expense expense("", emptyD, NONE, 0, Date(0, 0, 0, 0, 0, 0), "", 0);

            for (int j = 0; j < mb->eList.size(); j++)
            {
                if (mb->eList.at(j).getIDCode() == localIDCode)
                {
                    expense = mb->eList.at(j);
                }
            }

            mb->undoStack.push(new DeleteExpenseCommand(mb, expense.getName(), expense.getAmount(), expense.getLAmount(), expense.getPriorityLevel(), expense.getPenalty(),
                expense.getDueDate(), expense.getAdditionalInfo(), mb->mainBudgetTab.currentIndex(), localIDCode));


            mb->populateExpensesTable(mb->eList);
            mb->monthlyExpenses = 0;
            mb->monthlyLExpenses = 0;
            for (int i = 0; i < mb->eList.size(); i++)
            {
                if (mb->eList.at(i).getTabIndex() == mb->mainBudgetTab.currentIndex())
                {
                    if (mb->eList.at(i).getAmountType() == "long")
                        mb->containsLongExpense = true;
                    mb->monthlyExpenses += mb->eList.at(i).getNetAmount();
                    mb->monthlyLExpenses += mb->eList.at(i).getNetAmount() + mb->eList.at(i).getNetLAmount();
                }
            }
            //if (mb->containsLongExpense)
                mb->bd->totalMonthlyExpensesLineEdit->setText(mb->getCharAmountForMonthlyLExpenses(mb->monthlyLExpenses));
            //else
            //    mb->bd->totalMonthlyExpensesLineEdit->setText(mb->getCharAmountForMonthlyExpenses(mb->monthlyExpenses));

            mb->setCurrentBalance();
            
            mb->documentModified = true;
            if (mb->fileNameWithoutFullPath == "")
                mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
            else
                mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
        }
    }
}


/**
 Opens a new expense dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::addExpenseClick()
{
    mb->eDialog = new ExpensesDialog(mb);
    QDate qCurrentDate = QDate::currentDate();
    mb->eDialog->dueDateEdit->setDate(qCurrentDate);
    mb->eDialog->setModal(true);
    //mb->eDialog->setVisible(true);
    mb->eDialog->setWindowFlags(Qt::Sheet);
    mb->eDialog->setWindowTitle("Expense Info");
    mb->eDialog->show();
    connect(mb->eDialog->okButton, SIGNAL(clicked()), this, SLOT(insertExpensesDialogValues()));
    connect(mb->eDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeExpensesDialog()));
}


/**
 Inserts a new expense from the dialog values.
 
 @param  none.
 @return nothing.
 */
void MainWin::insertExpensesDialogValues()
{
    QDate qdDate = mb->eDialog->dueDateEdit->date();
    
    if (mb->allowBudgetAddition(qdDate)) {
        QString qsName = mb->eDialog->nameLineEdit->displayText();
        QChar * qcName = qsName.data();
        char cName[qsName.size() + 1];
        
        for (int i = 0; i < qsName.size() + 1; i++)
        {
            cName[i] = qcName->toAscii();
            ++qcName;
        }
        
        string name = string(cName);
        
        int year = qdDate.year();
        int month = qdDate.month();
        int day = qdDate.day();
        Date date(year, month, day, 0, 0, 0);
        
        if (!mb->tabTitleExists(qdDate))
        {
            mb->mainBudgetTab.insertTab(0, new BudgetFrame, mb->getTabBarDate(qdDate));
            mb->mainBudgetTab.setCurrentIndex(0);
            mb->selectedBudgetFrame->setMonth(month);
            mb->selectedBudgetFrame->setYear(year);
            if (mb->btl.size() > 0)
                mb->btl.clear();
            
            for (int i = 0; i < mb->mainBudgetTab.count(); i++)
            {
                mb->mainBudgetTab.setCurrentIndex(i);
                mb->btl.push_back(BudgetTabItem(mb->convertQStringToString(mb->mainBudgetTab.tabText(i)), mb->selectedBudgetFrame->getMonth(),
                                                mb->selectedBudgetFrame->getYear(), i));
            }
            
            mb->msBudget = new MergeSortBudget(mb->btl);
            mb->msBudget->displayElements();
            mb->msBudget->sort(mb->btl);
            mb->msBudget->displayElements();
            
            for (int i = 0; i < mb->btl.size(); i++)
            {
                mb->mainBudgetTab.setCurrentIndex(i);
                mb->mainBudgetTab.setTabText(i, mb->convertStringToQString(mb->msBudget->data.at(i).getTabTitle()));
                mb->selectedBudgetFrame->setMonth(mb->msBudget->data.at(i).getMonth());
                mb->selectedBudgetFrame->setYear(mb->msBudget->data.at(i).getYear());
            }
        }
        
        QString qsPriorityLevel = mb->eDialog->priorityLevelComboBox->currentText();
        QChar * qcPriorityLevel = qsPriorityLevel.data();
        char cPriorityLevel[qsPriorityLevel.size() + 1];
        
        for (int j = 0; j < qsPriorityLevel.size() + 1; j++)
        {
            cPriorityLevel[j] = qcPriorityLevel->toAscii();
            ++qcPriorityLevel;
        }
        
        PriorityLevel pLevel;
        switch (cPriorityLevel[0]) {
            case 'H': pLevel = HIGH; break;
            case 'M': pLevel = MEDIUM; break;
            case 'L': pLevel = LOW; break;
            case 'N': pLevel = NONE; break;
            default: ;
        }
        
        
        QString qsAmount = mb->eDialog->amountLineEdit->text();
        QChar * qcAmount = qsAmount.data();
        char cAmount[100];
        int k = 0;
        while (!qcAmount->isNull())
        {
            cAmount[k] = qcAmount->toAscii();
            ++qcAmount;
            k++;
        }
        double amount = atof(cAmount);
        long lAmount = strtold(cAmount, NULL);
        
        QString qsPenalty = mb->eDialog->penaltyLineEdit->text();
        QChar * qcPenalty = qsPenalty.data();
        char cPenalty[100];
        int n = 0;
        while (!qcPenalty->isNull())
        {
            cPenalty[n] = qcPenalty->toAscii();
            ++qcPenalty;
            n++;
        }
        double penalty = atof(cPenalty);
        
        QString qsAdditionalInfo = mb->eDialog->additionalInfoTextEdit->toPlainText();
        QChar * qcAdditionalInfo = qsAdditionalInfo.data();
        char cAdditionalInfo[qsAdditionalInfo.size() + 1];
        
        for (int m = 0; m < qsAdditionalInfo.size() + 1; m++)
        {
            cAdditionalInfo[m] = qcAdditionalInfo->toAscii();
            ++qcAdditionalInfo;
        }
        
        string additionalInfo = string(cAdditionalInfo);
        
        mb->undoStack.push(new AddExpenseCommand(mb, name, amount, lAmount, pLevel, penalty,
                                                 date, additionalInfo, mb->mainBudgetTab.currentIndex(), mb->eList.size()));
        
        mb->IDForExpenseOnStack = mb->eList.size();
        
        //mb->eDialog->setModal(false);
        mb->eDialog->done(0);
        
        for (int j = 0; j < mb->btl.size(); j++)
        {
            shuffleExpenseTabs(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear(),
                               mb->msBudget->getSortedTabIndex(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear()), mb->eList);
            shuffleIncomeTabs(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear(),
                              mb->msBudget->getSortedTabIndex(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear()), mb->iList);
            shuffleDebtTabs(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear(),
                            mb->msBudget->getSortedTabIndex(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear()), mb->dList);
        }
        
        mb->populateExpensesTable(mb->eList);
        mb->populateIncomeTable(mb->iList);
        mb->populateDebtTable(mb->dList);
        mb->monthlyExpenses = 0;
        mb->monthlyLExpenses = 0;
        for (int i = 0; i < mb->eList.size(); i++)
        {
            if (mb->eList.at(i).getTabIndex() == mb->mainBudgetTab.currentIndex())
            {
                if (mb->eList.at(i).getAmountType() == "long")
                    mb->containsLongExpense = true;
                mb->monthlyExpenses += mb->eList.at(i).getNetAmount();
                mb->monthlyLExpenses += mb->eList.at(i).getNetAmount() + mb->eList.at(i).getNetLAmount();
            }
        }
        //if (mb->containsLongExpense)
            mb->bd->totalMonthlyExpensesLineEdit->setText(mb->getCharAmountForMonthlyLExpenses(mb->monthlyLExpenses));
        //else
        //    mb->bd->totalMonthlyExpensesLineEdit->setText(mb->getCharAmountForMonthlyExpenses(mb->monthlyExpenses));
        
        mb->setCurrentBalance();
        
        mb->documentModified = true;
        if (mb->fileNameWithoutFullPath == "")
            mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
        else
            mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
    } else {
        mb->eDialog->done(0);
        QMessageBox *msgBox = new QMessageBox(mb);
        msgBox->setText("The date you entered exceeds the 1 year limit for a fiscal year record. Create a new fiscal year record.");
        msgBox->setWindowModality(Qt::WindowModal);
        msgBox->exec();
    }
}


/**
 This closes the expenses dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::closeExpensesDialog()
{
    //mb->eDialog->setModal(false);
    mb->eDialog->done(0);
}


/**
 Opens a new debt dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::addDebtClick()
{
    mb->dDialog = new DebtDialog(mb);
    QDate qCurrentDate = QDate::currentDate();
    mb->dDialog->dueDateEdit->setDate(qCurrentDate);
    mb->dDialog->setModal(true);
    //mb->dDialog->setVisible(true);
    mb->dDialog->setWindowFlags(Qt::Sheet);
    mb->dDialog->setWindowTitle("Debt Info");
    mb->dDialog->show();
    connect(mb->dDialog->okButton, SIGNAL(clicked()), this, SLOT(insertDebtDialogValues()));
    connect(mb->dDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeDebtDialog()));
}


/**
 Inserts a new debt from the dialog values.
 
 @param  none.
 @return nothing.
 */
void MainWin::insertDebtDialogValues()
{
    QDate qdDate = mb->dDialog->dueDateEdit->date();
    
    if (mb->allowBudgetAddition(qdDate)) {
        QString qsName = mb->dDialog->nameLineEdit->displayText();
        QChar * qcName = qsName.data();
        char cName[qsName.size() + 1];
        
        for (int i = 0; i < qsName.size() + 1; i++)
        {
            cName[i] = qcName->toAscii();
            ++qcName;
        }
        
        string name = string(cName);
        
        int year = qdDate.year();
        int month = qdDate.month();
        int day = qdDate.day();
        Date date(year, month, day, 0, 0, 0);
        
        if (!mb->tabTitleExists(qdDate))
        {
            mb->mainBudgetTab.insertTab(0, new BudgetFrame, mb->getTabBarDate(qdDate));
            mb->mainBudgetTab.setCurrentIndex(0);
            mb->selectedBudgetFrame->setMonth(month);
            mb->selectedBudgetFrame->setYear(year);
            if (mb->btl.size() > 0)
                mb->btl.clear();
            
            for (int i = 0; i < mb->mainBudgetTab.count(); i++)
            {
                mb->mainBudgetTab.setCurrentIndex(i);
                mb->btl.push_back(BudgetTabItem(mb->convertQStringToString(mb->mainBudgetTab.tabText(i)), mb->selectedBudgetFrame->getMonth(),
                                                mb->selectedBudgetFrame->getYear(), i));
            }
            
            mb->msBudget = new MergeSortBudget(mb->btl);
            mb->msBudget->displayElements();
            mb->msBudget->sort(mb->btl);
            mb->msBudget->displayElements();
            
            for (int i = 0; i < mb->btl.size(); i++)
            {
                mb->mainBudgetTab.setCurrentIndex(i);
                mb->mainBudgetTab.setTabText(i, mb->convertStringToQString(mb->msBudget->data.at(i).getTabTitle()));
                mb->selectedBudgetFrame->setMonth(mb->msBudget->data.at(i).getMonth());
                mb->selectedBudgetFrame->setYear(mb->msBudget->data.at(i).getYear());
            }
        }
        
        QString qsPriorityLevel = mb->dDialog->priorityLevelComboBox->currentText();
        QChar * qcPriorityLevel = qsPriorityLevel.data();
        char cPriorityLevel[qsPriorityLevel.size() + 1];
        
        for (int j = 0; j < qsPriorityLevel.size() + 1; j++)
        {
            cPriorityLevel[j] = qcPriorityLevel->toAscii();
            ++qcPriorityLevel;
        }
        
        PriorityLevel pLevel;
        switch (cPriorityLevel[0]) {
            case 'H': pLevel = HIGH; break;
            case 'M': pLevel = MEDIUM; break;
            case 'L': pLevel = LOW; break;
            case 'N': pLevel = NONE; break;
            default: ;
        }
        
        
        QString qsAmount = mb->dDialog->amountLineEdit->text();
        QChar * qcAmount = qsAmount.data();
        char cAmount[100];
        int k = 0;
        while (!qcAmount->isNull())
        {
            cAmount[k] = qcAmount->toAscii();
            ++qcAmount;
            k++;
        }
        double amount = atof(cAmount);
        long lAmount = strtold(cAmount, NULL);
        
        QString qsAPR = mb->dDialog->APRLineEdit->text();
        QChar * qcAPR = qsAPR.data();
        char cAPR[100];
        int l = 0;
        while (!qcAPR->isNull())
        {
            cAPR[l] = qcAPR->toAscii();
            ++qcAPR;
            l++;
        }
        float APR = atof(cAPR);
        
        QString qsAdditionalInfo = mb->dDialog->additionalInfoTextEdit->toPlainText();
        QChar * qcAdditionalInfo = qsAdditionalInfo.data();
        char cAdditionalInfo[qsAdditionalInfo.size() + 1];
        
        for (int m = 0; m < qsAdditionalInfo.size() + 1; m++)
        {
            cAdditionalInfo[m] = qcAdditionalInfo->toAscii();
            ++qcAdditionalInfo;
        }
        
        string additionalInfo = string(cAdditionalInfo);
        
        QString qsNumberOfMonths = mb->dDialog->numberOfMonthsLineEdit->text();
        QChar * qcNumberOfMonths = qsNumberOfMonths.data();
        char cNumberOfMonths[100];
        int n = 0;
        while (!qcNumberOfMonths->isNull())
        {
            cNumberOfMonths[n] = qcNumberOfMonths->toAscii();
            ++qcNumberOfMonths;
            n++;
        }
        int numberOfMonths = atoi(cNumberOfMonths);
        if (numberOfMonths < 1)
            numberOfMonths = 12;
        
        mb->undoStack.push(new AddDebtCommand(mb, name, amount, lAmount, true, APR, pLevel, date,
                                              additionalInfo, numberOfMonths, mb->mainBudgetTab.currentIndex(), mb->dList.size()));
        
        mb->IDForDebtOnStack = mb->dList.size();
        
        //mb->dDialog->setModal(false);
        mb->dDialog->done(0);
        
        for (int j = 0; j < mb->btl.size(); j++)
        {
            shuffleDebtTabs(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear(),
                            mb->msBudget->getSortedTabIndex(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear()), mb->dList);
            shuffleIncomeTabs(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear(),
                              mb->msBudget->getSortedTabIndex(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear()), mb->iList);
            shuffleExpenseTabs(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear(),
                               mb->msBudget->getSortedTabIndex(mb->btl.at(j).getMonth(), mb->btl.at(j).getYear()), mb->eList);
        }
        
        mb->populateDebtTable(mb->dList);
        mb->populateIncomeTable(mb->iList);
        mb->populateExpensesTable(mb->eList);
        mb->monthlyDebt = 0;
        mb->monthlyLDebt = 0;
        for (int i = 0; i < mb->dList.size(); i++)
        {
            if (mb->dList.at(i).getTabIndex() == mb->mainBudgetTab.currentIndex())
            {
                if (mb->dList.at(i).getAmountType() == "long")
                    mb->containsLongDebt = true;
                mb->monthlyDebt += mb->dList.at(i).getNetAmount();
                mb->monthlyLDebt += mb->dList.at(i).getNetAmount() + mb->dList.at(i).getNetLAmount();
            }
        }
        //if (mb->containsLongDebt)
            mb->bd->totalMonthlyDebtLineEdit->setText(mb->getCharAmountForMonthlyLDebt(mb->monthlyLDebt));
        //else
        //    mb->bd->totalMonthlyDebtLineEdit->setText(mb->getCharAmountForMonthlyDebt(mb->monthlyDebt));
        mb->setCurrentBalance();
        
        mb->documentModified = true;
        if (mb->fileNameWithoutFullPath == "")
            mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
        else
            mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
    } else {
        mb->dDialog->done(0);
        QMessageBox *msgBox = new QMessageBox(mb);
        msgBox->setText("The date you entered exceeds the 1 year limit for a fiscal year record. Create a new fiscal year record.");
        msgBox->setWindowModality(Qt::WindowModal);
        msgBox->exec();
    }
}


/**
 This closes the debt dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::closeDebtDialog()
{
    //mb->dDialog->setModal(false);
    mb->dDialog->done(0);
}


/**
 Opens a new savings dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::addSavingsClick()
{
    mb->svDialog = new SavingsDialog(mb);
    QDate qCurrentDate = QDate::currentDate();
    mb->svDialog->dueDateEdit->setDate(qCurrentDate);
    mb->svDialog->setModal(true);
    //mb->svDialog->setVisible(true);
    mb->svDialog->setWindowFlags(Qt::Sheet);
    mb->svDialog->setWindowTitle("Savings Info");
    mb->svDialog->show();
    connect(mb->svDialog->okButton, SIGNAL(clicked()), this, SLOT(insertSavingsDialogValues()));
    connect(mb->svDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeSavingsDialog()));
}


/**
 Inserts a new saving from the dialog values.
 
 @param  none.
 @return nothing.
 */
void MainWin::insertSavingsDialogValues()
{
    QString qsName = mb->svDialog->nameLineEdit->displayText();
    QChar * qcName = qsName.data();
    char cName[qsName.size() + 1];

    for (int i = 0; i < qsName.size() + 1; i++)
    {
        cName[i] = qcName->toAscii();
        ++qcName;
    }

    string name = string(cName);

    QString qsNature = mb->svDialog->natureComboBox->currentText();
    QChar * qcNature = qsNature.data();
    char cNature[qsNature.size() + 1];

    for (int j = 0; j < qsNature.size() + 1; j++)
    {
        cNature[j] = qcNature->toAscii();
        ++qcNature;
    }

    SavingsNature nature;
    switch (cNature[0]) {
        case 'S': nature = STOCK; break;
        case 'B': nature = BANK; break;
        default: ;
        }


    QString qsAmount = mb->svDialog->amountLineEdit->text();
    QChar * qcAmount = qsAmount.data();
    char cAmount[100];
    int k = 0;
    while (!qcAmount->isNull())
    {
        cAmount[k] = qcAmount->toAscii();
        ++qcAmount;
        k++;
    }
    double amount = atof(cAmount);
    long lAmount = strtold(cAmount, NULL);

    QString qsAPR = mb->svDialog->APRLineEdit->text();
    QChar * qcAPR = qsAPR.data();
    char cAPR[100];
    int n = 0;
    while (!qcAPR->isNull())
    {
        cAPR[n] = qcAPR->toAscii();
        ++qcAPR;
        n++;
    }
    float APR = atof(cAPR);

    QDate qdDate = mb->svDialog->dueDateEdit->date();
    int year = qdDate.year();
    int month = qdDate.month();
    int day = qdDate.day();
    Date date(year, month, day, 0, 0, 0);

    QString qsDescription = mb->svDialog->descriptionTextEdit->toPlainText();
    QChar * qcDescription = qsDescription.data();
    char cDescription[qsDescription.size() + 1];

    for (int m = 0; m < qsDescription.size() + 1; m++)
    {
        cDescription[m] = qcDescription->toAscii();
        ++qcDescription;
    }

    string description = string(cDescription);

    mb->undoStack.push(new AddSavingsCommand(mb, name, amount, lAmount, APR, nature, date, description, mb->sList.size()));

    mb->IDForSavingsOnStack = mb->sList.size();
    //mb->svDialog->setModal(false);
    mb->svDialog->done(0);
    mb->populateSavingsTable(mb->sList);

    mb->savingsBalance = 0;
    mb->savingsLBalance = 0;
    for (int i = 0; i < mb->sList.size(); i++)
    {
        if (mb->sList.at(i).getAmountType() == "long")
            mb->containsLongAssSaving = true;
        mb->savingsBalance += mb->sList.at(i).getAmount();
        mb->savingsLBalance += mb->sList.at(i).getAmount() + mb->sList.at(i).getLAmount();
    }
    //if (mb->containsLongAssSaving)
        mb->sd->currentBalanceLineEdit->setText(QString(mb->getCharAmountForSavingsCurrentLBalance(mb->savingsLBalance)));
    //else
    //    mb->sd->currentBalanceLineEdit->setText(QString(mb->getCharAmountForSavingsCurrentBalance(mb->savingsBalance)));
    
    mb->documentModified = true;
    if (mb->fileNameWithoutFullPath == "")
        mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
    else
        mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
}


/**
 This closes the savings dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::closeSavingsDialog()
{
    //mb->svDialog->setModal(false);
    mb->svDialog->done(0);
}


/**
 This deletes the selected savings item.
 
 @param  none.
 @return nothing.
 */
void MainWin::deleteSelectedSavings()
{
    if (mb->sd->savingsTable->currentItem() && (mb->tableFocus == "savings"))
    {
        QMessageBox *msgBox = new QMessageBox(mb);
        msgBox->setWindowTitle("Savings item deletion");
        msgBox->setWindowIcon(QIcon("images/cake_heap_icon.png"));
        msgBox->setText("You are about to delete a savings item.");
        msgBox->setInformativeText("Are you sure you want to delete this item?");
        msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox->setDefaultButton(QMessageBox::No);
        msgBox->setWindowModality(Qt::WindowModal);
        int ret = msgBox->exec();

        if (ret == QMessageBox::Yes)
        {
            int index = mb->sd->savingsTable->currentRow();
             mb->undoStack.push(new DeleteSavingsCommand(mb, mb->sList.at(index).getName(), mb->sList.at(index).getAmount(), mb->sList.at(index).getLAmount(), mb->sList.at(index).getAPR(), mb->sList.at(index).getNature(),
                mb->sList.at(index).getDate(), mb->sList.at(index).getDescription(), mb->sList.at(index).getIDCode()));
            mb->populateSavingsTable(mb->sList);
        }

        mb->savingsBalance = 0;
        mb->savingsLBalance = 0;
        for (int i = 0; i < mb->sList.size(); i++)
        {
            if (mb->sList.at(i).getAmountType() == "long")
                mb->containsLongAssSaving = true;
            mb->savingsBalance += mb->sList.at(i).getAmount();
            mb->savingsLBalance += mb->sList.at(i).getAmount() + mb->sList.at(i).getLAmount();
        }
        //if (mb->containsLongAssSaving)
            mb->sd->currentBalanceLineEdit->setText(QString(mb->getCharAmountForSavingsCurrentLBalance(mb->savingsLBalance)));
        //else
        //    mb->sd->currentBalanceLineEdit->setText(QString(mb->getCharAmountForSavingsCurrentBalance(mb->savingsBalance)));
        
        mb->documentModified = true;
        if (mb->fileNameWithoutFullPath == "")
            mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
        else
            mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
    }
}


/**
 Opens a new inventory dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::addItemClick()
{
    mb->itDialog = new ItemDialog(mb);
    mb->itDialog->setModal(true);
    //mb->itDialog->setVisible(true);
    mb->itDialog->setWindowFlags(Qt::Sheet);
    mb->itDialog->setWindowTitle("Item Info");
    mb->itDialog->show();
    connect(mb->itDialog->okButton, SIGNAL(clicked()), this, SLOT(insertItemDialogValues()));
    connect(mb->itDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeItemDialog()));
}


/**
 This closes the inventory dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::closeItemDialog()
{
    //mb->itDialog->setModal(false);
    mb->itDialog->done(0);
}


/**
 Inserts a new inventory item from the dialog values.
 
 @param  none.
 @return nothing.
 */
void MainWin::insertItemDialogValues()
{
    QString qsName = mb->itDialog->nameLineEdit->displayText();
    QChar * qcName = qsName.data();
    char cName[qsName.size() + 1];

    for (int i = 0; i < qsName.size() + 1; i++)
    {
        cName[i] = qcName->toAscii();
        ++qcName;
    }

    string name = string(cName);

    QString qsItemID = mb->itDialog->IDCodeLineEdit->text();
    QChar * qcItemID = qsItemID.data();
    char cItemID[qsItemID.size() + 1];

    for (int k = 0; k < qsItemID.size() + 1; k++)
    {
        cItemID[k] = qcItemID->toAscii();
        ++qcItemID;
    }
    string itemID = string(cItemID);

    QString qsNumber = mb->itDialog->amountLineEdit->text();
    QChar * qcNumber = qsNumber.data();
    char cNumber[100];
    int l = 0;
    while (!qcNumber->isNull())
    {
        cNumber[l] = qcNumber->toAscii();
        ++qcNumber;
        l++;
    }
    int number = atoi(cNumber);

    QString qsPrice = mb->itDialog->priceLineEdit->text();
    QChar * qcPrice = qsPrice.data();
    char cPrice[100];
    int m = 0;
    while (!qcPrice->isNull())
    {
        cPrice[m] = qcPrice->toAscii();
        ++qcPrice;
        m++;
    }
    double price = atof(cPrice);

    mb->undoStack.push(new AddItemCommand(mb, name, price, number, itemID, mb->itList.size()));

    mb->IDForItemOnStack = mb->itList.size();
    //mb->itDialog->setModal(false);
    mb->itDialog->done(0);
    mb->populateInventoryTable(mb->itList);
    
    mb->documentModified = true;
    if (mb->fileNameWithoutFullPath == "")
        mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
    else
        mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
}


/**
 This deletes the selected inventory item.
 
 @param  none.
 @return nothing.
 */
void MainWin::deleteSelectedInventoryItem()
{
    if (mb->id->inventoryTable->currentItem() && (mb->tableFocus == "items"))
    {
        QMessageBox *msgBox = new QMessageBox(mb);
        msgBox->setWindowTitle("Inventory item deletion");
        msgBox->setWindowIcon(QIcon("images/cake_heap_icon.png"));
        msgBox->setText("You are about to delete an inventory item.");
        msgBox->setInformativeText("Are you sure you want to delete this item?");
        msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox->setDefaultButton(QMessageBox::No);
        msgBox->setWindowModality(Qt::WindowModal);
        int ret = msgBox->exec();

        if (ret == QMessageBox::Yes)
        {
            int index = mb->id->inventoryTable->currentRow();
            mb->undoStack.push(new DeleteItemCommand(mb, mb->itList.at(index).getName(), mb->itList.at(index).getPrice(), mb->itList.at(index).getNumber(),
                mb->itList.at(index).getItemID(), mb->itList.at(index).getIDCode()));
            mb->populateInventoryTable(mb->itList);
            
            mb->documentModified = true;
            if (mb->fileNameWithoutFullPath == "")
                mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
            else
                mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
        }
    }
}


/**
 Opens a new reminder dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::addReminderClick()
{
    mb->rmDialog = new ReminderDialog(mb);
    QDate qCurrentDate = QDate::currentDate();
    mb->rmDialog->dateTimeEdit->setDate(qCurrentDate);
    mb->rmDialog->setModal(true);
    //mb->rmDialog->setVisible(true);
    mb->rmDialog->setWindowFlags(Qt::Sheet);
    mb->rmDialog->setWindowTitle("Reminder Info");
    mb->rmDialog->show();
    connect(mb->rmDialog->okButton, SIGNAL(clicked()), this, SLOT(insertReminderDialogValues()));
    connect(mb->rmDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeReminderDialog()));
}


/**
 This closes the reminder dialog.
 
 @param  none.
 @return nothing.
 */
void MainWin::closeReminderDialog()
{
    //mb->rmDialog->setModal(false);
    mb->rmDialog->done(0);
}


/**
 Inserts a new reminder from the dialog values.
 
 @param  none.
 @return nothing.
 */
void MainWin::insertReminderDialogValues()
{
    QString qsSubject = mb->rmDialog->subjectLineEdit->displayText();
    QChar * qcSubject = qsSubject.data();
    char cSubject[qsSubject.size() + 1];

    for (int i = 0; i < qsSubject.size() + 1; i++)
    {
        cSubject[i] = qcSubject->toAscii();
        ++qcSubject;
    }

    string subject = string(cSubject);

    QDate qdDate = mb->rmDialog->dateTimeEdit->date();
    QTime qdTime = mb->rmDialog->dateTimeEdit->time();
    int year = qdDate.year();
    int month = qdDate.month();
    int day = qdDate.day();
    int hour = qdTime.hour();
    int minute = qdTime.minute();
    int second = qdTime.second();
    Date date(year, month, day, hour, minute, second);
    mb->bd->calendar->setReminderDate(QDate(year, month, day));
    mb->sd->calendar->setReminderDate(QDate(year, month, day));
    mb->id->calendar->setReminderDate(QDate(year, month, day));
    mb->rd->calendar->setReminderDate(QDate(year, month, day));

    QString qsMessage = mb->rmDialog->messageTextEdit->toPlainText();
    QChar * qcMessage = qsMessage.data();
    char cMessage[qsMessage.size() + 1];
    
    for (int m = 0; m < qsMessage.size() + 1; m++)
    {
        cMessage[m] = qcMessage->toAscii();
        ++qcMessage;
    }

    string message = string(cMessage);

    mb->undoStack.push(new AddReminderCommand(mb, date, subject, message, HIGH, mb->rList.size()));

    mb->IDForReminderOnStack = mb->rList.size();
    //mb->rmDialog->setModal(false);
    mb->rmDialog->done(0);
    mb->populateReminderTable(mb->rList);
    
    mb->documentModified = true;
    if (mb->fileNameWithoutFullPath == "")
        mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
    else
        mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
}


/**
 This deletes the selected reminder.
 
 @param  none.
 @return nothing.
 */
void MainWin::deleteSelectedReminder()
{
    if (mb->rd->remindersTable->currentItem() && (mb->tableFocus == "reminders"))
    {
        QMessageBox *msgBox = new QMessageBox(mb);
        msgBox->setWindowTitle("Reminder item deletion");
        msgBox->setWindowIcon(QIcon("images/cake_heap_icon.png"));
        msgBox->setText("You are about to delete a reminder item.");
        msgBox->setInformativeText("Are you sure you want to delete this item?");
        msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox->setDefaultButton(QMessageBox::No);
        msgBox->setWindowModality(Qt::WindowModal);
        int ret = msgBox->exec();

        if (ret == QMessageBox::Yes)
        {
            int index = mb->rd->remindersTable->currentRow();
            mb->undoStack.push(new DeleteReminderCommand(mb, mb->rList.at(index).getDueDate(), mb->rList.at(index).getSubject(),
                mb->rList.at(index).getMessage(), HIGH, mb->rList.at(index).getIDCode()));
            mb->populateReminderTable(mb->rList);
            QDateList d;
            mb->sd->calendar->repaintReminders(index);
            mb->id->calendar->repaintReminders(index);
            mb->rd->calendar->repaintReminders(index);
            
            mb->documentModified = true;
            if (mb->fileNameWithoutFullPath == "")
                mb->setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
            else
                mb->setWindowTitle("CakeHeap Budget Professional - " + mb->fileNameWithoutFullPath + " - Modified");
        }
    }
}


/**
 This this activates the selected budget tab.
 
 @param  none.
 @return nothing.
 */
void MainWin::activateCurrentBudgetTabForMainWin()
{
    mb->selectedBudgetFrame = static_cast<BudgetFrame*>(mb->mainBudgetTab.currentWidget());

    // Income section
    disconnect(mb->selectedBudgetFrame->addIcomeButtom_2, SIGNAL(clicked()), this, SLOT(addIncomeClick()));
    connect(mb->selectedBudgetFrame->addIcomeButtom_2, SIGNAL(clicked()), this, SLOT(addIncomeClick()));

    // Debt section
    disconnect(mb->selectedBudgetFrame->addDebtButton_2, SIGNAL(clicked()), this, SLOT(addDebtClick()));
    connect(mb->selectedBudgetFrame->addDebtButton_2, SIGNAL(clicked()), this, SLOT(addDebtClick()));

    // Expenses section
    disconnect(mb->selectedBudgetFrame->addExpenseButtom_2, SIGNAL(clicked()), this, SLOT(addExpenseClick()));
    connect(mb->selectedBudgetFrame->addExpenseButtom_2, SIGNAL(clicked()), this, SLOT(addExpenseClick()));
}
