#ifndef EDITED_EXPENSES_DIALOG_H_INCLUDED
#define EDITED_EXPENSES_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_expenses_dialog.h"
class EditedExpensesDialog : public QDialog, public Ui::expensesDialog
{
    Q_OBJECT
public:
    EditedExpensesDialog(QWidget *parent = 0);
};


#endif // EDITED_EXPENSES_DIALOG_H_INCLUDED
