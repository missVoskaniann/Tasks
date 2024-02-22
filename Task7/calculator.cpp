#include "calculator.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QStack>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Calculator");

    input = new QLineEdit();
    input->setReadOnly(true);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(buttons[0][0] = new QPushButton("1"), 1, 0);
    layout->addWidget(buttons[0][1] = new QPushButton("2"), 1, 1);
    layout->addWidget(buttons[0][2] = new QPushButton("3"), 1, 2);
    layout->addWidget(buttons[0][3] = new QPushButton("+"), 1, 3);

    layout->addWidget(buttons[1][0] = new QPushButton("4"), 2, 0);
    layout->addWidget(buttons[1][1] = new QPushButton("5"), 2, 1);
    layout->addWidget(buttons[1][2] = new QPushButton("6"), 2, 2);
    layout->addWidget(buttons[1][3] = new QPushButton("-"), 2, 3);

    layout->addWidget(buttons[2][0] = new QPushButton("7"), 3, 0);
    layout->addWidget(buttons[2][1] = new QPushButton("8"), 3, 1);
    layout->addWidget(buttons[2][2] = new QPushButton("9"), 3, 2);
    layout->addWidget(buttons[2][3] = new QPushButton("x"), 3, 3);

    layout->addWidget(buttons[3][0] = new QPushButton("%"), 4, 0);
    layout->addWidget(buttons[3][1] = new QPushButton("0"), 4, 1);
    layout->addWidget(buttons[3][2] = new QPushButton("/"), 4, 2);
    layout->addWidget(buttons[3][3] = new QPushButton("="), 4, 3);
    layout->addWidget(clearButton = new QPushButton("C"), 0, 0, 1, 1);
    layout->addWidget(input, 0, 1, 1, 4);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(clearButton, &QPushButton::clicked, input, &QLineEdit::clear);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            connect(buttons[i][j], &QPushButton::clicked, this, &Calculator::handleButtonClick);
        }
    }
}

Calculator::~Calculator() {
    delete input;
    delete clearButton;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            delete buttons[i][j];
        }
    }
}

void Calculator::handleButtonClick() {
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
        QString text = btn->text();
        if (text == "=") {
            QString expr = input->text();
            QStringList operands;
            double num1, num2;
            QString op;
            bool opFound = false;
            for (int i = 0; i < expr.size(); ++i) {
                if (expr[i] == '+' || expr[i] == '-' || expr[i] == 'x' || expr[i] == '/' || expr[i] == '%') {
                    op = expr[i];
                    operands = expr.split(op);
                    if (operands.size() == 2) {
                        num1 = operands[0].toDouble();
                        num2 = operands[1].toDouble();
                        opFound = true;
                        break;
                    }
                }
            }
            if (!opFound) {
                QMessageBox::warning(this, "Error", "Invalid expression");
                return;
            }
            double res = 0;
            if (op == "+") {
                res = num1 + num2;
            } else if (op == "-") {
                res = num1 - num2;
            } else if (op == "x") {
                res = num1 * num2;
            } else if (op == "/") {
                if (num2 != 0) {
                    res = num1 / num2;
                } else {
                    QMessageBox::warning(this, "Error", "You cannot divide by zero");
                    return;
                }
            } else if (op == "%") {
                res = fmod(num1, num2);
            }
            input->setText(QString::number(res));
        } else {
            input->setText(input->text() + text);
        }
    }
}
