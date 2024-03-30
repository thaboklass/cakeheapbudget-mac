#ifndef EDITED_SAVINGS_DIALOG_H_INCLUDED
#define EDITED_SAVINGS_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_savings_dialog.h"
class EditedSavingsDialog : public QDialog, public Ui::savingsDialog
{
    Q_OBJECT
public:
    EditedSavingsDialog(QWidget *parent = 0);
};


#endif // EDITED_SAVINGS_DIALOG_H_INCLUDED
