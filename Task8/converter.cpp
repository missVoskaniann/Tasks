#include "converter.h"

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QMessageBox>

Converter::Converter(QWidget *parent)
    : QMainWindow(parent)
{
    currentType = new QLabel("From:", this);
    convertedType = new QLabel("To:", this);

    myMoney = new QLineEdit();
    myMoney->setPlaceholderText("Enter amount");
    convertedMoney = new QLabel("Converted amount");

    type1 = new QComboBox();
    type1->addItem("AMD");
    type1->addItem("USD");
    type1->addItem("RU");
    type1->setPlaceholderText(QStringLiteral("Choose"));
    type1->setCurrentIndex(-1);

    type2 = new QComboBox();
    type2->addItem("AMD");
    type2->addItem("USD");
    type2->addItem("RU");
    type2->setPlaceholderText(QStringLiteral("Choose"));
    type2->setCurrentIndex(-1);

    convertBtn = new QPushButton("convert", this);
    connect(convertBtn, &QPushButton::clicked, this, &Converter::convert);

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(currentType, 0, 0);
    layout->addWidget(type1, 0, 1);
    layout->addWidget(convertedType, 1, 0);
    layout->addWidget(type2, 1, 1);
    layout->addWidget(myMoney, 2, 0, 1, 2);
    layout->addWidget(convertBtn, 4, 0, 1, 2);
    layout->addWidget(convertedMoney, 3, 0, 1, 2);

    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

Converter::~Converter() = default;

void Converter::convert() {
    if (type1->currentIndex() == -1 || type2->currentIndex() == -1) {
        QMessageBox::warning(this, "Error", "Please select both currencies.");
        return;
    }

    QString inputAmountString = myMoney->text();
    bool ok;

    double inputAmount = inputAmountString.toDouble(&ok);
    if (!ok || inputAmount <= 0) {
        QMessageBox::warning(this, "Error", "Invalid input amount.");
        return;
    }

    double conversionRateAMD_USD = 407.40;
    double conversionRateAMD_RU = 4.28;
    double conversionRateUSD_RU = 93.06;

    double convertedAmount;
    if (type1->currentText() == "AMD" && type2->currentText() == "USD") {
        convertedAmount = inputAmount / conversionRateAMD_USD;
    } else if (type1->currentText() == "AMD" && type2->currentText() == "RU") {
        convertedAmount = inputAmount / conversionRateAMD_RU;
    } else if (type1->currentText() == "USD" && type2->currentText() == "AMD") {
        convertedAmount = inputAmount * conversionRateAMD_USD;
    } else if (type1->currentText() == "USD" && type2->currentText() == "RU") {
        convertedAmount = inputAmount * conversionRateUSD_RU;
    } else if (type1->currentText() == "RU" && type2->currentText() == "AMD") {
        convertedAmount = inputAmount * conversionRateAMD_RU;
    } else if (type1->currentText() == "RU" && type2->currentText() == "USD") {
        convertedAmount = inputAmount / conversionRateUSD_RU;
    } else {
        convertedAmount = inputAmount;
    }
    convertedMoney->setText(QString::number(convertedAmount));
}

