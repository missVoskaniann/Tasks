#include "counter.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFont>
Counter::Counter(QWidget *parent) : QMainWindow(parent), count(0)
{

    QPushButton* click = new QPushButton("Click", this);
    label = new QLabel(QString::number(count), this);
    QFont font = label->font();
    font.setPointSize(24);
    label->setFont(font);

    connect(click, &QPushButton::clicked, this, &Counter::buttonClicked);


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(click);
    layout->addWidget(label);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

Counter::~Counter() = default;

void Counter::buttonClicked() {
    ++count;
    label->setText(QString::number(count));
}
