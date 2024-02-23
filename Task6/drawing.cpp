#include "drawing.h"
#include <QPainter>
#include <QMouseEvent>
#include <cmath>
#include <QHBoxLayout>
#include <QVBoxLayout>

Drawing::Drawing(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(800, 600);

    lineBtn = new QPushButton("Line", this);
    rectangleBtn = new QPushButton("Rectangle", this);
    circleBtn = new QPushButton("Circle", this);
    triangleBtn = new QPushButton("Triangle", this);


    connect(lineBtn, &QPushButton::clicked, this, &Drawing::currForLine);
    connect(rectangleBtn, &QPushButton::clicked, this, &Drawing::currForRectangle);
    connect(circleBtn, &QPushButton::clicked, this, &Drawing::currForCircle);
    connect(triangleBtn, &QPushButton::clicked, this, &Drawing::currForTriangle);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    mainLayout->addWidget(lineBtn);
    mainLayout->addWidget(rectangleBtn);
    mainLayout->addWidget(circleBtn);
    mainLayout->addWidget(triangleBtn);
    mainLayout->addStretch();
}

Drawing::~Drawing() = default;

void Drawing::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    for (const auto &shape : drawings) {
        if (shape.type == Line) {
            painter.drawLine(shape.rect.topLeft(), shape.rect.bottomRight());
        } else if (shape.type == Rectangle) {
            painter.drawRect(shape.rect);
        } else if (shape.type == Circle) {
            painter.drawEllipse(shape.rect);
        } else if (shape.type == Triangle) {
            QPoint top = shape.rect.topLeft();
            QPoint bLeft = shape.rect.bottomLeft();
            QPoint bRight = shape.rect.bottomRight();
            QPoint middle = QPoint((bLeft.x() + bRight.x()) / 2, bLeft.y());
            painter.drawLine(top, bLeft);
            painter.drawLine(top, bRight);
            painter.drawLine(bLeft, bRight);
        }
    }
    if (drawing) {
        if (currShape == Line) {
            painter.drawLine(start, end);
        } else if (currShape == Rectangle) {
            painter.drawRect(QRect(start, end));
        } else if (currShape == Circle) {
            int radius = std::hypot(end.x() - start.x(), end.y() - start.y());
            painter.drawEllipse(start, radius, radius);
        } else if (currShape == Triangle) {
            painter.drawRect(QRect(start, end));
        }
    }
}

void Drawing::mousePressEvent(QMouseEvent* event) {
    start = event->pos();
    drawing = true;
    update();
}

void Drawing::mouseMoveEvent(QMouseEvent* event) {
    end = event->pos();
    update();
}

void Drawing::mouseReleaseEvent(QMouseEvent* event) {
    end = event->pos();
    drawing = false;
    if (currShape == Line) {
        drawings.append({Line, QRect(start, end)});
    } else if (currShape == Rectangle) {
        drawings.append({Rectangle, QRect(start, end)});
    } else if (currShape == Circle) {
        int radius = std::hypot(end.x() - start.x(), end.y() - start.y());
        drawings.append({Circle, QRect(start.x() - radius, start.y() - radius, radius * 2, radius * 2)});
    } else if (currShape == Triangle) {
        drawings.append({Triangle, QRect(start, end)});
    }
    update();
}

void Drawing::currForLine() {
    currShape = Line;
}

void Drawing::currForRectangle() {
    currShape = Rectangle;
}

void Drawing::currForCircle() {
    currShape = Circle;
}

void Drawing::currForTriangle() {
    currShape = Triangle;
}

void Drawing::clear() {
    drawings.clear();
    update();
}
