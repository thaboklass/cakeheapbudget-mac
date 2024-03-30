#ifndef DONATE_DIALOG_H_INCLUDED
#define DONATE_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_donate_dialog.h"
class DonateDialog : public QDialog, public Ui::donationDialog
{
    Q_OBJECT
public:
    DonateDialog(QWidget *parent = 0);
};


#endif // DONATE_DIALOG_H_INCLUDED
