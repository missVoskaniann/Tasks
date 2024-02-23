#ifndef DRAWING_H
#define DRAWING_H

#include <QMainWindow>
#include <QList>
#include <QPoint>
#include <QPushButton>

class Drawing : public QMainWindow
{
    Q_OBJECT

public:
    Drawing(QWidget *parent = nullptr);
    ~Drawing();

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

public slots:
    void currForLine();
    void currForRectangle();
    void currForCircle();
    void currForTriangle();
    void clear();

private:
    enum Type {
        Line,
        Circle,
        Triangle,
        Rectangle
    };
    struct Shape {
        Type type;
        QRect rect;
    };

    QList<Shape> drawings;
    QPoint start;
    QPoint end;
    bool drawing;
    Type currShape;

    QPushButton *lineBtn;
    QPushButton *rectangleBtn;
    QPushButton *circleBtn;
    QPushButton *triangleBtn;
};
#endif // DRAWING_H
