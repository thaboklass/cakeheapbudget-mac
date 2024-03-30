#ifndef INCOME_DIALOG_H_INCLUDED
#define INCOME_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_income_dialog.h"
class IncomeDialog : public QDialog, public Ui::incomeDialog
{
    Q_OBJECT
public:
    IncomeDialog(QWidget *parent = 0);
/*    QCalendarWidget * calendar;

private slots:
    void setSelectedDate();
    void popupCalendar();*/
};


#endif // INCOME_DIALOG_H_INCLUDED
