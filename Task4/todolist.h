#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>

class QLineEdit;
class QListWidget;
class QPushButton;

class ToDoList : public QMainWindow
{
    Q_OBJECT

public:
    ToDoList(QWidget *parent = nullptr);
    ~ToDoList();
private slots:
    void add();
    void remove();
private:
    QPushButton* addB;
    QPushButton* removeB;
    QLineEdit* input;
    QListWidget* list;
};
#endif // TODOLIST_H
