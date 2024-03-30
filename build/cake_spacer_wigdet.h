#ifndef CAKE_SPACER_WIGDET_H
#define CAKE_SPACER_WIGDET_H

class CakeSpacerWidget: public QWidget
{
    Q_OBJECT

public:
    explicit CakeSpacerWidget(QWidget *parent=0) : QWidget(parent) { }

protected:
    void mousePressEvent(QMouseEvent *evt)
    {
        oldPos = evt->globalPos();
    }

    void mouseMoveEvent(QMouseEvent *evt)
    {
        const QPoint delta = evt->globalPos() - oldPos;
        move(x()+delta.x(), y()+delta.y());
        oldPos = evt->globalPos();
    }

private:
    QPoint oldPos;
};

#endif // CAKE_SPACER_WIGDET_H
