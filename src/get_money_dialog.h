#ifndef GET_MONEY_DIALOG_H_INCLUDED
#define GET_MONEY_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_get_money_dialog.h"
class GetMoneyDialog : public QDialog, public Ui::getMoneyDialog
{
    Q_OBJECT
public:
    GetMoneyDialog(QWidget *parent = 0);
};


#endif // GET_MONEY_DIALOG_H_INCLUDED
