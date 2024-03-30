/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The CakeHeap Application class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef CAKEHEAPAPPLICATION_H
#define CAKEHEAPAPPLICATION_H

#include <QApplication>
//#include <QEvent>
#include <QFileOpenEvent>
#include <QtDebug>
#include "main_window.h"

class CakeHeapApplication : public QApplication
{
    public:
        CakeHeapApplication(int &argc, char **argv);
        
        bool event(QEvent *event);
        MainWin *budget;
};

#endif // CAKEHEAPAPPLICATION_H
