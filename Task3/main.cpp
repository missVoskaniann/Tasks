#include "validation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Validation w;
    w.show();
    return a.exec();
}
