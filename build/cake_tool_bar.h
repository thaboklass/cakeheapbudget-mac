#ifndef CAKE_TOOL_BAR_H
#define CAKE_TOOL_BAR_H

#include <QToolBar>
#include <QWidget>
#include <QEvent>
#include <QDebug>

class CakeToolBar : public QToolBar
{
    Q_OBJECT
    
public:
    CakeToolBar(QWidget *parent = 0);
    bool event(QEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
};


#endif // CAKE_TOOL_BAR_H
