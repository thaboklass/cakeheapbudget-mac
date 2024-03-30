#ifndef SAVINGS_DOCK_H_INCLUDED
#define SAVINGS_DOCK_H_INCLUDED
#include <QDockWidget>
#include "ui_savings_dock.h"
class SavingsDock : public QDockWidget, public Ui::SavingsDock
{
    Q_OBJECT
public:
    SavingsDock(QWidget *parent = 0);
    void resizeEvent(QResizeEvent * event);
private:
    int originalWidth;
    int originalHeight;

    int savingsNameColumnWidth;
    int savingsNatureColumnWidth;
    int savingsAPRColumnWidth;
    int savingsAmountColumnWidth;
};


#endif // SAVINGS_DOCK_H_INCLUDED
