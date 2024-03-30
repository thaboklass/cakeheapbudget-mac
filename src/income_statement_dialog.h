#ifndef INCOME_STATEMENT_DIALOG_H_INCLUDED
#define INCOME_STATEMENT_DIALOG_H_INCLUDED

#include <QDialog>
#include "ui_income_statement.h"
class IncomeStatementDialog : public QDialog, public Ui::incomeStatementDialog
{
    Q_OBJECT
public:
    IncomeStatementDialog(QWidget *parent = 0);
};

#endif // INCOME_STATEMENT_DIALOG_H_INCLUDED
