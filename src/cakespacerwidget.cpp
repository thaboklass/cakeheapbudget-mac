#include "cakespacerwidget.h"
#include "main_budget.h"

CakeSpacerWidget::CakeSpacerWidget(QWidget *parent)
: QWidget(parent) {
    
};

void CakeSpacerWidget::mousePressEvent(QMouseEvent *evt)
{
    oldPos = evt->globalPos();
}

void CakeSpacerWidget::mouseMoveEvent(QMouseEvent *evt)
{
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}

void CakeSpacerWidget::mouseDoubleClickEvent(QMouseEvent *evt)
{
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        MainBudget *mainBudget = qobject_cast<MainBudget *>(widget);
        if (mainBudget) {
            if (mainBudget->isMaximized())
                mainBudget->showNormal();
            else
                mainBudget->showMaximized();
        }
    }
}