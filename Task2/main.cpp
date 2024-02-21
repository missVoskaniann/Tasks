#include "counter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Counter w;
    w.setFixedSize(200, 100);
    w.show();
    return a.exec();
}
