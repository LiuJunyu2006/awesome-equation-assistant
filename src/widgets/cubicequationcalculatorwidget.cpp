#include "widgets/cubicequationcalculatorwidget.h"

CubicEquationCalculatorWidget::CubicEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::CubicEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
}

CubicEquationCalculatorWidget::~CubicEquationCalculatorWidget() {
    delete ui;
}
