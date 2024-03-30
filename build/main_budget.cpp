#include "main_budget.h"
#include "cake_spacer_wigdet.h"

/**
 The constructor for the MainBudget class.
 
 @param *parent           the parent widget.
 */
MainBudget::MainBudget(QWidget *parent)
    : QMainWindow(parent)
{
    // Set the title of the window
    setWindowTitle("CakeHeap Budget Professional");
    fileNameWithoutFullPath = "";
    
    // Set the window icon - this doesn't seem necessary on Mac
    QIcon icon;
    icon.addFile(QString::fromUtf8("images/cake_heap_icon.png"), QSize(), QIcon::Normal, QIcon::On);
    setWindowIcon(icon);
    
    // Resize the window
    resize(1140, 626);
    setMinimumWidth(1140);
    setMinimumHeight(620);
    
    // Set the workspace defaults
    selectedBudgetFrame = new BudgetFrame;
    workSpaceActive = false;
    documentModified = false;
    documentSaved = false;
    containsLongIncome = false;
    containsLongDebt = false;
    containsLongExpense = false;
    currentBalance = 0;
    currentLBalance = 0;
    
    // Create the 'File' menu, add menu items to it and shortcuts
    fileMenu = new QMenu(tr("File"), this);
    menuBar()->addMenu(fileMenu);
    QAction *newAction = fileMenu->addAction(QString("New Fiscal Year Record"), this, SLOT(newFiscalRecord()));
    newAction->setShortcut(QKeySequence(tr("Ctrl+N")));
    QAction *openAction = fileMenu->addAction(QString("Open..."), this, SLOT(openGeneric()));
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
    QAction *saveAction = fileMenu->addAction(QString("Save"), this, SLOT(save()));
    saveAction->setShortcut(QKeySequence(tr("Ctrl+S")));
    fileMenu->addAction(QString("Save as..."), this, SLOT(saveAs()));
    fileMenu->addSeparator();
    
    separatorAct = fileMenu->addSeparator();
    /*
    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(recentFileActs[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
        fileMenu->addAction(recentFileActs[i]);
        cout << "Inside the first thing" << endl;
    }
    
    updateRecentFileActions();
    */
    fileMenu->addSeparator();
    fileMenu->addAction(QString("Print Balance Sheet..."), this, SLOT(balanceSheetFilePrint()));
    fileMenu->addAction(QString("Print Balance Sheet preview..."), this, SLOT(balanceSheetFilePrintPreview()));
    fileMenu->addAction(QString("Print Income Statement..."), this, SLOT(incomeStatementFilePrint()));
    fileMenu->addAction(QString("Print Income Statement preview..."), this, SLOT(incomeStatementFilePrintPreview()));
    fileMenu->addSeparator();
    QAction * closeAction = fileMenu->addAction(QString("Close Record"), this, SLOT(close()));
    closeAction->setShortcut(QKeySequence(tr("Ctrl+W")));
    fileMenu->addSeparator();
    QAction *quitAction = fileMenu->addAction(QString("Quit"), this, SLOT(quit()));
    quitAction->setShortcut(QKeySequence(tr("Ctrl+Q")));
    
    // Create 'Edit' menu
    editMenu = new QMenu(tr("Edit"), this);
    menuBar()->addMenu(editMenu);
    
    // Create 'View' menu, add menu items to it
    viewMenu = new QMenu(tr("View"), this);
    viewMenu->addAction(QString("Budget"), this, SLOT(viewBudget()));
    viewMenu->addAction(QString("Savings"), this, SLOT(viewSavings()));
    viewMenu->addAction(QString("Inventory"), this, SLOT(viewInventory()));
    viewMenu->addAction(QString("Reminders"), this, SLOT(viewReminders()));
    onboaderAction = new QAction("Onboarder");
    connect(onboaderAction, SIGNAL(triggered()), this, SLOT(showOnboarder()));
    viewMenu->addAction(onboaderAction);
    menuBar()->addMenu(viewMenu);
    
    // Create 'Tools' menu, add menu items to it
    toolsMenu = new QMenu(tr("Tools"), this);
    toolsMenu->addAction(QString("Balance Sheet"), this, SLOT(showBalanceSheet()));
    //toolsMenu->addAction(QString("Cash Flow Statement"), this, SLOT(showCashFlowStatement()));
    toolsMenu->addAction(QString("Income Statement"), this, SLOT(showIncomeStatement()));
    toolsMenu->addAction(QString("Monthly Finances Chart"), this, SLOT(loadPieChart()));
    menuBar()->addMenu(toolsMenu);
    
    // Create 'Help' menu, add menu items to it
    helpMenu = new QMenu(tr("Help"), this);
    helpMenu->addAction(QString("Manual"), this, SLOT(openManual()));
    helpMenu->addAction(QString("License"), this, SLOT(openLicense()));
    helpMenu->addAction(QString("Support"), this, SLOT(openSupport()));
    helpMenu->addAction(QString("Sample file"), this, SLOT(openSample()));
    helpMenu->addAction(QString("About"), this, SLOT(popAboutMessageBox()));
    //helpMenu->addAction(QString("Donate?...Why Donate?"), this, SLOT(popDonateMessageBox()));
    menuBar()->addMenu(helpMenu);
    
    // Create actions with icons for the side toolbar
    QIcon tbBudget(":/resources/images/budget.png");
    clickBudget = new QAction( tbBudget, "Budget", this);
    //clickBudget->setObjectName("toolBarChildSelected");
    clickBudget->setCheckable(true);
    //clickBudget->setChecked(true);
    QIcon tbSavings(":/resources/images/savings.png");
    clickSavings = new QAction( tbSavings, "Savings", this);
    clickSavings->setCheckable(true);
    QIcon tbInventory(":/resources/images/inventory.png");
    clickInventory = new QAction( tbInventory, "Inventory", this);
    clickInventory->setCheckable(true);
    QIcon tbReminders(":/resources/images/reminders.png");
    clickReminders = new QAction( tbReminders, "Reminders", this);
    clickReminders->setCheckable(true);
    // Create a side toolbar, add actions to it and connect
    // the actions to slots
    tbSide = new QToolBar("Pages", this);
    tbSide->setObjectName("cakeSideToolBar");
    tbSide->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    
    //tbSide->toggleViewAction();
    
    /*QFont *tbSideFont = new QFont("Helvetica Neue");
    tbSideFont->setBold(true);
    tbSide->setFont(tbSideFont);*/
    
    /*QObject *toolBarChild01 = tbSide->children().at(1);
    QToolButton *toolButton01 = qobject_cast<QToolButton *>(toolBarChild01);
    toolButton01->setObjectName("toolBarChildSelected"); // doesn't work*/
    
    tbSide->setStyleSheet("#cakeSideToolBar { border: 0px; background-color: #404244; border: 0px solid #fffff8; } QToolButton { color: #ffffff; } QToolButton:checked { background-color: #000000 }");
    
    // Make sure the toolbar is not movable
    tbSide->setMovable(false);
    tbSide->setFloatable(false);
    tbSide->addAction(clickBudget);
    connect(clickBudget, SIGNAL(triggered()), this, SLOT(viewBudget()));
    tbSide->addAction(clickSavings);
    connect(clickSavings, SIGNAL(triggered()), this, SLOT(viewSavings()));
    tbSide->addAction(clickInventory);
    connect(clickInventory, SIGNAL(triggered()), this, SLOT(viewInventory()));
    tbSide->addAction(clickReminders);
    connect(clickReminders, SIGNAL(triggered()), this, SLOT(viewReminders()));
    tbSide->setIconSize(QSize(90, 90));
    
    foreach(QToolButton* button, tbSide->findChildren<QToolButton*>())
    {
        button->installEventFilter(this);
    }
    
    /*foreach (QToolButton *button, toolbar->findChildren<QToolButton*>())
    {
        button->setToolTip(QString());
    }*/
    
    /*for (int i = 0; i < tbSide->children().size(); i++) {
        cout << "inside loop" << endl;
        QObject *toolBarChild = tbSide->children().at(1);
        QToolButton *toolButton = qobject_cast<QToolButton *>(toolBarChild);
        toolButton->setToolTip(QString());
    }*/
    
    //setStyleSheet("toolBarChildSelected:checked { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa); }");
    
    /*
    // Create actions with icons for the top toolbar
    CakeSpacerWidget *leftSpacer = new CakeSpacerWidget();
    leftSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QAction* clickNew = new QAction(QIcon(":/resources/images/cake_new.png"), "New", this);
    QAction* clickOpen = new QAction(QIcon(":/resources/images/cake_open.png"), "Open", this);
    QAction* clickSave = new QAction(QIcon(":/resources/images/cake_save.png"), "Save", this);
    clickCut = new QAction(QIcon(":/resources/images/cake_cut.png"), "Cut", this);
    clickCopy = new QAction(QIcon(":/resources/images/cake_copy.png"), "Copy", this);
    clickPaste = new QAction(QIcon(":/resources/images/cake_paste.png"), "Paste", this);
    CakeSpacerWidget *rightSpacer = new CakeSpacerWidget();
    rightSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // Create a top toolbar, add actions to it and connect
    // the actions to slots
    tbTop = new QToolBar("General Functions", this);
    tbTop->setObjectName("cakeTopToolBar");
    tbTop->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // Make sure the toolbar is not movable
    tbTop->setMovable(false);
    tbTop->setFloatable(false);
    tbTop->addWidget(leftSpacer);
    //tbTop->addSpacer();
    tbTop->addAction(clickNew);
    connect(clickNew, SIGNAL(triggered()), this, SLOT(newFiscalRecord()));
    tbTop->addAction(clickOpen);
    connect(clickOpen, SIGNAL(triggered()), this, SLOT(openGeneric()));
    tbTop->addAction(clickSave);
    connect(clickSave, SIGNAL(triggered()), this, SLOT(save()));
    //tbTop->addSeparator();
    tbTop->addAction(clickCut);
    tbTop->addAction(clickCopy);
    tbTop->addAction(clickPaste);
    //tbTop>addSpacer();
    //tbTop->setStyleSheet("#cakeTopToolBar { margin:0 auto; }");
    tbTop->addWidget(rightSpacer);
    //tbTop->addSeparator();
    // Make the title and toolbar unified like on Mac.
    setUnifiedTitleAndToolBarOnMac(true);
    
    // Set the orientation of the toolbars and
    // add them to the window
    addToolBar(tbTop);*/
    tbSide->setOrientation(Qt::Vertical);
    addToolBar(Qt::LeftToolBarArea, tbSide);
    
    // Add the CakeTabWidget (mainBudgetTab) to
    // the budget dock
    bd = new BudgetDock(this);
    //bd->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    bd->setTitleBarWidget(new QWidget());
    
    //mainBudgetTab = new CakeTabWidget(bd->scrollArea);
    
    mainBudgetTab.setStyleSheet("QTabWidget { border-top: 0px solid #C2C7CB; padding: 10px; }");
    bd->scrollArea->setWidget(&mainBudgetTab);
    // set the tab widget index to zero and
    // add an empty budget frame
    mainBudgetTab.setCurrentIndex(0);
    mainBudgetTab.addTab(&bf, getTabBarDate(QDate::currentDate()));

    // ??? THE POPUP MENU SECTION - I honestly have no idea what this does
    popupMenu = new QMenu(this);
    QAction *editPopupAction = popupMenu->addAction(QString("Edit"), this, SLOT(editEntry()));
    popupMenu->addSeparator();
    QAction *cutAction = editMenu->addAction(QString("Cut"), this, SLOT(cutEntry()));
    cutAction->setShortcut(QKeySequence(tr("Ctrl+X")));
    QAction *copyAction = editMenu->addAction(QString("Copy"), this, SLOT(copyEntry()));
    copyAction->setShortcut(QKeySequence(tr("Ctrl+C")));
    QAction *pasteAction = editMenu->addAction(QString("Paste"), this, SLOT(pasteEntry()));
    pasteAction->setShortcut(QKeySequence(tr("Ctrl+V")));

    /*connect(clickCut, SIGNAL(triggered()), this, SLOT(cutEntry()));
    connect(clickCopy, SIGNAL(triggered()), this, SLOT(copyEntry()));
    connect(clickPaste, SIGNAL(triggered()), this, SLOT(pasteEntry()));*/

    cutPopupAction = popupMenu->addAction(QString("Cut"), this, SLOT(cutEntry()));
    cutPopupAction->setShortcut(QKeySequence(tr("Ctrl+X")));
    copyPopupAction = popupMenu->addAction(QString("Copy"), this, SLOT(copyEntry()));
    copyPopupAction->setShortcut(QKeySequence(tr("Ctrl+C")));
    pastePopupAction = popupMenu->addAction(QString("Paste"), this, SLOT(pasteEntry()));
    pastePopupAction->setShortcut(QKeySequence(tr("Ctrl+V")));

    // This sets the default tab to that with an index of 0
    selectedBudgetFrame = static_cast<BudgetFrame*>(mainBudgetTab.currentWidget());
    selectedBudgetFrame->setMonth(QDate::currentDate().month());
    selectedBudgetFrame->setYear(QDate::currentDate().year());
    connect(&mainBudgetTab, SIGNAL(currentChanged(int)), this, SLOT(activateCurrentBudgetTab()));

    // Add the budget dock to the window
    addDockWidget(Qt::BottomDockWidgetArea, bd);
    bd->setVisible(false);
    connect(bd->editButton, SIGNAL(clicked()), this, SLOT(editSelectedItem()));
    connect(selectedBudgetFrame->saveMoneyButton, SIGNAL(clicked()), this, SLOT(saveMoneyClick()));

    // Set the look and behavior of the income table
    // Open the edit dialog for the selected item
    selectedBudgetFrame->incomeTable_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    selectedBudgetFrame->incomeTable_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    selectedBudgetFrame->incomeTable_2->setSelectionMode(QAbstractItemView::SingleSelection);
    selectedBudgetFrame->incomeTable_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(selectedBudgetFrame->incomeTable_2, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setIncomeTableFocus()));
    connect(selectedBudgetFrame->incomeTable_2, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedItem()));


    // Set the look and behavior of the debt table
    // Open the edit dialog for the selected item
    selectedBudgetFrame->debtTable_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    selectedBudgetFrame->debtTable_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    selectedBudgetFrame->debtTable_2->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(selectedBudgetFrame->debtTable_2, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setDebtTableFocus()));
    connect(selectedBudgetFrame->debtTable_2, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedItem()));

    // Set the look and behavior of the expense table
    // Open the edit dialog for the selected item
    selectedBudgetFrame->expensesTable_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    selectedBudgetFrame->expensesTable_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    selectedBudgetFrame->expensesTable_2->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(selectedBudgetFrame->expensesTable_2, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setExpensesTableFocus()));
    connect(selectedBudgetFrame->expensesTable_2, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedItem()));

    // Add the savings dock to the window
    sd = new SavingsDock(this);
    sd->setTitleBarWidget(new QWidget());
    addDockWidget(Qt::BottomDockWidgetArea, sd);
    sd->setVisible(false);
    connect(sd->editButton, SIGNAL(clicked()), this, SLOT(editSelectedSavings()));
    connect(sd->pushButton, SIGNAL(clicked()), this, SLOT(getMoneyClick()));

    // Set the look and behavior of the savings table
    // Open the edit dialog for the selected item
    sd->savingsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    sd->savingsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    sd->savingsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(sd->savingsTable, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setSavingsTableFocus()));
    connect(sd->savingsTable, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedSavings()));

    // Add the inventory dock to the window
    id = new InventoryDock(this);
    id->setTitleBarWidget(new QWidget());
    addDockWidget(Qt::BottomDockWidgetArea, id);
    id->setVisible(false);
    connect(id->editButton, SIGNAL(clicked()), this, SLOT(editSelectedInventoryItem()));

    /// Set the look and behavior of the inventory table
    // Open the edit dialog for the selected item
    id->inventoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    id->inventoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    id->inventoryTable->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(id->inventoryTable, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setInventoryTableFocus()));
    connect(id->inventoryTable, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedInventoryItem()));

    // Add the reminder dock to the window
    rd = new RemindersDock(this);
    rd->setTitleBarWidget(new QWidget());
    addDockWidget(Qt::BottomDockWidgetArea, rd);
    rd->setVisible(false);
    connect(rd->editButton, SIGNAL(clicked()), this, SLOT(editSelectedReminder()));

    // Set the look and behavior of the reminders table
    // Open the edit dialog for the selected item
    rd->remindersTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    rd->remindersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    rd->remindersTable->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(rd->remindersTable, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setRemindersTableFocus()));
    connect(rd->remindersTable, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedReminder()));

    // Calculate totals and balances
    monthlyIncome = 0;
    monthlyLIncome = 0;
    for (int i = 0; i < iList.size(); i++)
    {
        if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (iList.at(i).getAmountType() == "long")
                containsLongIncome = true;
            monthlyIncome += iList.at(i).getNetAmount();
            monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
        }
    }
    //if (containsLongIncome)
        bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
    //else
    //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));

    monthlyDebt = 0;
    monthlyLDebt = 0;
    for (int i = 0; i < dList.size(); i++)
    {
        if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (dList.at(i).getAmountType() == "long")
                containsLongDebt = true;
            monthlyDebt += dList.at(i).getNetAmount();
            monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
        }
    }
    //if (containsLongDebt)
        bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
    //else
    //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));

    monthlyExpenses = 0;
    monthlyLExpenses = 0;
    for (int i = 0; i < eList.size(); i++)
    {
        if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (eList.at(i).getAmountType() == "long")
                containsLongExpense = true;
            monthlyExpenses += eList.at(i).getNetAmount();
            monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
        }
    }
    //if (containsLongExpense)
        bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
    //else
    //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

    setCurrentBalance();

    // Calculate total savings
    savingsBalance = 0;
    savingsLBalance = 0;
    for (int i = 0; i < sList.size(); i++)
    {
        if (sList.at(i).getAmountType() == "long")
            containsLongAssSaving = true;
        savingsBalance += sList.at(i).getAmount();
        savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
    }
    //if (containsLongAssSaving)
        sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
    //else
    //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));
    
    // Calculate the savings APR
    sA = new SavingsAPR(&sList);
    sA->start();
    
    // Signals and slots for the calendar on different pages
    connect(bd->calendar, SIGNAL(clicked(const QDate &)),
            this, SLOT(selectClickedReminderBudget()));
    connect(sd->calendar, SIGNAL(clicked(const QDate &)),
            this, SLOT(selectClickedReminderSavings()));
    connect(id->calendar, SIGNAL(clicked(const QDate &)),
            this, SLOT(selectClickedReminderInventory()));
    connect(rd->calendar, SIGNAL(clicked(const QDate &)),
            this, SLOT(selectClickedReminderReminders()));
    
    // ??? I HAVE NO IDEA WHAT THIS DOES
    openCanceled = false;
    
    // ??? This has something do with a reminder being ready
    /*cr = new CheckReminders(&rList);
    cr->start();
    connect(cr, SIGNAL(notifyMessageBox()),
        this, SLOT(popCakeMessageBox()), Qt::DirectConnection);*/
    connect(selectedBudgetFrame->incomeTable_2, SIGNAL(customContextMenuRequested(const QPoint &)),
        this, SLOT(showContextMenu(const QPoint &)));
    
    // Center the window hozintally
    int WIDTH = 1140;
    //int HEIGHT = 680;
    int screenWidth;
    //int screenHeight;
    int x, y;
    
    QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width();
    //screenHeight = desktop->height();
    x = (screenWidth - WIDTH) / 2;
    //y = (screenHeight - HEIGHT) / 2;
    
    const QString DEFAULT_X_KEY("default_x");
    const QString DEFAULT_Y_KEY("default_y");
    const QString DEFAULT_WIDTH_KEY("default_width");
    const QString DEFAULT_HEIGHT_KEY("default_height");
    const QString DEFAULT_ONBOARDER_KEY("default_onboarder");
    
    QSettings *mySettings = new QSettings(("Thabo David Klass", "CakeHeap Budget Professional"));
    
    if (mySettings->contains(DEFAULT_X_KEY)) {
        this->move(mySettings->value(DEFAULT_X_KEY).toInt(), mySettings->value(DEFAULT_Y_KEY).toInt());
        resize(mySettings->value(DEFAULT_WIDTH_KEY).toInt(), mySettings->value(DEFAULT_HEIGHT_KEY).toInt());
    } else
        this->move(x, 0);
    
    //this->setStyleSheet("QWidget { font-family: 'Helvetica Neue'; }");
    
    setAcceptDrops(true);
    
    if (!mySettings->contains(DEFAULT_ONBOARDER_KEY))
    {
        showOnboarder();
    } else
    {
        if (!mySettings->value(DEFAULT_ONBOARDER_KEY).toBool()) {
            showOnboarder();
        }
    }
}

/// A bool holding whether the reminder time has been reached
bool MainBudget::reminderTimeReached = false;


/**
 The destructor for the MainBudget class.
 */
MainBudget::~MainBudget()
{
    delete bd;
    bd = 0;
    delete sd;
    sd = 0;
    delete id;
    id = 0;
    delete rd;
    rd = 0;
    delete tbSide;
    tbSide = 0;
    delete tbTop;
    tbTop = 0;
    delete iDialog;
    iDialog = 0;
    delete eiDialog;
    eiDialog = 0;
    delete dDialog;
    dDialog = 0;
    delete edDialog;
    edDialog = 0;
    delete eDialog;
    eDialog = 0;
    delete smDialog;
    smDialog = 0;
    delete svDialog;
    svDialog = 0;
    delete itDialog;
    itDialog = 0;
    delete rmDialog;
    rmDialog = 0;
    delete obDialog;
    obDialog = 0;
}

void MainBudget::disableAffectedMenus()
{
    for (int i = 0; i < fileMenu->actions().size(); i++)
    {
        fileMenu->actions().at(i)->setEnabled(false);
    }
    
    for (int i = 0; i < editMenu->actions().size(); i++)
    {
        editMenu->actions().at(i)->setEnabled(false);
    }
    
    for (int i = 0; i < viewMenu->actions().size(); i++)
    {
        viewMenu->actions().at(i)->setEnabled(false);
    }
    
    for (int i = 0; i < toolsMenu->actions().size(); i++)
    {
        toolsMenu->actions().at(i)->setEnabled(false);
    }
    
    for (int i = 0; i < helpMenu->actions().size(); i++)
    {
        helpMenu->actions().at(i)->setEnabled(false);
    }
}

void MainBudget::enableAffectedMenus()
{
    for (int i = 0; i < fileMenu->actions().size(); i++)
    {
        fileMenu->actions().at(i)->setEnabled(true);
    }
    
    for (int i = 0; i < editMenu->actions().size(); i++)
    {
        editMenu->actions().at(i)->setEnabled(true);
    }
    
    for (int i = 0; i < viewMenu->actions().size(); i++)
    {
        viewMenu->actions().at(i)->setEnabled(true);
    }
    
    for (int i = 0; i < toolsMenu->actions().size(); i++)
    {
        toolsMenu->actions().at(i)->setEnabled(true);
    }
    
    for (int i = 0; i < helpMenu->actions().size(); i++)
    {
        helpMenu->actions().at(i)->setEnabled(true);
    }
}

void MainBudget::showOnboarder()
{
    obDialog = new OnboaderDialog(this);
    obDialog->setStyleSheet("QDialog { background-color: #ffffff; border: 0px solid #fffff8; }");
    obDialog->setModal(true);
    obDialog->setWindowFlags(Qt::Sheet);
    obDialog->setWindowTitle("Welcome!");
    obDialog->show();
    
    //connect(eiDialog->okButton, SIGNAL(clicked()), this,
    //        SLOT(insertEditedIncomeDialogValues()));
    connect(obDialog->doneButton_2, SIGNAL(clicked()), this, SLOT(openSample()));
    connect(obDialog->doneButton_3, SIGNAL(clicked()), this, SLOT(openManual()));
    connect(obDialog->doneButton_4, SIGNAL(clicked()), this, SLOT(newFiscalRecord()));
    connect(obDialog->doneButton, SIGNAL(clicked()), this, SLOT(closeOnboaderDialog()));
}

void MainBudget::closeOnboaderDialog()
{
    const QString DEFAULT_ONBOARDER_KEY("default_onboarder");
    
    QSettings *mySettings = new QSettings(("Thabo David Klass", "CakeHeap Budget Professional"));
    
    if (obDialog->showAgainCheckBox->isChecked()) {
        mySettings->setValue(DEFAULT_ONBOARDER_KEY,
                         true);
    } else
    {
        mySettings->setValue(DEFAULT_ONBOARDER_KEY,
                             false);
    }
    
    obDialog->done(0);
}

void MainBudget::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}


void MainBudget::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls()) {
        QString fileName = url.toLocalFile();
        qDebug() << "Dropped file:" << fileName;
        openDragAndDrop(fileName);
    }
}

bool MainBudget::eventFilter(QObject* o, QEvent* e)
{
    if (e->type() == QEvent::ToolTip)
    {
        return true;
    }
    return QMainWindow::eventFilter(o, e);
}


/**
 The view the budget page.
 
 @param  none.
 @return nothing.
 */
void MainBudget::viewBudget()
{
    clickBudget->setChecked(false);
    clickSavings->setChecked(false);
    clickInventory->setChecked(false);
    clickReminders->setChecked(false);
    
    if (workSpaceActive)
    {
        sd->setVisible(false);
        id->setVisible(false);
        rd->setVisible(false);
        activateCurrentBudgetTab();
        bd->setVisible(true);
        
        clickBudget->setChecked(true);
    }
}


/**
 The view the savings page.
 
 @param  none.
 @return nothing.
 */
void MainBudget::viewSavings()
{
    clickBudget->setChecked(false);
    clickSavings->setChecked(false);
    clickInventory->setChecked(false);
    clickReminders->setChecked(false);

    if (workSpaceActive)
    {
        bd->setVisible(false);
        id->setVisible(false);
        rd->setVisible(false);
        sd->setVisible(true);
        
        clickSavings->setChecked(true);
    }
}

void MainBudget::selectedSavingsIcon() {
    /*
    QIcon tbSavings("images/savings_focused.png");
    this->clickSavings = new QAction( tbSavings, "Savings Page", this);
    this->tbSide->addAction(clickSavings);
    connect(clickSavings, SIGNAL(triggered()), this, SLOT(viewSavings()));*/
    
    QObject *toolBarChild01 = tbSide->children().at(1);
    QToolButton *toolButton01 = qobject_cast<QToolButton *>(toolBarChild01);
    //toolButton01->setObjectName("toolBarChildSelected");
    QIcon tbSavings("images/savings_focused.png");
    toolButton01->setIcon(tbSavings);
    
    int n = tbSide->children().count();
    cout << n; //
}


/**
 The view the inventory page.
 
 @param  none.
 @return nothing.
 */
void MainBudget::viewInventory()
{
    clickBudget->setChecked(false);
    clickSavings->setChecked(false);
    clickInventory->setChecked(false);
    clickReminders->setChecked(false);
    
    if (workSpaceActive)
    {
        bd->setVisible(false);
        sd->setVisible(false);
        rd->setVisible(false);
        id->setVisible(true);
        
        clickInventory->setChecked(true);
    }
}


/**
 The view the reminders page.
 
 @param  none.
 @return nothing.
 */
void MainBudget::viewReminders()
{
    clickBudget->setChecked(false);
    clickSavings->setChecked(false);
    clickInventory->setChecked(false);
    clickReminders->setChecked(false);
    
    if (workSpaceActive)
    {
        bd->setVisible(false);
        sd->setVisible(false);
        id->setVisible(false);
        rd->setVisible(true);
        
        clickReminders->setChecked(true);
    }
}


/**
 Opens the save money dialog to save income
 and put it into the savings.
 
 @param  none.
 @return nothing.
 */

void MainBudget::saveMoneyClick()
{
    smDialog = new SaveMoneyDialog(this);
    //smDialog->setVisible(true);
    for (int i = 0; i < sList.size(); i++)
    {
        strcpy(cSelectedSaving, sList.at(i).getName().c_str());
        smDialog->selectSavingsComboBox->addItem(QString(cSelectedSaving));
    }
    smDialog->setModal(true);
    smDialog->setWindowFlags(Qt::Sheet);
    smDialog->setWindowTitle("Save Money Info");
    smDialog->show();
    connect(smDialog->okButton, SIGNAL(clicked()), this, SLOT(insertSaveMoneyValues()));
    connect(smDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeSaveMoneyDialog()));
}


/**
 Opens the get money dialog to use savings
 and put it into the income.
 
 @param  none.
 @return nothing.
 */
void MainBudget::getMoneyClick()
{
    gmDialog = new GetMoneyDialog(this);
    gmDialog->setModal(true);
    //gmDialog->setVisible(true);
    gmDialog->setWindowFlags(Qt::Sheet);
    gmDialog->setWindowTitle("Get Money Info");
    gmDialog->show();
    connect(gmDialog->okButton, SIGNAL(clicked()), this, SLOT(insertGetMoneyValues()));
    connect(gmDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeGetMoneyDialog()));
}


/**
 Get the char value for monthly income.
 
 @param  amount          the double amount.
 @return cMonthlyIncome  the char * value of monthly income.
 */
char * MainBudget::getCharAmountForMonthlyIncome(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cMonthlyIncome[i] = sAmount[i];
    return cMonthlyIncome;
}


/**
 Get the char value for monthly income.
 
 @param  lAmount the long amount.
 @return cMonthlyIncome the char * value of monthly income.
 */
char * MainBudget::getCharAmountForMonthlyLIncome(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cMonthlyIncome[i] = sAmount[i];
    containsLongIncome = false;
    return cMonthlyIncome;
}


/**
 Get the char value for monthly debt.
 
 @param  amount          the double amount.
 @return cMonthlyDebt    the char * value of monthly debt.
 */
char * MainBudget::getCharAmountForMonthlyDebt(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cMonthlyDebt[i] = sAmount[i];
    return cMonthlyDebt;
}


/**
 Get the char value for monthly debt.
 
 @param  lAmount         the long amount.
 @return cMonthlyDebt    the char * value of monthly debt.
 */
char * MainBudget::getCharAmountForMonthlyLDebt(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cMonthlyDebt[i] = sAmount[i];
    containsLongDebt = false;
    return cMonthlyDebt;
}


/**
 Get the char value for monthly expense.
 
 @param  amount              the double amount.
 @return cMonthlyExpenses    the char * value of monthly expenses.
 */
char * MainBudget::getCharAmountForMonthlyExpenses(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cMonthlyExpenses[i] = sAmount[i];
    containsLongExpense = false;
    return cMonthlyExpenses;
}


/**
 Get the char value for monthly expense.
 
 @param  lAmount             the long amount.
 @return cMonthlyExpenses    the char * value of monthly expenses.
 */
char * MainBudget::getCharAmountForMonthlyLExpenses(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cMonthlyExpenses[i] = sAmount[i];
    return cMonthlyExpenses;
}


/**
 Get the char value for current balance.
 
 @param  amount             the double amount.
 @return cCurrentBalance    the char * value of current balance.
 */
char * MainBudget::getCharAmountForCurrentBalance(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cCurrentBalance[i] = sAmount[i];
    return cCurrentBalance;
}


/**
 Get the char value for current balance.
 
 @param  lAmount            the long amount.
 @return cCurrentBalance    the char * value of current balance.
 */
char * MainBudget::getCharAmountForCurrentLBalance(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cCurrentBalance[i] = sAmount[i];
    return cCurrentBalance;
}


/**
 The current balance setter.
 
 @param  none.
 @return nothing.
 */
void MainBudget::setCurrentBalance()
{
    QString qsIncomeBalance = bd->totalMonthlyIncomeLineEdit->text();
    QChar * qcIncomeBalance = qsIncomeBalance.data();
    char cIncomeBalance[16];
    int i = 0;
    while (!qcIncomeBalance->isNull())
    {
        cIncomeBalance[i] = qcIncomeBalance->toAscii();
        ++qcIncomeBalance;
        i++;
    }
    double incomeAmount = atof(cIncomeBalance);
    long incomeLAmount = strtold(cIncomeBalance, NULL);

    QString qsDebtBalance = bd->totalMonthlyDebtLineEdit->text();
    QChar * qcDebtBalance = qsDebtBalance.data();
    char cDebtBalance[16];
    int j = 0;
    while (!qcDebtBalance->isNull())
    {
        cDebtBalance[j] = qcDebtBalance->toAscii();
        ++qcDebtBalance;
        j++;
    }
    double debtAmount = atof(cDebtBalance);
    long debtLAmount = strtold(cDebtBalance, NULL);

    QString qsExpensesBalance = bd->totalMonthlyExpensesLineEdit->text();
    QChar * qcExpensesBalance = qsExpensesBalance.data();
    char cExpensesBalance[16];
    int k = 0;
    while (!qcExpensesBalance->isNull())
    {
        cExpensesBalance[k] = qcExpensesBalance->toAscii();
        ++qcExpensesBalance;
        k++;
    }
    double expensesAmount = atof(cExpensesBalance);
    long expensesLAmount = strtold(cExpensesBalance, NULL);

    currentBalance = incomeAmount - (debtAmount + expensesAmount);
    currentLBalance = incomeLAmount - (debtLAmount + expensesLAmount);

    if ((currentLBalance > 999999) || (debtAmount > 999999) || (expensesAmount > 999999))
        bd->currentBalanceLineEdit->setText(getCharAmountForCurrentLBalance(currentLBalance));
    else
        bd->currentBalanceLineEdit->setText(getCharAmountForCurrentBalance(currentBalance));
}


/**
 Get the char value for the income name.
 
 @param  name     the string value of the income name.
 @return cName    the char * value of the income name.
 */
char * MainBudget::getCharNameForIncome(string name)
{
    strcpy(cName, name.c_str());
    return cName;
}


/**
 Get the char value for the income date.
 
 @param  date       the income date.
 @return cTheDate   the char * value of the income date.
 */
char * MainBudget::getCharDateForIncome(Date date)
{
    ostringstream ostrYear;
    ostringstream ostrMonth;
    ostringstream ostrDay;
    ostrYear << date.getYear();
    string year = ostrYear.str();
    ostrMonth << date.getMonth();
    string month = ostrMonth.str();
    ostrDay << date.getDay();
    string day = ostrDay.str();
    string theDate = day + "/" + month + "/" + year;

    for (int i = 0; i < 11; i++)
        cTheDate[i] = theDate[i];
    return cTheDate;
}


/**
 Get the char value for the income nature.
 
 @param  nature      the income nature.
 @return cNature     the char * value of the income nature.
 */
char * MainBudget::getCharNatureForIncome(Nature nature)
{
    if (nature == SALARY)
        cNature = "SALARY";
    else if (nature == DIVIDEND)
        cNature = "DIVIDEND";
    else if (nature == STOCK_SALE)
        cNature = "STOCK_SALE";
    else if (nature == IOU)
        cNature = "IOU";
    else if (nature == DIP)
        cNature = "DIP";
    else if (nature == OTHER)
        cNature = "OTHER";
    return cNature;
}


/**
 Get the char value for income.
 
 @param  amount   the double amount.
 @return cAmount  the char * value of the income.
 */
char * MainBudget::getCharAmountForIncome(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cAmount[i] = sAmount[i];
    return cAmount;
}


/**
 Get the char value for income.
 
 @param  lAmount   the long amount.
 @return cAmount   the char * value of the income.
 */
char * MainBudget::getCharAmountForLIncome(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cAmount[i] = sAmount[i];
    return cAmount;
}


/**
 Get the char value for income tax.
 
 @param  tax   the float tax.
 @return cTax  the char * value of the tax.
 */
char * MainBudget::getCharTaxForIncome(float tax)
{
    ostringstream ostrTax;
    ostrTax << tax;
    string sTax = ostrTax.str();
    for (int i = 0; i < 11; i++)
        cTax[i] = sTax[i];
    return cTax;
}


/**
 Get the char value for net income.
 
 @param  netAmount   the double net amount.
 @return cNetAmount  the char * value of the net income.
 */
