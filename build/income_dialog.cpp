#include <QtGui>
#include "income_dialog.h"
IncomeDialog::IncomeDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    //calendar->setObjectName(QString::fromUtf8("calendarWidget"));
/*
    connect(dateEdit, SIGNAL(dateChanged(const QDate &)),
        this, SLOT(popupCalendar()));
    connect(calendar, SIGNAL(clicked(const QDate &)),
        this, SLOT(setSelectedDate()));*/
}
/*
void IncomeDialog::popupCalendar()
{
    calendar = new QCalendarWidget(this);
    calendar->setVisible(true);
}

void IncomeDialog::setSelectedDate()
{
    dateEdit->setDate(calendar->selectedDate());
    calendar->setVisible(false);
}
*/
