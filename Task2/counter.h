#ifndef COUNTER_H
#define COUNTER_H

#include <QMainWindow>
class QLabel;

class Counter : public QMainWindow
{
    Q_OBJECT

public:
    Counter(QWidget *parent = nullptr);
    ~Counter();
private slots:
    void buttonClicked();

private:
    QLabel* label;
    int count;
};
#endif // COUNTER_H
