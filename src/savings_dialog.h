#ifndef SAVINGS_DIALOG_H_INCLUDED
#define SAVINGS_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_savings_dialog.h"
class SavingsDialog : public QDialog, public Ui::savingsDialog
{
    Q_OBJECT
public:
    SavingsDialog(QWidget *parent = 0);
};

#endif // SAVINGS_DIALOG_H_INCLUDED
