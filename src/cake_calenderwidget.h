#ifndef CAKE_CALENDERWIDGET_H_INCLUDED
#define CAKE_CALENDERWIDGET_H_INCLUDED

#include <QColor>
//#include <QDate>
#include <QPen>
#include <QBrush>
#include <QCalendarWidget>
#include <vector>
using namespace std;

typedef vector<QDate> QDateList;

class CakeCalendarWidget : public QCalendarWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ getColor WRITE setColor)

    public:
        CakeCalendarWidget(QWidget *parent = 0);
        ~CakeCalendarWidget();

        void setColor(QColor & color);
        QColor getColor();
        void setReminderDate(QDate date);
        QDateList reminderDate;
        void repaintReminders(int index);

    protected:
        virtual void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

    private:
        QPen m_outlinePen;
        QBrush m_transparentBrush;
};

#endif // CAKE_CALENDERWIDGET_H_INCLUDED