char * MainBudget::getCharNetAmountForIncome(double netAmount)
{
    ostringstream ostrNetAmount;
    ostrNetAmount << netAmount;
    string sNetAmount = ostrNetAmount.str();
    for (int i = 0; i < 16; i++)
        cNetAmount[i] = sNetAmount[i];
    return cNetAmount;
}


/**
 Get the char value for net income.
 
 @param  netLAmount   the long net amount.
 @return cNetAmount   the char * value of the net income.
 */
char * MainBudget::getCharNetAmountForLIncome(long netLAmount)
{
    ostringstream ostrNetAmount;
    ostrNetAmount << netLAmount;
    string sNetAmount = ostrNetAmount.str();
    for (int i = 0; i < 16; i++)
        cNetAmount[i] = sNetAmount[i];
    return cNetAmount;
}


/**
 Get the char value for the ID code.
 
 @param  IDCode    the int ID code.
 @return cIDCode   the char * value of the ID code.
 */
char * MainBudget::getCharIDCodeForIncome(int IDCode)
{
    ostringstream ostrIDCode;
    ostrIDCode << IDCode;
    string sIDCode = ostrIDCode.str();
    for (int i = 0; i < 16; i++)
        cIDCode[i] = sIDCode[i];
    return cIDCode;
}


/**
 Insert and income into the income table.
 
 @param  i         the table cell index.
 @param  income    the income to be inserted ih the table.
 @return           nothing.
 */
void MainBudget::insertIncomeValues(int i, Income * income)
{
    selectedBudgetFrame->incomeTable_2->setItem(i, 0, new QTableWidgetItem(QString(getCharDateForIncome(income->getReceivedDate()))));
    selectedBudgetFrame->incomeTable_2->setItem(i, 1, new QTableWidgetItem(QString(getCharNameForIncome(income->getName()))));
    selectedBudgetFrame->incomeTable_2->setItem(i, 2, new QTableWidgetItem(QString(getCharNatureForIncome(income->getNature()))));
    if (income->getAmountType() == "double")
        selectedBudgetFrame->incomeTable_2->setItem(i, 3, new QTableWidgetItem(QString(getCharAmountForIncome(income->getAmount()))));
    else
        selectedBudgetFrame->incomeTable_2->setItem(i, 3, new QTableWidgetItem(QString(getCharAmountForLIncome(income->getLAmount()))));
    selectedBudgetFrame->incomeTable_2->setItem(i, 4, new QTableWidgetItem(QString(getCharTaxForIncome(income->getTax()))));
    if (income->getAmountType() == "long")
        selectedBudgetFrame->incomeTable_2->setItem(i, 5, new QTableWidgetItem(QString(getCharNetAmountForLIncome(income->getNetLAmount()))));
    else
        selectedBudgetFrame->incomeTable_2->setItem(i, 5, new QTableWidgetItem(QString(getCharNetAmountForIncome(income->getNetAmount()))));
    selectedBudgetFrame->incomeTable_2->setItem(i, 6, new QTableWidgetItem(QString(getCharIDCodeForIncome(income->getIDCode()))));
}


/**
 Populate the income table using insertIncomeValues()
 
 @param  iList     the income list.
 @return income    nothing.
 */
void MainBudget::populateIncomeTable(IncomeList iList)
{
    selectedBudgetFrame->incomeTable_2->setRowCount(0);
    for (int i = 0; i < iList.size(); i++)
    {
        if (mainBudgetTab.currentIndex() == iList.at(i).getTabIndex())
        {
            selectedBudgetFrame->incomeTable_2->setRowCount(selectedBudgetFrame->incomeTable_2->rowCount() + 1);
            insertIncomeValues(selectedBudgetFrame->incomeTable_2->rowCount() - 1, &iList.at(i));
        }
    }
}


/**
 Opens a modal dialog to edit budget values.
 
 @param  none.
 @return nothing.
 */
void MainBudget::editSelectedItem()
{
    // The income section
    // Add the income information into the modal dialog
    if (selectedBudgetFrame->incomeTable_2->currentItem() && (tableFocus == "income"))
    {
        int index = selectedBudgetFrame->incomeTable_2->currentRow();
        eiDialog = new EditedIncomeDialog(this);

        QString qsLocalIDCode = selectedBudgetFrame->incomeTable_2->item(index, 6)->text();
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

        for (int j = 0; j < iList.size(); j++)
        {
            if (iList.at(j).getIDCode() == localIDCode)
            {
                strcpy(cName, iList.at(j).getName().c_str());
                eiDialog->nameLineEdit->setText(QString(cName));

                int year = iList.at(j).getReceivedDate().getYear();
                int month = iList.at(j).getReceivedDate().getMonth();
                int day = iList.at(j).getReceivedDate().getDay();
                eiDialog->dateEdit->setDate(QDate(year, month, day));

                Nature nature = iList.at(j).getNature();
                if (nature == SALARY)
                    eiDialog->natureComboBox->setCurrentIndex(0);
                if (nature == DIVIDEND)
                    eiDialog->natureComboBox->setCurrentIndex(1);
                if (nature == STOCK_SALE)
                    eiDialog->natureComboBox->setCurrentIndex(2);
                if (nature == IOU)
                    eiDialog->natureComboBox->setCurrentIndex(3);
                if (nature == DIP)
                    eiDialog->natureComboBox->setCurrentIndex(4);
                if (nature == OTHER)
                    eiDialog->natureComboBox->setCurrentIndex(5);

                if (iList.at(j).getAmountType() == "double")
                {
                    double amount = iList.at(j).getAmount();
                    eiDialog->amountLineEdit->setText(getCharAmountForIncome(amount));
                }
                else
                {
                    long amount = iList.at(j).getLAmount();
                    eiDialog->amountLineEdit->setText(getCharAmountForLIncome(amount));
                }

                float tax = iList.at(j).getTax();
                eiDialog->taxLineEdt->setText(getCharTaxForIncome(tax));

                strcpy(cAdditionalInfo, iList.at(j).getAdditionalInfo().c_str());
                eiDialog->additionalInfoTextEdit->setText(QString(cAdditionalInfo));

                eiDialog->setModal(true);
                //eiDialog->setVisible(true);
                //eiDialog->exec();
                eiDialog->setWindowFlags(Qt::Sheet);
                eiDialog->setWindowTitle("Income Info");
                eiDialog->setWindowModality(Qt::WindowModal);
                eiDialog->show();
                IDCode = iList.at(j).getIDCode();
                
                //disableAffectedMenus();
            }
        }

        connect(eiDialog->okButton, SIGNAL(clicked()), this,
            SLOT(insertEditedIncomeDialogValues()));
        connect(eiDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeEditedIncomeDialog()));
    }

    // The debt section
    // Add the debt information into the modal dialog
    if (selectedBudgetFrame->debtTable_2->currentItem() && (tableFocus == "debt"))
    {
        int index = selectedBudgetFrame->debtTable_2->currentRow();
        edDialog = new EditedDebtDialog(this);

        QString qsLocalIDCode = selectedBudgetFrame->debtTable_2->item(index, 6)->text();
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

        for (int j = 0; j < dList.size(); j++)
        {
            if (dList.at(j).getIDCode() == localIDCode)
            {
                strcpy(cName, dList.at(j).getName().c_str());
                edDialog->nameLineEdit->setText(QString(cName));

                int year = dList.at(j).getDueDate().getYear();
                int month = dList.at(j).getDueDate().getMonth();
                int day = dList.at(j).getDueDate().getDay();
                edDialog->dueDateEdit->setDate(QDate(year, month, day));

                PriorityLevel pLevel = dList.at(j).getPriorityLevel();
                if (pLevel == HIGH)
                    edDialog->priorityLevelComboBox->setCurrentIndex(0);
                if (pLevel == MEDIUM)
                    edDialog->priorityLevelComboBox->setCurrentIndex(1);
                if (pLevel == LOW)
                    edDialog->priorityLevelComboBox->setCurrentIndex(2);
                if (pLevel == NONE)
                    edDialog->priorityLevelComboBox->setCurrentIndex(3);

                if (dList.at(j).getAmountType() == "double")
                {
                    double amount = dList.at(j).getAmount();
                    edDialog->amountLineEdit->setText(getCharAmountForDebt(amount));
                }
                else
                {
                    long amount = dList.at(j).getLAmount();
                    edDialog->amountLineEdit->setText(getCharAmountForLDebt(amount));
                }

                float APR = dList.at(j).getAPR();
                edDialog->APRLineEdit->setText(getCharAPRForDebt(APR));

                strcpy(cAdditionalInfo, dList.at(j).getAdditionalInfo().c_str());
                edDialog->additionalInfoTextEdit->setText(QString(cAdditionalInfo));

                int numberOfMonths = dList.at(j).getNumberOfMonths();
                edDialog->numberOfMonthsLineEdit->setText(getCharNumberOfMonthsForDebt(numberOfMonths));

                edDialog->setModal(true);
                //edDialog->setVisible(true);
                edDialog->setWindowFlags(Qt::Sheet);
                edDialog->setWindowTitle("Debt Info");
                edDialog->show();
                IDCode = dList.at(j).getIDCode();
            }
        }

        connect(edDialog->okButton, SIGNAL(clicked()), this,
            SLOT(insertEditedDebtDialogValues()));
        connect(edDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeEditedDebtDialog()));
    }

    // The expenses section
    // Add the expenses information into the modal dialog
    if (selectedBudgetFrame->expensesTable_2->currentItem() && (tableFocus == "expenses"))
    {
        int index = selectedBudgetFrame->expensesTable_2->currentRow();
        eeDialog = new EditedExpensesDialog(this);

        QString qsLocalIDCode = selectedBudgetFrame->expensesTable_2->item(index, 6)->text();
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

        for (int j = 0; j < eList.size(); j++)
        {
            if (eList.at(j).getIDCode() == localIDCode)
            {
                strcpy(cName, eList.at(j).getName().c_str());
                eeDialog->nameLineEdit->setText(QString(cName));

                int year = eList.at(j).getDueDate().getYear();
                int month = eList.at(j).getDueDate().getMonth();
                int day = eList.at(j).getDueDate().getDay();
                eeDialog->dueDateEdit->setDate(QDate(year, month, day));

                PriorityLevel pLevel = eList.at(j).getPriorityLevel();
                if (pLevel == HIGH)
                    eeDialog->priorityLevelComboBox->setCurrentIndex(0);
                if (pLevel == MEDIUM)
                    eeDialog->priorityLevelComboBox->setCurrentIndex(1);
                if (pLevel == LOW)
                    eeDialog->priorityLevelComboBox->setCurrentIndex(2);
                if (pLevel == NONE)
                    eeDialog->priorityLevelComboBox->setCurrentIndex(3);

                if (eList.at(j).getAmountType() == "double")
                {
                    double amount = eList.at(j).getAmount();
                    eeDialog->amountLineEdit->setText(getCharAmountForExpenses(amount));
                }
                else
                {
                    long amount = eList.at(j).getLAmount();
                    eeDialog->amountLineEdit->setText(getCharAmountForLExpenses(amount));
                }

                double penalty = eList.at(j).getPenalty();
                eeDialog->penaltyLineEdit->setText(getCharPenaltyForExpenses(penalty));

                strcpy(cAdditionalInfo, eList.at(j).getAdditionalInfo().c_str());
                eeDialog->additionalInfoTextEdit->setText(QString(cAdditionalInfo));

                eeDialog->setModal(true);
                //eeDialog->setVisible(true);
                eeDialog->setWindowFlags(Qt::Sheet);
                eeDialog->setWindowTitle("Expense Info");
                eeDialog->show();
                IDCode = eList.at(j).getIDCode();
            }
        }

        connect(eeDialog->okButton, SIGNAL(clicked()), this,
            SLOT(insertEditedExpensesDialogValues()));
        connect(eeDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeEditedExpensesDialog()));
    }
}


/**
 Opens a modal dialog to edit budget values.
 
 @param  none.
 @return nothing.
 */
void MainBudget::insertEditedIncomeDialogValues()
{
    QString qsName = eiDialog->nameLineEdit->displayText();
    QChar * qcName = qsName.data();
    char cName[qsName.size() + 1];

    for (int i = 0; i < qsName.size() + 1; i++)
    {
        cName[i] = qcName->toAscii();
        ++qcName;
    }

    string name = string(cName);

    QDate qdDate = eiDialog->dateEdit->date();
    int year = qdDate.year();
    int month = qdDate.month();
    int day = qdDate.day();
    Date date(year, month, day, 0, 0, 0);

    QString qsNature = eiDialog->natureComboBox->currentText();
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


    QString qsAmount = eiDialog->amountLineEdit->text();
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

    QString qsTax = eiDialog->taxLineEdt->text();
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

    QString qsAdditionalInfo = eiDialog->additionalInfoTextEdit->toPlainText();
    QChar * qcAdditionalInfo = qsAdditionalInfo.data();
    char cAdditionalInfo[qsAdditionalInfo.size() + 1];
    
    for (int m = 0; m < qsAdditionalInfo.size() + 1; m++)
    {
        cAdditionalInfo[m] = qcAdditionalInfo->toAscii();
        ++qcAdditionalInfo;
    }

    string additionalInfo = string(cAdditionalInfo);

    if (strtold(cAmount, NULL) > 999999)
    {
        editIncome(name, 0, false, 0, date,
                   nature, tax, additionalInfo, mainBudgetTab.currentIndex(), iList, IDCode);
        editLIncome(name, lAmount, false, 0, date,
            nature, tax, additionalInfo, mainBudgetTab.currentIndex(), iList, IDCode);
    }
    else
    {
        editLIncome(name, 0, false, 0, date,
                    nature, tax, additionalInfo, mainBudgetTab.currentIndex(), iList, IDCode);
        editIncome(name, amount, false, 0, date,
            nature, tax, additionalInfo, mainBudgetTab.currentIndex(), iList, IDCode);
    }

    //eiDialog->setModal(false);
    eiDialog->done(0);
    //enableAffectedMenus();
    populateIncomeTable(iList);
    monthlyIncome = 0;
    monthlyLIncome = 0;
    for (int i = 0; i < iList.size(); i++)
    {
        if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (iList.at(i).getAmountType() == "long")
                containsLongIncome = true;
            monthlyIncome += iList.at(i).getNetAmount();
            monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
        }
    }
    //if (containsLongIncome)
        bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
    //else
    //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));
    setCurrentBalance();
    
    documentModified = true;
    if (fileNameWithoutFullPath == "")
        setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
    else
        setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath + " - Modified");
}


/**
 Close the edited income dialog.
 
 @param  none.
 @return nothing.
 */
void MainBudget::closeEditedIncomeDialog()
{
    //eiDialog->setModal(false);
    eiDialog->done(0);
    //enableAffectedMenus();
}


/**
 Set the table focus to income.
 
 @param  none.
 @return nothing.
 */
void MainBudget::setIncomeTableFocus()
{
    tableFocus = "income";
}


/**
 Populate the debt table with the debt list.
 
 @param  dList  the debt list.
 @return        nothing.
 */
void MainBudget::populateDebtTable(DebtList dList)
{
    selectedBudgetFrame->debtTable_2->setRowCount(0);
    for (int i = 0; i < dList.size(); i++)
    {
        if (mainBudgetTab.currentIndex() == dList.at(i).getTabIndex())
        {
            selectedBudgetFrame->debtTable_2->setRowCount(selectedBudgetFrame->debtTable_2->rowCount() + 1);
            insertDebtValues(selectedBudgetFrame->debtTable_2->rowCount() - 1, &dList.at(i));
        }
    }
}


/**
 Get the debt name as a char.
 
 @param   name   the debt name.
 @return  cName  the name in char form.
 */
char * MainBudget::getCharNameForDebt(string name)
{
    strcpy(cName, name.c_str());
    return cName;
}


/**
 Get the debt date as a char.
 
 @param   date      the debt date.
 @return  cTheDate  the date in char form.
 */
char * MainBudget::getCharDateForDebt(Date date)
{
    ostringstream ostrYear;
    ostringstream ostrMonth;
    ostringstream ostrDay;
    ostrYear << date.getYear();
    string year = ostrYear.str();
    ostrMonth << date.getMonth();
    string month = ostrMonth.str();
    ostrDay << date.getDay();
    string day = ostrDay.str();
    string theDate = day + "/" + month + "/" + year;

    for (int i = 0; i < 11; i++)
        cTheDate[i] = theDate[i];
    return cTheDate;
}


/**
 Get the debt priority level as a char.
 
 @param   pLevel          the debt priority level.
 @return  cPriorityLevel  the priority level in char form.
 */
char * MainBudget::getCharPriorityLevelForDebt(PriorityLevel pLevel)
{
    if (pLevel == HIGH)
        cPriorityLevel = "HIGH";
    else if (pLevel == MEDIUM)
        cPriorityLevel = "MEDIUM";
    else if (pLevel == LOW)
        cPriorityLevel = "LOW";
    else if (pLevel == NONE)
        cPriorityLevel = "NONE";
    return cPriorityLevel;
}


/**
 Get the debt amount as a char.
 
 @param   amount   the debt amount.
 @return  cAmount  the amount in char form.
 */
char * MainBudget::getCharAmountForDebt(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();

    for (int i = 0; i < 16; i++)
        cAmount[i] = sAmount[i];
    return cAmount;
}


/**
 Get the debt amount(long) as a char.
 
 @param   lAmount   the debt amount(long).
 @return  cAmount   the amount in char form.
 */
char * MainBudget::getCharAmountForLDebt(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();

    for (int i = 0; i < 16; i++)
        cAmount[i] = sAmount[i];
    return cAmount;
}


/**
 Get the debt APR as a char.
 
 @param   APR      the debt APR.
 @return  cAPR     the APR in char form.
 */
char * MainBudget::getCharAPRForDebt(float APR)
{
    ostringstream ostrAPR;
    ostrAPR << APR;
    string sAPR = ostrAPR.str();

    for (int i = 0; i < 11; i++)
        cAPR[i] = sAPR[i];
    return cAPR;
}


/**
 Get the debt APR as a char.
 
 @param   APR      the debt APR.
 @return  cAPR     the APR in char form.
 */
char * MainBudget::getCharNumberOfMonthsForDebt(int numberOfMonths)
{
    ostringstream ostrNumberOfMonths;
    ostrNumberOfMonths << numberOfMonths;
    string sNumberOfMonths = ostrNumberOfMonths.str();

    for (int i = 0; i < 16; i++)
        cNumberOfMonths[i] = sNumberOfMonths[i];
    return cNumberOfMonths;
}


/**
 Get the debt APR as a char.
 
 @param   APR      the debt APR.
 @return  cAPR     the APR in char form.
 */
char * MainBudget::getCharNetAmountForDebt(double netAmount)
{
    ostringstream ostrNetAmount;
    ostrNetAmount << netAmount;
    string sNetAmount = ostrNetAmount.str();

    for (int i = 0; i < 16; i++)
        cNetAmount[i] = sNetAmount[i];
    return cNetAmount;
}


/**
 Get the debt net amount as a char.
 
 @param   netLAmount    the debt net amount(long).
 @return  cNetAmount    the APR in char form.
 */
char * MainBudget::getCharNetAmountForLDebt(long netLAmount)
{
    ostringstream ostrNetAmount;
    ostrNetAmount << netLAmount;
    string sNetAmount = ostrNetAmount.str();

    for (int i = 0; i < 16; i++)
        cNetAmount[i] = sNetAmount[i];
    return cNetAmount;
}


/**
 Get the debt net amount as a char.
 
 @param   netLAmount    the debt net amount(long).
 @return  cNetAmount    the APR in char form.
 */
char * MainBudget::getCharIDCodeForDebt(int IDCode)
{
    ostringstream ostrIDCode;
    ostrIDCode << IDCode;
    string sIDCode = ostrIDCode.str();

    for (int i = 0; i < 16; i++)
        cIDCode[i] = sIDCode[i];
    return cIDCode;
}


/**
 Get the debt net amount as a char.
 
 @param   i      the index.
 @param   debt   the debt.
 @return         nothing.
 */
void MainBudget::insertDebtValues(int i, Debt * debt)
{
    selectedBudgetFrame->debtTable_2->setItem(i, 0, new QTableWidgetItem(QString(getCharDateForDebt(debt->getDueDate()))));
    selectedBudgetFrame->debtTable_2->setItem(i, 1, new QTableWidgetItem(QString(getCharNameForDebt(debt->getName()))));
    selectedBudgetFrame->debtTable_2->setItem(i, 2, new QTableWidgetItem(QString(getCharPriorityLevelForDebt(debt->getPriorityLevel()))));
    if (debt->getAmountType() == "double")
        selectedBudgetFrame->debtTable_2->setItem(i, 3, new QTableWidgetItem(QString(getCharAmountForDebt(debt->getAmount()))));
    else
        selectedBudgetFrame->debtTable_2->setItem(i, 3, new QTableWidgetItem(QString(getCharAmountForLDebt(debt->getLAmount()))));
    selectedBudgetFrame->debtTable_2->setItem(i, 4, new QTableWidgetItem(QString(getCharAPRForDebt(debt->getAPR()))));
    if (debt->getAmountType() == "long")
        selectedBudgetFrame->debtTable_2->setItem(i, 5, new QTableWidgetItem(QString(getCharNetAmountForLDebt(debt->getNetLAmount()))));
    else
        selectedBudgetFrame->debtTable_2->setItem(i, 5, new QTableWidgetItem(QString(getCharNetAmountForDebt(debt->getNetAmount()))));
    selectedBudgetFrame->debtTable_2->setItem(i, 6, new QTableWidgetItem(QString(getCharIDCodeForDebt(debt->getIDCode()))));
}


/**
 Set the table focus to debt.
 
 @param   none
 @return  nothing.
 */
void MainBudget::setDebtTableFocus()
{
    tableFocus = "debt";

}


/**
 Insert edited debt dialog values into the
 debt table.
 
 @param   none
 @return  nothing.
 */
void MainBudget::insertEditedDebtDialogValues()
{
    QString qsName = edDialog->nameLineEdit->displayText();
    QChar * qcName = qsName.data();
    char cName[qsName.size() + 1];

    for (int i = 0; i < qsName.size() + 1; i++)
    {
        cName[i] = qcName->toAscii();
        ++qcName;
    }

    string name = string(cName);

    QDate qdDate = edDialog->dueDateEdit->date();
    int year = qdDate.year();
    int month = qdDate.month();
    int day = qdDate.day();
    Date date(year, month, day, 0, 0, 0);

    QString qsPriorityLevel = edDialog->priorityLevelComboBox->currentText();
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


    QString qsAmount = edDialog->amountLineEdit->text();
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

    QString qsAPR = edDialog->APRLineEdit->text();
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

    QString qsAdditionalInfo = edDialog->additionalInfoTextEdit->toPlainText();
    QChar * qcAdditionalInfo = qsAdditionalInfo.data();
    char cAdditionalInfo[qsAdditionalInfo.size() + 1];

    for (int m = 0; m < qsAdditionalInfo.size() + 1; m++)
    {
        cAdditionalInfo[m] = qcAdditionalInfo->toAscii();
        ++qcAdditionalInfo;
    }

    string additionalInfo = string(cAdditionalInfo);

    QString qsNumberOfMonths = edDialog->numberOfMonthsLineEdit->text();
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

    if (strtold(cAmount, NULL) > 999999)
    {
        editDebt(name, 0, true, APR, pLevel,
                 date, additionalInfo, numberOfMonths, mainBudgetTab.currentIndex(), dList, IDCode);
        editLDebt(name, lAmount, true, APR, pLevel,
            date, additionalInfo, numberOfMonths, mainBudgetTab.currentIndex(), dList, IDCode);
    }
    else
    {
        editLDebt(name, 0, true, APR, pLevel,
                  date, additionalInfo, numberOfMonths, mainBudgetTab.currentIndex(), dList, IDCode);
        editDebt(name, amount, true, APR, pLevel,
            date, additionalInfo, numberOfMonths, mainBudgetTab.currentIndex(), dList, IDCode);
    }

    //edDialog->setModal(false);
    edDialog->done(0);
    populateDebtTable(dList);
    monthlyDebt = 0;
    monthlyLDebt = 0;
    for (int i = 0; i < dList.size(); i++)
    {
        if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (dList.at(i).getAmountType() == "long")
                containsLongDebt = true;
            monthlyDebt += dList.at(i).getNetAmount();
            monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
        }
    }
    //if (containsLongDebt)
        bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
    //else
    //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));
    setCurrentBalance();
    
    documentModified = true;
    if (fileNameWithoutFullPath == "")
        setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
    else
        setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath + " - Modified");
}


/**
 Close the edited debt dialog.
 
 @param   none
 @return  nothing.
 */
void MainBudget::closeEditedDebtDialog()
{
    //edDialog->setModal(false);
    edDialog->done(0);
}


/**
 Close the save money dialog.
 
 @param   none
 @return  nothing.
 */
void MainBudget::closeSaveMoneyDialog()
{
    //smDialog->setModal(false);
    smDialog->done(0);
}

void MainBudget::populateExpensesTable(ExpenseList eList)
{
    selectedBudgetFrame->expensesTable_2->setRowCount(0);
    for (int i = 0; i < eList.size(); i++)
    {
        if (mainBudgetTab.currentIndex() == eList.at(i).getTabIndex())
        {
            selectedBudgetFrame->expensesTable_2->setRowCount(selectedBudgetFrame->expensesTable_2->rowCount() + 1);
            insertExpenseValues(selectedBudgetFrame->expensesTable_2->rowCount() - 1, &eList.at(i));
        }
    }
}


/**
 Get the expense name in char format.
 
 @param   name  the expense name in string formate
 @return  cName the expense name in char format.
 */
char * MainBudget::getCharNameForExpenses(string name)
{
    strcpy(cName, name.c_str());
    return cName;
}


/**
 Get the expense date in char format.
 
 @param   date     the expense date
 @return  cTheDate the expense date in char format.
 */
char * MainBudget::getCharDateForExpenses(Date date)
{
    ostringstream ostrYear;
    ostringstream ostrMonth;
    ostringstream ostrDay;
    ostrYear << date.getYear();
    string year = ostrYear.str();
    ostrMonth << date.getMonth();
    string month = ostrMonth.str();
    ostrDay << date.getDay();
    string day = ostrDay.str();
    string theDate = day + "/" + month + "/" + year;

    for (int i = 0; i < 11; i++)
        cTheDate[i] = theDate[i];
    return cTheDate;
}

char * MainBudget::getCharPriorityLevelForExpenses(PriorityLevel pLevel)
{
    if (pLevel == HIGH)
        cPriorityLevel = "HIGH";
    else if (pLevel == MEDIUM)
        cPriorityLevel = "MEDIUM";
    else if (pLevel == LOW)
        cPriorityLevel = "LOW";
    else if (pLevel == NONE)
        cPriorityLevel = "NONE";
    return cPriorityLevel;
}

char * MainBudget::getCharAmountForExpenses(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();
    
    for (int i = 0; i < 16; i++)
        cAmount[i] = sAmount[i];
    return cAmount;
}

char * MainBudget::getCharAmountForLExpenses(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();

    for (int i = 0; i < 16; i++)
        cAmount[i] = sAmount[i];
    return cAmount;
}

char * MainBudget::getCharPenaltyForExpenses(double penalty)
{
    ostringstream ostrPenalty;
    ostrPenalty << penalty;
    string sPenalty = ostrPenalty.str();

    for (int i = 0; i < 16; i++)
        cPenalty[i] = sPenalty[i];
    return cPenalty;
}

char * MainBudget::getCharNetAmountForExpenses(double netAmount)
{
    ostringstream ostrNetAmount;
    ostrNetAmount << netAmount;
    string sNetAmount = ostrNetAmount.str();

    for (int i = 0; i < 16; i++)
        cNetAmount[i] = sNetAmount[i];
    return cNetAmount;
}

char * MainBudget::getCharNetAmountForLExpenses(long netLAmount)
{
    ostringstream ostrNetAmount;
    ostrNetAmount << netLAmount;
    string sNetAmount = ostrNetAmount.str();

    for (int i = 0; i < 16; i++)
        cNetAmount[i] = sNetAmount[i];
    return cNetAmount;
}

char * MainBudget::getCharIDCodeForExpenses(int IDCode)
{
    ostringstream ostrIDCode;
    ostrIDCode << IDCode;
    string sIDCode = ostrIDCode.str();

    for (int i = 0; i < 16; i++)
        cIDCode[i] = sIDCode[i];
    return cIDCode;
}

void MainBudget::setExpensesTableFocus()
{
    tableFocus = "expenses";

}

void MainBudget::insertExpenseValues(int i, Expense * expense)
{
    selectedBudgetFrame->expensesTable_2->setItem(i, 0, new QTableWidgetItem(QString(getCharDateForExpenses(expense->getDueDate()))));
    selectedBudgetFrame->expensesTable_2->setItem(i, 1, new QTableWidgetItem(QString(getCharNameForExpenses(expense->getName()))));
    selectedBudgetFrame->expensesTable_2->setItem(i, 2, new QTableWidgetItem(QString(getCharPriorityLevelForExpenses(expense->getPriorityLevel()))));
    if (expense->getAmountType() == "double")
        selectedBudgetFrame->expensesTable_2->setItem(i, 3, new QTableWidgetItem(QString(getCharAmountForExpenses(expense->getAmount()))));
    else
        selectedBudgetFrame->expensesTable_2->setItem(i, 3, new QTableWidgetItem(QString(getCharAmountForLExpenses(expense->getLAmount()))));
    selectedBudgetFrame->expensesTable_2->setItem(i, 4, new QTableWidgetItem(QString(getCharPenaltyForExpenses(expense->getPenalty()))));
    if (expense->getAmountType() == "long")
        selectedBudgetFrame->expensesTable_2->setItem(i, 5, new QTableWidgetItem(QString(getCharNetAmountForLExpenses(expense->getNetLAmount()))));
    else
        selectedBudgetFrame->expensesTable_2->setItem(i, 5, new QTableWidgetItem(QString(getCharNetAmountForExpenses(expense->getNetAmount()))));
    selectedBudgetFrame->expensesTable_2->setItem(i, 6, new QTableWidgetItem(QString(getCharIDCodeForExpenses(expense->getIDCode()))));
}

void MainBudget::closeEditedExpensesDialog()
{
    //eeDialog->setModal(false);
    eeDialog->done(0);
}

void MainBudget::insertEditedExpensesDialogValues()
{
    QString qsName = eeDialog->nameLineEdit->displayText();
    QChar * qcName = qsName.data();
    char cName[qsName.size() + 1];
    for (int i = 0; i < qsName.size() + 1; i++)
    {
        cName[i] = qcName->toAscii();
        ++qcName;
    }

    string name = string(cName);

    QDate qdDate = eeDialog->dueDateEdit->date();
    int year = qdDate.year();
    int month = qdDate.month();
    int day = qdDate.day();
    Date date(year, month, day, 0, 0, 0);

    QString qsPriorityLevel = eeDialog->priorityLevelComboBox->currentText();
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


    QString qsAmount = eeDialog->amountLineEdit->text();
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

    QString qsPenalty = eeDialog->penaltyLineEdit->text();
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

    QString qsAdditionalInfo = eeDialog->additionalInfoTextEdit->toPlainText();
    QChar * qcAdditionalInfo = qsAdditionalInfo.data();
    char cAdditionalInfo[qsAdditionalInfo.size() + 1];

    for (int m = 0; m < qsAdditionalInfo.size() + 1; m++)
    {
        cAdditionalInfo[m] = qcAdditionalInfo->toAscii();
        ++qcAdditionalInfo;
    }

    string additionalInfo = string(cAdditionalInfo);


    if (strtold(cAmount, NULL) > 999999)
    {
        cout << lAmount << endl;
        editExpense(name, 0, pLevel, penalty,
                    date, additionalInfo, mainBudgetTab.currentIndex(), eList, IDCode);
        editLExpense(name, lAmount, pLevel, penalty,
            date, additionalInfo, mainBudgetTab.currentIndex(), eList, IDCode);
            //cout << "it works" << endl;
    }
    else
    {
        editLExpense(name, 0, pLevel, penalty,
                     date, additionalInfo, mainBudgetTab.currentIndex(), eList, IDCode);
        editExpense(name, amount, pLevel, penalty,
            date, additionalInfo, mainBudgetTab.currentIndex(), eList, IDCode);
    }
    
    //eeDialog->setModal(false);
    eeDialog->done(0);
    populateExpensesTable(eList);
    monthlyExpenses = 0;
    monthlyLExpenses = 0;
    for (int i = 0; i < eList.size(); i++)
    {
        if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (eList.at(i).getAmountType() == "long")
                containsLongExpense = true;
            monthlyExpenses += eList.at(i).getNetAmount();
            monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
        }
    }
    //if (containsLongExpense)
        bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
    //else
    //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

    setCurrentBalance();
    
    documentModified = true;
    if (fileNameWithoutFullPath == "")
        setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
    else
        setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath + " - Modified");
}

void MainBudget::insertSaveMoneyValues()
{
    if (sList.size() > 0)
    {
    int index = smDialog->selectSavingsComboBox->currentIndex();
    int savingsIDCode = sList.at(index).getIDCode();

    QString qsAmount = smDialog->amountLineEdit->text();
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

    QDate qdDate = bd->calendar->selectedDate();
    Date dueDate(qdDate.year(), qdDate.month(), qdDate.day(), 0, 0, 0);

    string additionalInfo;
    SavingsNature nature = sList.at(index).getNature();
    if (nature == STOCK)
        additionalInfo = "Stock/Share Buy";
    if (nature == BANK)
        additionalInfo = "Rudimentary Saving";

    if (strtold(cAmount, NULL) > 999999)
    {
        saveLMoney(eList, sList, savingsIDCode,
            lAmount, LOW, dueDate, additionalInfo, mainBudgetTab.currentIndex());
    }
    else
    {
        saveMoney(eList, sList, savingsIDCode,
            amount, LOW, dueDate, additionalInfo, mainBudgetTab.currentIndex());
    }

    //smDialog->setModal(false);
    smDialog->done(0);

    populateExpensesTable(eList);
    populateSavingsTable(sList);

    savingsBalance = 0;
    savingsLBalance = 0;
    for (int i = 0; i < sList.size(); i++)
    {
        if (sList.at(i).getAmountType() == "long")
            containsLongAssSaving = true;
        savingsBalance += sList.at(i).getAmount();
        savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
    }
    //if (containsLongAssSaving)
        sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
    //else
    //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));

    monthlyExpenses = 0;
    monthlyLExpenses = 0;
    for (int i = 0; i < eList.size(); i++)
    {
        if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (eList.at(i).getAmountType() == "long")
                containsLongExpense = true;
            monthlyExpenses += eList.at(i).getNetAmount();
            monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
            cout << monthlyLExpenses << endl;
        }
    }
    //if (containsLongExpense)
        bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
    //else
    //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

    setCurrentBalance();

    }
    else
    {
        //smDialog->setModal(false);
        smDialog->done(0);
    }
}

/* SAVINGS DIALOG SECTION----------------------------------------------------------------------------------------*/

void MainBudget::populateSavingsTable(SavingsList sList)
{
    sd->savingsTable->setRowCount(0);
    for (int i = 0; i < sList.size(); i++)
    {
        sd->savingsTable->setRowCount(i + 1);
        insertSavingsValues(i, &sList.at(i));
    }
}

char * MainBudget::getCharNameForSavings(string name)
{
    strcpy(cName, name.c_str());
    return cName;
}

char * MainBudget::getCharNatureForSavings(SavingsNature nature)
{
    if (nature == STOCK)
        cNature = "STOCK";
    else if (nature == BANK)
        cNature = "BANK";
    return cNature;
}

char * MainBudget::getCharAmountForSavings(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cAmount[i] = sAmount[i];
    return cAmount;
}

char * MainBudget::getCharAmountForLSavings(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();
    for (int i = 0; i < 16; i++)
        cAmount[i] = sAmount[i];
    return cAmount;
}

