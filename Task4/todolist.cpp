#include "todolist.h"
#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QGridLayout>

ToDoList::ToDoList(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("My Todo List");
    addB = new QPushButton("Add", this);
    removeB = new QPushButton("Remove", this);

    connect(addB, &QPushButton::clicked, this, &ToDoList::add);
    connect(removeB, &QPushButton::clicked, this, &ToDoList::remove);

    input = new QLineEdit(this);
    list = new QListWidget(this);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(input, 0, 0, 1, 2);
    layout->addWidget(list, 1, 0, 1, 2);
    layout->addWidget(addB, 2, 0);
    layout->addWidget(removeB, 2, 1);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

ToDoList::~ToDoList() = default;

void ToDoList::add() {
    QString task = input->text();
    if (task.length() > 0) {
        list->addItem(task);
        input->clear();
    }
}

void ToDoList::remove() {
    qDeleteAll(list->selectedItems());
    QListWidgetItem *select = list->currentItem();
    if (select) {
        delete select;
    }
}
