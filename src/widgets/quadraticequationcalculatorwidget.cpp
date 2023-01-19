#include "widgets/quadraticequationcalculatorwidget.h"

#include <string>

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
    ui->widget->addContent(
        QString::fromUtf8(solveQuadraticEquation(Expression(std::string(ui->lineEditA->text().toLocal8Bit())),
                                                 Expression(std::string(ui->lineEditB->text().toLocal8Bit())),
                                                 Expression(std::string(ui->lineEditC->text().toLocal8Bit())))));
}