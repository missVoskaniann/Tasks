#include "validation.h"
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QMessageBox>
#include <QWidget>
#include <QLabel>
#include <QFont>

Validation::Validation(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Simple Validator");
    QLabel* label = new QLabel("This is validation program", this);
    QFont font = label->font();
    font.setPointSize(24);
    label->setFont(font);

    submit = new QPushButton("Submit", this);
    name = new QLineEdit(this);
    surname = new QLineEdit(this);
    birthday = new QLineEdit(this);

    QLabel* nameLabel = new QLabel("Enter your name: ", this);
    QLabel* surnameLabel = new QLabel("Enter your surname: ", this);
    QLabel* birthdayLabel = new QLabel("Enter your birthday: ", this);

    connect(submit, &QPushButton::clicked, this, &Validation::validate);

    QFormLayout* layout = new QFormLayout();
    layout->addWidget(label);
    layout->addRow(nameLabel, name);
    layout->addRow(surnameLabel, surname);
    layout->addRow(birthdayLabel, birthday);
    layout->addWidget(submit);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

Validation::~Validation() = default;

void Validation::validate() {
    if (name->text().isEmpty() || surname->text().isEmpty() || birthday->text().isEmpty()) {
        QMessageBox m;
        m.setIcon(QMessageBox::Critical);
        m.setText("ERROR! Fill all fields.");
        m.exec();
    } else {
        QMessageBox m;
        m.setIcon(QMessageBox::Information);
        m.setText("SUCCESS! Validated!");
        m.exec();
    }
}

