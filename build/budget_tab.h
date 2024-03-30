#ifndef BUDGET_TAB_H_INCLUDED
#define BUDGET_TAB_H_INCLUDED
#include "ui_budget_tab.h"

class BudgetTab : public QTabWidget, public Ui::BudgetTab
{
    Q_OBJECT
public:
    BudgetTab(QWidget *parent = 0);
};

#endif // BUDGET_TAB_H_INCLUDED
