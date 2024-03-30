#ifndef BUDGET_DOCK_H_INCLUDED
#define BUDGET_DOCK_H_INCLUDED
#include <QDockWidget>
#include "ui_budget_dock.h"
class BudgetDock : public QDockWidget, public Ui::BudgetDock
{
    Q_OBJECT
public:
    BudgetDock(QWidget *parent = 0);
    void resizeEvent(QResizeEvent * event);

private:
    int originalWidth;
    int originalHeight;
};


#endif // BUDGET_DOCK_H_INCLUDED
