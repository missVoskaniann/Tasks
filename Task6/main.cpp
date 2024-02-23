#include "drawing.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Drawing w;
    w.show();
    return a.exec();
}
