#ifndef CONVERTER_H
#define CONVERTER_H

#include <QMainWindow>
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;

class Converter : public QMainWindow
{
    Q_OBJECT

public:
    Converter(QWidget *parent = nullptr);
    ~Converter();
private slots:
    void convert();

private:
    QLabel* currentType;
    QLabel* convertedType;
    QLineEdit* myMoney;
    QLabel* convertedMoney;
    QComboBox* type1;
    QComboBox* type2;
    QPushButton* convertBtn;
};
#endif // CONVERTER_H
