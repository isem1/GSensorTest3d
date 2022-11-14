#include <QGuiApplication>
#include <QApplication>

#include "mainwindow.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    MainWindow widget;
    widget.show();

    return app.exec();
}