char * MainBudget::getCharAPRForSavings(float APR)
{
    ostringstream ostrAPR;
    ostrAPR << APR;
    string sAPR = ostrAPR.str();
    for (int i = 0; i < 16; i++)
        cAPR[i] = sAPR[i];
    return cAPR;
}

void MainBudget::insertSavingsValues(int i, Savings * savings)
{
    sd->savingsTable->setItem(i, 0, new QTableWidgetItem(QString(getCharNameForSavings(savings->getName()))));
    sd->savingsTable->setItem(i, 1, new QTableWidgetItem(QString(getCharNatureForSavings(savings->getNature()))));
    sd->savingsTable->setItem(i, 2, new QTableWidgetItem(QString(getCharAPRForSavings(savings->getAPR()))));
    if (savings->getAmountType() == "double")
        sd->savingsTable->setItem(i, 3, new QTableWidgetItem(QString(getCharAmountForSavings(savings->getAmount()))));
    else
        sd->savingsTable->setItem(i, 3, new QTableWidgetItem(QString(getCharAmountForLSavings(savings->getLAmount()))));
}

void MainBudget::editSelectedSavings()
{
    if (sd->savingsTable->currentItem() && (tableFocus == "savings"))
    {
        int index = sd->savingsTable->currentRow();
        esvDialog = new EditedSavingsDialog(this);

        strcpy(cName, sList.at(index).getName().c_str());
        esvDialog->nameLineEdit->setText(QString(cName));

        SavingsNature nature = sList.at(index).getNature();
        if (nature == STOCK)
            esvDialog->natureComboBox->setCurrentIndex(0);
        if (nature == BANK)
            esvDialog->natureComboBox->setCurrentIndex(1);



        if (sList.at(index).getAmountType() == "double")
        {
            double amount = sList.at(index).getAmount();
            esvDialog->amountLineEdit->setText(getCharAmountForSavings(amount));
        }
        else
        {
            long amount = sList.at(index).getLAmount();
            esvDialog->amountLineEdit->setText(getCharAmountForLSavings(amount));
        }

        float APR = sList.at(index).getAPR();
        esvDialog->APRLineEdit->setText(getCharAPRForSavings(APR));

        int year = sList.at(index).getDate().getYear();
        int month = sList.at(index).getDate().getMonth();
        int day = sList.at(index).getDate().getDay();
        esvDialog->dueDateEdit->setDate(QDate(year, month, day));

        strcpy(cDescription, sList.at(index).getDescription().c_str());
        esvDialog->descriptionTextEdit->setText(QString(cDescription));

        esvDialog->setModal(true);
        //esvDialog->setVisible(true);
        esvDialog->setWindowFlags(Qt::Sheet);
        esvDialog->setWindowTitle("Savings Info");
        esvDialog->show();
        IDCode = sList.at(index).getIDCode();

        connect(esvDialog->okButton, SIGNAL(clicked()), this,
            SLOT(insertEditedSavingsDialogValues()));
        connect(esvDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeEditedSavingsDialog()));
    }
}

void MainBudget::setSavingsTableFocus()
{
    tableFocus = "savings";
    int index = sd->savingsTable->currentRow();
    strcpy(cDescription, sList.at(index).getDescription().c_str());
    sd->textBrowser->setPlainText(QString(cDescription));
}

void MainBudget::closeEditedSavingsDialog()
{
    //esvDialog->setModal(false);
    esvDialog->done(0);
}

void MainBudget::insertEditedSavingsDialogValues()
{
    QString qsName = esvDialog->nameLineEdit->displayText();
    QChar * qcName = qsName.data();
    char cName[qsName.size() + 1];

    for (int i = 0; i < qsName.size() + 1; i++)
    {
        cName[i] = qcName->toAscii();
        ++qcName;
    }

    string name = string(cName);

    QString qsNature = esvDialog->natureComboBox->currentText();
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


    QString qsAmount = esvDialog->amountLineEdit->text();
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

    QString qsAPR = esvDialog->APRLineEdit->text();
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

    QDate qdDate = esvDialog->dueDateEdit->date();
    int year = qdDate.year();
    int month = qdDate.month();
    int day = qdDate.day();
    Date date(year, month, day, 0, 0, 0);

    QString qsDescription = esvDialog->descriptionTextEdit->toPlainText();
    QChar * qcDescription = qsDescription.data();
    char cDescription[qsDescription.size() + 1];

    for (int m = 0; m < qsDescription.size() + 1; m++)
    {
        cDescription[m] = qcDescription->toAscii();
        ++qcDescription;
    }

    string description = string(cDescription);

    if (strtold(cAmount, NULL) > 999999)
    {
        editSavings(name, 0, APR,
                    nature, date, description, sList, IDCode);
        editLSavings(name, lAmount, APR,
            nature, date, description, sList, IDCode);
    }
    else
    {
        editLSavings(name, 0, APR,
                     nature, date, description, sList, IDCode);
        editSavings(name, amount, APR,
            nature, date, description, sList, IDCode);
    }

    //esvDialog->setModal(false);
    esvDialog->done(0);
    populateSavingsTable(sList);

    savingsBalance = 0;
    savingsLBalance = 0;
    for (int i = 0; i < sList.size(); i++)
    {
        if (sList.at(i).getAmountType() == "long")
            containsLongAssSaving = true;
        savingsBalance += sList.at(i).getAmount();
        savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
    }
    //if (containsLongAssSaving)
        sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
    //else
    //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));
    
    documentModified = true;
    if (fileNameWithoutFullPath == "")
        setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
    else
        setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath + " - Modified");
}

void MainBudget::closeGetMoneyDialog()
{
    //gmDialog->setModal(false);
    gmDialog->done(0);
}

void MainBudget::insertGetMoneyValues()
{
    if (sd->savingsTable->currentItem() && (tableFocus == "savings"))
    {
        int index = sd->savingsTable->currentRow();
        int savingsIDCode = sList.at(index).getIDCode();

        QString qsAmount = gmDialog->amountLineEdit->text();
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

        QDate qdDate = bd->calendar->selectedDate();
        Date receivedDate(qdDate.year(), qdDate.month(), qdDate.day(), 0, 0, 0);

        int year = qdDate.year();
        int month = qdDate.month();
        int day = qdDate.day();

        if (!tabTitleExists(qdDate))
        {
            mainBudgetTab.insertTab(0, new BudgetFrame, getTabBarDate(qdDate));
            mainBudgetTab.setCurrentIndex(0);
            selectedBudgetFrame->setMonth(month);
            selectedBudgetFrame->setYear(year);
            if (btl.size() > 0)
                    btl.clear();

            for (int i = 0; i < mainBudgetTab.count(); i++)
            {
                mainBudgetTab.setCurrentIndex(i);
                btl.push_back(BudgetTabItem(convertQStringToString(mainBudgetTab.tabText(i)), selectedBudgetFrame->getMonth(),
                    selectedBudgetFrame->getYear(), i));
            }

            msBudget = new MergeSortBudget(btl);
            msBudget->displayElements();
            msBudget->sort(btl);
            msBudget->displayElements();

            for (int i = 0; i < btl.size(); i++)
            {
                mainBudgetTab.setCurrentIndex(i);
                mainBudgetTab.setTabText(i, convertStringToQString(msBudget->data.at(i).getTabTitle()));
                selectedBudgetFrame->setMonth(msBudget->data.at(i).getMonth());
                selectedBudgetFrame->setYear(msBudget->data.at(i).getYear());
            }
        }

        if (strtold(cAmount, NULL) > 999999)
        {
            getLMoney(sList, iList, savingsIDCode,
                lAmount, receivedDate);
        }
        else
        {
            getMoney(sList, iList, savingsIDCode,
                amount, receivedDate);
        }

        //gmDialog->setModal(false);
        gmDialog->done(0);

        for (int j = 0; j < btl.size(); j++)
        {
            shuffleIncomeTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
                msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), iList);
        }

        populateSavingsTable(sList);

        savingsBalance = 0;
        savingsLBalance = 0;
        for (int i = 0; i < sList.size(); i++)
        {
            if (sList.at(i).getAmountType() == "long")
                containsLongAssSaving = true;
            savingsBalance += sList.at(i).getAmount();
            savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
        }
        //if (containsLongAssSaving)
            sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
        //else
        //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));

        monthlyIncome = 0;
        monthlyLIncome = 0;
        for (int i = 0; i < iList.size(); i++)
        {
            if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (iList.at(i).getAmountType() == "long")
                    containsLongIncome = true;
                monthlyIncome += iList.at(i).getNetAmount();
                monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
            }
        }
        //if (containsLongIncome)
            bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
        //else
        //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));
        setCurrentBalance();
    }
    else
    {
        //gmDialog->setModal(false);
        gmDialog->done(0);
    }
}

char * MainBudget::getCharAmountForSavingsCurrentBalance(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();

    for (int i = 0; i < 16; i++)
        cSavingsCurrentBalance[i] = sAmount[i];
    return cSavingsCurrentBalance;
}

char * MainBudget::getCharAmountForSavingsCurrentLBalance(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();

    for (int i = 0; i < 16; i++)
        cSavingsCurrentBalance[i] = sAmount[i];
    containsLongAssSaving = false;
    return cSavingsCurrentBalance;
}

/* ITEMS DIALOG SECTION----------------------------------------------------------------------------------------*/

void MainBudget::setInventoryTableFocus()
{
    tableFocus = "items";
}

void MainBudget::populateInventoryTable(ItemList itList)
{
    id->inventoryTable->setRowCount(0);
    for (int i = 0; i < itList.size(); i++)
    {
        id->inventoryTable->setRowCount(i + 1);
        insertInventoryValues(i, &itList.at(i));
    }
}

char * MainBudget::getCharIDCodeForInventory(string itemID)
{
    strcpy(cItemID, itemID.c_str());
    return cItemID;
}

char * MainBudget::getCharNameForInventory(string name)
{
    strcpy(cName, name.c_str());
    return cName;
}

char * MainBudget::getCharNoOfItemsForInventory(int number)
{
    ostringstream ostrNumber;
    ostrNumber << number;
    string sNumber = ostrNumber.str();

    for (int i = 0; i < 16; i++)
        cNumber[i] = sNumber[i];
    return cNumber;
}

char * MainBudget::getCharPriceForInventory(double price)
{
    ostringstream ostrPrice;
    ostrPrice << price;
    string sPrice = ostrPrice.str();

    for (int i = 0; i < 16; i++)
        cPrice[i] = sPrice[i];
    return cPrice;
}


void MainBudget::insertInventoryValues(int i, Items * item)
{
    id->inventoryTable->setItem(i, 0, new QTableWidgetItem(QString(getCharIDCodeForInventory(item->getItemID()))));
    id->inventoryTable->setItem(i, 1, new QTableWidgetItem(QString(getCharNameForInventory(item->getName()))));
    id->inventoryTable->setItem(i, 2, new QTableWidgetItem(QString(getCharNoOfItemsForInventory(item->getNumber()))));
    id->inventoryTable->setItem(i, 3, new QTableWidgetItem(QString(getCharPriceForInventory(item->getPrice()))));
}

void MainBudget::editSelectedInventoryItem()
{
    if (id->inventoryTable->currentItem() && (tableFocus == "items"))
    {
        int index = id->inventoryTable->currentRow();
        eitDialog = new ItemDialog(this);

        strcpy(cName, itList.at(index).getName().c_str());
        eitDialog->nameLineEdit->setText(QString(cName));

        strcpy(cItemID, itList.at(index).getItemID().c_str());
        eitDialog->IDCodeLineEdit->setText(QString(cItemID));

        int number = itList.at(index).getNumber();
        eitDialog->amountLineEdit->setText(QString(getCharNoOfItemsForInventory(number)));

        double price = itList.at(index).getPrice();
        eitDialog->priceLineEdit->setText(QString(getCharPriceForInventory(price)));

        eitDialog->setModal(true);
        //eitDialog->setVisible(true);
        eitDialog->setWindowFlags(Qt::Sheet);
        eitDialog->setWindowTitle("Item Info");
        eitDialog->show();
        IDCode = itList.at(index).getIDCode();

        connect(eitDialog->okButton, SIGNAL(clicked()), this,
            SLOT(insertEditedItemDialogValues()));
        connect(eitDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeEditedItemDialog()));
    }
}

void MainBudget::closeEditedItemDialog()
{
    //eitDialog->setModal(false);
    eitDialog->done(0);
}

void MainBudget::insertEditedItemDialogValues()
{
    QString qsName = eitDialog->nameLineEdit->displayText();
    QChar * qcName = qsName.data();
    char cName[qsName.size() + 1];

    for (int i = 0; i < qsName.size() + 1; i++)
    {
        cName[i] = qcName->toAscii();
        ++qcName;
    }

    string name = string(cName);

    QString qsItemID = eitDialog->IDCodeLineEdit->text();
    QChar * qcItemID = qsItemID.data();
    char cItemID[qsItemID.size() + 1];

    for (int k = 0; k < qsItemID.size() + 1; k++)
    {
        cItemID[k] = qcItemID->toAscii();
        ++qcItemID;
    }
    string itemID = string(cItemID);

    QString qsNumber = eitDialog->amountLineEdit->text();
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

    QString qsPrice = eitDialog->priceLineEdit->text();
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

    editItem(name, price, number, itemID, itList, IDCode);
    //eitDialog->setModal(false);
    eitDialog->done(0);
    populateInventoryTable(itList);
    
    documentModified = true;
    if (fileNameWithoutFullPath == "")
        setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
    else
        setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath + " - Modified");
}

/* REMINDERS DIALOG SECTION----------------------------------------------------------------------------------------*/

void MainBudget::setRemindersTableFocus()
{
    tableFocus = "reminders";
    int index = rd->remindersTable->currentRow();
    strcpy(cMessage, rList.at(index).getMessage().c_str());
    rd->textBrowser->setPlainText(QString(cMessage));
}

void MainBudget::populateReminderTable(ReminderList rList)
{
    rd->remindersTable->setRowCount(0);
    for (int i = 0; i < rList.size(); i++)
    {
        rd->remindersTable->setRowCount(i + 1);
        insertReminderValues(i, &rList.at(i));
    }
}

char * MainBudget::getCharDateForReminders(Date date)
{
    ostringstream ostrYear;
    ostringstream ostrMonth;
    ostringstream ostrDay;
    ostrYear << date.getYear();
    string year = ostrYear.str();
    ostrMonth << date.getMonth();
    string month = ostrMonth.str();
    ostrDay << date.getDay();
    string day = ostrDay.str();
    string theDate = day + "/" + month + "/" + year;

    for (int i = 0; i < 11; i++)
        cTheDate[i] = theDate[i];
    return cTheDate;
}

char * MainBudget::getCharSubjectForReminders(string subject)
{
    strcpy(cSubject, subject.c_str());
    return cSubject;
}

void MainBudget::insertReminderValues(int i, Reminder * reminder)
{
    rd->remindersTable->setItem(i, 0, new QTableWidgetItem(QString(getCharDateForReminders(reminder->getDueDate()))));
    rd->remindersTable->setItem(i, 1, new QTableWidgetItem(QString(getCharSubjectForReminders(reminder->getSubject()))));
}

void MainBudget::editSelectedReminder()
{
    if (rd->remindersTable->currentItem() && (tableFocus == "reminders"))
    {
        int index = rd->remindersTable->currentRow();
        reminderIndex = index;
        ermDialog = new ReminderDialog(this);

        strcpy(cSubject, rList.at(index).getSubject().c_str());
        ermDialog->subjectLineEdit->setText(QString(cSubject));


        int year = rList.at(index).getDueDate().getYear();
        int month = rList.at(index).getDueDate().getMonth();
        int day = rList.at(index).getDueDate().getDay();
        int hour = rList.at(index).getDueDate().getHour();
        int minute = rList.at(index).getDueDate().getMinute();
        int second = rList.at(index).getDueDate().getSecond();
        ermDialog->dateTimeEdit->setDate(QDate(year, month, day));
        ermDialog->dateTimeEdit->setTime(QTime(hour, minute, second));

        strcpy(cMessage, rList.at(index).getMessage().c_str());
        ermDialog->messageTextEdit->setPlainText(QString(cMessage));

        ermDialog->setModal(true);
        //ermDialog->setVisible(true);
        ermDialog->setWindowFlags(Qt::Sheet);
        ermDialog->setWindowTitle("Reminder Info");
        ermDialog->show();
        IDCode = rList.at(index).getIDCode();

        connect(ermDialog->okButton, SIGNAL(clicked()), this,
            SLOT(insertEditedReminderDialogValues()));
        connect(ermDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeEditedReminderDialog()));
    }
}

void MainBudget::closeEditedReminderDialog()
{
    //ermDialog->setModal(false);
    ermDialog->done(0);
}

void MainBudget::insertEditedReminderDialogValues()
{
    QString qsSubject = ermDialog->subjectLineEdit->displayText();
    QChar * qcSubject = qsSubject.data();
    char cSubject[qsSubject.size() + 1];

    for (int i = 0; i < qsSubject.size() + 1; i++)
    {
        cSubject[i] = qcSubject->toAscii();
        ++qcSubject;
    }

    string subject = string(cSubject);

    sd->calendar->repaintReminders(reminderIndex);
    id->calendar->repaintReminders(reminderIndex);
    rd->calendar->repaintReminders(reminderIndex);

    QDate qdDate = ermDialog->dateTimeEdit->date();
    QTime qdTime = ermDialog->dateTimeEdit->time();
    int year = qdDate.year();
    int month = qdDate.month();
    int day = qdDate.day();
    int hour = qdTime.hour();
    int minute = qdTime.minute();
    int second = qdTime.second();
    Date date(year, month, day, hour, minute, second);
    sd->calendar->setReminderDate(QDate(year, month, day));
    id->calendar->setReminderDate(QDate(year, month, day));
    rd->calendar->setReminderDate(QDate(year, month, day));

    QString qsMessage = ermDialog->messageTextEdit->toPlainText();
    QChar * qcMessage = qsMessage.data();
    char cMessage[qsMessage.size() + 1];
    
    for (int m = 0; m < qsMessage.size() + 1; m++)
    {
        cMessage[m] = qcMessage->toAscii();
        ++qcMessage;
    }

    string message = string(cMessage);


    editReminder(date, subject, message,
        HIGH, rList, IDCode);
    //ermDialog->setModal(false);
    ermDialog->done(0);
    populateReminderTable(rList);
    
    documentModified = true;
    if (fileNameWithoutFullPath == "")
        setWindowTitle("CakeHeap Budget Professional  - untitled.chf - Modified");
    else
        setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath + " - Modified");
}

/* CUT, COPY AND PASTE SECTION */

void MainBudget::copyEntry()
{
    entryType = tableFocus;

    if (selectedBudgetFrame->incomeTable_2->currentItem() && (entryType == "income"))
    {
        int index = selectedBudgetFrame->incomeTable_2->currentRow();

        QString qsLocalIDCode = selectedBudgetFrame->incomeTable_2->item(index, 6)->text();
        QChar * qcLocalIDCode = qsLocalIDCode.data();
        char cLocalIDCode[16];
        int i = 0;
        while (!qcLocalIDCode->isNull())
        {
            cLocalIDCode[i] = qcLocalIDCode->toAscii();
            ++qcLocalIDCode;
            i++;
        }
        incomeEntryLocalIDCode = atoi(cLocalIDCode);

        for (int j = 0; j < iList.size(); j++)
        {
            if (iList.at(j).getIDCode() == incomeEntryLocalIDCode)
            {
                strcpy(cIncomeEntryName, iList.at(j).getName().c_str());

                QDate qCurrentDate = QDate::currentDate();

                incomeEntryYear = qCurrentDate.year();
                incomeEntryMonth = qCurrentDate.month();
                incomeEntryDay = qCurrentDate.day();

                incomeEntryNature = iList.at(j).getNature();

                if (iList.at(j).getAmountType() == "double")
                {
                    dIncomeEntryAmount = iList.at(j).getAmount();
                    lIncomeEntryAmount = 0;
                }
                else
                {
                    lIncomeEntryAmount = iList.at(j).getLAmount();
                    dIncomeEntryAmount = 0;
                }

                incomeEntryTax = iList.at(j).getTax();

                strcpy(cIncomeEntryAdditionalInfo, iList.at(j).getAdditionalInfo().c_str());
            }
        }
    }

    if (selectedBudgetFrame->debtTable_2->currentItem() && (tableFocus == "debt"))
    {
        int index = selectedBudgetFrame->debtTable_2->currentRow();

        QString qsLocalIDCode = selectedBudgetFrame->debtTable_2->item(index, 6)->text();
        QChar * qcLocalIDCode = qsLocalIDCode.data();
        char cLocalIDCode[16];
        int i = 0;
        while (!qcLocalIDCode->isNull())
        {
            cLocalIDCode[i] = qcLocalIDCode->toAscii();
            ++qcLocalIDCode;
            i++;
        }
        debtEntryLocalIDCode = atoi(cLocalIDCode);

        for (int j = 0; j < dList.size(); j++)
        {
            if (dList.at(j).getIDCode() == debtEntryLocalIDCode)
            {
                strcpy(cDebtEntryName, dList.at(j).getName().c_str());

                QDate qCurrentDate = QDate::currentDate();

                debtEntryYear = qCurrentDate.year();
                debtEntryMonth = qCurrentDate.month();
                debtEntryDay = qCurrentDate.day();

                debtEntryPLevel = dList.at(j).getPriorityLevel();

                if (dList.at(j).getAmountType() == "double")
                {
                    dDebtEntryAmount = dList.at(j).getAmount();
                    lDebtEntryAmount = 0;
                }
                else
                {
                    lDebtEntryAmount = dList.at(j).getLAmount();
                    dDebtEntryAmount = 0;
                }

                debtEntryAPR = dList.at(j).getAPR();

                strcpy(cDebtEntryAdditionalInfo, dList.at(j).getAdditionalInfo().c_str());

                debtEntryNumberOfMonths = dList.at(j).getNumberOfMonths();
            }
        }
    }

    if (selectedBudgetFrame->expensesTable_2->currentItem() && (tableFocus == "expenses"))
    {
        int index = selectedBudgetFrame->expensesTable_2->currentRow();

        QString qsLocalIDCode = selectedBudgetFrame->expensesTable_2->item(index, 6)->text();
        QChar * qcLocalIDCode = qsLocalIDCode.data();
        char cLocalIDCode[16];
        int i = 0;
        while (!qcLocalIDCode->isNull())
        {
            cLocalIDCode[i] = qcLocalIDCode->toAscii();
            ++qcLocalIDCode;
            i++;
        }
        expensesEntryLocalIDCode = atoi(cLocalIDCode);

        for (int j = 0; j < eList.size(); j++)
        {
            if (eList.at(j).getIDCode() == expensesEntryLocalIDCode)
            {
                strcpy(cExpensesEntryName, eList.at(j).getName().c_str());

                QDate qCurrentDate = QDate::currentDate();

                expensesEntryYear = qCurrentDate.year();
                expensesEntryMonth = qCurrentDate.month();
                expensesEntryDay = qCurrentDate.day();

                expensesEntryPLevel = eList.at(j).getPriorityLevel();

                if (eList.at(j).getAmountType() == "double")
                {
                    dExpensesEntryAmount = eList.at(j).getAmount();
                    lExpensesEntryAmount = 0;
                }
                else
                {
                    lExpensesEntryAmount = eList.at(j).getLAmount();
                    dExpensesEntryAmount = 0;
                }

                expensesEntryPenalty = eList.at(j).getPenalty();

                strcpy(cExpensesEntryAdditionalInfo, eList.at(j).getAdditionalInfo().c_str());
            }
        }
    }

    if (sd->savingsTable->currentItem() && (tableFocus == "savings"))
    {
        int index = sd->savingsTable->currentRow();

        strcpy(cSavingsEntryName, sList.at(index).getName().c_str());

        savingsEntryNature = sList.at(index).getNature();

        if (sList.at(index).getAmountType() == "double")
        {
            dSavingsEntryAmount = sList.at(index).getAmount();
            lSavingsEntryAmount = 0;
        }
        else
        {
            lSavingsEntryAmount = sList.at(index).getLAmount();
            dSavingsEntryAmount = 0;
        }

        savingsEntryAPR = sList.at(index).getAPR();

        savingsEntryYear = sList.at(index).getDate().getYear();
        savingsEntryMonth = sList.at(index).getDate().getMonth();
        savingsEntryDay = sList.at(index).getDate().getDay();

        strcpy(cSavingsEntryDescription, sList.at(index).getDescription().c_str());
    }

    if (id->inventoryTable->currentItem() && (tableFocus == "items"))
    {
        int index = id->inventoryTable->currentRow();

        strcpy(cItemEntryName, itList.at(index).getName().c_str());

        strcpy(cItemEntryItemID, itList.at(index).getItemID().c_str());

        itemEntryNumber = itList.at(index).getNumber();

        itemEntryPrice = itList.at(index).getPrice();
    }

    if (rd->remindersTable->currentItem() && (tableFocus == "reminders"))
    {
        int index = rd->remindersTable->currentRow();
        reminderIndex = index;

        strcpy(cRemindersEntrySubject, rList.at(index).getSubject().c_str());


        remindersEntryYear = rList.at(index).getDueDate().getYear();
        remindersEntryMonth = rList.at(index).getDueDate().getMonth();
        remindersEntryDay = rList.at(index).getDueDate().getDay();
        remindersEntryHour = rList.at(index).getDueDate().getHour();
        remindersEntryMinute = rList.at(index).getDueDate().getMinute();
        remindersEntrySecond = rList.at(index).getDueDate().getSecond();

        strcpy(cRemidersEntryMessage, rList.at(index).getMessage().c_str());
    }
}


void MainBudget::cutEntry()
{
    entryType = tableFocus;

    if (selectedBudgetFrame->incomeTable_2->currentItem() && (entryType == "income"))
    {
        int index = selectedBudgetFrame->incomeTable_2->currentRow();

        QString qsLocalIDCode = selectedBudgetFrame->incomeTable_2->item(index, 6)->text();
        QChar * qcLocalIDCode = qsLocalIDCode.data();
        char cLocalIDCode[16];
        int i = 0;
        while (!qcLocalIDCode->isNull())
        {
            cLocalIDCode[i] = qcLocalIDCode->toAscii();
            ++qcLocalIDCode;
            i++;
        }
        incomeEntryLocalIDCode = atoi(cLocalIDCode);

        for (int j = 0; j < iList.size(); j++)
        {
            if (iList.at(j).getIDCode() == incomeEntryLocalIDCode)
            {
                strcpy(cIncomeEntryName, iList.at(j).getName().c_str());

                QDate qCurrentDate = QDate::currentDate();

                incomeEntryYear = qCurrentDate.year();
                incomeEntryMonth = qCurrentDate.month();
                incomeEntryDay = qCurrentDate.day();

                incomeEntryNature = iList.at(j).getNature();

                if (iList.at(j).getAmountType() == "double")
                {
                    dIncomeEntryAmount = iList.at(j).getAmount();
                    lIncomeEntryAmount = 0;
                }
                else
                {
                    lIncomeEntryAmount = iList.at(j).getLAmount();
                    dIncomeEntryAmount = 0;
                }

                incomeEntryTax = iList.at(j).getTax();

                strcpy(cIncomeEntryAdditionalInfo, iList.at(j).getAdditionalInfo().c_str());
            }
        }

        for (int j = 0; j < iList.size(); j++)
        {
            if (iList.at(j).getIDCode() == incomeEntryLocalIDCode)
            {
                deleteIncome(iList, iList.at(j).getIDCode());
            }
        }
        populateIncomeTable(iList);
        monthlyIncome = 0;
        monthlyLIncome = 0;
        for (int i = 0; i < iList.size(); i++)
        {
            if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (iList.at(i).getAmountType() == "long")
                    containsLongIncome = true;
                monthlyIncome += iList.at(i).getNetAmount();
                monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
            }
        }
        //if (containsLongIncome)
            bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
        //else
        //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));
        setCurrentBalance();
    }

    if (selectedBudgetFrame->debtTable_2->currentItem() && (tableFocus == "debt"))
    {
        int index = selectedBudgetFrame->debtTable_2->currentRow();

        QString qsLocalIDCode = selectedBudgetFrame->debtTable_2->item(index, 6)->text();
        QChar * qcLocalIDCode = qsLocalIDCode.data();
        char cLocalIDCode[16];
        int i = 0;
        while (!qcLocalIDCode->isNull())
        {
            cLocalIDCode[i] = qcLocalIDCode->toAscii();
            ++qcLocalIDCode;
            i++;
        }
        debtEntryLocalIDCode = atoi(cLocalIDCode);

        for (int j = 0; j < dList.size(); j++)
        {
            if (dList.at(j).getIDCode() == debtEntryLocalIDCode)
            {
                strcpy(cDebtEntryName, dList.at(j).getName().c_str());

                QDate qCurrentDate = QDate::currentDate();

                debtEntryYear = qCurrentDate.year();
                debtEntryMonth = qCurrentDate.month();
                debtEntryDay = qCurrentDate.day();

                debtEntryPLevel = dList.at(j).getPriorityLevel();

                if (dList.at(j).getAmountType() == "double")
                {
                    dDebtEntryAmount = dList.at(j).getAmount();
                    lDebtEntryAmount = 0;
                }
                else
                {
                    lDebtEntryAmount = dList.at(j).getLAmount();
                    dDebtEntryAmount = 0;
                }

                debtEntryAPR = dList.at(j).getAPR();

                strcpy(cDebtEntryAdditionalInfo, dList.at(j).getAdditionalInfo().c_str());

                debtEntryNumberOfMonths = dList.at(j).getNumberOfMonths();
            }
        }

        for (int j = 0; j < dList.size(); j++)
        {
            if (dList.at(j).getIDCode() == debtEntryLocalIDCode)
            {
                deleteDebt(dList, dList.at(j).getIDCode());
            }
        }
        populateDebtTable(dList);

        monthlyDebt = 0;
        monthlyLDebt = 0;
        for (int i = 0; i < dList.size(); i++)
        {
            if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (dList.at(i).getAmountType() == "long")
                    containsLongDebt = true;
                monthlyDebt += dList.at(i).getNetAmount();
                monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
            }
        }
        //if (containsLongDebt)
            bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
        //else
        //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));
        setCurrentBalance();
    }

    if (selectedBudgetFrame->expensesTable_2->currentItem() && (tableFocus == "expenses"))
    {
        int index = selectedBudgetFrame->expensesTable_2->currentRow();

        QString qsLocalIDCode = selectedBudgetFrame->expensesTable_2->item(index, 6)->text();
        QChar * qcLocalIDCode = qsLocalIDCode.data();
        char cLocalIDCode[16];
        int i = 0;
        while (!qcLocalIDCode->isNull())
        {
            cLocalIDCode[i] = qcLocalIDCode->toAscii();
            ++qcLocalIDCode;
            i++;
        }
        expensesEntryLocalIDCode = atoi(cLocalIDCode);

        for (int j = 0; j < eList.size(); j++)
        {
            if (eList.at(j).getIDCode() == expensesEntryLocalIDCode)
            {
                strcpy(cExpensesEntryName, eList.at(j).getName().c_str());

                QDate qCurrentDate = QDate::currentDate();

                expensesEntryYear = qCurrentDate.year();
                expensesEntryMonth = qCurrentDate.month();
                expensesEntryDay = qCurrentDate.day();

                expensesEntryPLevel = eList.at(j).getPriorityLevel();

                if (eList.at(j).getAmountType() == "double")
                {
                    dExpensesEntryAmount = eList.at(j).getAmount();
                    lExpensesEntryAmount = 0;
                }
                else
                {
                    lExpensesEntryAmount = eList.at(j).getLAmount();
                    dExpensesEntryAmount = 0;
                }

                expensesEntryPenalty = eList.at(j).getPenalty();

                strcpy(cExpensesEntryAdditionalInfo, eList.at(j).getAdditionalInfo().c_str());
            }
        }

        for (int j = 0; j < eList.size(); j++)
        {
            if (eList.at(j).getIDCode() == expensesEntryLocalIDCode)
            {
                deleteExpense(eList, eList.at(j).getIDCode());
            }
        }
        populateExpensesTable(eList);
        monthlyExpenses = 0;
        monthlyLExpenses = 0;
        for (int i = 0; i < eList.size(); i++)
        {
            if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (eList.at(i).getAmountType() == "long")
                    containsLongExpense = true;
                monthlyExpenses += eList.at(i).getNetAmount();
                monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
            }
        }
        //if (containsLongExpense)
            bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
        //else
        //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

        setCurrentBalance();
    }

    if (sd->savingsTable->currentItem() && (tableFocus == "savings"))
    {
        int index = sd->savingsTable->currentRow();

        strcpy(cSavingsEntryName, sList.at(index).getName().c_str());

        savingsEntryNature = sList.at(index).getNature();

        if (sList.at(index).getAmountType() == "double")
        {
            dSavingsEntryAmount = sList.at(index).getAmount();
            lSavingsEntryAmount = 0;
        }
        else
        {
            lSavingsEntryAmount = sList.at(index).getLAmount();
            dSavingsEntryAmount = 0;
        }

        savingsEntryAPR = sList.at(index).getAPR();

        savingsEntryYear = sList.at(index).getDate().getYear();
        savingsEntryMonth = sList.at(index).getDate().getMonth();
        savingsEntryDay = sList.at(index).getDate().getDay();

        strcpy(cSavingsEntryDescription, sList.at(index).getDescription().c_str());

        deleteSavings(sList, sList.at(index).getIDCode());
        populateSavingsTable(sList);
        savingsBalance = 0;
        savingsLBalance = 0;
        for (int i = 0; i < sList.size(); i++)
        {
            if (sList.at(i).getAmountType() == "long")
                containsLongAssSaving = true;
            savingsBalance += sList.at(i).getAmount();
            savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
        }
        //if (containsLongAssSaving)
            sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
        //else
        //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));
    }

    if (id->inventoryTable->currentItem() && (tableFocus == "items"))
    {
        int index = id->inventoryTable->currentRow();

        strcpy(cItemEntryName, itList.at(index).getName().c_str());

        strcpy(cItemEntryItemID, itList.at(index).getItemID().c_str());

        itemEntryNumber = itList.at(index).getNumber();

        itemEntryPrice = itList.at(index).getPrice();

        deleteItem(itList, itList.at(index).getIDCode());
        populateInventoryTable(itList);
    }

    if (rd->remindersTable->currentItem() && (tableFocus == "reminders"))
    {
        int index = rd->remindersTable->currentRow();
        reminderIndex = index;

        strcpy(cRemindersEntrySubject, rList.at(index).getSubject().c_str());


        remindersEntryYear = rList.at(index).getDueDate().getYear();
        remindersEntryMonth = rList.at(index).getDueDate().getMonth();
        remindersEntryDay = rList.at(index).getDueDate().getDay();
        remindersEntryHour = rList.at(index).getDueDate().getHour();
        remindersEntryMinute = rList.at(index).getDueDate().getMinute();
        remindersEntrySecond = rList.at(index).getDueDate().getSecond();

        strcpy(cRemidersEntryMessage, rList.at(index).getMessage().c_str());

        deleteReminder(rList, rList.at(index).getIDCode());
        populateReminderTable(rList);
        QDateList d;
        //bd->calendar->repaintReminders(index);
        sd->calendar->repaintReminders(index);
        id->calendar->repaintReminders(index);
        rd->calendar->repaintReminders(index);
    }
}

