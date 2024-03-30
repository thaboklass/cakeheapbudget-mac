#ifndef EXPENSES_DIALOG_H_INCLUDED
#define EXPENSES_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_expenses_dialog.h"
class ExpensesDialog : public QDialog, public Ui::expensesDialog
{
    Q_OBJECT
public:
    ExpensesDialog(QWidget *parent = 0);
};


#endif // EXPENSES_DIALOG_H_INCLUDED
