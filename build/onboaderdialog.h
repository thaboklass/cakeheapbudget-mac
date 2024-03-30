#ifndef ONBOADERDIALOG_H
#define ONBOADERDIALOG_H

#include <QDialog>
#include "ui_onboaderdialog.h"

class OnboaderDialog : public QDialog, public Ui::OnboarderDialog
{
    Q_OBJECT

public:
    OnboaderDialog(QWidget *parent = 0);
};

#endif // ONBOADERDIALOG_H
