#include "widgets/cubicequationcalculatorwidget.h"
#include <QtGui/QRegularExpressionValidator>

#include <QtCore/QRegularExpression>

#include <string>

#include "solutions/solutions.h"

CubicEquationCalculatorWidget::CubicEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::CubicEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
    ui->lineEditA->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditA));
    ui->lineEditB->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditB));
    ui->lineEditC->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditC));
    ui->lineEditD->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditD));
}

CubicEquationCalculatorWidget::~CubicEquationCalculatorWidget() {
    delete ui;
}

void CubicEquationCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    if (ui->lineEditA->text().isEmpty() || ui->lineEditB->text().isEmpty() || ui->lineEditC->text().isEmpty() ||
        ui->lineEditD->text().isEmpty())
        return;
    ui->widget->addContent(
        QString::fromUtf8(solveCubicEquation(Decimal(std::string(ui->lineEditA->text().toLocal8Bit())),
                                             Decimal(std::string(ui->lineEditB->text().toLocal8Bit())),
                                             Decimal(std::string(ui->lineEditC->text().toLocal8Bit())),
                                             Decimal(std::string(ui->lineEditD->text().toLocal8Bit())))));
}
