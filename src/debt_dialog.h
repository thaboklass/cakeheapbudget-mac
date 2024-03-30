#ifndef DEBT_DIALOG_H_INCLUDED
#define DEBT_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_debt_dialog.h"
class DebtDialog : public QDialog, public Ui::debtDialog
{
    Q_OBJECT
public:
    DebtDialog(QWidget *parent = 0);
};

#endif // DEBT_DIALOG_H_INCLUDED