void MainBudget::pasteEntry()
{
    if ((entryType == tableFocus) && (tableFocus == "income"))
    {
        if (lIncomeEntryAmount > 0)
        {
            addLIncome(cIncomeEntryName, lIncomeEntryAmount, false, 0, Date(incomeEntryYear, incomeEntryMonth, incomeEntryDay, 0, 0, 0),
                incomeEntryNature, incomeEntryTax, cIncomeEntryAdditionalInfo, mainBudgetTab.currentIndex(), iList);
                //cout << "it works" << endl;
        }
        else
        {
            addIncome(cIncomeEntryName, dIncomeEntryAmount, false, 0, Date(incomeEntryYear, incomeEntryMonth, incomeEntryDay, 0, 0, 0),
                incomeEntryNature, incomeEntryTax, cIncomeEntryAdditionalInfo, mainBudgetTab.currentIndex(), iList);
        }

        populateIncomeTable(iList);
        populateDebtTable(dList);
        populateExpensesTable(eList);
        monthlyIncome = 0;
        monthlyLIncome = 0;
        for (int i = 0; i < iList.size(); i++)
        {
            if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (iList.at(i).getAmountType() == "long")
                    containsLongIncome = true;
                monthlyIncome += iList.at(i).getNetAmount();
                monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
            }
        }
        //if (containsLongIncome)
            bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
        //else
        //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));
        setCurrentBalance();
    }

    if ((entryType == tableFocus) && (tableFocus == "debt"))
    {
        if (lDebtEntryAmount > 0)
        {
            addLDebt(cDebtEntryName, lDebtEntryAmount, true, debtEntryAPR, debtEntryPLevel,
                Date(debtEntryYear, debtEntryMonth, debtEntryDay, 0, 0, 0), cDebtEntryAdditionalInfo, debtEntryNumberOfMonths, mainBudgetTab.currentIndex(), dList);
        }
        else
        {
            addDebt(cDebtEntryName, dDebtEntryAmount, true, debtEntryAPR, debtEntryPLevel,
                Date(debtEntryYear, debtEntryMonth, debtEntryDay, 0, 0, 0), cDebtEntryAdditionalInfo, debtEntryNumberOfMonths, mainBudgetTab.currentIndex(), dList);
        }

        populateDebtTable(dList);
        populateIncomeTable(iList);
        populateExpensesTable(eList);
        monthlyDebt = 0;
        monthlyLDebt = 0;
        for (int i = 0; i < dList.size(); i++)
        {
            if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (dList.at(i).getAmountType() == "long")
                    containsLongDebt = true;
                monthlyDebt += dList.at(i).getNetAmount();
                monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
            }
        }
        //if (containsLongDebt)
            bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
        //else
        //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));
        setCurrentBalance();
    }

    if ((entryType == tableFocus) && (tableFocus == "expenses"))
    {
        if (lExpensesEntryAmount > 0)
        {
            addLExpense(cExpensesEntryName, lExpensesEntryAmount, expensesEntryPLevel, expensesEntryPenalty,
                Date(expensesEntryYear, expensesEntryMonth, expensesEntryDay, 0, 0, 0), cExpensesEntryAdditionalInfo, mainBudgetTab.currentIndex(), eList);
        }
        else
        {
            addExpense(cExpensesEntryName, dExpensesEntryAmount, expensesEntryPLevel, expensesEntryPenalty,
                Date(expensesEntryYear, expensesEntryMonth, expensesEntryDay, 0, 0, 0), cExpensesEntryAdditionalInfo, mainBudgetTab.currentIndex(), eList);
        }

        populateExpensesTable(eList);
        populateIncomeTable(iList);
        populateDebtTable(dList);
        monthlyExpenses = 0;
        monthlyLExpenses = 0;
        for (int i = 0; i < eList.size(); i++)
        {
            if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (eList.at(i).getAmountType() == "long")
                    containsLongExpense = true;
                monthlyExpenses += eList.at(i).getNetAmount();
                monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
            }
        }
        //if (containsLongExpense)
            bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
        //else
        //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

        setCurrentBalance();
    }

    if ((entryType == tableFocus) && (tableFocus == "savings"))
    {
        if (lSavingsEntryAmount > 0)
        {
            addLSavings(cSavingsEntryName, lSavingsEntryAmount, savingsEntryAPR,
                savingsEntryNature, Date(savingsEntryYear, savingsEntryMonth, savingsEntryDay, 0, 0, 0), cSavingsEntryDescription, sList);
        }
        else
        {
            addSavings(cSavingsEntryName, dSavingsEntryAmount, savingsEntryAPR,
                savingsEntryNature, Date(savingsEntryYear, savingsEntryMonth, savingsEntryDay, 0, 0, 0), cSavingsEntryDescription, sList);
        }

        populateSavingsTable(sList);

        savingsBalance = 0;
        savingsLBalance = 0;
        for (int i = 0; i < sList.size(); i++)
        {
            if (sList.at(i).getAmountType() == "long")
                containsLongAssSaving = true;
            savingsBalance += sList.at(i).getAmount();
            savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
        }
        //if (containsLongAssSaving)
            sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
        //else
        //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));
    }

    if (id->inventoryTable->currentItem() && (tableFocus == "items"))
    {
        addItem(cItemEntryName, itemEntryPrice, itemEntryNumber, cItemEntryItemID, itList);
        populateInventoryTable(itList);
    }

    if (rd->remindersTable->currentItem() && (tableFocus == "reminders"))
    {
        Date date(remindersEntryYear, remindersEntryMonth, remindersEntryDay, remindersEntryHour, remindersEntryMinute, remindersEntrySecond);
        bd->calendar->setReminderDate(QDate(remindersEntryYear, remindersEntryMonth, remindersEntryDay));
        sd->calendar->setReminderDate(QDate(remindersEntryYear, remindersEntryMonth, remindersEntryDay));
        id->calendar->setReminderDate(QDate(remindersEntryYear, remindersEntryMonth, remindersEntryDay));
        rd->calendar->setReminderDate(QDate(remindersEntryYear, remindersEntryMonth, remindersEntryDay));

        addReminder(date, cRemindersEntrySubject, cRemidersEntryMessage,
            HIGH, rList);

        populateReminderTable(rList);
    }
}

void MainBudget::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
        loadFile(action->data().toString());
    
    documentSaved = true;
}

void MainBudget::updateRecentFileActions()
{
    QSettings settings("Thabo David Klass", "CakeHeap Budget Professional");
    QStringList files = settings.value("recentFileList").toStringList();
    
    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);
    cout << numRecentFiles << endl;
    
    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1 %2").arg(i + 1).arg(strippedName(files[i]));
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActs[j]->setVisible(false);
    
    separatorAct->setVisible(numRecentFiles > 0);
}

void MainBudget::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowFilePath(curFile);
    
    QSettings settings("Thabo David Klass", "CakeHeap Budget Professional");
    QStringList files = settings.value("recentFileList").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > MaxRecentFiles)
        files.removeLast();
    
    settings.setValue("recentFileList", files);
    
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        MainBudget *mainBudget = qobject_cast<MainBudget *>(widget);
        if (mainBudget)
            mainBudget->updateRecentFileActions();
    }
}

void MainBudget::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Recent Files"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }
    
    openFromFileName(fileName);
    /*QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();
    
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);*/
}

QString MainBudget::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainBudget::save()
{
    const QString DEFAULT_DIR_KEY("default_dir");
    
    QSettings mySettings("Thabo David Klass", "CakeHeap Budget Professional");
    
    if (!documentSaved && workSpaceActive) {
        if (mySettings.contains(DEFAULT_DIR_KEY))
            fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"), mySettings.value(DEFAULT_DIR_KEY).toString(), "*.chf");
        else
            fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"), QDir::homePath() + "/Documents", "*.chf");
    } else
        fileName = saveFileName;

    if (!fileName.isEmpty())
    {
        QDir currentDir;
        mySettings.setValue(DEFAULT_DIR_KEY,
                            currentDir.absoluteFilePath(fileName));
        
        QStringList pieces = fileName.split( "/" );
        fileNameWithoutFullPath = pieces.value(pieces.length() - 1);
        
        setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath);
        saveFileName = fileName;
        //documentModified = true;

        QFile fileSave(fileName);

        if (!fileSave.open(QIODevice::WriteOnly))
        {
            return;
        }

        const int indent = 4;
        QDomDocument doc;
        QDomElement root = doc.createElement("chf");
        QDomElement fiscalRecord = doc.createElement("fiscalRecord");
        QDomElement income = doc.createElement("income");
        QDomElement debt =
         doc.createElement("debt");
        QDomElement expense = doc.createElement("expense");
        QDomElement savings = doc.createElement("savings");
        QDomElement inventory = doc.createElement("inventory");
        QDomElement reminders = doc.createElement("reminders");

        doc.appendChild(root);
        root.appendChild(fiscalRecord);
        fiscalRecord.appendChild(income);
        fiscalRecord.appendChild(debt);
        fiscalRecord.appendChild(expense);
        fiscalRecord.appendChild(savings);
        fiscalRecord.appendChild(inventory);
        fiscalRecord.appendChild(reminders);

        // SAVE INCOME DATA
        for (int i = 0; i < iList.size(); i++)
        {
            QDomElement incomeItem = doc.createElement("incomeItem");
            QDomElement dateItem = doc.createElement("dateItem");
            QDomElement nameItem = doc.createElement("nameItem");
            QDomElement natureItem = doc.createElement("natureItem");
            QDomElement amountItem = doc.createElement("amountItem");
            QDomElement taxItem = doc.createElement("taxItem");
            QDomElement netAmountItem = doc.createElement("netAmountItem");
            QDomElement IDCodeItem = doc.createElement("IDCodeItem");
            QDomElement additionalInfoItem = doc.createElement("additionalInfoItem");
            QDomElement tabIndexItem = doc.createElement("tabIndexItem");

            QDomElement day = doc.createElement("day");
            QDomElement month = doc.createElement("month");
            QDomElement year = doc.createElement("year");

            QDomText dayText = doc.createTextNode(getQStringForDaySave(iList.at(i).getReceivedDate().getDay()));
            QDomText monthText = doc.createTextNode(getQStringForMonthSave(iList.at(i).getReceivedDate().getMonth()));
            QDomText yearText = doc.createTextNode(getQStringForYearSave(iList.at(i).getReceivedDate().getYear()));

            QDomElement name = doc.createElement("name");

            QDomText nameText = doc.createTextNode(getQStringForNameSave(iList.at(i).getName()));

            QDomElement nature = doc.createElement("nature");

            QDomText natureText = doc.createTextNode(getQStringForNatureSave(iList.at(i).getNature()));

            QDomElement amount = doc.createElement("amount");

            QDomText amountText;
            if (iList.at(i).getAmountType() == "double")
                amountText = doc.createTextNode(getQStringForAmountSave(iList.at(i).getAmount()));
            else
                amountText = doc.createTextNode(getQStringForLAmountSave(iList.at(i).getLAmount()));

            QDomElement tax = doc.createElement("tax");

            QDomText taxText = doc.createTextNode(getQStringForTaxSave(iList.at(i).getTax()));

            QDomElement netAmount = doc.createElement("netAmount");

            QDomText netAmountText;
            if (iList.at(i).getAmountType() == "double")
                netAmountText = doc.createTextNode(getQStringForNetAmountSave(iList.at(i).getNetAmount()));
            else
                netAmountText = doc.createTextNode(getQStringForNetLAmountSave(iList.at(i).getNetLAmount()));

            QDomElement IDCode = doc.createElement("IDCode");

            QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(iList.at(i).getIDCode()));

            QDomElement additionalInfo = doc.createElement("additionalInfo");

            QDomText additionalInfoText = doc.createTextNode(getQStringForAdditionalInfoSave(iList.at(i).getAdditionalInfo()));

            QDomElement tabIndex = doc.createElement("tabIndex");

            QDomText tabIndexText = doc.createTextNode(getQStringForTabIndexSave(iList.at(i).getTabIndex()));


            income.appendChild(incomeItem);
            incomeItem.appendChild(dateItem);
            incomeItem.appendChild(nameItem);
            incomeItem.appendChild(natureItem);
            incomeItem.appendChild(amountItem);
            incomeItem.appendChild(taxItem);
            incomeItem.appendChild(netAmountItem);
            incomeItem.appendChild(IDCodeItem);
            incomeItem.appendChild(additionalInfoItem);
            incomeItem.appendChild(tabIndexItem);
            incomeItem.appendChild(IDCodeItem);

            dateItem.appendChild(day);
            dateItem.appendChild(month);
            dateItem.appendChild(year);
            day.appendChild(dayText);
            month.appendChild(monthText);
            year.appendChild(yearText);
            nameItem.appendChild(name);
            name.appendChild(nameText);
            natureItem.appendChild(nature);
            nature.appendChild(natureText);
            amountItem.appendChild(amount);
            amount.appendChild(amountText);
            taxItem.appendChild(tax);
            tax.appendChild(taxText);
            netAmountItem.appendChild(netAmount);
            netAmount.appendChild(netAmountText);
            IDCodeItem.appendChild(IDCode);
            IDCode.appendChild(IDCodeText);
            additionalInfoItem.appendChild(additionalInfo);
            additionalInfo.appendChild(additionalInfoText);
            tabIndexItem.appendChild(tabIndex);
            tabIndex.appendChild(tabIndexText);
            IDCodeItem.appendChild(IDCode);
            IDCode.appendChild(IDCodeText);
        }
        //bd->progressBar->setValue(17);
        //sd->progressBar->setValue(17);
        //id->progressBar->setValue(17);
        //rd->progressBar->setValue(17);

        // SAVE DEBT DATA
        for (int i = 0; i < dList.size(); i++)
        {
            QDomElement debtItem = doc.createElement("debtItem");
            QDomElement dateItem = doc.createElement("dateItem");
            QDomElement nameItem = doc.createElement("nameItem");
            QDomElement priorityLevelItem = doc.createElement("priorityLevelItem");
            QDomElement amountItem = doc.createElement("amountItem");
            QDomElement APRItem = doc.createElement("APRItem");
            QDomElement netAmountItem = doc.createElement("netAmountItem");
            QDomElement IDCodeItem = doc.createElement("IDCodeItem");
            QDomElement additionalInfoItem = doc.createElement("additionalInfoItem");
            QDomElement numberOfMonthsItem = doc.createElement("numberOfMonthsItem");
            QDomElement tabIndexItem = doc.createElement("tabIndexItem");

            QDomElement day = doc.createElement("day");
            QDomElement month = doc.createElement("month");
            QDomElement year = doc.createElement("year");

            QDomText dayText = doc.createTextNode(getQStringForDaySave(dList.at(i).getDueDate().getDay()));
            QDomText monthText = doc.createTextNode(getQStringForMonthSave(dList.at(i).getDueDate().getMonth()));
            QDomText yearText = doc.createTextNode(getQStringForYearSave(dList.at(i).getDueDate().getYear()));

            QDomElement name = doc.createElement("name");

            QDomText nameText = doc.createTextNode(getQStringForNameSave(dList.at(i).getName()));

            QDomElement priorityLevel = doc.createElement("priorityLevel");

            QDomText priorityLevelText = doc.createTextNode(getQStringForPriorityLevelSave(dList.at(i).getPriorityLevel()));

            QDomElement amount = doc.createElement("amount");

            QDomText amountText;
            if (dList.at(i).getAmountType() == "double")
                amountText = doc.createTextNode(getQStringForAmountSave(dList.at(i).getAmount()));
            else
                amountText = doc.createTextNode(getQStringForLAmountSave(dList.at(i).getLAmount()));

            QDomElement APR = doc.createElement("APR");

            QDomText APRText = doc.createTextNode(getQStringForAPRSave(dList.at(i).getAPR()));

            QDomElement netAmount = doc.createElement("netAmount");

            QDomText netAmountText;
            if (dList.at(i).getAmountType() == "double")
                netAmountText = doc.createTextNode(getQStringForNetAmountSave(dList.at(i).getNetAmount()));
            else
                netAmountText = doc.createTextNode(getQStringForNetLAmountSave(dList.at(i).getNetLAmount()));

            QDomElement IDCode = doc.createElement("IDCode");

            QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(dList.at(i).getIDCode()));

            QDomElement additionalInfo = doc.createElement("additionalInfo");

            QDomText additionalInfoText = doc.createTextNode(getQStringForAdditionalInfoSave(dList.at(i).getAdditionalInfo()));

            QDomElement numberOfMonths = doc.createElement("numberOfMonths");

            QDomText numberOfMonthsText = doc.createTextNode(getQStringForNumberOfMonthsSave(dList.at(i).getNumberOfMonths()));

            QDomElement tabIndex = doc.createElement("tabIndex");

            QDomText tabIndexText = doc.createTextNode(getQStringForTabIndexSave(dList.at(i).getTabIndex()));


            debt.appendChild(debtItem);
            debtItem.appendChild(dateItem);
            debtItem.appendChild(nameItem);
            debtItem.appendChild(priorityLevelItem);
            debtItem.appendChild(amountItem);
            debtItem.appendChild(APRItem);
            debtItem.appendChild(netAmountItem);
            debtItem.appendChild(IDCodeItem);
            debtItem.appendChild(additionalInfoItem);
            debtItem.appendChild(numberOfMonthsItem);
            debtItem.appendChild(tabIndexItem);

            dateItem.appendChild(day);
            dateItem.appendChild(month);
            dateItem.appendChild(year);
            day.appendChild(dayText);
            month.appendChild(monthText);
            year.appendChild(yearText);
            nameItem.appendChild(name);
            name.appendChild(nameText);
            priorityLevelItem.appendChild(priorityLevel);
            priorityLevel.appendChild(priorityLevelText);
            amountItem.appendChild(amount);
            amount.appendChild(amountText);
            APRItem.appendChild(APR);
            APR.appendChild(APRText);
            netAmountItem.appendChild(netAmount);
            netAmount.appendChild(netAmountText);
            IDCodeItem.appendChild(IDCode);
            IDCode.appendChild(IDCodeText);
            additionalInfoItem.appendChild(additionalInfo);
            additionalInfo.appendChild(additionalInfoText);
            numberOfMonthsItem.appendChild(numberOfMonths);
            numberOfMonths.appendChild(numberOfMonthsText);
            tabIndexItem.appendChild(tabIndex);
            tabIndex.appendChild(tabIndexText);
        }
        //bd->progressBar->setValue(34);
        //sd->progressBar->setValue(34);
        //id->progressBar->setValue(34);
        //rd->progressBar->setValue(34);

        // SAVE EXPENSE DATA
        for (int i = 0; i < eList.size(); i++)
        {
            QDomElement expenseItem = doc.createElement("expenseItem");
            QDomElement dateItem = doc.createElement("dateItem");
            QDomElement nameItem = doc.createElement("nameItem");
            QDomElement priorityLevelItem = doc.createElement("priorityLevelItem");
            QDomElement amountItem = doc.createElement("amountItem");
            QDomElement penaltyItem = doc.createElement("penaltyItem");
            QDomElement netAmountItem = doc.createElement("netAmountItem");
            QDomElement IDCodeItem = doc.createElement("IDCodeItem");
            QDomElement additionalInfoItem = doc.createElement("additionalInfoItem");
            QDomElement tabIndexItem = doc.createElement("tabIndexItem");

            QDomElement day = doc.createElement("day");
            QDomElement month = doc.createElement("month");
            QDomElement year = doc.createElement("year");

            QDomText dayText = doc.createTextNode(getQStringForDaySave(eList.at(i).getDueDate().getDay()));
            QDomText monthText = doc.createTextNode(getQStringForMonthSave(eList.at(i).getDueDate().getMonth()));
            QDomText yearText = doc.createTextNode(getQStringForYearSave(eList.at(i).getDueDate().getYear()));

            QDomElement name = doc.createElement("name");

            QDomText nameText = doc.createTextNode(getQStringForNameSave(eList.at(i).getName()));

            QDomElement priorityLevel = doc.createElement("priorityLevel");

            QDomText priorityLevelText = doc.createTextNode(getQStringForPriorityLevelSave(eList.at(i).getPriorityLevel()));

            QDomElement amount = doc.createElement("amount");

            QDomText amountText;
            if (eList.at(i).getAmountType() == "double")
                amountText = doc.createTextNode(getQStringForAmountSave(eList.at(i).getAmount()));
            else
                amountText = doc.createTextNode(getQStringForLAmountSave(eList.at(i).getLAmount()));

            QDomElement penalty = doc.createElement("penalty");

            QDomText penaltyText = doc.createTextNode(getQStringForPenaltySave(eList.at(i).getAPR()));

            QDomElement netAmount = doc.createElement("netAmount");

            QDomText netAmountText;
            if (eList.at(i).getAmountType() == "double")
                netAmountText = doc.createTextNode(getQStringForNetAmountSave(eList.at(i).getNetAmount()));
            else
                netAmountText = doc.createTextNode(getQStringForNetLAmountSave(eList.at(i).getNetLAmount()));

            QDomElement IDCode = doc.createElement("IDCode");

            QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(eList.at(i).getIDCode()));

            QDomElement additionalInfo = doc.createElement("additionalInfo");

            QDomText additionalInfoText = doc.createTextNode(getQStringForAdditionalInfoSave(eList.at(i).getAdditionalInfo()));

            QDomElement tabIndex = doc.createElement("tabIndex");

            QDomText tabIndexText = doc.createTextNode(getQStringForTabIndexSave(eList.at(i).getTabIndex()));


            expense.appendChild(expenseItem);
            expenseItem.appendChild(dateItem);
            expenseItem.appendChild(nameItem);
            expenseItem.appendChild(priorityLevelItem);
            expenseItem.appendChild(amountItem);
            expenseItem.appendChild(penaltyItem);
            expenseItem.appendChild(netAmountItem);
            expenseItem.appendChild(IDCodeItem);
            expenseItem.appendChild(additionalInfoItem);
            expenseItem.appendChild(tabIndexItem);

            dateItem.appendChild(day);
            dateItem.appendChild(month);
            dateItem.appendChild(year);
            day.appendChild(dayText);
            month.appendChild(monthText);
            year.appendChild(yearText);
            nameItem.appendChild(name);
            name.appendChild(nameText);
            priorityLevelItem.appendChild(priorityLevel);
            priorityLevel.appendChild(priorityLevelText);
            amountItem.appendChild(amount);
            amount.appendChild(amountText);
            penaltyItem.appendChild(penalty);
            penalty.appendChild(penaltyText);
            netAmountItem.appendChild(netAmount);
            netAmount.appendChild(netAmountText);
            IDCodeItem.appendChild(IDCode);
            IDCode.appendChild(IDCodeText);
            additionalInfoItem.appendChild(additionalInfo);
            additionalInfo.appendChild(additionalInfoText);
            tabIndexItem.appendChild(tabIndex);
            tabIndex.appendChild(tabIndexText);
        }
        //bd->progressBar->setValue(50);
        //sd->progressBar->setValue(50);
        //id->progressBar->setValue(50);
        //rd->progressBar->setValue(50);

        for (int i = 0; i < sList.size(); i++)
        {
            QDomElement savingsItem = doc.createElement("savingsItem");
            QDomElement nameItem = doc.createElement("nameItem");
            QDomElement natureItem = doc.createElement("natureItem");
            QDomElement APRItem = doc.createElement("APRItem");
            QDomElement amountItem = doc.createElement("amountItem");
            QDomElement dateItem = doc.createElement("dateItem");
            QDomElement descriptionItem = doc.createElement("descriptionItem");
            QDomElement IDCodeItem = doc.createElement("IDCodeItem");

            QDomElement name = doc.createElement("name");

            QDomText nameText = doc.createTextNode(getQStringForNameSave(sList.at(i).getName()));

            QDomElement nature = doc.createElement("nature");

            QDomText natureText = doc.createTextNode(getQStringForSavingsNatureSave(sList.at(i).getNature()));

            QDomElement APR = doc.createElement("APR");

            QDomText APRText = doc.createTextNode(getQStringForAPRSave(sList.at(i).getAPR()));

            QDomElement amount = doc.createElement("amount");

            QDomText amountText;
            if (sList.at(i).getAmountType() == "double")
                amountText = doc.createTextNode(getQStringForAmountSave(sList.at(i).getAmount()));
            else
                amountText = doc.createTextNode(getQStringForLAmountSave(sList.at(i).getLAmount()));

            QDomElement day = doc.createElement("day");
            QDomElement month = doc.createElement("month");
            QDomElement year = doc.createElement("year");

            QDomText dayText = doc.createTextNode(getQStringForDaySave(sList.at(i).getDate().getDay()));
            QDomText monthText = doc.createTextNode(getQStringForMonthSave(sList.at(i).getDate().getMonth()));
            QDomText yearText = doc.createTextNode(getQStringForYearSave(sList.at(i).getDate().getYear()));

            QDomElement description = doc.createElement("description");

            QDomText descriptionText = doc.createTextNode(getQStringForDescriptionSave(sList.at(i).getDescription()));

            QDomElement IDCode = doc.createElement("IDCode");

            QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(sList.at(i).getIDCode()));


            savings.appendChild(savingsItem);
            savingsItem.appendChild(nameItem);
            savingsItem.appendChild(natureItem);
            savingsItem.appendChild(APRItem);
            savingsItem.appendChild(amountItem);
            savingsItem.appendChild(dateItem);
            savingsItem.appendChild(descriptionItem);
            savingsItem.appendChild(IDCodeItem);

            nameItem.appendChild(name);
            name.appendChild(nameText);
            natureItem.appendChild(nature);
            nature.appendChild(natureText);
            APRItem.appendChild(APR);
            APR.appendChild(APRText);
            amountItem.appendChild(amount);
            amount.appendChild(amountText);
            dateItem.appendChild(day);
            dateItem.appendChild(month);
            dateItem.appendChild(year);
            day.appendChild(dayText);
            month.appendChild(monthText);
            year.appendChild(yearText);
            descriptionItem.appendChild(description);
            description.appendChild(descriptionText);
            IDCodeItem.appendChild(IDCode);
            IDCode.appendChild(IDCodeText);
        }
        //bd->progressBar->setValue(67);
        //sd->progressBar->setValue(67);
        //id->progressBar->setValue(67);
        //rd->progressBar->setValue(67);

        for (int i = 0; i < itList.size(); i++)
        {
            QDomElement inventoryItem = doc.createElement("inventoryItem");
            QDomElement IDCodeItem = doc.createElement("IDCodeItem");
            QDomElement itemIDItem = doc.createElement("itemIDItem");
            QDomElement nameItem = doc.createElement("nameItem");
            QDomElement numberItem = doc.createElement("numberItem");
            QDomElement priceItem = doc.createElement("priceItem");

            QDomElement IDCode = doc.createElement("IDCode");

            QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(itList.at(i).getIDCode()));

            QDomElement itemID = doc.createElement("itemID");

            QDomText itemIDText = doc.createTextNode(getQStringForItemIDSave(itList.at(i).getItemID()));

            QDomElement name = doc.createElement("nameItem");

            QDomText nameText = doc.createTextNode(getQStringForNameSave(itList.at(i).getName()));

            QDomElement number = doc.createElement("number");

            QDomText numberText = doc.createTextNode(getQStringForNumberSave(itList.at(i).getNumber()));

            QDomElement price = doc.createElement("price");

            QDomText priceText = doc.createTextNode(getQStringForPriceSave(itList.at(i).getPrice()));


            inventory.appendChild(inventoryItem);
            inventoryItem.appendChild(IDCodeItem);
            inventoryItem.appendChild(itemIDItem);
            inventoryItem.appendChild(nameItem);
            inventoryItem.appendChild(numberItem);
            inventoryItem.appendChild(priceItem);

            IDCodeItem.appendChild(IDCode);
            IDCode.appendChild(IDCodeText);
            itemIDItem.appendChild(itemID);
            itemID.appendChild(itemIDText);
            nameItem.appendChild(name);
            name.appendChild(nameText);
            numberItem.appendChild(number);
            number.appendChild(numberText);
            priceItem.appendChild(price);
            price.appendChild(priceText);
        }
        //bd->progressBar->setValue(83);
        //sd->progressBar->setValue(83);
        //id->progressBar->setValue(83);
        //rd->progressBar->setValue(83);

        for (int i = 0; i < rList.size(); i++)
        {
            QDomElement remindersItem = doc.createElement("remindersItem");
            QDomElement IDCodeItem = doc.createElement("IDCodeItem");
            QDomElement dateItem = doc.createElement("dateItem");
            QDomElement subjectItem = doc.createElement("subjectItem");
            QDomElement messageItem = doc.createElement("messageItem");

            QDomElement second = doc.createElement("second");
            QDomElement minute = doc.createElement("minute");
            QDomElement hour = doc.createElement("hour");
            QDomElement day = doc.createElement("day");
            QDomElement month = doc.createElement("month");
            QDomElement year = doc.createElement("year");

            QDomText secondText = doc.createTextNode(getQStringForSecondsSave(rList.at(i).getDueDate().getSecond()));
            QDomText minuteText = doc.createTextNode(getQStringForMinutesSave(rList.at(i).getDueDate().getMinute()));
            QDomText hourText = doc.createTextNode(getQStringForHourSave(rList.at(i).getDueDate().getHour()));
            QDomText dayText = doc.createTextNode(getQStringForDaySave(rList.at(i).getDueDate().getDay()));
            QDomText monthText = doc.createTextNode(getQStringForMonthSave(rList.at(i).getDueDate().getMonth()));
            QDomText yearText = doc.createTextNode(getQStringForYearSave(rList.at(i).getDueDate().getYear()));

            QDomElement IDCode = doc.createElement("IDCode");

            QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(rList.at(i).getIDCode()));

            QDomElement subject = doc.createElement("subject");

            QDomText subjectText = doc.createTextNode(getQStringForSubjectSave(rList.at(i).getSubject()));

            QDomElement message = doc.createElement("message");

            QDomText messageText = doc.createTextNode(getQStringForMessageSave(rList.at(i).getMessage()));


            reminders.appendChild(remindersItem);
            remindersItem.appendChild(IDCodeItem);
            remindersItem.appendChild(dateItem);
            remindersItem.appendChild(subjectItem);
            remindersItem.appendChild(messageItem);

            IDCodeItem.appendChild(IDCode);
            IDCode.appendChild(IDCodeText);
            dateItem.appendChild(second);
            dateItem.appendChild(minute);
            dateItem.appendChild(hour);
            dateItem.appendChild(day);
            dateItem.appendChild(month);
            dateItem.appendChild(year);
            second.appendChild(secondText);
            minute.appendChild(minuteText);
            hour.appendChild(hourText);
            day.appendChild(dayText);
            month.appendChild(monthText);
            year.appendChild(yearText);
            subjectItem.appendChild(subject);
            subject.appendChild(subjectText);
            messageItem.appendChild(message);
            message.appendChild(messageText);
        }

        //bd->progressBar->setValue(100);
        //sd->progressBar->setValue(100);
        //id->progressBar->setValue(100);
        //rd->progressBar->setValue(100);

        QTextStream out(&fileSave);
        doc.save(out, indent);

        fileSave.close();
        //setCurrentFile(fileName);
        
        documentModified = false;
        
        documentSaved = true;
    }
}

