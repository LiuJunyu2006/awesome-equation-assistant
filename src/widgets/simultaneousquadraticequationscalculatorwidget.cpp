#include "widgets/simultaneousquadraticequationscalculatorwidget.h"

SimultaneousQuadraticEquationsCalculatorWidget::SimultaneousQuadraticEquationsCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::SimultaneousQuadraticEquationsCalculatorWidgetClass()) {
    ui->setupUi(this);
}

SimultaneousQuadraticEquationsCalculatorWidget::~SimultaneousQuadraticEquationsCalculatorWidget() {
    delete ui;
}
