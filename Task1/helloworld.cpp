#include "helloworld.h"
#include <QLabel>

HelloWorld::HelloWorld(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel* label = new QLabel("Hello, World!", this);
    label->setAlignment(Qt::AlignCenter);
    label->setFixedSize(400, 200);
    QFont font = label->font();
    font.setPointSize(24);
    label->setFont(font);
    label->show();

}

HelloWorld::~HelloWorld() = default;

