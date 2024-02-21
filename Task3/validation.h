#ifndef VALIDATION_H
#define VALIDATION_H

#include <QMainWindow>
class QLineEdit;
class QPushButton;
class Validation : public QMainWindow
{
    Q_OBJECT

public:
    Validation(QWidget *parent = nullptr);
    ~Validation();
private slots:
    void validate();
private:
    QLineEdit* name;
    QLineEdit* surname;
    QLineEdit* birthday;
    QPushButton* submit;
};
#endif // VALIDATION_H
