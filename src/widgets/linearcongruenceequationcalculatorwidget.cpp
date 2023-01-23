#include "widgets/linearcongruenceequationcalculatorwidget.h"

#include "solutions/solutions.h"

LinearCongruenceEquationCalculatorWidget::LinearCongruenceEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::LinearCongruenceEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
}

LinearCongruenceEquationCalculatorWidget::~LinearCongruenceEquationCalculatorWidget() {
    delete ui;
}

void LinearCongruenceEquationCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    ui->widget->addContent(
        QString::fromUtf8(solveLinearCongruenceEquation(BigInteger(std::string(ui->lineEditA->text().toLocal8Bit())),
                                                        BigInteger(std::string(ui->lineEditB->text().toLocal8Bit())),
                                                        BigInteger(std::string(ui->lineEditN->text().toLocal8Bit())))));
}