void MainBudget::saveAs()
{
    const QString DEFAULT_DIR_KEY("default_dir");
    
    QSettings mySettings("Thabo David Klass", "CakeHeap Budget Professional");
    
    
    if (workSpaceActive) {
        if (mySettings.contains(DEFAULT_DIR_KEY))
            fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file as"), mySettings.value(DEFAULT_DIR_KEY).toString(), "*.chf");
        else
            fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file as"), QDir::homePath() + "/Documents", "*.chf");
        
        if (!fileName.isEmpty())
        {
            QDir currentDir;
            mySettings.setValue(DEFAULT_DIR_KEY,
                                currentDir.absoluteFilePath(fileName));
            
            QStringList pieces = fileName.split( "/" );
            fileNameWithoutFullPath = pieces.value(pieces.length() - 1);
            
            setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath);
            saveFileName = fileName;
            //documentModified = true;
            
            QFile fileSave(fileName);
            
            if (!fileSave.open(QIODevice::WriteOnly))
            {
                return;
            }
            
            const int indent = 4;
            QDomDocument doc;
            QDomElement root = doc.createElement("chf");
            QDomElement fiscalRecord = doc.createElement("fiscalRecord");
            QDomElement income = doc.createElement("income");
            QDomElement debt =
            doc.createElement("debt");
            QDomElement expense = doc.createElement("expense");
            QDomElement savings = doc.createElement("savings");
            QDomElement inventory = doc.createElement("inventory");
            QDomElement reminders = doc.createElement("reminders");
            
            doc.appendChild(root);
            root.appendChild(fiscalRecord);
            fiscalRecord.appendChild(income);
            fiscalRecord.appendChild(debt);
            fiscalRecord.appendChild(expense);
            fiscalRecord.appendChild(savings);
            fiscalRecord.appendChild(inventory);
            fiscalRecord.appendChild(reminders);
            
            // SAVE INCOME DATA
            for (int i = 0; i < iList.size(); i++)
            {
                QDomElement incomeItem = doc.createElement("incomeItem");
                QDomElement dateItem = doc.createElement("dateItem");
                QDomElement nameItem = doc.createElement("nameItem");
                QDomElement natureItem = doc.createElement("natureItem");
                QDomElement amountItem = doc.createElement("amountItem");
                QDomElement taxItem = doc.createElement("taxItem");
                QDomElement netAmountItem = doc.createElement("netAmountItem");
                QDomElement IDCodeItem = doc.createElement("IDCodeItem");
                QDomElement additionalInfoItem = doc.createElement("additionalInfoItem");
                QDomElement tabIndexItem = doc.createElement("tabIndexItem");
                
                QDomElement day = doc.createElement("day");
                QDomElement month = doc.createElement("month");
                QDomElement year = doc.createElement("year");
                
                QDomText dayText = doc.createTextNode(getQStringForDaySave(iList.at(i).getReceivedDate().getDay()));
                QDomText monthText = doc.createTextNode(getQStringForMonthSave(iList.at(i).getReceivedDate().getMonth()));
                QDomText yearText = doc.createTextNode(getQStringForYearSave(iList.at(i).getReceivedDate().getYear()));
                
                QDomElement name = doc.createElement("name");
                
                QDomText nameText = doc.createTextNode(getQStringForNameSave(iList.at(i).getName()));
                
                QDomElement nature = doc.createElement("nature");
                
                QDomText natureText = doc.createTextNode(getQStringForNatureSave(iList.at(i).getNature()));
                
                QDomElement amount = doc.createElement("amount");
                
                QDomText amountText;
                if (iList.at(i).getAmountType() == "double")
                    amountText = doc.createTextNode(getQStringForAmountSave(iList.at(i).getAmount()));
                else
                    amountText = doc.createTextNode(getQStringForLAmountSave(iList.at(i).getLAmount()));
                
                QDomElement tax = doc.createElement("tax");
                
                QDomText taxText = doc.createTextNode(getQStringForTaxSave(iList.at(i).getTax()));
                
                QDomElement netAmount = doc.createElement("netAmount");
                
                QDomText netAmountText;
                if (iList.at(i).getAmountType() == "double")
                    netAmountText = doc.createTextNode(getQStringForNetAmountSave(iList.at(i).getNetAmount()));
                else
                    netAmountText = doc.createTextNode(getQStringForNetLAmountSave(iList.at(i).getNetLAmount()));
                
                QDomElement IDCode = doc.createElement("IDCode");
                
                QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(iList.at(i).getIDCode()));
                
                QDomElement additionalInfo = doc.createElement("additionalInfo");
                
                QDomText additionalInfoText = doc.createTextNode(getQStringForAdditionalInfoSave(iList.at(i).getAdditionalInfo()));
                
                QDomElement tabIndex = doc.createElement("tabIndex");
                
                QDomText tabIndexText = doc.createTextNode(getQStringForTabIndexSave(iList.at(i).getTabIndex()));
                
                
                income.appendChild(incomeItem);
                incomeItem.appendChild(dateItem);
                incomeItem.appendChild(nameItem);
                incomeItem.appendChild(natureItem);
                incomeItem.appendChild(amountItem);
                incomeItem.appendChild(taxItem);
                incomeItem.appendChild(netAmountItem);
                incomeItem.appendChild(IDCodeItem);
                incomeItem.appendChild(additionalInfoItem);
                incomeItem.appendChild(tabIndexItem);
                incomeItem.appendChild(IDCodeItem);
                
                dateItem.appendChild(day);
                dateItem.appendChild(month);
                dateItem.appendChild(year);
                day.appendChild(dayText);
                month.appendChild(monthText);
                year.appendChild(yearText);
                nameItem.appendChild(name);
                name.appendChild(nameText);
                natureItem.appendChild(nature);
                nature.appendChild(natureText);
                amountItem.appendChild(amount);
                amount.appendChild(amountText);
                taxItem.appendChild(tax);
                tax.appendChild(taxText);
                netAmountItem.appendChild(netAmount);
                netAmount.appendChild(netAmountText);
                IDCodeItem.appendChild(IDCode);
                IDCode.appendChild(IDCodeText);
                additionalInfoItem.appendChild(additionalInfo);
                additionalInfo.appendChild(additionalInfoText);
                tabIndexItem.appendChild(tabIndex);
                tabIndex.appendChild(tabIndexText);
                IDCodeItem.appendChild(IDCode);
                IDCode.appendChild(IDCodeText);
            }
            //bd->progressBar->setValue(17);
            //sd->progressBar->setValue(17);
            //id->progressBar->setValue(17);
            //rd->progressBar->setValue(17);
            
            // SAVE DEBT DATA
            for (int i = 0; i < dList.size(); i++)
            {
                QDomElement debtItem = doc.createElement("debtItem");
                QDomElement dateItem = doc.createElement("dateItem");
                QDomElement nameItem = doc.createElement("nameItem");
                QDomElement priorityLevelItem = doc.createElement("priorityLevelItem");
                QDomElement amountItem = doc.createElement("amountItem");
                QDomElement APRItem = doc.createElement("APRItem");
                QDomElement netAmountItem = doc.createElement("netAmountItem");
                QDomElement IDCodeItem = doc.createElement("IDCodeItem");
                QDomElement additionalInfoItem = doc.createElement("additionalInfoItem");
                QDomElement numberOfMonthsItem = doc.createElement("numberOfMonthsItem");
                QDomElement tabIndexItem = doc.createElement("tabIndexItem");
                
                QDomElement day = doc.createElement("day");
                QDomElement month = doc.createElement("month");
                QDomElement year = doc.createElement("year");
                
                QDomText dayText = doc.createTextNode(getQStringForDaySave(dList.at(i).getDueDate().getDay()));
                QDomText monthText = doc.createTextNode(getQStringForMonthSave(dList.at(i).getDueDate().getMonth()));
                QDomText yearText = doc.createTextNode(getQStringForYearSave(dList.at(i).getDueDate().getYear()));
                
                QDomElement name = doc.createElement("name");
                
                QDomText nameText = doc.createTextNode(getQStringForNameSave(dList.at(i).getName()));
                
                QDomElement priorityLevel = doc.createElement("priorityLevel");
                
                QDomText priorityLevelText = doc.createTextNode(getQStringForPriorityLevelSave(dList.at(i).getPriorityLevel()));
                
                QDomElement amount = doc.createElement("amount");
                
                QDomText amountText;
                if (dList.at(i).getAmountType() == "double")
                    amountText = doc.createTextNode(getQStringForAmountSave(dList.at(i).getAmount()));
                else
                    amountText = doc.createTextNode(getQStringForLAmountSave(dList.at(i).getLAmount()));
                
                QDomElement APR = doc.createElement("APR");
                
                QDomText APRText = doc.createTextNode(getQStringForAPRSave(dList.at(i).getAPR()));
                
                QDomElement netAmount = doc.createElement("netAmount");
                
                QDomText netAmountText;
                if (dList.at(i).getAmountType() == "double")
                    netAmountText = doc.createTextNode(getQStringForNetAmountSave(dList.at(i).getNetAmount()));
                else
                    netAmountText = doc.createTextNode(getQStringForNetLAmountSave(dList.at(i).getNetLAmount()));
                
                QDomElement IDCode = doc.createElement("IDCode");
                
                QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(dList.at(i).getIDCode()));
                
                QDomElement additionalInfo = doc.createElement("additionalInfo");
                
                QDomText additionalInfoText = doc.createTextNode(getQStringForAdditionalInfoSave(dList.at(i).getAdditionalInfo()));
                
                QDomElement numberOfMonths = doc.createElement("numberOfMonths");
                
                QDomText numberOfMonthsText = doc.createTextNode(getQStringForNumberOfMonthsSave(dList.at(i).getNumberOfMonths()));
                
                QDomElement tabIndex = doc.createElement("tabIndex");
                
                QDomText tabIndexText = doc.createTextNode(getQStringForTabIndexSave(dList.at(i).getTabIndex()));
                
                
                debt.appendChild(debtItem);
                debtItem.appendChild(dateItem);
                debtItem.appendChild(nameItem);
                debtItem.appendChild(priorityLevelItem);
                debtItem.appendChild(amountItem);
                debtItem.appendChild(APRItem);
                debtItem.appendChild(netAmountItem);
                debtItem.appendChild(IDCodeItem);
                debtItem.appendChild(additionalInfoItem);
                debtItem.appendChild(numberOfMonthsItem);
                debtItem.appendChild(tabIndexItem);
                
                dateItem.appendChild(day);
                dateItem.appendChild(month);
                dateItem.appendChild(year);
                day.appendChild(dayText);
                month.appendChild(monthText);
                year.appendChild(yearText);
                nameItem.appendChild(name);
                name.appendChild(nameText);
                priorityLevelItem.appendChild(priorityLevel);
                priorityLevel.appendChild(priorityLevelText);
                amountItem.appendChild(amount);
                amount.appendChild(amountText);
                APRItem.appendChild(APR);
                APR.appendChild(APRText);
                netAmountItem.appendChild(netAmount);
                netAmount.appendChild(netAmountText);
                IDCodeItem.appendChild(IDCode);
                IDCode.appendChild(IDCodeText);
                additionalInfoItem.appendChild(additionalInfo);
                additionalInfo.appendChild(additionalInfoText);
                numberOfMonthsItem.appendChild(numberOfMonths);
                numberOfMonths.appendChild(numberOfMonthsText);
                tabIndexItem.appendChild(tabIndex);
                tabIndex.appendChild(tabIndexText);
            }
            //bd->progressBar->setValue(33);
            //sd->progressBar->setValue(33);
            //id->progressBar->setValue(33);
            //rd->progressBar->setValue(33);
            
            // SAVE EXPENSE DATA
            for (int i = 0; i < eList.size(); i++)
            {
                QDomElement expenseItem = doc.createElement("expenseItem");
                QDomElement dateItem = doc.createElement("dateItem");
                QDomElement nameItem = doc.createElement("nameItem");
                QDomElement priorityLevelItem = doc.createElement("priorityLevelItem");
                QDomElement amountItem = doc.createElement("amountItem");
                QDomElement penaltyItem = doc.createElement("penaltyItem");
                QDomElement netAmountItem = doc.createElement("netAmountItem");
                QDomElement IDCodeItem = doc.createElement("IDCodeItem");
                QDomElement additionalInfoItem = doc.createElement("additionalInfoItem");
                QDomElement tabIndexItem = doc.createElement("tabIndexItem");
                
                QDomElement day = doc.createElement("day");
                QDomElement month = doc.createElement("month");
                QDomElement year = doc.createElement("year");
                
                QDomText dayText = doc.createTextNode(getQStringForDaySave(eList.at(i).getDueDate().getDay()));
                QDomText monthText = doc.createTextNode(getQStringForMonthSave(eList.at(i).getDueDate().getMonth()));
                QDomText yearText = doc.createTextNode(getQStringForYearSave(eList.at(i).getDueDate().getYear()));
                
                QDomElement name = doc.createElement("name");
                
                QDomText nameText = doc.createTextNode(getQStringForNameSave(eList.at(i).getName()));
                
                QDomElement priorityLevel = doc.createElement("priorityLevel");
                
                QDomText priorityLevelText = doc.createTextNode(getQStringForPriorityLevelSave(eList.at(i).getPriorityLevel()));
                
                QDomElement amount = doc.createElement("amount");
                
                QDomText amountText;
                if (eList.at(i).getAmountType() == "double")
                    amountText = doc.createTextNode(getQStringForAmountSave(eList.at(i).getAmount()));
                else
                    amountText = doc.createTextNode(getQStringForLAmountSave(eList.at(i).getLAmount()));
                
                QDomElement penalty = doc.createElement("penalty");
                
                QDomText penaltyText = doc.createTextNode(getQStringForPenaltySave(eList.at(i).getAPR()));
                
                QDomElement netAmount = doc.createElement("netAmount");
                
                QDomText netAmountText;
                if (eList.at(i).getAmountType() == "double")
                    netAmountText = doc.createTextNode(getQStringForNetAmountSave(eList.at(i).getNetAmount()));
                else
                    netAmountText = doc.createTextNode(getQStringForNetLAmountSave(eList.at(i).getNetLAmount()));
                
                QDomElement IDCode = doc.createElement("IDCode");
                
                QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(eList.at(i).getIDCode()));
                
                QDomElement additionalInfo = doc.createElement("additionalInfo");
                
                QDomText additionalInfoText = doc.createTextNode(getQStringForAdditionalInfoSave(eList.at(i).getAdditionalInfo()));
                
                QDomElement tabIndex = doc.createElement("tabIndex");
                
                QDomText tabIndexText = doc.createTextNode(getQStringForTabIndexSave(eList.at(i).getTabIndex()));
                
                
                expense.appendChild(expenseItem);
                expenseItem.appendChild(dateItem);
                expenseItem.appendChild(nameItem);
                expenseItem.appendChild(priorityLevelItem);
                expenseItem.appendChild(amountItem);
                expenseItem.appendChild(penaltyItem);
                expenseItem.appendChild(netAmountItem);
                expenseItem.appendChild(IDCodeItem);
                expenseItem.appendChild(additionalInfoItem);
                expenseItem.appendChild(tabIndexItem);
                
                dateItem.appendChild(day);
                dateItem.appendChild(month);
                dateItem.appendChild(year);
                day.appendChild(dayText);
                month.appendChild(monthText);
                year.appendChild(yearText);
                nameItem.appendChild(name);
                name.appendChild(nameText);
                priorityLevelItem.appendChild(priorityLevel);
                priorityLevel.appendChild(priorityLevelText);
                amountItem.appendChild(amount);
                amount.appendChild(amountText);
                penaltyItem.appendChild(penalty);
                penalty.appendChild(penaltyText);
                netAmountItem.appendChild(netAmount);
                netAmount.appendChild(netAmountText);
                IDCodeItem.appendChild(IDCode);
                IDCode.appendChild(IDCodeText);
                additionalInfoItem.appendChild(additionalInfo);
                additionalInfo.appendChild(additionalInfoText);
                tabIndexItem.appendChild(tabIndex);
                tabIndex.appendChild(tabIndexText);
            }
            //bd->progressBar->setValue(50);
            //sd->progressBar->setValue(50);
            //id->progressBar->setValue(50);
            //rd->progressBar->setValue(50);
            
            for (int i = 0; i < sList.size(); i++)
            {
                QDomElement savingsItem = doc.createElement("savingsItem");
                QDomElement nameItem = doc.createElement("nameItem");
                QDomElement natureItem = doc.createElement("natureItem");
                QDomElement APRItem = doc.createElement("APRItem");
                QDomElement amountItem = doc.createElement("amountItem");
                QDomElement dateItem = doc.createElement("dateItem");
                QDomElement descriptionItem = doc.createElement("descriptionItem");
                QDomElement IDCodeItem = doc.createElement("IDCodeItem");
                
                QDomElement name = doc.createElement("name");
                
                QDomText nameText = doc.createTextNode(getQStringForNameSave(sList.at(i).getName()));
                
                QDomElement nature = doc.createElement("nature");
                
                QDomText natureText = doc.createTextNode(getQStringForSavingsNatureSave(sList.at(i).getNature()));
                
                QDomElement APR = doc.createElement("APR");
                
                QDomText APRText = doc.createTextNode(getQStringForAPRSave(sList.at(i).getAPR()));
                
                QDomElement amount = doc.createElement("amount");
                
                QDomText amountText;
                if (sList.at(i).getAmountType() == "double")
                    amountText = doc.createTextNode(getQStringForAmountSave(sList.at(i).getAmount()));
                else
                    amountText = doc.createTextNode(getQStringForLAmountSave(sList.at(i).getLAmount()));
                
                QDomElement description = doc.createElement("description");
                
                QDomElement day = doc.createElement("day");
                QDomElement month = doc.createElement("month");
                QDomElement year = doc.createElement("year");
                
                QDomText dayText = doc.createTextNode(getQStringForDaySave(sList.at(i).getDate().getDay()));
                QDomText monthText = doc.createTextNode(getQStringForMonthSave(sList.at(i).getDate().getMonth()));
                QDomText yearText = doc.createTextNode(getQStringForYearSave(sList.at(i).getDate().getYear()));
                
                QDomText descriptionText = doc.createTextNode(getQStringForDescriptionSave(sList.at(i).getDescription()));
                
                QDomElement IDCode = doc.createElement("IDCode");
                
                QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(sList.at(i).getIDCode()));
                
                
                savings.appendChild(savingsItem);
                savingsItem.appendChild(nameItem);
                savingsItem.appendChild(natureItem);
                savingsItem.appendChild(APRItem);
                savingsItem.appendChild(amountItem);
                savingsItem.appendChild(dateItem);
                savingsItem.appendChild(descriptionItem);
                savingsItem.appendChild(IDCodeItem);
                
                nameItem.appendChild(name);
                name.appendChild(nameText);
                natureItem.appendChild(nature);
                nature.appendChild(natureText);
                APRItem.appendChild(APR);
                APR.appendChild(APRText);
                amountItem.appendChild(amount);
                amount.appendChild(amountText);
                dateItem.appendChild(day);
                dateItem.appendChild(month);
                dateItem.appendChild(year);
                day.appendChild(dayText);
                month.appendChild(monthText);
                year.appendChild(yearText);
                descriptionItem.appendChild(description);
                description.appendChild(descriptionText);
                IDCodeItem.appendChild(IDCode);
                IDCode.appendChild(IDCodeText);
            }
            //bd->progressBar->setValue(67);
            //sd->progressBar->setValue(67);
            //id->progressBar->setValue(67);
            //rd->progressBar->setValue(67);
            
            for (int i = 0; i < itList.size(); i++)
            {
                QDomElement inventoryItem = doc.createElement("inventoryItem");
                QDomElement IDCodeItem = doc.createElement("IDCodeItem");
                QDomElement itemIDItem = doc.createElement("itemIDItem");
                QDomElement nameItem = doc.createElement("nameItem");
                QDomElement numberItem = doc.createElement("numberItem");
                QDomElement priceItem = doc.createElement("priceItem");
                
                QDomElement IDCode = doc.createElement("IDCode");
                
                QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(itList.at(i).getIDCode()));
                
                QDomElement itemID = doc.createElement("itemID");
                
                QDomText itemIDText = doc.createTextNode(getQStringForItemIDSave(itList.at(i).getItemID()));
                
                QDomElement name = doc.createElement("nameItem");
                
                QDomText nameText = doc.createTextNode(getQStringForNameSave(itList.at(i).getName()));
                
                QDomElement number = doc.createElement("number");
                
                QDomText numberText = doc.createTextNode(getQStringForNumberSave(itList.at(i).getNumber()));
                
                QDomElement price = doc.createElement("price");
                
                QDomText priceText = doc.createTextNode(getQStringForPriceSave(itList.at(i).getPrice()));
                
                
                inventory.appendChild(inventoryItem);
                inventoryItem.appendChild(IDCodeItem);
                inventoryItem.appendChild(itemIDItem);
                inventoryItem.appendChild(nameItem);
                inventoryItem.appendChild(numberItem);
                inventoryItem.appendChild(priceItem);
                
                IDCodeItem.appendChild(IDCode);
                IDCode.appendChild(IDCodeText);
                itemIDItem.appendChild(itemID);
                itemID.appendChild(itemIDText);
                nameItem.appendChild(name);
                name.appendChild(nameText);
                numberItem.appendChild(number);
                number.appendChild(numberText);
                priceItem.appendChild(price);
                price.appendChild(priceText);
            }
            //bd->progressBar->setValue(83);
            //sd->progressBar->setValue(83);
            //id->progressBar->setValue(83);
            //rd->progressBar->setValue(83);
            
            for (int i = 0; i < rList.size(); i++)
            {
                QDomElement remindersItem = doc.createElement("remindersItem");
                QDomElement IDCodeItem = doc.createElement("IDCodeItem");
                QDomElement dateItem = doc.createElement("dateItem");
                QDomElement subjectItem = doc.createElement("subjectItem");
                QDomElement messageItem = doc.createElement("messageItem");
                
                QDomElement second = doc.createElement("second");
                QDomElement minute = doc.createElement("minute");
                QDomElement hour = doc.createElement("hour");
                QDomElement day = doc.createElement("day");
                QDomElement month = doc.createElement("month");
                QDomElement year = doc.createElement("year");
                
                QDomText secondText = doc.createTextNode(getQStringForSecondsSave(rList.at(i).getDueDate().getSecond()));
                QDomText minuteText = doc.createTextNode(getQStringForMinutesSave(rList.at(i).getDueDate().getMinute()));
                QDomText hourText = doc.createTextNode(getQStringForHourSave(rList.at(i).getDueDate().getHour()));
                QDomText dayText = doc.createTextNode(getQStringForDaySave(rList.at(i).getDueDate().getDay()));
                QDomText monthText = doc.createTextNode(getQStringForMonthSave(rList.at(i).getDueDate().getMonth()));
                QDomText yearText = doc.createTextNode(getQStringForYearSave(rList.at(i).getDueDate().getYear()));
                
                QDomElement IDCode = doc.createElement("IDCode");
                
                QDomText IDCodeText = doc.createTextNode(getQStringForIDCodeSave(rList.at(i).getIDCode()));
                
                QDomElement subject = doc.createElement("subject");
                
                QDomText subjectText = doc.createTextNode(getQStringForSubjectSave(rList.at(i).getSubject()));
                
                QDomElement message = doc.createElement("message");
                
                QDomText messageText = doc.createTextNode(getQStringForMessageSave(rList.at(i).getMessage()));
                
                
                reminders.appendChild(remindersItem);
                remindersItem.appendChild(IDCodeItem);
                remindersItem.appendChild(dateItem);
                remindersItem.appendChild(subjectItem);
                remindersItem.appendChild(messageItem);
                
                IDCodeItem.appendChild(IDCode);
                IDCode.appendChild(IDCodeText);
                dateItem.appendChild(second);
                dateItem.appendChild(minute);
                dateItem.appendChild(hour);
                dateItem.appendChild(day);
                dateItem.appendChild(month);
                dateItem.appendChild(year);
                second.appendChild(secondText);
                minute.appendChild(minuteText);
                hour.appendChild(hourText);
                day.appendChild(dayText);
                month.appendChild(monthText);
                year.appendChild(yearText);
                subjectItem.appendChild(subject);
                subject.appendChild(subjectText);
                messageItem.appendChild(message);
                message.appendChild(messageText);
            }
            //bd->progressBar->setValue(100);
            //sd->progressBar->setValue(100);
            //id->progressBar->setValue(100);
            //rd->progressBar->setValue(100);
            
            QTextStream out(&fileSave);
            doc.save(out, indent);
            
            fileSave.close();
            //setCurrentFile(fileName);
            
            documentModified = false;
            
            documentSaved = true;
        }
    }
}

void MainBudget::writeSpendingToFile()
{
    char * pieColors[] = { "#854313", "#00f47a", "#89b489", "#c7e3e4" };
    int j = 0;
    ofstream pieFile;
    pieFile.open("data/pie_data.cht");
    for (int i = 0; i < dList.size(); i++)
    {
        if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            strcpy(cPieName, dList.at(i).getName().c_str());
            pieFile << cPieName << "," << dList.at(i).getNetAmount() << "," << pieColors[j] << "\n";
            if (j == 3)
                j = 0;
            else
                j++;
        }
    }

    for (int i = 0; i < eList.size(); i++)
    {
        if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            strcpy(cPieName, eList.at(i).getName().c_str());
            pieFile << cPieName << "," << eList.at(i).getNetAmount() << "," << pieColors[j] << "\n";
            if (j == 3)
                j = 0;
            else
                j++;
        }
    }
    pieFile.close();
}

void MainBudget::loadPieChart()
{
    if (workSpaceActive) {
        /*writeSpendingToFile();
         MainWindow *window = new MainWindow("data/pie_data.cht");
         window->show();*/
        
        QPieSeries *incomeSeries = new QPieSeries();
        for (int i = 0; i < iList.size(); i++)
        {
            if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                incomeSeries->setName("Income");
                incomeSeries->append(QString::fromStdString(iList.at(i).getName()), iList.at(i).getNetAmount() + iList.at(i).getNetLAmount());
            }
        }
        
        QPieSeries *debtSeries = new QPieSeries();
        for (int i = 0; i < dList.size(); i++)
        {
            if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                debtSeries->setName("Debt");
                debtSeries->append(QString::fromStdString(dList.at(i).getName()), dList.at(i).getNetAmount() + dList.at(i).getNetLAmount());
            }
        }
        
        QPieSeries *expensesSeries = new QPieSeries();
        for (int i = 0; i < eList.size(); i++)
        {
            if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                expensesSeries->setName("Expenses");
                expensesSeries->append(QString::fromStdString(eList.at(i).getName()), eList.at(i).getNetAmount() + eList.at(i).getNetLAmount());
            }
        }
        
        /*QPieSeries *series1 = new QPieSeries();
         series1->setName("Fossil fuels");
         series1->append("Oil", 353295);
         series1->append("Coal", 188500);
         series1->append("Natural gas", 148680);
         series1->append("Peat", 94545);
         cout << "jtrortoiruoitr" << endl;
         
         QPieSeries *series2 = new QPieSeries();
         series2->setName("Renewables");
         series2->append("Wood fuels", 319663);
         series2->append("Hydro power", 45875);
         series2->append("Wind power", 1060);
         cout << "jtrortoiruoitr2" << endl;
         
         QPieSeries *series3 = new QPieSeries();
         series3->setName("Others");
         series3->append("Nuclear energy", 238789);
         series3->append("Import energy", 37802);
         series3->append("Other", 32441);
         cout << "jtrortoiruoitr3" << endl;*/
        //![1]
        
        //![2]
        DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
        donutBreakdown->setAnimationOptions(QChart::AllAnimations);
        donutBreakdown->setTitle("Finances Chart - " + mainBudgetTab.tabText(mainBudgetTab.currentIndex()));
        donutBreakdown->legend()->setAlignment(Qt::AlignRight);
        donutBreakdown->addBreakdownSeries(incomeSeries, Qt::darkGreen);
        donutBreakdown->addBreakdownSeries(expensesSeries, Qt::red);
        donutBreakdown->addBreakdownSeries(debtSeries, Qt::darkRed);
        //cout << "jtrortoiruoitr4" << endl;
        //![2]
        
        //![3]
        QMainWindow *window = new QMainWindow();
        QChartView *chartView = new QChartView(donutBreakdown);
        chartView->setRenderHint(QPainter::Antialiasing);
        window->setCentralWidget(chartView);
        window->resize(1000, 600);
        //window->setMinimumSize(1000, 600);
        //window->setMaximumSize(1000, 600);
        window->show();
    }
    //cout << "jtrortoiruoitr5" << endl;
}

void MainBudget::getIncomeStatement()
{
    QString qBalanceSheet;
    //QTextStream ss(&qBalanceSheet);
    std::stringstream ss;
    
    QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    fixedFont.setPointSize(13);
    
    ss << "INCOME STATEMENT" << endl << endl;
    ss << "For the month ended: " << convertQStringToString(mainBudgetTab.tabText(mainBudgetTab.currentIndex())) << std::setw(0) << endl;
    
    ss << endl << endl;
    //ss << "Debit" << std::setw(0) << endl << endl;
    ss << "INCOME" << std::setw(0) << endl;
    
    long totalIncome = 0;
    for (int i = 0; i < iList.size(); i++)
    {
        if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            totalIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
            /*string income = iList.at(i).getName() + "\t\t\t" + string(getCharAmountForIncome(iList.at(i).getNetAmount())) + "\n";
             incomeStatement += income;*/
            
            ss << left << std::setw(80) << iList.at(i).getName() << right << std::setw(0) << string(getCharAmountForSavingsCurrentLBalance(iList.at(i).getNetAmount() + iList.at(i).getNetLAmount())) << std::setw(0) << endl;
        }
    }
    
    ss << endl;
    ss << left << std::setw(80) << "Total Income" << std::setw(16) << string(getCharAmountForSavingsCurrentLBalance(totalIncome)) << std::setw(0) << endl;
    
    ss << endl << endl;
    //ss << "Credit" << std::setw(0) << endl << endl;
    
    //ss << "DEBTS" << std::setw(0) << endl;
    
    //ss << endl;
    //ss << left << std::setw(80) << "Total Debt" << std::setw(16) << string(cMonthlyDebt) << std::setw(0) << endl;
    
    // add expenses
    //ss << endl;
    ss << "EXPENSES" << std::setw(0) << endl;
    
    long totalExpenses = 0;
    for (int i = 0; i < dList.size(); i++)
    {
        if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            totalExpenses += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
            //string debt = "\t\t\t\t\t\t" + dList.at(i).getName() + "\t\t\t" + string(getCharAmountForDebt(dList.at(i).getNetAmount())) + "\n";
            
            ss << left << std::setw(80) << dList.at(i).getName() << right << std::setw(0) << string(getCharAmountForSavingsCurrentLBalance(dList.at(i).getNetAmount() + dList.at(i).getNetLAmount())) << std::setw(0) << endl;
        }
    }
    
    for (int i = 0; i < eList.size(); i++)
    {
        if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            totalExpenses += eList.at(i).getAmount() + eList.at(i).getLAmount();
            //string expense = "\t\t\t\t\t\t" + eList.at(i).getName() + "\t\t\t" + string(getCharAmountForExpenses(eList.at(i).getNetAmount())) + "\n";
            //incomeStatement += expense;
            
            ss << left << std::setw(80) << eList.at(i).getName() << right << std::setw(0) << string(getCharAmountForSavingsCurrentLBalance(eList.at(i).getNetAmount() + eList.at(i).getLAmount())) << std::setw(0) << endl;
        }
    }
    
    ss << endl;
    ss << left << std::setw(80) << "Total Expenses" << std::setw(16) << string(getCharAmountForSavingsCurrentLBalance(totalExpenses)) << std::setw(0) << endl;
    
    //add net income
    ss << endl;
    ss << endl;
    ss << left << std::setw(80) << "Net Income" << std::setw(16) << string(getCharAmountForSavingsCurrentLBalance(totalIncome - totalExpenses)) << std::setw(0) << endl;
    
    isDialog = new IncomeStatementDialog(this);
    isDialog->setWindowTitle("Income Statement");
    
    //QFont fnt("", 13);
    //fnt.setStyleHint(QFont::Courier, QFont::PreferQuality);
    isDialog->textBrowser->setCurrentFont(fixedFont);
    
    isDialog->textBrowser->setPlainText(QString::fromStdString(ss.str()));
}

void MainBudget::showIncomeStatement()
{
    getIncomeStatement();
    isDialog->setModal(true);
    isDialog->show();
    connect(isDialog->closeButton, SIGNAL(clicked()), this, SLOT(closeIncomeStatement()));
}

void MainBudget::showCashFlowStatement() {
    
}

void MainBudget::getBalanceSheet() {
    QString qBalanceSheet;
    //QTextStream ss(&qBalanceSheet);
    std::stringstream ss;
    
    QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    fixedFont.setPointSize(13);
    
    ss << "BALANCE SHEET" << endl << endl;
    ss << "As at: " << convertQStringToString(mainBudgetTab.tabText(mainBudgetTab.currentIndex())) << std::setw(0) << endl;
    
    //string sDate = convertQStringToString(mainBudgetTab.tabText(mainBudgetTab.currentIndex()));
    ss << endl << endl;
    ss << "ASSETS" << std::setw(0) << endl << endl;
    ss << "CASH AND CASH EQUIVALENTS:" << std::setw(0) << endl;
    
    long totalAssets = 0;
    for (int i = 0; i < sList.size(); i++)
    {
        if (sList.at(i).getNature() == BANK) {
            totalAssets += sList.at(i).getAmount() + sList.at(i).getLAmount();
            
            //QString assetName = QString::fromStdString(sList.at(i).getName());
            
            //int width = fm.width(assetName);
            
            ss << left << std::setw(80) << sList.at(i).getName() << right << std::setw(0) << string(getCharAmountForSavingsCurrentLBalance(sList.at(i).getAmount() + sList.at(i).getLAmount())) << std::setw(0) << endl;
            ss.flush();
        }
    }
    ss << endl;
    ss << "INVESTMENTS:" << setw(0) << endl;
    for (int j = 0; j < sList.size(); j++)
    {
        if (sList.at(j).getNature() == STOCK) {
            totalAssets += sList.at(j).getAmount() + sList.at(j).getLAmount();
            
            //QString assetName = QString::fromStdString(sList.at(j).getName());
            
            //int width = fm.width(assetName);
            
            //QTextStream se(&qBalanceSheet);
            ss << left << std::setw(80) << sList.at(j).getName() << right << std::setw(0) << string(getCharAmountForSavingsCurrentLBalance(sList.at(j).getAmount() + sList.at(j).getLAmount())) << std::setw(0) << endl;
        }
    }
    
    ss << endl;
    ss << left << std::setw(80) << "Total Assets" << std::setw(16) << string(getCharAmountForSavingsCurrentLBalance(totalAssets)) << std::setw(0) << endl;
    ss << endl << endl;
    ss << "LIABILITIES" << std::setw(0) << endl << std::setw(0) << endl;
    ss << "DEBTS" << std::setw(0) << endl;
    
    long totalLiabilities = 0;
    for (int k = 0; k < dList.size(); k++)
    {
        if (dList.at(k).getTabIndex() == mainBudgetTab.currentIndex())
        {
            totalLiabilities += (dList.at(k).getNetAmount() + dList.at(k).getNetLAmount()) * dList.at(k).getNumberOfMonths();
            long currentLiability = (dList.at(k).getNetAmount() + dList.at(k).getNetLAmount()) * dList.at(k).getNumberOfMonths();
            
            //QTextStream sf(&qBalanceSheet);
            ss << left << std::setw(80) << dList.at(k).getName() << std::setw(16) << string(getCharAmountForSavingsCurrentLBalance(currentLiability)) << std::setw(0) << endl;
        }
    }
    
    long netWorth = totalAssets - totalLiabilities;
    ss << endl;
    ss << left << std::setw(80)<< "NET WORTH" << std::setw(16) << string(getCharAmountForSavingsCurrentLBalance(netWorth)) << setw(0) << endl;
    
    ss << endl;
    ss << left << std::setw(80)<< "Total Liabilites" << std::setw(16) << string(getCharAmountForSavingsCurrentLBalance(totalAssets)) << std::setw(0) << endl;
    
    cout << ss.str() << endl;
    
    isDialog = new IncomeStatementDialog(this);
    isDialog->setWindowTitle("Balance Sheet");
    
    //QFont fnt("", 13);
    //fnt.setStyleHint(QFont::Courier, QFont::PreferQuality);
    isDialog->textBrowser->setCurrentFont(fixedFont);
    
    isDialog->textBrowser->setPlainText(QString::fromStdString(ss.str()));
}

void MainBudget::showBalanceSheet() {
    getBalanceSheet();
    isDialog->setModal(true);
    isDialog->show();
    connect(isDialog->closeButton, SIGNAL(clicked()), this, SLOT(closeIncomeStatement()));
    
}

/*QString MainBudget::formatNameForStatement(QString originalQString) {
    
}*/

void MainBudget::closeIncomeStatement()
{
    //isDialog->setModal(false);
    isDialog->done(0);
}

void MainBudget::selectClickedReminderBudget()
{
    QDate selectedDate = bd->calendar->selectedDate();
    bool reminderExists = false;
    for (int i = 0; i < bd->calendar->reminderDate.size(); i++)
    {
        if (bd->calendar->reminderDate.at(i) == selectedDate)
        {
            reminderExists = true;
            rd->remindersTable->selectRow(i);
        }
    }
    if (reminderExists) {
        viewReminders();
        setRemindersTableFocus();
    }
}

void MainBudget::selectClickedReminderSavings()
{
    QDate selectedDate = sd->calendar->selectedDate();
    bool reminderExists = false;
    for (int i = 0; i < sd->calendar->reminderDate.size(); i++)
    {
        if (sd->calendar->reminderDate.at(i) == selectedDate)
        {
            reminderExists = true;
            rd->remindersTable->selectRow(i);
        }
    }
    if (reminderExists)
        viewReminders();
}

void MainBudget::selectClickedReminderInventory()
{
    QDate selectedDate = id->calendar->selectedDate();
    bool reminderExists = false;
    for (int i = 0; i < id->calendar->reminderDate.size(); i++)
    {
        if (id->calendar->reminderDate.at(i) == selectedDate)
        {
            reminderExists = true;
            rd->remindersTable->selectRow(i);
        }
    }
    if (reminderExists)
        viewReminders();
}

void MainBudget::selectClickedReminderReminders()
{
    QDate selectedDate = rd->calendar->selectedDate();
    bool reminderExists = false;
    for (int i = 0; i < rd->calendar->reminderDate.size(); i++)
    {
        if (rd->calendar->reminderDate.at(i) == selectedDate)
        {
            reminderExists = true;
            rd->remindersTable->selectRow(i);
        }
    }
    if (reminderExists)
        viewReminders();
}

void MainBudget::activateCurrentBudgetTab()
{
    selectedBudgetFrame = static_cast<BudgetFrame*>(mainBudgetTab.currentWidget());

    /*SET THE LOOK AND BEHAVIOR OF THE INCOME TABLE*/
    selectedBudgetFrame->incomeTable_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    selectedBudgetFrame->incomeTable_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    selectedBudgetFrame->incomeTable_2->setSelectionMode(QAbstractItemView::SingleSelection);

    /*EDITING SELECTED INCOMES*/
    disconnect(selectedBudgetFrame->incomeTable_2, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setIncomeTableFocus()));
    connect(selectedBudgetFrame->incomeTable_2, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setIncomeTableFocus()));
    disconnect(selectedBudgetFrame->incomeTable_2, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedItem()));
    connect(selectedBudgetFrame->incomeTable_2, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedItem()));

    /*SHOULD CHANGES OR DELETIONS OCCUR*/
    populateIncomeTable(iList);

    /*SET THE LOOK AND BEHAVIOR OF THE DEBT TABLE*/
    selectedBudgetFrame->debtTable_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    selectedBudgetFrame->debtTable_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    selectedBudgetFrame->debtTable_2->setSelectionMode(QAbstractItemView::SingleSelection);

    /*EDITING SELECTED DEBTS*/
    disconnect(selectedBudgetFrame->debtTable_2, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setDebtTableFocus()));
    connect(selectedBudgetFrame->debtTable_2, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setDebtTableFocus()));
    disconnect(selectedBudgetFrame->debtTable_2, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedItem()));
    connect(selectedBudgetFrame->debtTable_2, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedItem()));

    /*SHOULD CHANGES OR DELETIONS OCCUR*/
    populateDebtTable(dList);

    /*SET THE LOOK AND BEHAVIOR OF THE EXPENSES TABLE*/
    selectedBudgetFrame->expensesTable_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    selectedBudgetFrame->expensesTable_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    selectedBudgetFrame->expensesTable_2->setSelectionMode(QAbstractItemView::SingleSelection);

    /*EDITING SELECTED EXPENSES*/
    disconnect(selectedBudgetFrame->expensesTable_2, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setExpensesTableFocus()));
    connect(selectedBudgetFrame->expensesTable_2, SIGNAL(itemClicked(QTableWidgetItem *)),
        this, SLOT(setExpensesTableFocus()));
    disconnect(selectedBudgetFrame->expensesTable_2, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedItem()));
    connect(selectedBudgetFrame->expensesTable_2, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
        this, SLOT(editSelectedItem()));

    disconnect(selectedBudgetFrame->saveMoneyButton, SIGNAL(clicked()), this, SLOT(saveMoneyClick()));
    connect(selectedBudgetFrame->saveMoneyButton, SIGNAL(clicked()), this, SLOT(saveMoneyClick()));

    /*SHOULD CHANGES OR DELETIONS OCCUR*/
    populateExpensesTable(eList);

    /*TOTALS AND BALANCES*/
    monthlyIncome = 0;
    monthlyLIncome = 0;
    for (int i = 0; i < iList.size(); i++)
    {
        if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (iList.at(i).getAmountType() == "long")
                containsLongIncome = true;
            monthlyIncome += iList.at(i).getNetAmount();
            monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
        }
    }
    //if (containsLongIncome)
        bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
    //else
    //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));

    monthlyDebt = 0;
    monthlyLDebt = 0;
    for (int i = 0; i < dList.size(); i++)
    {
        if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (dList.at(i).getAmountType() == "long")
                containsLongDebt = true;
            monthlyDebt += dList.at(i).getNetAmount();
            monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
        }
    }
    //if (containsLongDebt)
        bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
    //else
    //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));

    monthlyExpenses = 0;
    monthlyLExpenses = 0;
    for (int i = 0; i < eList.size(); i++)
    {
        if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (eList.at(i).getAmountType() == "long")
                containsLongExpense = true;
            monthlyExpenses += eList.at(i).getNetAmount();
            monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
        }
    }
    //if (containsLongExpense)
        bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
    //else
    //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

    setCurrentBalance();
}

