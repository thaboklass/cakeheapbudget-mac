#include <QPainter>
#include "cake_calenderwidget.h"

CakeCalendarWidget::CakeCalendarWidget(QWidget *parent)
: QCalendarWidget(parent)
{
    //m_currentDate = QDate::currentDate();
    m_outlinePen.setColor(Qt::green);
    m_transparentBrush.setColor(Qt::green);
    
    setStyleSheet("QCalendarWidget QAbstractItemView:enabled { font-size: 11px; } ");
    setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    
    QWidget *calendarNavBar = findChild<QWidget *>("qt_calendar_navigationbar");
    if (calendarNavBar) {
        QPalette pal = calendarNavBar->palette();
        pal.setColor(calendarNavBar->backgroundRole(), QColor(236, 236, 236));
        pal.setColor(calendarNavBar->foregroundRole(), QColor(236, 236, 236));
        calendarNavBar->setPalette(pal);
    }
}

CakeCalendarWidget::~CakeCalendarWidget()
{
}

void CakeCalendarWidget::setColor(QColor & color)
{
    m_outlinePen.setColor(color);
}

QColor CakeCalendarWidget::getColor()
{
    return (m_outlinePen.color());
}

void CakeCalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    QCalendarWidget::paintCell(painter, rect, date);

    for (int i = 0; i < reminderDate.size(); i++)
    {
    if (date == reminderDate.at(i))
    {
        painter->setPen(m_outlinePen);
        painter->setBrush(m_transparentBrush);
        painter->drawRect(rect.adjusted(0, 0, -1, -1));
    }
    }
}

void CakeCalendarWidget::setReminderDate(QDate date)
{
    reminderDate.push_back(date);
    repaint();
}

void CakeCalendarWidget::repaintReminders(int index)
{
    int i = index;
    reminderDate.erase(reminderDate.begin() + i);
    repaint();
}
