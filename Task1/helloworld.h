#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <QMainWindow>

class HelloWorld : public QMainWindow
{
    Q_OBJECT

public:
    HelloWorld(QWidget *parent = nullptr);
    ~HelloWorld();
};
#endif // HELLOWORLD_H
