#include "widgets/zeropointofmonotonicfunctioncalculatorwidget.h"

#include <QButtonGroup>

#include "solutions/solutions.h"

ZeroPointOfMonotonicFunctionCalculatorWidget::ZeroPointOfMonotonicFunctionCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::ZeroPointOfMonotonicFunctionCalculatorWidgetClass()) {
    ui->setupUi(this);

    auto block = new QButtonGroup(this);
    block->addButton(ui->radioButtonIncrease);
    block->addButton(ui->radioButtonDecrease);
}

ZeroPointOfMonotonicFunctionCalculatorWidget::~ZeroPointOfMonotonicFunctionCalculatorWidget() {
    delete ui;
}

void ZeroPointOfMonotonicFunctionCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    ui->widget->addContent(QString::fromUtf8(solveZeroPointOfMonotonicFunction(
        std::string(ui->lineEditFX->text().toLocal8Bit()), Decimal(std::string(ui->lineEditL->text().toLocal8Bit())),
        Decimal(std::string(ui->lineEditR->text().toLocal8Bit())), ui->radioButtonIncrease->isChecked())));
}
