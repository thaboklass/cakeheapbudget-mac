#include "cake_tool_bar.h"

CakeToolBar::CakeToolBar(QWidget *parent)
: QToolBar(parent) {
    QAction *action = this->addAction("Action");
    action->setToolTip("");
};
    
bool CakeToolBar::event(QEvent *event)
{
    if(event->type() == QEvent::ToolTip)
    {
        qDebug() << "QEvent::ToolTip";
    }
    
    return QToolBar::event(event);
}

bool CakeToolBar::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::ToolTip)
    {
        return true;
    }
    return false;
}
