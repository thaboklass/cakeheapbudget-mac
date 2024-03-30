#include "cakeheapapplication.h"

CakeHeapApplication::CakeHeapApplication(int& argc, char**argv) : QApplication(argc, argv)
{
    budget = new MainWin;
};
    
bool CakeHeapApplication::event(QEvent *event)
{
    if (event->type() == QEvent::FileOpen) {
        QFileOpenEvent *openEvent = static_cast<QFileOpenEvent *>(event);
        qDebug() << "Open file" << openEvent->file();
        budget->mb->openDragAndDrop(openEvent->file());
    }
    
    return QApplication::event(event);
}
