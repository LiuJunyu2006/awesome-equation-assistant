#include "widgets/linearcongruenceequationcalculatorwidget.h"

LinearCongruenceEquationCalculatorWidget::LinearCongruenceEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::LinearCongruenceEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
}

LinearCongruenceEquationCalculatorWidget::~LinearCongruenceEquationCalculatorWidget() {
    delete ui;
}