QString MainBudget::getTabBarDate(QDate date)
{
    ostringstream ostrYear;
    ostringstream ostrMonth;
    ostrMonth << date.month();;
    string month = ostrMonth.str();
    ostrYear << date.year();
    string year = ostrYear.str();
    string theDate = month + "/" + year;
    char cDateTitle[9];
    for (int i = 0; i < 9; i++)
        cDateTitle[i] = theDate[i];

    QString dateTitle(cDateTitle);
    return dateTitle;
}

bool MainBudget::allowBudgetAddition(QDate entryDate) {
    int entryMonth = entryDate.month();
    int entryYear = entryDate.year();
    
    QString earliestRecordDateString = mainBudgetTab.tabText(mainBudgetTab.count() - 1);
    QStringList pieces = earliestRecordDateString.split("/");
    QString earliestRecordMonthString = pieces.value(pieces.length() - 2);
    QString earliestRecordYearString = pieces.value(pieces.length() - 1);
    
    int earliestRecordMonth = earliestRecordMonthString.toInt();
    int earliestRecordYear = earliestRecordYearString.toInt();
    
    // If the added record is in a year before the earliest record, stop
    if (entryYear < earliestRecordYear)
        return false;
    
    // If the records are in the same year but in a month greater than or
    // equal to the earliest record, proceed
    if (entryYear == earliestRecordYear) {
        if (entryMonth >= earliestRecordMonth) {
            return true;
        } else {
            return false;
        }
    }
    
    // If the entry record is larger than the earliest record
    if (entryYear > earliestRecordYear) {
        
        // If the record separation exceeds 1 year, stop
        if ((entryYear - earliestRecordYear) > 1) {
            return false;
        }
        
        // If the records are in the same year, proceed
        if ((entryYear - earliestRecordYear) == 1) {
            if (entryMonth < earliestRecordMonth) {
                return true;
            } else {
                return false;
            }
        }
    }
    
    cout << convertQStringToString(mainBudgetTab.tabText(mainBudgetTab.count() - 1)) << endl;
    cout << convertQStringToString(earliestRecordMonthString) << endl;
    cout << convertQStringToString(earliestRecordYearString) << endl;
    
    return false;
}

bool MainBudget::tabTitleExists(QDate subjectDate)
{
    for (int i = 0; i < mainBudgetTab.count(); i++)
    {
        if (mainBudgetTab.tabText(i) == getTabBarDate(subjectDate))
            return true;
    }
    return false;
}

string MainBudget::convertQStringToString(QString qString)
{
    QChar * qcString = qString.data();
    char cString[qString.size() + 1];
    //int i = 0;
    for (int i = 0; i < qString.size() + 1; i++)
    {
        cString[i] = qcString->toAscii();
        ++qcString;
    }

    string actualString = string(cString);
    return actualString;
}

QString MainBudget::convertStringToQString(string actualString)
{
    for (int i = 0; i < 8; i++)
        cTabTitle[i] = actualString[i];

    return QString(cTabTitle);
}

QString MainBudget::convertStringToQStringNoTab(string actualString)
{
    for (int i = 0; i < actualString.length(); i++)
        cTabTitle[i] = actualString[i];
    
    return QString(cTabTitle);
}

QString MainBudget::getQStringForSecondsSave(int seconds)
{
    ostringstream ostrSeconds;
    ostrSeconds << seconds;
    string sSeconds = ostrSeconds.str();
    
    for (int i = 0; i < 3; i++)
        cSecondsForSave[i] = sSeconds[i];
    return QString(cSecondsForSave);
}

QString MainBudget::getQStringForMinutesSave(int minutes)
{
    ostringstream ostrMinutes;
    ostrMinutes << minutes;
    string sMinutes = ostrMinutes.str();

    for (int i = 0; i < 3; i++)
        cMinutesForSave[i] = sMinutes[i];
    return QString(cMinutesForSave);
}

QString MainBudget::getQStringForHourSave(int hour)
{
    ostringstream ostrHour;
    ostrHour << hour;
    string sHour = ostrHour.str();

    for (int i = 0; i < 3; i++)
        cHourForSave[i] = sHour[i];
    return QString(cHourForSave);
}

QString MainBudget::getQStringForDaySave(int day)
{
    ostringstream ostrDay;
    ostrDay << day;
    string sDay = ostrDay.str();

    for (int i = 0; i < 3; i++)
        cDayForSave[i] = sDay[i];
    return QString(cDayForSave);
}

QString MainBudget::getQStringForMonthSave(int month)
{
    ostringstream ostrMonth;
    ostrMonth << month;
    string sMonth = ostrMonth.str();

    for (int i = 0; i < 3; i++)
        cMonthForSave[i] = sMonth[i];
    return QString(cMonthForSave);
}

QString MainBudget::getQStringForYearSave(int year)
{
    ostringstream ostrYear;
    ostrYear << year;
    string sYear = ostrYear.str();

    for (int i = 0; i < 5; i++)
        cYearForSave[i] = sYear[i];
    return QString(cYearForSave);
}

QString MainBudget::getQStringForNameSave(string name)
{
    strcpy(cNameForSave, name.c_str());
    return QString(cNameForSave);
}

QString MainBudget::getQStringForNatureSave(Nature nature)
{
    if (nature == SALARY)
        cNatureForSave = "SALARY";
    if (nature == DIVIDEND)
        cNatureForSave = "DIVIDEND";
    if (nature == STOCK_SALE)
        cNatureForSave = "STOCK_SALE";
    if (nature == IOU)
        cNatureForSave = "IOU";
    if (nature == DIP)
        cNatureForSave = "DIP";
    if (nature == OTHER)
        cNatureForSave = "OTHER";
    return QString(cNatureForSave);
}

QString MainBudget::getQStringForAmountSave(double amount)
{
    ostringstream ostrAmount;
    ostrAmount << amount;
    string sAmount = ostrAmount.str();

    for (int i = 0; i < 16; i++)
        cAmountForSave[i] = sAmount[i];
    return QString(cAmountForSave);
}

QString MainBudget::getQStringForLAmountSave(long lAmount)
{
    ostringstream ostrAmount;
    ostrAmount << lAmount;
    string sAmount = ostrAmount.str();

    for (int i = 0; i < 16; i++)
        cAmountForSave[i] = sAmount[i];
    return QString(cAmountForSave);
}

QString MainBudget::getQStringForTaxSave(float tax)
{
    ostringstream ostrTax;
    ostrTax << tax;
    string sTax = ostrTax.str();

    for (int i = 0; i < 11; i++)
        cTaxForSave[i] = sTax[i];
    return QString(cTaxForSave);
}

QString MainBudget::getQStringForNetAmountSave(double netAmount)
{
    ostringstream ostrNetAmount;
    ostrNetAmount << netAmount;
    string sNetAmount = ostrNetAmount.str();

    for (int i = 0; i < 16; i++)
        cNetAmountForSave[i] = sNetAmount[i];
    return QString(cNetAmountForSave);
}

QString MainBudget::getQStringForNetLAmountSave(long netLAmount)
{
    ostringstream ostrNetAmount;
    ostrNetAmount << netLAmount;
    string sNetAmount = ostrNetAmount.str();

    for (int i = 0; i < 16; i++)
        cNetAmountForSave[i] = sNetAmount[i];
    return QString(cNetAmountForSave);
}

QString MainBudget::getQStringForIDCodeSave(int IDCode)
{
    ostringstream ostrIDCode;
    ostrIDCode << IDCode;
    string sIDCode = ostrIDCode.str();

    for (int i = 0; i < 5; i++)
        cIDCodeForSave[i] = sIDCode[i];
    return QString(cIDCodeForSave);
}

QString MainBudget::getQStringForAdditionalInfoSave(string additionalInfo)
{
    strcpy(cAdditionalInfoForSave, additionalInfo.c_str());
    return QString(cAdditionalInfoForSave);
}

QString MainBudget::getQStringForTabIndexSave(int tabIndex)
{
    ostringstream ostrTabIndex;
    ostrTabIndex << tabIndex;
    string sTabIndex = ostrTabIndex.str();

    for (int i = 0; i < 10; i++)
        cTabIndexForSave[i] = sTabIndex[i];
    return QString(cTabIndexForSave);
}

QString MainBudget::getQStringForPriorityLevelSave(PriorityLevel priorityLevel)
{
    if (priorityLevel == HIGH)
        cPriorityLevelForSave = "HIGH";
    if (priorityLevel == MEDIUM)
        cPriorityLevelForSave = "MEDIUM";
    if (priorityLevel == LOW)
        cPriorityLevelForSave = "LOW";
    if (priorityLevel == NONE)
        cPriorityLevelForSave = "NONE";;
    return QString(cPriorityLevelForSave);
}

QString MainBudget::getQStringForAPRSave(float APR)
{
    ostringstream ostrAPR;
    ostrAPR << APR;
    string sAPR = ostrAPR.str();

    for (int i = 0; i < 11; i++)
        cAPRForSave[i] = sAPR[i];
    return QString(cAPRForSave);
}

QString MainBudget::getQStringForPenaltySave(double penalty)
{
    ostringstream ostrPenalty;
    ostrPenalty << penalty;
    string sPenalty = ostrPenalty.str();

    for (int i = 0; i < 16; i++)
        cPenaltyForSave[i] = sPenalty[i];
    return QString(cPenaltyForSave);
}

QString MainBudget::getQStringForSavingsNatureSave(SavingsNature savingsNature)
{
    if (savingsNature == STOCK)
        cSavingsNatureForSave = "STOCK";
    if (savingsNature == BANK)
        cSavingsNatureForSave = "BANK";
    return QString(cSavingsNatureForSave);
}

QString MainBudget::getQStringForDescriptionSave(string description)
{
    strcpy(cDescriptionForSave, description.c_str());
    return QString(cDescriptionForSave);
}

QString MainBudget::getQStringForItemIDSave(string itemID)
{
    strcpy(cItemIDForSave, itemID.c_str());
    return QString(cItemIDForSave);
}

QString MainBudget::getQStringForNumberSave(int number)
{
    ostringstream ostrNumber;
    ostrNumber << number;
    string sNumber = ostrNumber.str();

    for (int i = 0; i < 10; i++)
        cNumberForSave[i] = sNumber[i];
    return QString(cNumberForSave);
}

QString MainBudget::getQStringForPriceSave(double price)
{
    ostringstream ostrPrice;
    ostrPrice << price;
    string sPrice = ostrPrice.str();

    for (int i = 0; i < 16; i++)
        cPriceForSave[i] = sPrice[i];
    return QString(cPriceForSave);
}

QString MainBudget::getQStringForSubjectSave(string subject)
{
    strcpy(cSubjectForSave, subject.c_str());
    return QString(cSubjectForSave);
}

QString MainBudget::getQStringForMessageSave(string message)
{
    strcpy(cMessageForSave, message.c_str());
    return QString(cMessageForSave);
}

QString MainBudget::getQStringForNumberOfMonthsSave(int numberOfMonths)
{
    ostringstream ostrNumberOfMonths;
    ostrNumberOfMonths << numberOfMonths;
    string sNumberOfMonths = ostrNumberOfMonths.str();

    for (int i = 0; i < 10; i++)
        cNumberOfMonthsForSave[i] = sNumberOfMonths[i];
    return QString(cNumberOfMonthsForSave);
}


void MainBudget::openGeneric()
{
    if (workSpaceActive)
        close();
    if (openCanceled)
    {
        openCanceled = false;
        return;
    }
    
    const QString DEFAULT_DIR_KEY("default_dir");
    
    QSettings *mySettings = new QSettings(("Thabo David Klass", "CakeHeap Budget Professional"));
    
    if (mySettings->contains(DEFAULT_DIR_KEY))
        fileName = QFileDialog::getOpenFileName(this, tr("Choose a budget file"),
                                                mySettings->value(DEFAULT_DIR_KEY).toString(), "*.chf");
    else
        fileName = QFileDialog::getOpenFileName(this, tr("Choose a budget file"),
                                                QDir::homePath() + "/Documents", "*.chf");
    
    open(fileName, mySettings);
}


void MainBudget::openDragAndDrop(QString fileName) {
    if (workSpaceActive)
        close();
    if (openCanceled)
    {
        openCanceled = false;
        return;
    }
    
    const QString DEFAULT_DIR_KEY("default_dir");
    
    QSettings *mySettings = new QSettings(("Thabo David Klass", "CakeHeap Budget Professional"));
    
    open(fileName, mySettings);
}


void MainBudget::open(QString localfileName, QSettings *mySettings)
{
    /*if (workSpaceActive)
            close();
    if (openCanceled)
    {
        openCanceled = false;
        return;
    }
    
    //QString documentsLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    
    const QString DEFAULT_DIR_KEY("default_dir");
    
    QSettings mySettings;
    
    if (draggedAndDroppedFileName == "nil") {
        if (mySettings.contains(DEFAULT_DIR_KEY))
            fileName = QFileDialog::getOpenFileName(this, tr("Choose a budget file"),
                                                    mySettings.value(DEFAULT_DIR_KEY).toString(), "*.chf");
        else
            fileName = QFileDialog::getOpenFileName(this, tr("Choose a budget file"),
                                                    QDir::homePath() + "/Documents", "*.chf");
    } else
        fileName = draggedAndDroppedFileName;*/
    
    const QString DEFAULT_DIR_KEY("default_dir");
    
    fileName = localfileName;
    saveFileName = fileName;
    if (!fileName.isEmpty())
    {
        QDir currentDir;
        mySettings->setValue(DEFAULT_DIR_KEY,
                            currentDir.absoluteFilePath(fileName));
        
        workSpaceActive = true;
        //documentModified = true;
        QFile file(fileName);

        QStringList pieces = fileName.split( "/" );
        fileNameWithoutFullPath = pieces.value(pieces.length() - 1);
        
        setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath);

        QDomDocument doc;
        doc.setContent(&file);
        QDomElement root = doc.documentElement();
        QDomElement fiscalRecord = root.firstChild().toElement();
        QDomElement income = fiscalRecord.firstChild().toElement();
        QDomNode incomeNode = income.firstChild();
        
        while (!incomeNode.isNull())
        {
            QDomElement incomeItem = incomeNode.toElement();

            QDomElement dateItem = incomeItem.firstChild().toElement();
            QDomElement day = dateItem.firstChild().toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();

            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }

            int dayInt = atoi(cDay);

            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }

            int monthInt = atoi(cMonth);

            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }

            int yearInt = atoi(cYear);

            Date date(yearInt, monthInt, dayInt, 0, 0, 0);
            QDate qdDate(yearInt, monthInt, dayInt);

            if (!tabTitleExists(qdDate))
            {
                mainBudgetTab.insertTab(0, new BudgetFrame, getTabBarDate(qdDate));
                mainBudgetTab.setCurrentIndex(0);
                selectedBudgetFrame->setMonth(monthInt);
                selectedBudgetFrame->setYear(yearInt);
                if (btl.size() > 0)
                        btl.clear();

                for (int i = 0; i < mainBudgetTab.count(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    btl.push_back(BudgetTabItem(convertQStringToString(mainBudgetTab.tabText(i)), selectedBudgetFrame->getMonth(),
                        selectedBudgetFrame->getYear(), i));
                }

                msBudget = new MergeSortBudget(btl);
                msBudget->displayElements();
                msBudget->sort(btl);
                msBudget->displayElements();

                for (int i = 0; i < btl.size(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    mainBudgetTab.setTabText(i, convertStringToQString(msBudget->data.at(i).getTabTitle()));
                    selectedBudgetFrame->setMonth(msBudget->data.at(i).getMonth());
                    selectedBudgetFrame->setYear(msBudget->data.at(i).getYear());
                }
            }

            QDomElement nameItem = incomeItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();

            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }

            string nameString = string(cName);

            QDomElement natureItem = incomeItem.firstChildElement("natureItem").toElement();
            QDomElement nature = natureItem.firstChild().toElement();
            QDomText natureText = nature.firstChild().toText();

            QString qsNature = natureText.data();
            QChar * qcNature = qsNature.data();
            char cNature[qsNature.size() + 1];
            for (int i = 0; i < qsNature.size() + 1; i++)
            {
                cNature[i] = qcNature->toAscii();
                ++qcNature;
            }

            string natureString = string(cNature);
            Nature actualNature;
            if (natureString == "SALARY")
                actualNature = SALARY;
            if (natureString == "DIVIDEND")
                actualNature = DIVIDEND;
            if (natureString == "STOCK_SALE")
                actualNature = STOCK_SALE;
            if (natureString == "IOU")
                actualNature = IOU;
            if (natureString == "DIP")
                actualNature = DIP;
            if (natureString == "OTHER")
                actualNature = OTHER;

            QDomElement amountItem = incomeItem.firstChildElement("amountItem").toElement();
            QDomElement amount = amountItem.firstChild().toElement();
            QDomText amountText = amount.firstChild().toText();

            QString qsAmount = amountText.data();
            QChar * qcAmount = qsAmount.data();
            char cAmount[qsAmount.size() + 1];
            for (int i = 0; i < qsAmount.size() + 1; i++)
            {
                cAmount[i] = qcAmount->toAscii();
                ++qcAmount;
            }

            double amountDouble = atof(cAmount);
            long amountLong = strtold(cAmount, NULL);

            QDomElement taxItem = incomeItem.firstChildElement("taxItem").toElement();
            QDomElement tax = taxItem.firstChild().toElement();
            QDomText taxText = tax.firstChild().toText();

            QString qsTax = taxText.data();
            QChar * qcTax = qsTax.data();
            char cTax[qsTax.size() + 1];
            for (int i = 0; i < qsTax.size() + 1; i++)
            {
                cTax[i] = qcTax->toAscii();
                ++qcTax;
            }

            float taxFloat = atof(cTax);

            QDomElement additionalInfoItem = incomeItem.firstChildElement("additionalInfoItem").toElement();
            QDomElement additionalInfo = additionalInfoItem.firstChild().toElement();
            QDomText additionalInfoText = additionalInfo.firstChild().toText();

            QString qsAdditionalInfo = additionalInfoText.data();
            QChar * qcAdditionalInfo = qsAdditionalInfo.data();
            char cAdditionalInfo[qsAdditionalInfo.size() + 1];
            for (int i = 0; i < qsAdditionalInfo.size() + 1; i++)
            {
                cAdditionalInfo[i] = qcAdditionalInfo->toAscii();
                ++qcAdditionalInfo;
            }

            string additionalInfoString = string(cAdditionalInfo);

            QDomElement tabIndexItem = incomeItem.firstChildElement("tabIndexItem").toElement();
            QDomElement tabIndex = tabIndexItem.firstChild().toElement();
            QDomText tabIndexText = tabIndex.firstChild().toText();

            QString qsTabIndex = tabIndexText.data();
            QChar * qcTabIndex = qsTabIndex.data();
            char cTabIndex[qsTabIndex.size() + 1];
            for (int i = 0; i < qsTabIndex.size() + 1; i++)
            {
                cTabIndex[i] = qcTabIndex->toAscii();
                ++qcTabIndex;
            }

            int tabIndexInt = atoi(cTabIndex);

            if (strtold(cAmount, NULL) > 999999)
            {
                addLIncome(nameString, amountLong, false, 0, date,
                    actualNature, taxFloat, additionalInfoString, tabIndexInt, iList);
            }
            else
            {
                addIncome(nameString, amountDouble, false, 0, date,
                    actualNature, taxFloat, additionalInfoString, tabIndexInt, iList);
            }
            incomeNode = incomeNode.nextSibling();
        }

        QDomElement debt = fiscalRecord.firstChildElement("debt").toElement();
        QDomNode debtNode = debt.firstChild();
        while (!debtNode.isNull())
        {
            QDomElement debtItem = debtNode.toElement();

            QDomElement dateItem = debtItem.firstChild().toElement();
            QDomElement day = dateItem.firstChild().toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();

            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }

            int dayInt = atoi(cDay);

            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }

            int monthInt = atoi(cMonth);

            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }

            int yearInt = atoi(cYear);

            Date date(yearInt, monthInt, dayInt, 0, 0, 0);
            QDate qdDate(yearInt, monthInt, dayInt);

            if (!tabTitleExists(qdDate))
            {
                mainBudgetTab.insertTab(0, new BudgetFrame, getTabBarDate(qdDate));
                mainBudgetTab.setCurrentIndex(0);
                selectedBudgetFrame->setMonth(monthInt);
                selectedBudgetFrame->setYear(yearInt);
                if (btl.size() > 0)
                        btl.clear();

                for (int i = 0; i < mainBudgetTab.count(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    btl.push_back(BudgetTabItem(convertQStringToString(mainBudgetTab.tabText(i)), selectedBudgetFrame->getMonth(),
                        selectedBudgetFrame->getYear(), i));
                }

                msBudget = new MergeSortBudget(btl);
                msBudget->displayElements();
                msBudget->sort(btl);
                msBudget->displayElements();

                for (int i = 0; i < btl.size(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    mainBudgetTab.setTabText(i, convertStringToQString(msBudget->data.at(i).getTabTitle()));
                    selectedBudgetFrame->setMonth(msBudget->data.at(i).getMonth());
                    selectedBudgetFrame->setYear(msBudget->data.at(i).getYear());
                }
            }

            QDomElement nameItem = debtItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();

            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }

            string nameString = string(cName);

            QDomElement priorityLevelItem = debtItem.firstChildElement("priorityLevelItem").toElement();
            QDomElement priorityLevel = priorityLevelItem.firstChild().toElement();
            QDomText priorityLevelText = priorityLevel.firstChild().toText();

            QString qsPriorityLevel = priorityLevelText.data();
            QChar * qcPriorityLevel = qsPriorityLevel.data();
            char cPriorityLevel[qsPriorityLevel.size() + 1];
            for (int i = 0; i < qsPriorityLevel.size() + 1; i++)
            {
                cPriorityLevel[i] = qcPriorityLevel->toAscii();
                ++qcPriorityLevel;
            }

            string priorityLevelString = string(cPriorityLevel);
            PriorityLevel actualPriorityLevel;
            if (priorityLevelString == "HIGH")
                actualPriorityLevel= HIGH;
            if (priorityLevelString == "MEDIUM")
                actualPriorityLevel = MEDIUM;
            if (priorityLevelString == "LOW")
                actualPriorityLevel = LOW;
            if (priorityLevelString == "NONE")
                actualPriorityLevel = NONE;

            QDomElement amountItem = debtItem.firstChildElement("amountItem").toElement();
            QDomElement amount = amountItem.firstChild().toElement();
            QDomText amountText = amount.firstChild().toText();

            QString qsAmount = amountText.data();
            QChar * qcAmount = qsAmount.data();
            char cAmount[qsAmount.size() + 1];
            for (int i = 0; i < qsAmount.size() + 1; i++)
            {
                cAmount[i] = qcAmount->toAscii();
                ++qcAmount;
            }

            double amountDouble = atof(cAmount);
            long amountLong = strtold(cAmount, NULL);

            QDomElement APRItem = debtItem.firstChildElement("APRItem").toElement();
            QDomElement APR = APRItem.firstChild().toElement();
            QDomText APRText = APR.firstChild().toText();

            QString qsAPR = APRText.data();
            QChar * qcAPR = qsAPR.data();
            char cAPR[qsAPR.size() + 1];
            for (int i = 0; i < qsAPR.size() + 1; i++)
            {
                cAPR[i] = qcAPR->toAscii();
                ++qcAPR;
            }

            float APRFloat = atof(cAPR);

            QDomElement additionalInfoItem = debtItem.firstChildElement("additionalInfoItem").toElement();
            QDomElement additionalInfo = additionalInfoItem.firstChild().toElement();
            QDomText additionalInfoText = additionalInfo.firstChild().toText();

            QString qsAdditionalInfo = additionalInfoText.data();
            QChar * qcAdditionalInfo = qsAdditionalInfo.data();
            char cAdditionalInfo[qsAdditionalInfo.size() + 1];
            for (int i = 0; i < qsAdditionalInfo.size() + 1; i++)
            {
                cAdditionalInfo[i] = qcAdditionalInfo->toAscii();
                ++qcAdditionalInfo;
            }

            string additionalInfoString = string(cAdditionalInfo);

            QDomElement numberOfMonthsItem = debtItem.firstChildElement("numberOfMonthsItem").toElement();
            QDomElement numberOfMonths = numberOfMonthsItem.firstChild().toElement();
            QDomText numberOfMonthsText = numberOfMonths.firstChild().toText();

            QString qsNumberOfMonths = numberOfMonthsText.data();
            QChar * qcNumberOfMonths = qsNumberOfMonths.data();
            char cNumberOfMonths[qsNumberOfMonths.size() + 1];
            for (int i = 0; i < qsNumberOfMonths.size() + 1; i++)
            {
                cNumberOfMonths[i] = qcNumberOfMonths->toAscii();
                ++qcNumberOfMonths;
            }

            int numberOfMonthsInt = atoi(cNumberOfMonths);

            QDomElement tabIndexItem = debtItem.firstChildElement("tabIndexItem").toElement();
            QDomElement tabIndex = tabIndexItem.firstChild().toElement();
            QDomText tabIndexText = tabIndex.firstChild().toText();

            QString qsTabIndex = tabIndexText.data();
            QChar * qcTabIndex = qsTabIndex.data();
            char cTabIndex[qsTabIndex.size() + 1];
            for (int i = 0; i < qsTabIndex.size() + 1; i++)
            {
                cTabIndex[i] = qcTabIndex->toAscii();
                ++qcTabIndex;
            }

            int tabIndexInt = atoi(cTabIndex);

            if (strtold(cAmount, NULL) > 999999)
            {
                addLDebt(nameString, amountLong, true, APRFloat, actualPriorityLevel,
                    date, additionalInfoString, numberOfMonthsInt, tabIndexInt, dList);
            }
            else
            {
                addDebt(nameString, amountDouble, true, APRFloat, actualPriorityLevel,
                    date, additionalInfoString, numberOfMonthsInt, tabIndexInt, dList);
            }

            debtNode = debtNode.nextSibling();
        }

        QDomElement expense = fiscalRecord.firstChildElement("expense").toElement();
        QDomNode expenseNode = expense.firstChild();
        while (!expenseNode.isNull())
        {
            QDomElement expenseItem = expenseNode.toElement();

            QDomElement dateItem = expenseItem.firstChild().toElement();
            QDomElement day = dateItem.firstChild().toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();

            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }

            int dayInt = atoi(cDay);

            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }

            int monthInt = atoi(cMonth);

            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }

            int yearInt = atoi(cYear);

            Date date(yearInt, monthInt, dayInt, 0, 0, 0);
            QDate qdDate(yearInt, monthInt, dayInt);

            if (!tabTitleExists(qdDate))
            {
                mainBudgetTab.insertTab(0, new BudgetFrame, getTabBarDate(qdDate));
                mainBudgetTab.setCurrentIndex(0);
                selectedBudgetFrame->setMonth(monthInt);
                selectedBudgetFrame->setYear(yearInt);
                if (btl.size() > 0)
                        btl.clear();

                for (int i = 0; i < mainBudgetTab.count(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    btl.push_back(BudgetTabItem(convertQStringToString(mainBudgetTab.tabText(i)), selectedBudgetFrame->getMonth(),
                        selectedBudgetFrame->getYear(), i));
                }

                msBudget = new MergeSortBudget(btl);
                msBudget->displayElements();
                msBudget->sort(btl);
                msBudget->displayElements();

                for (int i = 0; i < btl.size(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    mainBudgetTab.setTabText(i, convertStringToQString(msBudget->data.at(i).getTabTitle()));
                    selectedBudgetFrame->setMonth(msBudget->data.at(i).getMonth());
                    selectedBudgetFrame->setYear(msBudget->data.at(i).getYear());
                }
            }

            QDomElement nameItem = expenseItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();

            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }

            string nameString = string(cName);

            QDomElement priorityLevelItem = expenseItem.firstChildElement("priorityLevelItem").toElement();
            QDomElement priorityLevel = priorityLevelItem.firstChild().toElement();
            QDomText priorityLevelText = priorityLevel.firstChild().toText();

            QString qsPriorityLevel = priorityLevelText.data();
            QChar * qcPriorityLevel = qsPriorityLevel.data();
            char cPriorityLevel[qsPriorityLevel.size() + 1];
            for (int i = 0; i < qsPriorityLevel.size() + 1; i++)
            {
                cPriorityLevel[i] = qcPriorityLevel->toAscii();
                ++qcPriorityLevel;
            }

            string priorityLevelString = string(cPriorityLevel);
            PriorityLevel actualPriorityLevel;
            if (priorityLevelString == "HIGH")
                actualPriorityLevel= HIGH;
            if (priorityLevelString == "MEDIUM")
                actualPriorityLevel = MEDIUM;
            if (priorityLevelString == "LOW")
                actualPriorityLevel = LOW;
            if (priorityLevelString == "NONE")
                actualPriorityLevel = NONE;

            QDomElement amountItem = expenseItem.firstChildElement("amountItem").toElement();
            QDomElement amount = amountItem.firstChild().toElement();
            QDomText amountText = amount.firstChild().toText();

            QString qsAmount = amountText.data();
            QChar * qcAmount = qsAmount.data();
            char cAmount[qsAmount.size() + 1];
            for (int i = 0; i < qsAmount.size() + 1; i++)
            {
                cAmount[i] = qcAmount->toAscii();
                ++qcAmount;
            }

            double amountDouble = atof(cAmount);
            long amountLong = strtold(cAmount, NULL);

            QDomElement penaltyItem = expenseItem.firstChildElement("penaltyItem").toElement();
            QDomElement penalty = penaltyItem.firstChild().toElement();
            QDomText penaltyText = penalty.firstChild().toText();

            QString qsPenalty = penaltyText.data();
            QChar * qcPenalty = qsPenalty.data();
            char cPenalty[qsPenalty.size() + 1];
            for (int i = 0; i < qsPenalty.size() + 1; i++)
            {
                cPenalty[i] = qcPenalty->toAscii();
                ++qcPenalty;
            }

            double penaltyDouble = atof(cPenalty);

            QDomElement additionalInfoItem = expenseItem.firstChildElement("additionalInfoItem").toElement();
            QDomElement additionalInfo = additionalInfoItem.firstChild().toElement();
            QDomText additionalInfoText = additionalInfo.firstChild().toText();

            QString qsAdditionalInfo = additionalInfoText.data();
            QChar * qcAdditionalInfo = qsAdditionalInfo.data();
            char cAdditionalInfo[qsAdditionalInfo.size() + 1];
            for (int i = 0; i < qsAdditionalInfo.size() + 1; i++)
            {
                cAdditionalInfo[i] = qcAdditionalInfo->toAscii();
                ++qcAdditionalInfo;
            }

            string additionalInfoString = string(cAdditionalInfo);

            QDomElement tabIndexItem = expenseItem.firstChildElement("tabIndexItem").toElement();
            QDomElement tabIndex = tabIndexItem.firstChild().toElement();
            QDomText tabIndexText = tabIndex.firstChild().toText();

            QString qsTabIndex = tabIndexText.data();
            QChar * qcTabIndex = qsTabIndex.data();
            char cTabIndex[qsTabIndex.size() + 1];
            for (int i = 0; i < qsTabIndex.size() + 1; i++)
            {
                cTabIndex[i] = qcTabIndex->toAscii();
                ++qcTabIndex;
            }

            int tabIndexInt = atoi(cTabIndex);

            if (strtold(cAmount, NULL) > 999999)
            {
                addLExpense(nameString, amountLong, actualPriorityLevel,
                    penaltyDouble, date, additionalInfoString, tabIndexInt, eList);
            }
            else
            {
                addExpense(nameString, amountDouble, actualPriorityLevel,
                    penaltyDouble, date, additionalInfoString, tabIndexInt, eList);
            }
            expenseNode = expenseNode.nextSibling();
        }

        QDomElement savings = fiscalRecord.firstChildElement("savings").toElement();
        QDomNode savingsNode = savings.firstChild();
        while (!savingsNode.isNull())
        {
            QDomElement savingsItem = savingsNode.toElement();

            QDomElement nameItem = savingsItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();

            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }

            string nameString = string(cName);

            QDomElement savingsNatureItem = savingsItem.firstChildElement("natureItem").toElement();
            QDomElement savingsNature = savingsNatureItem.firstChild().toElement();
            QDomText savingsNatureText = savingsNature.firstChild().toText();

            QString qsSavingsNature = savingsNatureText.data();
            QChar * qcSavingsNature = qsSavingsNature.data();
            char cSavingsNature[qsSavingsNature.size() + 1];
            for (int i = 0; i < qsSavingsNature.size() + 1; i++)
            {
                cSavingsNature[i] = qcSavingsNature->toAscii();
                ++qcSavingsNature;
            }

            string savingsNatureString = string(cSavingsNature);
            SavingsNature actualSavingsNature;
            if (savingsNatureString == "STOCK")
                actualSavingsNature = STOCK;
            if (savingsNatureString == "BANK")
                actualSavingsNature = BANK;

            QDomElement APRItem = savingsItem.firstChildElement("APRItem").toElement();
            QDomElement APR = APRItem.firstChild().toElement();
            QDomText APRText = APR.firstChild().toText();

            QString qsAPR = APRText.data();
            QChar * qcAPR = qsAPR.data();
            char cAPR[qsAPR.size() + 1];
            for (int i = 0; i < qsAPR.size() + 1; i++)
            {
                cAPR[i] = qcAPR->toAscii();
                ++qcAPR;
            }

            float APRFloat = atof(cAPR);

            QDomElement amountItem = savingsItem.firstChildElement("amountItem").toElement();
            QDomElement amount = amountItem.firstChild().toElement();
            QDomText amountText = amount.firstChild().toText();

            QString qsAmount = amountText.data();
            QChar * qcAmount = qsAmount.data();
            char cAmount[qsAmount.size() + 1];
            for (int i = 0; i < qsAmount.size() + 1; i++)
            {
                cAmount[i] = qcAmount->toAscii();
                ++qcAmount;
            }

            double amountDouble = atof(cAmount);
            long amountLong = strtold(cAmount, NULL);

            QDomElement descriptionItem = savingsItem.firstChildElement("descriptionItem").toElement();
            QDomElement description = descriptionItem.firstChild().toElement();
            QDomText descriptionText = description.firstChild().toText();

            QDomElement dateItem = savingsItem.firstChildElement("dateItem").toElement();
            QDomElement day = dateItem.firstChild().toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();

            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }

            int dayInt = atoi(cDay);

            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }

            int monthInt = atoi(cMonth);

            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }

            int yearInt = atoi(cYear);

            Date date(yearInt, monthInt, dayInt, 0, 0, 0);

            QString qsDescription = descriptionText.data();
            QChar * qcDescription = qsDescription.data();
            char cDescription[qsDescription.size() + 1];
            for (int i = 0; i < qsDescription.size() + 1; i++)
            {
                cDescription[i] = qcDescription->toAscii();
                ++qcDescription;
            }

            string descriptionString = string(cDescription);

            if (strtold(cAmount, NULL) > 999999)
            {
                addLSavings(nameString, amountLong, APRFloat,
                    actualSavingsNature, date, descriptionString, sList);
            }
            else
            {
                addSavings(nameString, amountDouble, APRFloat,
                    actualSavingsNature, date, descriptionString, sList);
            }

            savingsNode = savingsNode.nextSibling();
        }

        QDomElement inventory = fiscalRecord.firstChildElement("inventory").toElement();
        QDomNode inventoryNode = inventory.firstChild();
        while (!inventoryNode.isNull())
        {
            QDomElement inventoryItem = inventoryNode.toElement();

            QDomElement nameItem = inventoryItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();

            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }

            string nameString = string(cName);

            QDomElement IDCodeItem = inventoryItem.firstChildElement("IDCodeItem").toElement();
            QDomElement IDCode = IDCodeItem.firstChild().toElement();
            QDomText IDCodeText = IDCode.firstChild().toText();

            QString qsIDCode = IDCodeText.data();
            QChar * qcIDCode = qsIDCode.data();
            char cIDCode[qsIDCode.size() + 1];
            for (int i = 0; i < qsIDCode.size() + 1; i++)
            {
                cIDCode[i] = qcIDCode->toAscii();
                ++qcIDCode;
            }

            int IDCodeInt = atoi(cIDCode);

            QDomElement itemIDItem = inventoryItem.firstChildElement("itemIDItem").toElement();
            QDomElement itemID = itemIDItem.firstChild().toElement();
            QDomText itemIDText = itemID.firstChild().toText();

            QString qsItemID = itemIDText.data();
            QChar * qcItemID = qsItemID.data();
            char cItemID[qsItemID.size() + 1];
            for (int i = 0; i < qsItemID.size() + 1; i++)
            {
                cItemID[i] = qcItemID->toAscii();
                ++qcItemID;
            }

            string itemIDString = string(cItemID);

            QDomElement numberItem = inventoryItem.firstChildElement("numberItem").toElement();
            QDomElement number = numberItem.firstChild().toElement();
            QDomText numberText = number.firstChild().toText();

            QString qsNumber = numberText.data();
            QChar * qcNumber = qsNumber.data();
            char cNumber[qsNumber.size() + 1];
            for (int i = 0; i < qsNumber.size() + 1; i++)
            {
                cNumber[i] = qcNumber->toAscii();
                ++qcNumber;
            }

            int numberInt = atoi(cNumber);

            QDomElement priceItem = inventoryItem.firstChildElement("priceItem").toElement();
            QDomElement price = priceItem.firstChild().toElement();
            QDomText priceText = price.firstChild().toText();

            QString qsPrice = priceText.data();
            QChar * qcPrice = qsPrice.data();
            char cPrice[qsPrice.size() + 1];
            for (int i = 0; i < qsPrice.size() + 1; i++)
            {
                cPrice[i] = qcPrice->toAscii();
                ++qcPrice;
            }

            double priceDouble = atof(cPrice);


            addItem(nameString, priceDouble, numberInt,
                    itemIDString, itList);
            inventoryNode = inventoryNode.nextSibling();
        }

        QDomElement reminders = fiscalRecord.firstChildElement("reminders").toElement();
        QDomNode remindersNode = reminders.firstChild();
        while (!remindersNode.isNull())
        {
            QDomElement remindersItem = remindersNode.toElement();

            QDomElement dateItem = remindersItem.firstChildElement("dateItem").toElement();
            QDomElement second = dateItem.firstChildElement("second").toElement();
            QDomText secondText = second.firstChild().toText();
            QDomElement minute = dateItem.firstChildElement("minute").toElement();
            QDomText minuteText = minute.firstChild().toText();
            QDomElement hour = dateItem.firstChildElement("hour").toElement();
            QDomText hourText = hour.firstChild().toText();
            QDomElement day = dateItem.firstChildElement("day").toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();

            QString qsSecond = secondText.data();
            QChar * qcSecond = qsSecond.data();
            char cSecond[qsSecond.size() + 1];
            for (int i = 0; i < qsSecond.size() + 1; i++)
            {
                cSecond[i] = qcSecond->toAscii();
                ++qcSecond;
            }

            int secondInt = atoi(cSecond);

            QString qsMinute = minuteText.data();
            QChar * qcMinute = qsMinute.data();
            char cMinute[qsMinute.size() + 1];
            for (int i = 0; i < qsMinute.size() + 1; i++)
            {
                cMinute[i] = qcMinute->toAscii();
                ++qcMinute;
            }

            int minuteInt = atoi(cMinute);

            QString qsHour = hourText.data();
            QChar * qcHour = qsHour.data();
            char cHour[qsHour.size() + 1];
            for (int i = 0; i < qsHour.size() + 1; i++)
            {
                cHour[i] = qcHour->toAscii();
                ++qcHour;
            }

            int hourInt = atoi(cHour);

            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }

            int dayInt = atoi(cDay);

            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }

            int monthInt = atoi(cMonth);

            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }

            int yearInt = atoi(cYear);

            Date date(yearInt, monthInt, dayInt, hourInt, minuteInt, secondInt);

            bd->calendar->setReminderDate(QDate(yearInt, monthInt, dayInt));
            // hack to repaint the cake calendar widget's reminders, if there are any
            if (bd->isVisible())
            {
                bd->setVisible(false);
                bd->setVisible(true);
            }
            sd->calendar->setReminderDate(QDate(yearInt, monthInt, dayInt));
            // hack to repaint the cake calendar widget's reminders, if there are any
            if (sd->isVisible())
            {
                sd->setVisible(false);
                sd->setVisible(true);
            }
            id->calendar->setReminderDate(QDate(yearInt, monthInt, dayInt));
            // hack to repaint the cake calendar widget's reminders, if there are any
            if (id->isVisible())
            {
                id->setVisible(false);
                id->setVisible(true);
            }
            rd->calendar->setReminderDate(QDate(yearInt, monthInt, dayInt));
            // hack to repaint the cake calendar widget's reminders, if there are any
            if (rd->isVisible())
            {
                rd->setVisible(false);
                rd->setVisible(true);
            }

            QDomElement subjectItem = remindersItem.firstChildElement("subjectItem").toElement();
            QDomElement subject = subjectItem.firstChild().toElement();
            QDomText subjectText = subject.firstChild().toText();

            QString qsSubject = subjectText.data();
            QChar * qcSubject = qsSubject.data();
            char cSubject[qsSubject.size() + 1];
            for (int i = 0; i < qsSubject.size() + 1; i++)
            {
                cSubject[i] = qcSubject->toAscii();
                ++qcSubject;
            }

            string subjectString = string(cSubject);

            QDomElement messageItem = remindersItem.firstChildElement("messageItem").toElement();
            QDomElement message = messageItem.firstChild().toElement();
            QDomText messageText = message.firstChild().toText();

            QString qsMessage = messageText.data();
            QChar * qcMessage = qsMessage.data();
            char cMessage[qsMessage.size() + 1];
            for (int i = 0; i < qsMessage.size() + 1; i++)
            {
                cMessage[i] = qcMessage->toAscii();
                ++qcMessage;
            }

            string messageString = string(cMessage);

            addReminder(date, subjectString, messageString,
                    HIGH, rList);
            remindersNode = remindersNode.nextSibling();
        }


        for (int j = 0; j < btl.size(); j++)
        {
            shuffleIncomeTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
                msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), iList);
        }

        for (int j = 0; j < btl.size(); j++)
        {
            shuffleDebtTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
                msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), dList);
        }

        for (int j = 0; j < btl.size(); j++)
        {
            shuffleExpenseTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
                msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), eList);
        }

        populateIncomeTable(iList);
        populateDebtTable(dList);
        populateExpensesTable(eList);
        populateSavingsTable(sList);
        populateInventoryTable(itList);
        populateReminderTable(rList);

        /*TOTALS AND BALANCES*/
        monthlyIncome = 0;
        monthlyLIncome = 0;
        for (int i = 0; i < iList.size(); i++)
        {
            if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (iList.at(i).getAmountType() == "long")
                    containsLongIncome = true;
                monthlyIncome += iList.at(i).getNetAmount();
                monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
            }
        }
        //if (containsLongIncome)
            bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
        //else
        //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));

        monthlyDebt = 0;
        monthlyLDebt = 0;
        for (int i = 0; i < dList.size(); i++)
        {
            if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (dList.at(i).getAmountType() == "long")
                    containsLongDebt = true;
                monthlyDebt += dList.at(i).getNetAmount();
                monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
            }
        }
        //if (containsLongDebt)
            bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
        //else
        //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));

        monthlyExpenses = 0;
        monthlyLExpenses = 0;
        for (int i = 0; i < eList.size(); i++)
        {
            if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (eList.at(i).getAmountType() == "long")
                    containsLongExpense = true;
                monthlyExpenses += eList.at(i).getNetAmount();
                monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
            }
        }
        //if (containsLongExpense)
            bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
        //else
        //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

        setCurrentBalance();

        savingsBalance = 0;
        savingsLBalance = 0;
        for (int i = 0; i < sList.size(); i++)
        {
            if (sList.at(i).getAmountType() == "long")
                containsLongAssSaving = true;
            savingsBalance += sList.at(i).getAmount();
            savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
        }
        //if (containsLongAssSaving)
            sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
        //else
        //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));

        bd->setVisible(true);
        //setCurrentFile(fileName);
        clickBudget->setChecked(true);
        
        documentSaved = true;
    }
}

