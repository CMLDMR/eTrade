
#include <QApplication>
#include <QLabel>
#include <iostream>

#include "Qt/MainWindow.h"

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);

    MainWindow window;
    window.show();

    return app.exec();
}
