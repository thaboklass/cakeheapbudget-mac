#ifndef EDITED_INCOME_DIALOG_H_INCLUDED
#define EDITED_INCOME_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_edited_income_dialog.h"
class EditedIncomeDialog : public QDialog, public Ui::editedIncomeDialog
{
    Q_OBJECT
public:
    EditedIncomeDialog(QWidget *parent = 0);
};


#endif // EDITED_INCOME_DIALOG_H_INCLUDED