void MainBudget::openFromFileName(QString fileName)
{
    if (workSpaceActive)
        close();
    if (openCanceled)
    {
        openCanceled = false;
        return;
    }
    //fileName = QFileDialog::getOpenFileName(this, tr("Choose a budget file"),
    //                                        "", "*.chf");
    saveFileName = fileName;
    if (!fileName.isEmpty())
    {
        workSpaceActive = true;
        //documentModified = true;
        QFile file(fileName);
        
        QStringList pieces = fileName.split( "/" );
        fileNameWithoutFullPath = pieces.value(pieces.length() - 1);
        
        setWindowTitle("CakeHeap Budget Professional - " + fileNameWithoutFullPath);
        
        QDomDocument doc;
        doc.setContent(&file);
        QDomElement root = doc.documentElement();
        QDomElement fiscalRecord = root.firstChild().toElement();
        QDomElement income = fiscalRecord.firstChild().toElement();
        QDomNode incomeNode = income.firstChild();
        
        while (!incomeNode.isNull())
        {
            QDomElement incomeItem = incomeNode.toElement();
            
            QDomElement dateItem = incomeItem.firstChild().toElement();
            QDomElement day = dateItem.firstChild().toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();
            
            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }
            
            int dayInt = atoi(cDay);
            
            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }
            
            int monthInt = atoi(cMonth);
            
            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }
            
            int yearInt = atoi(cYear);
            
            Date date(yearInt, monthInt, dayInt, 0, 0, 0);
            QDate qdDate(yearInt, monthInt, dayInt);
            
            if (!tabTitleExists(qdDate))
            {
                mainBudgetTab.insertTab(0, new BudgetFrame, getTabBarDate(qdDate));
                mainBudgetTab.setCurrentIndex(0);
                selectedBudgetFrame->setMonth(monthInt);
                selectedBudgetFrame->setYear(yearInt);
                if (btl.size() > 0)
                    btl.clear();
                
                for (int i = 0; i < mainBudgetTab.count(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    btl.push_back(BudgetTabItem(convertQStringToString(mainBudgetTab.tabText(i)), selectedBudgetFrame->getMonth(),
                                                selectedBudgetFrame->getYear(), i));
                }
                
                msBudget = new MergeSortBudget(btl);
                msBudget->displayElements();
                msBudget->sort(btl);
                msBudget->displayElements();
                
                for (int i = 0; i < btl.size(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    mainBudgetTab.setTabText(i, convertStringToQString(msBudget->data.at(i).getTabTitle()));
                    selectedBudgetFrame->setMonth(msBudget->data.at(i).getMonth());
                    selectedBudgetFrame->setYear(msBudget->data.at(i).getYear());
                }
            }
            
            QDomElement nameItem = incomeItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();
            
            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }
            
            string nameString = string(cName);
            
            QDomElement natureItem = incomeItem.firstChildElement("natureItem").toElement();
            QDomElement nature = natureItem.firstChild().toElement();
            QDomText natureText = nature.firstChild().toText();
            
            QString qsNature = natureText.data();
            QChar * qcNature = qsNature.data();
            char cNature[qsNature.size() + 1];
            for (int i = 0; i < qsNature.size() + 1; i++)
            {
                cNature[i] = qcNature->toAscii();
                ++qcNature;
            }
            
            string natureString = string(cNature);
            Nature actualNature;
            if (natureString == "SALARY")
                actualNature = SALARY;
            if (natureString == "DIVIDEND")
                actualNature = DIVIDEND;
            if (natureString == "STOCK_SALE")
                actualNature = STOCK_SALE;
            if (natureString == "IOU")
                actualNature = IOU;
            if (natureString == "DIP")
                actualNature = DIP;
            if (natureString == "OTHER")
                actualNature = OTHER;
            
            QDomElement amountItem = incomeItem.firstChildElement("amountItem").toElement();
            QDomElement amount = amountItem.firstChild().toElement();
            QDomText amountText = amount.firstChild().toText();
            
            QString qsAmount = amountText.data();
            QChar * qcAmount = qsAmount.data();
            char cAmount[qsAmount.size() + 1];
            for (int i = 0; i < qsAmount.size() + 1; i++)
            {
                cAmount[i] = qcAmount->toAscii();
                ++qcAmount;
            }
            
            double amountDouble = atof(cAmount);
            long amountLong = strtold(cAmount, NULL);
            
            QDomElement taxItem = incomeItem.firstChildElement("taxItem").toElement();
            QDomElement tax = taxItem.firstChild().toElement();
            QDomText taxText = tax.firstChild().toText();
            
            QString qsTax = taxText.data();
            QChar * qcTax = qsTax.data();
            char cTax[qsTax.size() + 1];
            for (int i = 0; i < qsTax.size() + 1; i++)
            {
                cTax[i] = qcTax->toAscii();
                ++qcTax;
            }
            
            float taxFloat = atof(cTax);
            
            QDomElement additionalInfoItem = incomeItem.firstChildElement("additionalInfoItem").toElement();
            QDomElement additionalInfo = additionalInfoItem.firstChild().toElement();
            QDomText additionalInfoText = additionalInfo.firstChild().toText();
            
            QString qsAdditionalInfo = additionalInfoText.data();
            QChar * qcAdditionalInfo = qsAdditionalInfo.data();
            char cAdditionalInfo[qsAdditionalInfo.size() + 1];
            for (int i = 0; i < qsAdditionalInfo.size() + 1; i++)
            {
                cAdditionalInfo[i] = qcAdditionalInfo->toAscii();
                ++qcAdditionalInfo;
            }
            
            string additionalInfoString = string(cAdditionalInfo);
            
            QDomElement tabIndexItem = incomeItem.firstChildElement("tabIndexItem").toElement();
            QDomElement tabIndex = tabIndexItem.firstChild().toElement();
            QDomText tabIndexText = tabIndex.firstChild().toText();
            
            QString qsTabIndex = tabIndexText.data();
            QChar * qcTabIndex = qsTabIndex.data();
            char cTabIndex[qsTabIndex.size() + 1];
            for (int i = 0; i < qsTabIndex.size() + 1; i++)
            {
                cTabIndex[i] = qcTabIndex->toAscii();
                ++qcTabIndex;
            }
            
            int tabIndexInt = atoi(cTabIndex);
            
            if (strtold(cAmount, NULL) > 999999)
            {
                addLIncome(nameString, amountLong, false, 0, date,
                           actualNature, taxFloat, additionalInfoString, tabIndexInt, iList);
            }
            else
            {
                addIncome(nameString, amountDouble, false, 0, date,
                          actualNature, taxFloat, additionalInfoString, tabIndexInt, iList);
            }
            incomeNode = incomeNode.nextSibling();
        }
        
        QDomElement debt = fiscalRecord.firstChildElement("debt").toElement();
        QDomNode debtNode = debt.firstChild();
        while (!debtNode.isNull())
        {
            QDomElement debtItem = debtNode.toElement();
            
            QDomElement dateItem = debtItem.firstChild().toElement();
            QDomElement day = dateItem.firstChild().toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();
            
            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }
            
            int dayInt = atoi(cDay);
            
            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }
            
            int monthInt = atoi(cMonth);
            
            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }
            
            int yearInt = atoi(cYear);
            
            Date date(yearInt, monthInt, dayInt, 0, 0, 0);
            QDate qdDate(yearInt, monthInt, dayInt);
            
            if (!tabTitleExists(qdDate))
            {
                mainBudgetTab.insertTab(0, new BudgetFrame, getTabBarDate(qdDate));
                mainBudgetTab.setCurrentIndex(0);
                selectedBudgetFrame->setMonth(monthInt);
                selectedBudgetFrame->setYear(yearInt);
                if (btl.size() > 0)
                    btl.clear();
                
                for (int i = 0; i < mainBudgetTab.count(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    btl.push_back(BudgetTabItem(convertQStringToString(mainBudgetTab.tabText(i)), selectedBudgetFrame->getMonth(),
                                                selectedBudgetFrame->getYear(), i));
                }
                
                msBudget = new MergeSortBudget(btl);
                msBudget->displayElements();
                msBudget->sort(btl);
                msBudget->displayElements();
                
                for (int i = 0; i < btl.size(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    mainBudgetTab.setTabText(i, convertStringToQString(msBudget->data.at(i).getTabTitle()));
                    selectedBudgetFrame->setMonth(msBudget->data.at(i).getMonth());
                    selectedBudgetFrame->setYear(msBudget->data.at(i).getYear());
                }
            }
            
            QDomElement nameItem = debtItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();
            
            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }
            
            string nameString = string(cName);
            
            QDomElement priorityLevelItem = debtItem.firstChildElement("priorityLevelItem").toElement();
            QDomElement priorityLevel = priorityLevelItem.firstChild().toElement();
            QDomText priorityLevelText = priorityLevel.firstChild().toText();
            
            QString qsPriorityLevel = priorityLevelText.data();
            QChar * qcPriorityLevel = qsPriorityLevel.data();
            char cPriorityLevel[qsPriorityLevel.size() + 1];
            for (int i = 0; i < qsPriorityLevel.size() + 1; i++)
            {
                cPriorityLevel[i] = qcPriorityLevel->toAscii();
                ++qcPriorityLevel;
            }
            
            string priorityLevelString = string(cPriorityLevel);
            PriorityLevel actualPriorityLevel;
            if (priorityLevelString == "HIGH")
                actualPriorityLevel= HIGH;
            if (priorityLevelString == "MEDIUM")
                actualPriorityLevel = MEDIUM;
            if (priorityLevelString == "LOW")
                actualPriorityLevel = LOW;
            if (priorityLevelString == "NONE")
                actualPriorityLevel = NONE;
            
            QDomElement amountItem = debtItem.firstChildElement("amountItem").toElement();
            QDomElement amount = amountItem.firstChild().toElement();
            QDomText amountText = amount.firstChild().toText();
            
            QString qsAmount = amountText.data();
            QChar * qcAmount = qsAmount.data();
            char cAmount[qsAmount.size() + 1];
            for (int i = 0; i < qsAmount.size() + 1; i++)
            {
                cAmount[i] = qcAmount->toAscii();
                ++qcAmount;
            }
            
            double amountDouble = atof(cAmount);
            long amountLong = strtold(cAmount, NULL);
            
            QDomElement APRItem = debtItem.firstChildElement("APRItem").toElement();
            QDomElement APR = APRItem.firstChild().toElement();
            QDomText APRText = APR.firstChild().toText();
            
            QString qsAPR = APRText.data();
            QChar * qcAPR = qsAPR.data();
            char cAPR[qsAPR.size() + 1];
            for (int i = 0; i < qsAPR.size() + 1; i++)
            {
                cAPR[i] = qcAPR->toAscii();
                ++qcAPR;
            }
            
            float APRFloat = atof(cAPR);
            
            QDomElement additionalInfoItem = debtItem.firstChildElement("additionalInfoItem").toElement();
            QDomElement additionalInfo = additionalInfoItem.firstChild().toElement();
            QDomText additionalInfoText = additionalInfo.firstChild().toText();
            
            QString qsAdditionalInfo = additionalInfoText.data();
            QChar * qcAdditionalInfo = qsAdditionalInfo.data();
            char cAdditionalInfo[qsAdditionalInfo.size() + 1];
            for (int i = 0; i < qsAdditionalInfo.size() + 1; i++)
            {
                cAdditionalInfo[i] = qcAdditionalInfo->toAscii();
                ++qcAdditionalInfo;
            }
            
            string additionalInfoString = string(cAdditionalInfo);
            
            QDomElement numberOfMonthsItem = debtItem.firstChildElement("numberOfMonthsItem").toElement();
            QDomElement numberOfMonths = numberOfMonthsItem.firstChild().toElement();
            QDomText numberOfMonthsText = numberOfMonths.firstChild().toText();
            
            QString qsNumberOfMonths = numberOfMonthsText.data();
            QChar * qcNumberOfMonths = qsNumberOfMonths.data();
            char cNumberOfMonths[qsNumberOfMonths.size() + 1];
            for (int i = 0; i < qsNumberOfMonths.size() + 1; i++)
            {
                cNumberOfMonths[i] = qcNumberOfMonths->toAscii();
                ++qcNumberOfMonths;
            }
            
            int numberOfMonthsInt = atoi(cNumberOfMonths);
            
            QDomElement tabIndexItem = debtItem.firstChildElement("tabIndexItem").toElement();
            QDomElement tabIndex = tabIndexItem.firstChild().toElement();
            QDomText tabIndexText = tabIndex.firstChild().toText();
            
            QString qsTabIndex = tabIndexText.data();
            QChar * qcTabIndex = qsTabIndex.data();
            char cTabIndex[qsTabIndex.size() + 1];
            for (int i = 0; i < qsTabIndex.size() + 1; i++)
            {
                cTabIndex[i] = qcTabIndex->toAscii();
                ++qcTabIndex;
            }
            
            int tabIndexInt = atoi(cTabIndex);
            
            if (strtold(cAmount, NULL) > 999999)
            {
                addLDebt(nameString, amountLong, true, APRFloat, actualPriorityLevel,
                         date, additionalInfoString, numberOfMonthsInt, tabIndexInt, dList);
            }
            else
            {
                addDebt(nameString, amountDouble, true, APRFloat, actualPriorityLevel,
                        date, additionalInfoString, numberOfMonthsInt, tabIndexInt, dList);
            }
            
            debtNode = debtNode.nextSibling();
        }
        
        QDomElement expense = fiscalRecord.firstChildElement("expense").toElement();
        QDomNode expenseNode = expense.firstChild();
        while (!expenseNode.isNull())
        {
            QDomElement expenseItem = expenseNode.toElement();
            
            QDomElement dateItem = expenseItem.firstChild().toElement();
            QDomElement day = dateItem.firstChild().toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();
            
            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }
            
            int dayInt = atoi(cDay);
            
            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }
            
            int monthInt = atoi(cMonth);
            
            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }
            
            int yearInt = atoi(cYear);
            
            Date date(yearInt, monthInt, dayInt, 0, 0, 0);
            QDate qdDate(yearInt, monthInt, dayInt);
            
            if (!tabTitleExists(qdDate))
            {
                mainBudgetTab.insertTab(0, new BudgetFrame, getTabBarDate(qdDate));
                mainBudgetTab.setCurrentIndex(0);
                selectedBudgetFrame->setMonth(monthInt);
                selectedBudgetFrame->setYear(yearInt);
                if (btl.size() > 0)
                    btl.clear();
                
                for (int i = 0; i < mainBudgetTab.count(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    btl.push_back(BudgetTabItem(convertQStringToString(mainBudgetTab.tabText(i)), selectedBudgetFrame->getMonth(),
                                                selectedBudgetFrame->getYear(), i));
                }
                
                msBudget = new MergeSortBudget(btl);
                msBudget->displayElements();
                msBudget->sort(btl);
                msBudget->displayElements();
                
                for (int i = 0; i < btl.size(); i++)
                {
                    mainBudgetTab.setCurrentIndex(i);
                    mainBudgetTab.setTabText(i, convertStringToQString(msBudget->data.at(i).getTabTitle()));
                    selectedBudgetFrame->setMonth(msBudget->data.at(i).getMonth());
                    selectedBudgetFrame->setYear(msBudget->data.at(i).getYear());
                }
            }
            
            QDomElement nameItem = expenseItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();
            
            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }
            
            string nameString = string(cName);
            
            QDomElement priorityLevelItem = expenseItem.firstChildElement("priorityLevelItem").toElement();
            QDomElement priorityLevel = priorityLevelItem.firstChild().toElement();
            QDomText priorityLevelText = priorityLevel.firstChild().toText();
            
            QString qsPriorityLevel = priorityLevelText.data();
            QChar * qcPriorityLevel = qsPriorityLevel.data();
            char cPriorityLevel[qsPriorityLevel.size() + 1];
            for (int i = 0; i < qsPriorityLevel.size() + 1; i++)
            {
                cPriorityLevel[i] = qcPriorityLevel->toAscii();
                ++qcPriorityLevel;
            }
            
            string priorityLevelString = string(cPriorityLevel);
            PriorityLevel actualPriorityLevel;
            if (priorityLevelString == "HIGH")
                actualPriorityLevel= HIGH;
            if (priorityLevelString == "MEDIUM")
                actualPriorityLevel = MEDIUM;
            if (priorityLevelString == "LOW")
                actualPriorityLevel = LOW;
            if (priorityLevelString == "NONE")
                actualPriorityLevel = NONE;
            
            QDomElement amountItem = expenseItem.firstChildElement("amountItem").toElement();
            QDomElement amount = amountItem.firstChild().toElement();
            QDomText amountText = amount.firstChild().toText();
            
            QString qsAmount = amountText.data();
            QChar * qcAmount = qsAmount.data();
            char cAmount[qsAmount.size() + 1];
            for (int i = 0; i < qsAmount.size() + 1; i++)
            {
                cAmount[i] = qcAmount->toAscii();
                ++qcAmount;
            }
            
            double amountDouble = atof(cAmount);
            long amountLong = strtold(cAmount, NULL);
            
            QDomElement penaltyItem = expenseItem.firstChildElement("penaltyItem").toElement();
            QDomElement penalty = penaltyItem.firstChild().toElement();
            QDomText penaltyText = penalty.firstChild().toText();
            
            QString qsPenalty = penaltyText.data();
            QChar * qcPenalty = qsPenalty.data();
            char cPenalty[qsPenalty.size() + 1];
            for (int i = 0; i < qsPenalty.size() + 1; i++)
            {
                cPenalty[i] = qcPenalty->toAscii();
                ++qcPenalty;
            }
            
            double penaltyDouble = atof(cPenalty);
            
            QDomElement additionalInfoItem = expenseItem.firstChildElement("additionalInfoItem").toElement();
            QDomElement additionalInfo = additionalInfoItem.firstChild().toElement();
            QDomText additionalInfoText = additionalInfo.firstChild().toText();
            
            QString qsAdditionalInfo = additionalInfoText.data();
            QChar * qcAdditionalInfo = qsAdditionalInfo.data();
            char cAdditionalInfo[qsAdditionalInfo.size() + 1];
            for (int i = 0; i < qsAdditionalInfo.size() + 1; i++)
            {
                cAdditionalInfo[i] = qcAdditionalInfo->toAscii();
                ++qcAdditionalInfo;
            }
            
            string additionalInfoString = string(cAdditionalInfo);
            
            QDomElement tabIndexItem = expenseItem.firstChildElement("tabIndexItem").toElement();
            QDomElement tabIndex = tabIndexItem.firstChild().toElement();
            QDomText tabIndexText = tabIndex.firstChild().toText();
            
            QString qsTabIndex = tabIndexText.data();
            QChar * qcTabIndex = qsTabIndex.data();
            char cTabIndex[qsTabIndex.size() + 1];
            for (int i = 0; i < qsTabIndex.size() + 1; i++)
            {
                cTabIndex[i] = qcTabIndex->toAscii();
                ++qcTabIndex;
            }
            
            int tabIndexInt = atoi(cTabIndex);
            
            if (strtold(cAmount, NULL) > 999999)
            {
                addLExpense(nameString, amountLong, actualPriorityLevel,
                            penaltyDouble, date, additionalInfoString, tabIndexInt, eList);
            }
            else
            {
                addExpense(nameString, amountDouble, actualPriorityLevel,
                           penaltyDouble, date, additionalInfoString, tabIndexInt, eList);
            }
            expenseNode = expenseNode.nextSibling();
        }
        
        QDomElement savings = fiscalRecord.firstChildElement("savings").toElement();
        QDomNode savingsNode = savings.firstChild();
        while (!savingsNode.isNull())
        {
            QDomElement savingsItem = savingsNode.toElement();
            
            QDomElement nameItem = savingsItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();
            
            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }
            
            string nameString = string(cName);
            
            QDomElement savingsNatureItem = savingsItem.firstChildElement("natureItem").toElement();
            QDomElement savingsNature = savingsNatureItem.firstChild().toElement();
            QDomText savingsNatureText = savingsNature.firstChild().toText();
            
            QString qsSavingsNature = savingsNatureText.data();
            QChar * qcSavingsNature = qsSavingsNature.data();
            char cSavingsNature[qsSavingsNature.size() + 1];
            for (int i = 0; i < qsSavingsNature.size() + 1; i++)
            {
                cSavingsNature[i] = qcSavingsNature->toAscii();
                ++qcSavingsNature;
            }
            
            string savingsNatureString = string(cSavingsNature);
            SavingsNature actualSavingsNature;
            if (savingsNatureString == "STOCK")
                actualSavingsNature = STOCK;
            if (savingsNatureString == "BANK")
                actualSavingsNature = BANK;
            
            QDomElement APRItem = savingsItem.firstChildElement("APRItem").toElement();
            QDomElement APR = APRItem.firstChild().toElement();
            QDomText APRText = APR.firstChild().toText();
            
            QString qsAPR = APRText.data();
            QChar * qcAPR = qsAPR.data();
            char cAPR[qsAPR.size() + 1];
            for (int i = 0; i < qsAPR.size() + 1; i++)
            {
                cAPR[i] = qcAPR->toAscii();
                ++qcAPR;
            }
            
            float APRFloat = atof(cAPR);
            
            QDomElement amountItem = savingsItem.firstChildElement("amountItem").toElement();
            QDomElement amount = amountItem.firstChild().toElement();
            QDomText amountText = amount.firstChild().toText();
            
            QString qsAmount = amountText.data();
            QChar * qcAmount = qsAmount.data();
            char cAmount[qsAmount.size() + 1];
            for (int i = 0; i < qsAmount.size() + 1; i++)
            {
                cAmount[i] = qcAmount->toAscii();
                ++qcAmount;
            }
            
            double amountDouble = atof(cAmount);
            long amountLong = strtold(cAmount, NULL);
            
            QDomElement descriptionItem = savingsItem.firstChildElement("descriptionItem").toElement();
            QDomElement description = descriptionItem.firstChild().toElement();
            QDomText descriptionText = description.firstChild().toText();
            
            QDomElement dateItem = savingsItem.firstChildElement("dateItem").toElement();
            QDomElement day = dateItem.firstChild().toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();
            
            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }
            
            int dayInt = atoi(cDay);
            
            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }
            
            int monthInt = atoi(cMonth);
            
            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }
            
            int yearInt = atoi(cYear);
            
            Date date(yearInt, monthInt, dayInt, 0, 0, 0);
            
            QString qsDescription = descriptionText.data();
            QChar * qcDescription = qsDescription.data();
            char cDescription[qsDescription.size() + 1];
            for (int i = 0; i < qsDescription.size() + 1; i++)
            {
                cDescription[i] = qcDescription->toAscii();
                ++qcDescription;
            }
            
            string descriptionString = string(cDescription);
            
            if (strtold(cAmount, NULL) > 999999)
            {
                addLSavings(nameString, amountLong, APRFloat,
                            actualSavingsNature, date, descriptionString, sList);
            }
            else
            {
                addSavings(nameString, amountDouble, APRFloat,
                           actualSavingsNature, date, descriptionString, sList);
            }
            
            savingsNode = savingsNode.nextSibling();
        }
        
        QDomElement inventory = fiscalRecord.firstChildElement("inventory").toElement();
        QDomNode inventoryNode = inventory.firstChild();
        while (!inventoryNode.isNull())
        {
            QDomElement inventoryItem = inventoryNode.toElement();
            
            QDomElement nameItem = inventoryItem.firstChildElement("nameItem").toElement();
            QDomElement name = nameItem.firstChild().toElement();
            QDomText nameText = name.firstChild().toText();
            
            QString qsName = nameText.data();
            QChar * qcName = qsName.data();
            char cName[qsName.size() + 1];
            for (int i = 0; i < qsName.size() + 1; i++)
            {
                cName[i] = qcName->toAscii();
                ++qcName;
            }
            
            string nameString = string(cName);
            
            QDomElement IDCodeItem = inventoryItem.firstChildElement("IDCodeItem").toElement();
            QDomElement IDCode = IDCodeItem.firstChild().toElement();
            QDomText IDCodeText = IDCode.firstChild().toText();
            
            QString qsIDCode = IDCodeText.data();
            QChar * qcIDCode = qsIDCode.data();
            char cIDCode[qsIDCode.size() + 1];
            for (int i = 0; i < qsIDCode.size() + 1; i++)
            {
                cIDCode[i] = qcIDCode->toAscii();
                ++qcIDCode;
            }
            
            int IDCodeInt = atoi(cIDCode);
            
            QDomElement itemIDItem = inventoryItem.firstChildElement("itemIDItem").toElement();
            QDomElement itemID = itemIDItem.firstChild().toElement();
            QDomText itemIDText = itemID.firstChild().toText();
            
            QString qsItemID = itemIDText.data();
            QChar * qcItemID = qsItemID.data();
            char cItemID[qsItemID.size() + 1];
            for (int i = 0; i < qsItemID.size() + 1; i++)
            {
                cItemID[i] = qcItemID->toAscii();
                ++qcItemID;
            }
            
            string itemIDString = string(cItemID);
            
            QDomElement numberItem = inventoryItem.firstChildElement("numberItem").toElement();
            QDomElement number = numberItem.firstChild().toElement();
            QDomText numberText = number.firstChild().toText();
            
            QString qsNumber = numberText.data();
            QChar * qcNumber = qsNumber.data();
            char cNumber[qsNumber.size() + 1];
            for (int i = 0; i < qsNumber.size() + 1; i++)
            {
                cNumber[i] = qcNumber->toAscii();
                ++qcNumber;
            }
            
            int numberInt = atoi(cNumber);
            
            QDomElement priceItem = inventoryItem.firstChildElement("priceItem").toElement();
            QDomElement price = priceItem.firstChild().toElement();
            QDomText priceText = price.firstChild().toText();
            
            QString qsPrice = priceText.data();
            QChar * qcPrice = qsPrice.data();
            char cPrice[qsPrice.size() + 1];
            for (int i = 0; i < qsPrice.size() + 1; i++)
            {
                cPrice[i] = qcPrice->toAscii();
                ++qcPrice;
            }
            
            double priceDouble = atof(cPrice);
            
            
            addItem(nameString, priceDouble, numberInt,
                    itemIDString, itList);
            inventoryNode = inventoryNode.nextSibling();
        }
        
        QDomElement reminders = fiscalRecord.firstChildElement("reminders").toElement();
        QDomNode remindersNode = reminders.firstChild();
        while (!remindersNode.isNull())
        {
            QDomElement remindersItem = remindersNode.toElement();
            
            QDomElement dateItem = remindersItem.firstChildElement("dateItem").toElement();
            QDomElement second = dateItem.firstChildElement("second").toElement();
            QDomText secondText = second.firstChild().toText();
            QDomElement minute = dateItem.firstChildElement("minute").toElement();
            QDomText minuteText = minute.firstChild().toText();
            QDomElement hour = dateItem.firstChildElement("hour").toElement();
            QDomText hourText = hour.firstChild().toText();
            QDomElement day = dateItem.firstChildElement("day").toElement();
            QDomText dayText = day.firstChild().toText();
            QDomElement month = dateItem.firstChildElement("month").toElement();
            QDomText monthText = month.firstChild().toText();
            QDomElement year = dateItem.firstChildElement("year").toElement();
            QDomText yearText = year.firstChild().toText();
            
            QString qsSecond = secondText.data();
            QChar * qcSecond = qsSecond.data();
            char cSecond[qsSecond.size() + 1];
            for (int i = 0; i < qsSecond.size() + 1; i++)
            {
                cSecond[i] = qcSecond->toAscii();
                ++qcSecond;
            }
            
            int secondInt = atoi(cSecond);
            
            QString qsMinute = minuteText.data();
            QChar * qcMinute = qsMinute.data();
            char cMinute[qsMinute.size() + 1];
            for (int i = 0; i < qsMinute.size() + 1; i++)
            {
                cMinute[i] = qcMinute->toAscii();
                ++qcMinute;
            }
            
            int minuteInt = atoi(cMinute);
            
            QString qsHour = hourText.data();
            QChar * qcHour = qsHour.data();
            char cHour[qsHour.size() + 1];
            for (int i = 0; i < qsHour.size() + 1; i++)
            {
                cHour[i] = qcHour->toAscii();
                ++qcHour;
            }
            
            int hourInt = atoi(cHour);
            
            QString qsDay = dayText.data();
            QChar * qcDay = qsDay.data();
            char cDay[qsDay.size() + 1];
            for (int i = 0; i < qsDay.size() + 1; i++)
            {
                cDay[i] = qcDay->toAscii();
                ++qcDay;
            }
            
            int dayInt = atoi(cDay);
            
            QString qsMonth = monthText.data();
            QChar * qcMonth = qsMonth.data();
            char cMonth[qsMonth.size() + 1];
            for (int i = 0; i < qsMonth.size() + 1; i++)
            {
                cMonth[i] = qcMonth->toAscii();
                ++qcMonth;
            }
            
            int monthInt = atoi(cMonth);
            
            QString qsYear = yearText.data();
            QChar * qcYear = qsYear.data();
            char cYear[qsYear.size() + 1];
            for (int i = 0; i < qsYear.size() + 1; i++)
            {
                cYear[i] = qcYear->toAscii();
                ++qcYear;
            }
            
            int yearInt = atoi(cYear);
            
            Date date(yearInt, monthInt, dayInt, hourInt, minuteInt, secondInt);
            
            bd->calendar->setReminderDate(QDate(yearInt, monthInt, dayInt));
            // hack to repaint the cake calendar widget's reminders, if there are any
            if (bd->isVisible())
            {
                bd->setVisible(false);
                bd->setVisible(true);
            }
            sd->calendar->setReminderDate(QDate(yearInt, monthInt, dayInt));
            // hack to repaint the cake calendar widget's reminders, if there are any
            if (sd->isVisible())
            {
                sd->setVisible(false);
                sd->setVisible(true);
            }
            id->calendar->setReminderDate(QDate(yearInt, monthInt, dayInt));
            // hack to repaint the cake calendar widget's reminders, if there are any
            if (id->isVisible())
            {
                id->setVisible(false);
                id->setVisible(true);
            }
            rd->calendar->setReminderDate(QDate(yearInt, monthInt, dayInt));
            // hack to repaint the cake calendar widget's reminders, if there are any
            if (rd->isVisible())
            {
                rd->setVisible(false);
                rd->setVisible(true);
            }
            
            QDomElement subjectItem = remindersItem.firstChildElement("subjectItem").toElement();
            QDomElement subject = subjectItem.firstChild().toElement();
            QDomText subjectText = subject.firstChild().toText();
            
            QString qsSubject = subjectText.data();
            QChar * qcSubject = qsSubject.data();
            char cSubject[qsSubject.size() + 1];
            for (int i = 0; i < qsSubject.size() + 1; i++)
            {
                cSubject[i] = qcSubject->toAscii();
                ++qcSubject;
            }
            
            string subjectString = string(cSubject);
            
            QDomElement messageItem = remindersItem.firstChildElement("messageItem").toElement();
            QDomElement message = messageItem.firstChild().toElement();
            QDomText messageText = message.firstChild().toText();
            
            QString qsMessage = messageText.data();
            QChar * qcMessage = qsMessage.data();
            char cMessage[qsMessage.size() + 1];
            for (int i = 0; i < qsMessage.size() + 1; i++)
            {
                cMessage[i] = qcMessage->toAscii();
                ++qcMessage;
            }
            
            string messageString = string(cMessage);
            
            addReminder(date, subjectString, messageString,
                        HIGH, rList);
            remindersNode = remindersNode.nextSibling();
        }
        
        
        for (int j = 0; j < btl.size(); j++)
        {
            shuffleIncomeTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
                              msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), iList);
        }
        
        for (int j = 0; j < btl.size(); j++)
        {
            shuffleDebtTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
                            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), dList);
        }
        
        for (int j = 0; j < btl.size(); j++)
        {
            shuffleExpenseTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
                               msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), eList);
        }
        
        populateIncomeTable(iList);
        populateDebtTable(dList);
        populateExpensesTable(eList);
        populateSavingsTable(sList);
        populateInventoryTable(itList);
        populateReminderTable(rList);
        
        /*TOTALS AND BALANCES*/
        monthlyIncome = 0;
        monthlyLIncome = 0;
        for (int i = 0; i < iList.size(); i++)
        {
            if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (iList.at(i).getAmountType() == "long")
                    containsLongIncome = true;
                monthlyIncome += iList.at(i).getNetAmount();
                monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
            }
        }
        //if (containsLongIncome)
            bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
        //else
        //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));
        
        monthlyDebt = 0;
        monthlyLDebt = 0;
        for (int i = 0; i < dList.size(); i++)
        {
            if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (dList.at(i).getAmountType() == "long")
                    containsLongDebt = true;
                monthlyDebt += dList.at(i).getNetAmount();
                monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
            }
        }
        //if (containsLongDebt)
            bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
        //else
        //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));
        
        monthlyExpenses = 0;
        monthlyLExpenses = 0;
        for (int i = 0; i < eList.size(); i++)
        {
            if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
            {
                if (eList.at(i).getAmountType() == "long")
                    containsLongExpense = true;
                monthlyExpenses += eList.at(i).getNetAmount();
                monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
            }
        }
        //if (containsLongExpense)
            bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
        //else
        //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));
        
        setCurrentBalance();
        
        savingsBalance = 0;
        savingsLBalance = 0;
        for (int i = 0; i < sList.size(); i++)
        {
            if (sList.at(i).getAmountType() == "long")
                containsLongAssSaving = true;
            savingsBalance += sList.at(i).getAmount();
            savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
        }
        //if (containsLongAssSaving)
            sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
        //else
        //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));
        
        bd->setVisible(true);
        //setCurrentFile(fileName);
        clickBudget->setChecked(true);
    }
}

