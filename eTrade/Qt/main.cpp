
#include <QApplication>
#include <QLabel>
#include <iostream>

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);

    std::cout << "Hello World Qt" << std::endl;


    QLabel label("sdf");

    label.show();

    return app.exec();
}
