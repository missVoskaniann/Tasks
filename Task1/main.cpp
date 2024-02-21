#include "helloworld.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloWorld w;
    w.setFixedSize(400, 200);
    w.show();
    return a.exec();
}
