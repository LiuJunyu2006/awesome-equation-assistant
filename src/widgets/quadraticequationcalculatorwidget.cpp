#include "widgets/quadraticequationcalculatorwidget.h"
#include <QtGui/QRegularExpressionValidator>

#include <QtCore/QRegularExpression>

#include <string>

#include "solutions/solutions.h"

QuadraticEquationCalculatorWidget::QuadraticEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::QuadraticEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
    ui->lineEditA->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditA));
    ui->lineEditB->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditB));
    ui->lineEditC->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditC));
}

QuadraticEquationCalculatorWidget::~QuadraticEquationCalculatorWidget() {
    delete ui;
}

void QuadraticEquationCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    if (ui->lineEditA->text().isEmpty() || ui->lineEditB->text().isEmpty() || ui->lineEditC->text().isEmpty())
        return;
    ui->widget->addContent(
        QString::fromUtf8(solveQuadraticEquation(Expression(std::string(ui->lineEditA->text().toLocal8Bit())),
                                                 Expression(std::string(ui->lineEditB->text().toLocal8Bit())),
                                                 Expression(std::string(ui->lineEditC->text().toLocal8Bit())))));
}
