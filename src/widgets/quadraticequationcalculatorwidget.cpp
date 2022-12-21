#include "widgets/quadraticequationcalculatorwidget.h"

#include "solutions/solutions.h"

QuadraticEquationCalculatorWidget::QuadraticEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::QuadraticEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
}

QuadraticEquationCalculatorWidget::~QuadraticEquationCalculatorWidget() {
    delete ui;
}

void QuadraticEquationCalculatorWidget::on_pushButton_clicked() {
    ui->widget->clearContent();
    ui->widget->addContent(solveQuadraticEquation(Fraction(ui->lineEditA->text()), Fraction(ui->lineEditB->text()),
                                                  Fraction(ui->lineEditC->text())));
}