void MainBudget::newFiscalRecord()
{
    if (workSpaceActive)
        close();
    workSpaceActive = true;
    documentModified = true;
    bd->setVisible(true);
    setWindowTitle("CakeHeap Budget Professional - untitled.chf");
    
    clickBudget->setChecked(true);
    clickSavings->setChecked(false);
    clickInventory->setChecked(false);
    clickReminders->setChecked(false);
}

void MainBudget::close()
{
    if (documentModified) {
        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Save file");
        msgBox->setWindowIcon(QIcon("images/cake_heap_icon.png"));
        //msgBox.setModal(true);
        //msgBox->setWindowFlags(Qt::Sheet);
        msgBox->setWindowModality(Qt::WindowModal);
        if (fileNameWithoutFullPath == "")
            msgBox->setText("File untitled.chf has been modified...");
        else
            msgBox->setText("File " + fileNameWithoutFullPath + " has been modified...");
        msgBox->setInformativeText("Do you want to save the changes?");
        msgBox->setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox->setDefaultButton(QMessageBox::Save);
        int ret = msgBox->exec();
        //cout << ret;
        if (ret == QMessageBox::Cancel)
        {
            openCanceled = true;
            return;
        }
        if (ret == QMessageBox::Save)
            save();
    }
    
    iList.clear();
    dList.clear();
    eList.clear();
    sList.clear();
    itList.clear();
    rList.clear();
    btl.clear();
    workSpaceActive = false;
    documentModified = false;
    documentSaved = false;
    saveFileName.clear();
    bd->setVisible(false);
    sd->setVisible(false);
    id->setVisible(false);
    rd->setVisible(false);
    setWindowTitle("CakeHeap Budget Professional");
    populateIncomeTable(iList);
    populateDebtTable(dList);
    populateExpensesTable(eList);
    populateSavingsTable(sList);
    populateInventoryTable(itList);
    populateReminderTable(rList);

    int originalTabCount = mainBudgetTab.count();
    for (int i = 0; i < originalTabCount - 1; i++)
    {
            mainBudgetTab.removeTab(0);
    }
    int month = QDate::currentDate().month();
    int year = QDate::currentDate().year();
    int day = QDate::currentDate().day();

    mainBudgetTab.setCurrentIndex(0);
    selectedBudgetFrame->setYear(year);
    selectedBudgetFrame->setMonth(month);
    mainBudgetTab.setTabText(0, getTabBarDate(QDate(year, month, day)));

    bd->calendar->reminderDate.clear();
    sd->calendar->reminderDate.clear();
    id->calendar->reminderDate.clear();
    rd->calendar->reminderDate.clear();

    fileName.clear();

    savingsBalance = 0;
    savingsLBalance = 0;

    currentBalance = 0;
    currentLBalance = 0;

    monthlyIncome = 0;
    monthlyLIncome = 0;

    monthlyDebt = 0;
    monthlyLDebt = 0;

    monthlyExpenses = 0;
    monthlyLExpenses = 0;

    bd->currentBalanceLineEdit->setText(getCharAmountForCurrentBalance(currentBalance));
    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForDebt(monthlyDebt));
    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForExpenses(monthlyExpenses));
    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForIncome(monthlyIncome));
    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));

    sd->textBrowser->setPlainText("");
    rd->textBrowser->setPlainText("");
    
    fileNameWithoutFullPath = "";
    
    clickBudget->setChecked(false);
    clickSavings->setChecked(false);
    clickInventory->setChecked(false);
    clickReminders->setChecked(false);
}

void MainBudget::incomeStatementFilePrintPreview()
{
    if (workSpaceActive)
    {
        QPrinter printer(QPrinter::HighResolution);
        QPrintPreviewDialog preview(&printer, this);
        connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(incomeStatementPrintPreview(QPrinter *)));
        preview.exec();
    }
}

void MainBudget::incomeStatementPrintPreview(QPrinter *printer)
{
    getIncomeStatement();
    isDialog->textBrowser->print(printer);
}

void MainBudget::incomeStatementFilePrint()
{
    if (workSpaceActive)
    {
        QPrinter printer(QPrinter::HighResolution);
        QPrintDialog *dlg = new QPrintDialog(&printer, this);
        getIncomeStatement();
        if (isDialog->textBrowser->textCursor().hasSelection())
            dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
        dlg->setWindowTitle(tr("Print Document"));
        if (dlg->exec() == QDialog::Accepted) {
            isDialog->textBrowser->print(&printer);
        }
        delete dlg;
    }
}

void MainBudget::balanceSheetFilePrintPreview()
{
    if (workSpaceActive)
    {
        QPrinter printer(QPrinter::HighResolution);
        QPrintPreviewDialog preview(&printer, this);
        connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(balanceSheetPrintPreview(QPrinter *)));
        preview.exec();
    }
}

void MainBudget::balanceSheetPrintPreview(QPrinter *printer)
{
    getBalanceSheet();
    isDialog->textBrowser->print(printer);
}

void MainBudget::balanceSheetFilePrint()
{
    if (workSpaceActive)
    {
        QPrinter printer(QPrinter::HighResolution);
        QPrintDialog *dlg = new QPrintDialog(&printer, this);
        getBalanceSheet();
        if (isDialog->textBrowser->textCursor().hasSelection())
            dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
        dlg->setWindowTitle(tr("Print Document"));
        if (dlg->exec() == QDialog::Accepted) {
            isDialog->textBrowser->print(&printer);
        }
        delete dlg;
    }
}

void MainBudget::quit()
{
    if (workSpaceActive)
    {
        if (documentModified) {
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Save file");
            msgBox->setWindowIcon(QIcon("images/cake_heap_icon.png"));
            //msgBox.setWindowFlags(Qt::Sheet);
            msgBox->setWindowModality(Qt::WindowModal);
            if (fileNameWithoutFullPath == "")
                msgBox->setText("File untitled.chf has been modified...");
            else
                msgBox->setText("File " + fileNameWithoutFullPath + " has been modified...");
            msgBox->setInformativeText("Do you want to save the changes?");
            msgBox->setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox->setDefaultButton(QMessageBox::Yes);
            int ret = msgBox->exec();
            
            if (ret == QMessageBox::Cancel)
            {
                openCanceled = true;
                return;
            }
            if (ret == QMessageBox::Save)
                save();
        }
    }
    
    const QString DEFAULT_X_KEY("default_x");
    const QString DEFAULT_Y_KEY("default_y");
    const QString DEFAULT_WIDTH_KEY("default_width");
    const QString DEFAULT_HEIGHT_KEY("default_height");
    
    QSettings *mySettings = new QSettings(("Thabo David Klass", "CakeHeap Budget Professional"));
    
    mySettings->setValue(DEFAULT_X_KEY,
                        this->x());
    mySettings->setValue(DEFAULT_Y_KEY,
                         this->y());
    mySettings->setValue(DEFAULT_WIDTH_KEY,
                         this->width());
    mySettings->setValue(DEFAULT_HEIGHT_KEY,
                         this->height());
    
    qApp->exit(0);
}

void MainBudget::closeEvent(QCloseEvent *e)
{
    if (workSpaceActive)
    {
        if (documentModified) {
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Save file");
            msgBox->setWindowIcon(QIcon("images/cake_heap_icon.png"));
            //msgBox.setWindowFlags(Qt::Sheet);
            msgBox->setWindowModality(Qt::WindowModal);
            if (fileNameWithoutFullPath == "")
                msgBox->setText("File untitled.chf has been modified...");
            else
                msgBox->setText("File " + fileNameWithoutFullPath + " has been modified...");
            msgBox->setInformativeText("Do you want to save the changes?");
            msgBox->setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox->setDefaultButton(QMessageBox::Yes);
            int ret = msgBox->exec();
            
            if (ret == QMessageBox::Cancel)
            {
                openCanceled = true;
                e->ignore();
                return;
            }
            if (ret == QMessageBox::Save)
                save();
        }
    }
}

char * MainBudget::convertStringToChar(string s)
{
    strcpy(convertedChar, s.c_str());
    return convertedChar;
}

void MainBudget::popCakeMessageBox()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Reminder");
    msgBox.setWindowIcon(QIcon("images/cake_heap_icon.png"));
    msgBox.setText(convertStringToChar(CheckReminders::subject));
    msgBox.setInformativeText(convertStringToChar(CheckReminders::message));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainBudget::popAboutMessageBox()
{
    aDialog = new AboutDialog(this);
    aDialog->setStyleSheet("QDialog { background-color: #ffffff; border: 0px solid #fffff8; }");
    //aDialog->setModal(true);
    //aDialog->setVisible(true);
    aDialog->show();
    connect(aDialog->okButton, SIGNAL(clicked()), this, SLOT(closeAboutDialog()));
}

void MainBudget::closeAboutDialog()
{
    //aDialog->setModal(false);
    aDialog->done(0);
}

void MainBudget::popDonateMessageBox()
{
    donDialog = new DonateDialog(this);
    donDialog->setModal(true);
    //donDialog->setVisible(true);
    donDialog->show();
    connect(donDialog->donateButton, SIGNAL(clicked()), this, SLOT(runDonate()));
    connect(donDialog->cancelButton, SIGNAL(clicked()), this, SLOT(closeDonateDialog()));
}

void MainBudget::closeDonateDialog()
{
    //donDialog->setModal(false);
    donDialog->done(0);
}

void MainBudget::openManual()
{
    QDesktopServices::openUrl(QUrl("https://s3.amazonaws.com/cakeheap/index.html"));
}

void MainBudget::openLicense()
{
    QDesktopServices::openUrl(QUrl("https://s3.amazonaws.com/cakeheap/cake-heap-end-user-licence-agreement.pdf"));
}

void MainBudget::openSupport()
{
    QDesktopServices::openUrl(QUrl("http://openbeacon.biz/support"));
}

void MainBudget::openSample()
{
    QDesktopServices::openUrl(QUrl("https://s3.amazonaws.com/cakeheap/yuccie.chf"));
}

void MainBudget::runDonate()
{
    QDesktopServices::openUrl(QUrl("https://www.paypal.com/cgi-bin/websrc?cmd=_s-xclick&hosted_button_id=2GC9DGNTWTULJ"));
    closeDonateDialog();
}

void MainBudget::showContextMenu(const QPoint &p)
{
    popupMenu->exec(QCursor::pos());
}

void MainBudget::contextMenuEvent(QContextMenuEvent *event)
{
    // THE POPUP MENU SECTION
    QMenu *popupMenu_2 = new QMenu(selectedBudgetFrame);
    QAction *editPopupAction = popupMenu_2->addAction(QString("Edit"), this, SLOT(editEntry()));
    //QAction *deletePopupAction = popupMenu_2->addAction(QString("Delete"), this, SLOT(deleteEntry()));
    popupMenu_2->addSeparator();
    QAction *cutPopupAction = popupMenu_2->addAction(QString("Cut"), this, SLOT(cutEntry()));
    cutPopupAction->setShortcut(QKeySequence(tr("Ctrl+X")));
    QAction *copyPopupAction = popupMenu_2->addAction(QString("Copy"), this, SLOT(copyEntry()));
    copyPopupAction->setShortcut(QKeySequence(tr("Ctrl+C")));
    QAction *pastePopupAction = popupMenu_2->addAction(QString("Paste"), this, SLOT(pasteEntry()));
    pastePopupAction->setShortcut(QKeySequence(tr("Ctrl+V")));
    popupMenu_2->exec(event->globalPos());
}

void MainBudget::editEntry()
{
    editSelectedItem();
    editSelectedSavings();
    editSelectedInventoryItem();
    editSelectedReminder();
}

/* THIS SECTION IS FOR THE UNDO-REDO PART */

void MainBudget::reAddIncome(Income *income)
{
    if (income->getLAmount() > 999999)
    {
        addLIncome(income->getName(), income->getLAmount(), false, 0, income->getReceivedDate(),
            income->getNature(), income->getTax(), income->getAdditionalInfo(), income->getTabIndex(), iList);
    }
    else
    {
        addIncome(income->getName(), income->getAmount(), false, 0, income->getReceivedDate(),
            income->getNature(), income->getTax(), income->getAdditionalInfo(), income->getTabIndex(), iList);
    }

    //iDialog->setModal(false);
    iDialog->done(0);

    for (int j = 0; j < btl.size(); j++)
    {
        shuffleIncomeTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), iList);
        shuffleDebtTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), dList);
        shuffleExpenseTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), eList);
    }

    populateIncomeTable(iList);
    populateDebtTable(dList);
    populateExpensesTable(eList);
    monthlyIncome = 0;
    monthlyLIncome = 0;
    for (int i = 0; i < iList.size(); i++)
    {
        if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (iList.at(i).getAmountType() == "long")
                containsLongIncome = true;
            monthlyIncome += iList.at(i).getNetAmount();
            monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
        }
    }
    //if (containsLongIncome)
        bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
    //else
    //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));
    setCurrentBalance();
    IDForIncomeOnStack = iList.size();
}


void MainBudget::undoAddIncome()
{
    for (int j = 0; j < iList.size(); j++)
    {
        if (iList.at(j).getIDCode() == IDForIncomeOnStack)
        {
            deleteIncome(iList, iList.at(j).getIDCode());
        }
    }
    populateIncomeTable(iList);
    monthlyIncome = 0;
    monthlyLIncome = 0;
    for (int i = 0; i < iList.size(); i++)
    {
        if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (iList.at(i).getAmountType() == "long")
                containsLongIncome = true;
            monthlyIncome += iList.at(i).getNetAmount();
            monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
        }
    }
    //if (containsLongIncome)
        bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
    //else
    //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));
    setCurrentBalance();
    IDForIncomeOnStack = iList.size();
}

void MainBudget::reDeleteIncome(Income *income)
{
    for (int j = 0; j < iList.size(); j++)
    {
        if (iList.at(j).getIDCode() == income->getIDCode())
        {
            deleteIncome(iList, iList.at(j).getIDCode());
        }
    }
}

void MainBudget::undoDeleteIncome(Income *income)
{
    if (income->getLAmount() > 999999)
    {
        addLIncomeAgain(income->getName(), income->getLAmount(), false, 0, income->getReceivedDate(),
            income->getNature(), income->getTax(), income->getAdditionalInfo(), income->getTabIndex(), income->getIDCode(), iList);
    }
    else
    {
        addIncomeAgain(income->getName(), income->getAmount(), false, 0, income->getReceivedDate(),
            income->getNature(), income->getTax(), income->getAdditionalInfo(), income->getTabIndex(), income->getIDCode(), iList);
    }

    for (int j = 0; j < btl.size(); j++)
    {
        shuffleIncomeTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), iList);
        shuffleDebtTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), dList);
        shuffleExpenseTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), eList);
    }

    populateIncomeTable(iList);
    populateDebtTable(dList);
    populateExpensesTable(eList);
    monthlyIncome = 0;
    monthlyLIncome = 0;
    for (int i = 0; i < iList.size(); i++)
    {
        if (iList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (iList.at(i).getAmountType() == "long")
                containsLongIncome = true;
            monthlyIncome += iList.at(i).getNetAmount();
            monthlyLIncome += iList.at(i).getNetAmount() + iList.at(i).getNetLAmount();
        }
    }
    //if (containsLongIncome)
        bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyLIncome(monthlyLIncome));
    //else
    //    bd->totalMonthlyIncomeLineEdit->setText(getCharAmountForMonthlyIncome(monthlyIncome));
    setCurrentBalance();
}

void MainBudget::reAddExpense(Expense *expense)
{
    if (expense->getLAmount() > 999999)
    {
        addLExpense(expense->getName(), expense->getLAmount(), expense->getPriorityLevel(), expense->getPenalty(),
            expense->getDueDate(), expense->getAdditionalInfo(), expense->getTabIndex(), eList);
    }
    else
    {
        addExpense(expense->getName(), expense->getAmount(), expense->getPriorityLevel(), expense->getPenalty(),
            expense->getDueDate(), expense->getAdditionalInfo(), expense->getTabIndex(), eList);
    }

    //eDialog->setModal(false);
    eDialog->done(0);

    for (int j = 0; j < btl.size(); j++)
    {
        shuffleExpenseTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), eList);
        shuffleIncomeTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), iList);
        shuffleDebtTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), dList);
    }

    populateExpensesTable(eList);
    populateIncomeTable(iList);
    populateDebtTable(dList);
    monthlyExpenses = 0;
    monthlyLExpenses = 0;
    for (int i = 0; i < eList.size(); i++)
    {
        if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (eList.at(i).getAmountType() == "long")
                containsLongExpense = true;
            monthlyExpenses += eList.at(i).getNetAmount();
            monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
        }
    }
    //if (containsLongExpense)
        bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
    //else
    //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

    setCurrentBalance();
    IDForExpenseOnStack = eList.size();
}

void MainBudget::undoAddExpense()
{
    for (int j = 0; j < eList.size(); j++)
    {
        if (eList.at(j).getIDCode() == IDForExpenseOnStack)
        {
            deleteExpense(eList, eList.at(j).getIDCode());
        }
    }
    populateExpensesTable(eList);
    monthlyExpenses = 0;
    monthlyLExpenses = 0;
    for (int i = 0; i < eList.size(); i++)
    {
        if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (eList.at(i).getAmountType() == "long")
                containsLongExpense = true;
            monthlyExpenses += eList.at(i).getNetAmount();
            monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
        }
    }
    //if (containsLongExpense)
        bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
    //else
    //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

    setCurrentBalance();
    IDForExpenseOnStack = eList.size();
}

void MainBudget::reDeleteExpense(Expense *expense)
{
    for (int j = 0; j < eList.size(); j++)
    {
        if (eList.at(j).getIDCode() == expense->getIDCode())
        {
            deleteExpense(eList, eList.at(j).getIDCode());
        }
    }
}

void MainBudget::undoDeleteExpense(Expense *expense)
{
    if (expense->getLAmount() > 999999)
    {
        addLExpenseAgain(expense->getName(), expense->getLAmount(), expense->getPriorityLevel(), expense->getPenalty(),
            expense->getDueDate(), expense->getAdditionalInfo(), expense->getTabIndex(), expense->getIDCode(), eList);
    }
    else
    {
        addExpenseAgain(expense->getName(), expense->getAmount(), expense->getPriorityLevel(), expense->getPenalty(),
            expense->getDueDate(), expense->getAdditionalInfo(), expense->getTabIndex(), expense->getIDCode(), eList);
    }


    for (int j = 0; j < btl.size(); j++)
    {
        shuffleExpenseTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), eList);
        shuffleIncomeTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), iList);
        shuffleDebtTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), dList);
    }

    populateExpensesTable(eList);
    populateIncomeTable(iList);
    populateDebtTable(dList);
    monthlyExpenses = 0;
    monthlyLExpenses = 0;
    for (int i = 0; i < eList.size(); i++)
    {
        if (eList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (eList.at(i).getAmountType() == "long")
                containsLongExpense = true;
            monthlyExpenses += eList.at(i).getNetAmount();
            monthlyLExpenses += eList.at(i).getNetAmount() + eList.at(i).getNetLAmount();
        }
    }
    //if (containsLongExpense)
        bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyLExpenses(monthlyLExpenses));
    //else
    //    bd->totalMonthlyExpensesLineEdit->setText(getCharAmountForMonthlyExpenses(monthlyExpenses));

    setCurrentBalance();
}

void MainBudget::reAddDebt(Debt *debt)
{
    if (debt->getLAmount() > 999999)
    {
        addLDebt(debt->getName(), debt->getLAmount(), true, debt->getAPR(), debt->getPriorityLevel(),
            debt->getDueDate(), debt->getAdditionalInfo(), debt->getNumberOfMonths(), debt->getTabIndex(), dList);
    }
    else
    {
        addDebt(debt->getName(), debt->getAmount(), true, debt->getAPR(), debt->getPriorityLevel(),
            debt->getDueDate(), debt->getAdditionalInfo(), debt->getNumberOfMonths(), debt->getTabIndex(), dList);
    }

    //dDialog->setModal(false);
    dDialog->done(0);

    for (int j = 0; j < btl.size(); j++)
    {
        shuffleDebtTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), dList);
        shuffleIncomeTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), iList);
        shuffleExpenseTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), eList);
    }

    populateDebtTable(dList);
    populateIncomeTable(iList);
    populateExpensesTable(eList);
    monthlyDebt = 0;
    monthlyLDebt = 0;
    for (int i = 0; i < dList.size(); i++)
    {
        if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (dList.at(i).getAmountType() == "long")
                containsLongDebt = true;
            monthlyDebt += dList.at(i).getNetAmount();
            monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
        }
    }
    //if (containsLongDebt)
        bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
    //else
    //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));
    setCurrentBalance();
    IDForDebtOnStack = dList.size();
}

void MainBudget::undoAddDebt()
{
    for (int j = 0; j < dList.size(); j++)
    {
        if (dList.at(j).getIDCode() == IDForDebtOnStack)
        {
            deleteDebt(dList, dList.at(j).getIDCode());
        }
    }
    populateDebtTable(dList);

    monthlyDebt = 0;
    monthlyLDebt = 0;
    for (int i = 0; i < dList.size(); i++)
    {
        if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (dList.at(i).getAmountType() == "long")
                containsLongDebt = true;
            monthlyDebt += dList.at(i).getNetAmount();
            monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
        }
    }
    //if (containsLongDebt)
        bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
    //else
    //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));
    setCurrentBalance();
    IDForDebtOnStack = dList.size();
}

void MainBudget::reDeleteDebt(Debt *debt)
{
    for (int j = 0; j < dList.size(); j++)
    {
        if (dList.at(j).getIDCode() == debt->getIDCode())
        {
            deleteDebt(dList, dList.at(j).getIDCode());
        }
    }
}

void MainBudget::undoDeleteDebt(Debt *debt)
{
    if (debt->getLAmount() > 999999)
    {
        addLDebtAgain(debt->getName(), debt->getLAmount(), true, debt->getAPR(), debt->getPriorityLevel(),
            debt->getDueDate(), debt->getAdditionalInfo(), debt->getNumberOfMonths(), debt->getTabIndex(), debt->getIDCode(), dList);
    }
    else
    {
        addDebtAgain(debt->getName(), debt->getAmount(), true, debt->getAPR(), debt->getPriorityLevel(),
            debt->getDueDate(), debt->getAdditionalInfo(), debt->getNumberOfMonths(), debt->getTabIndex(), debt->getIDCode(), dList);
    }


    for (int j = 0; j < btl.size(); j++)
    {
        shuffleDebtTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), dList);
        shuffleIncomeTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), iList);
        shuffleExpenseTabs(btl.at(j).getMonth(), btl.at(j).getYear(),
            msBudget->getSortedTabIndex(btl.at(j).getMonth(), btl.at(j).getYear()), eList);
    }

    populateDebtTable(dList);
    populateIncomeTable(iList);
    populateExpensesTable(eList);
    monthlyDebt = 0;
    monthlyLDebt = 0;
    for (int i = 0; i < dList.size(); i++)
    {
        if (dList.at(i).getTabIndex() == mainBudgetTab.currentIndex())
        {
            if (dList.at(i).getAmountType() == "long")
                containsLongDebt = true;
            monthlyDebt += dList.at(i).getNetAmount();
            monthlyLDebt += dList.at(i).getNetAmount() + dList.at(i).getNetLAmount();
        }
    }
    //if (containsLongDebt)
        bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyLDebt(monthlyLDebt));
    //else
    //    bd->totalMonthlyDebtLineEdit->setText(getCharAmountForMonthlyDebt(monthlyDebt));
    setCurrentBalance();
}

void MainBudget::reAddSavings(Savings *savings)
{
    if (savings->getLAmount() > 999999)
    {
        addLSavings(savings->getName(), savings->getLAmount(), savings->getAPR(),
            savings->getNature(), savings->getDate(), savings->getDescription(), sList);
    }
    else
    {
        addSavings(savings->getName(), savings->getAmount(), savings->getAPR(),
            savings->getNature(), savings->getDate(), savings->getDescription(), sList);
    }

    //svDialog->setModal(false);
    svDialog->done(0);
    populateSavingsTable(sList);

    savingsBalance = 0;
    savingsLBalance = 0;
    for (int i = 0; i < sList.size(); i++)
    {
        if (sList.at(i).getAmountType() == "long")
            containsLongAssSaving = true;
        savingsBalance += sList.at(i).getAmount();
        savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
    }
    //if (containsLongAssSaving)
        sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
    //else
    //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));
    IDForSavingsOnStack = sList.size();
}

void MainBudget::undoAddSavings()
{
    deleteSavings(sList, IDForSavingsOnStack);
    populateSavingsTable(sList);

    savingsBalance = 0;
    savingsLBalance = 0;
    for (int i = 0; i < sList.size(); i++)
    {
        if (sList.at(i).getAmountType() == "long")
            containsLongAssSaving = true;
        savingsBalance += sList.at(i).getAmount();
        savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
    }
    //if (containsLongAssSaving)
        sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
    //else
    //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));
    IDForSavingsOnStack = sList.size();
}

void MainBudget::reDeleteSavings(Savings *savings)
{
    deleteSavings(sList, savings->getIDCode());
}

void MainBudget::undoDeleteSavings(Savings *savings)
{
    if (savings->getLAmount() > 999999)
    {
        addLSavingsAgain(savings->getName(), savings->getLAmount(), savings->getAPR(),
            savings->getNature(), savings->getDate(), savings->getDescription(), savings->getIDCode(), sList);
    }
    else
    {
        addSavingsAgain(savings->getName(), savings->getAmount(), savings->getAPR(),
            savings->getNature(), savings->getDate(), savings->getDescription(), savings->getIDCode(), sList);
    }

    populateSavingsTable(sList);

    savingsBalance = 0;
    savingsLBalance = 0;
    for (int i = 0; i < sList.size(); i++)
    {
        if (sList.at(i).getAmountType() == "long")
            containsLongAssSaving = true;
        savingsBalance += sList.at(i).getAmount();
        savingsLBalance += sList.at(i).getAmount() + sList.at(i).getLAmount();
    }
    //if (containsLongAssSaving)
        sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentLBalance(savingsLBalance)));
    //else
    //    sd->currentBalanceLineEdit->setText(QString(getCharAmountForSavingsCurrentBalance(savingsBalance)));
}

void MainBudget::reAddItem(Items *item)
{
    addItem(item->getName(), item->getPrice(), item->getNumber(), item->getItemID(), itList);

    //itDialog->setModal(false);
    itDialog->done(0);
    populateInventoryTable(itList);
    IDForItemOnStack = itList.size();
}

void MainBudget::undoAddItem()
{
    deleteItem(itList, IDForItemOnStack);
    populateInventoryTable(itList);
    IDForItemOnStack = itList.size();
}

void MainBudget::reDeleteItem(Items *item)
{
    deleteItem(itList, item->getIDCode());
}

void MainBudget::undoDeleteItem(Items *item)
{
    addItemAgain(item->getName(), item->getPrice(), item->getNumber(), item->getItemID(), item->getIDCode(), itList);

    populateInventoryTable(itList);
    IDForItemOnStack = itList.size();
}

void MainBudget::reAddReminder(Reminder *reminder)
{
    addReminder(reminder->getDueDate(), reminder->getSubject(), reminder->getMessage(),
        HIGH, rList);

    //rmDialog->setModal(false);
    rmDialog->done(0);
    populateReminderTable(rList);
    IDForReminderOnStack = rList.size();
}

void MainBudget::undoAddReminder()
{
    deleteReminder(rList, IDForReminderOnStack);
    populateReminderTable(rList);
    IDForReminderOnStack = rList.size();
}

void MainBudget::reDeleteReminder(Reminder *reminder)
{
    deleteReminder(rList, reminder->getIDCode());
}

void MainBudget::undoDeleteReminder(Reminder *reminder)
{
    addReminderAgain(reminder->getDueDate(), reminder->getSubject(), reminder->getMessage(),
        HIGH, reminder->getIDCode(), rList);

    populateReminderTable(rList);
    IDForReminderOnStack = rList.size();
}
