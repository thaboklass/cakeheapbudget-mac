#ifndef EDITED_DEBT_DIALOG_H_INCLUDED
#define EDITED_DEBT_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_debt_dialog.h"
class EditedDebtDialog : public QDialog, public Ui::debtDialog
{
    Q_OBJECT
public:
    EditedDebtDialog(QWidget *parent = 0);
};

#endif // EDITED_DEBT_DIALOG_H_INCLUDED
