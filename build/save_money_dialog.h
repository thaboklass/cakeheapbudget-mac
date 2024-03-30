#ifndef SAVE_MONEY_DIALOG_H_INCLUDED
#define SAVE_MONEY_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_save_money_dialog.h"
class SaveMoneyDialog : public QDialog, public Ui::saveMoneyDialog
{
    Q_OBJECT
public:
    SaveMoneyDialog(QWidget *parent = 0);
};

#endif // SAVE_MONEY_DIALOG_H_INCLUDED
