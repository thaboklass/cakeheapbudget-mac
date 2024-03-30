#ifndef ABOUT_DIALOG_H_INCLUDED
#define ABOUT_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_about_dialog.h"
class AboutDialog : public QDialog, public Ui::aboutDialog
{
    Q_OBJECT
public:
    AboutDialog(QWidget *parent = 0);
};


#endif // ABOUT_DIALOG_H_INCLUDED
