#include "widgets/quadraticequationcalculatorwidget.h"

QuadraticEquationCalculatorWidget::QuadraticEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::QuadraticEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
}

QuadraticEquationCalculatorWidget::~QuadraticEquationCalculatorWidget() {
    delete ui;
}
