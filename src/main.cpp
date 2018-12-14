#include <QGuiApplication>
#include <QApplication>

#include "mainwindow.hpp"

/******************************************************************************/

int main( int _argc, char** _argv )
{
    QApplication app( _argc, _argv );

    MainWindow widget;
    widget.show();

    return app.exec();
}

/******************************************************************************/
