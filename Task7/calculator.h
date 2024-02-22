#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
class QPushButton;
class QLineEdit;

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void handleButtonClick();

private:
    QPushButton *buttons[4][4];
    QPushButton *clearButton;
    QLineEdit* input;
};
#endif // CALCULATOR_H
