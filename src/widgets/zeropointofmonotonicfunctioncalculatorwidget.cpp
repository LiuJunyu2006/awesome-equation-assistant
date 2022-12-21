#include "zeropointofmonotonicfunctioncalculatorwidget.h"

ZeroPointOfMonotonicFunctionCalculatorWidget::ZeroPointOfMonotonicFunctionCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::ZeroPointOfMonotonicFunctionCalculatorWidgetClass()) {
    ui->setupUi(this);
}

ZeroPointOfMonotonicFunctionCalculatorWidget::~ZeroPointOfMonotonicFunctionCalculatorWidget() {
    delete ui;
}

void ZeroPointOfMonotonicFunctionCalculatorWidget::on_pushButton_clicked() {}