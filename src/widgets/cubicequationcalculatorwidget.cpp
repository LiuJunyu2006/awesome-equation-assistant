#include "widgets/cubicequationcalculatorwidget.h"

#include <string>

#include "solutions/solutions.h"

CubicEquationCalculatorWidget::CubicEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::CubicEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
}

CubicEquationCalculatorWidget::~CubicEquationCalculatorWidget() {
    delete ui;
}

void CubicEquationCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    ui->widget->addContent(
        QString::fromUtf8(solveCubicEquation(Decimal(std::string(ui->lineEditA->text().toLocal8Bit())),
                                             Decimal(std::string(ui->lineEditB->text().toLocal8Bit())),
                                             Decimal(std::string(ui->lineEditC->text().toLocal8Bit())),
                                             Decimal(std::string(ui->lineEditD->text().toLocal8Bit())))));
}
