/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Cake Spacer Widget class

 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef CAKESPACERWIDGET_H
#define CAKESPACERWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QMouseEvent>

class CakeSpacerWidget : public QWidget
{
    Q_OBJECT

    public:
        CakeSpacerWidget(QWidget *parent = 0);
    
    protected:
        void mousePressEvent(QMouseEvent *evt);
        void mouseMoveEvent(QMouseEvent *evt);
        void mouseDoubleClickEvent(QMouseEvent *evt);

    private:
        QPoint oldPos;
};

#endif // CAKESPACERWIDGET_H
