//#include <QApplication>
#include <QStyle>
//#include <QtDebug>
//#include <QFileOpenEvent>
//#include "main_window.h"
#include "check_reminders.h"
#include "cakeheapapplication.h"

/**
 The application entry point.
 
 @param  argc.
 @param  argv.
 @return app.exec().
 */
int main( int argc, char ** argv )
{
    /*int WIDTH = 1140;
     int HEIGHT = 680;
     int screenWidth;
     int screenHeight;
     int x, y;*/
    
    CakeHeapApplication app(argc, argv);
    app.setOrganizationName("Thabo Klass");
    app.setApplicationName("CakeHeap Budget Professional");
    app.setOrganizationDomain("http://openbeacon.biz/");
    //QFont systemFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    //QFont lucidaGrande;
    //lucidaGrande.setFamily("Lucida Grande");
    //app.setFont(lucidaGrande);
    //QApplication::setFont("Helvetica Neue");
    //MainWin *budget = new MainWin;
    
    /*budget->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            QSize(1140, 680),
            app.desktop()->availableGeometry()
        )
    );*/
    
    /*QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;
    budget->move(x, y);*/
    
    /*int x = 1140 ; // whatever
    int y = 680 ; // whatever
    
    // Make sure it fits on the screen
    QRect ScreenRect = qApp -> desktop() -> availableGeometry (ApplicationData -> mainWindow) ;
    
    if (x + frameGeometry().width() > ScreenRect.right())
        x = ScreenRect.right() - frameGeometry().width() ;
    if (x < ScreenRect.x()) x = ScreenRect.x() ;
    
    if (y + frameGeometry().height() > ScreenRect.bottom())
        y = ScreenRect.bottom() - frameGeometry().height() ;
    if (y < ScreenRect.y()) y = ScreenRect.y() ;
    
    move (x, y)*/
    
    return app.exec();
}
