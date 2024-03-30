#ifndef CAKE_TAB_WIDGET_H_INCLUDED
#define CAKE_TAB_WIDGET_H_INCLUDED

class CakeTabWidget : public QTabWidget
{
    public:
        //CakeTabWidget(QWidget *parent = 0) : QTabWidget(p){}
        QTabBar * tabBar() const { return QTabWidget::tabBar(); }
};

#endif // CAKE_TAB_WIDGET_H_INCLUDED
