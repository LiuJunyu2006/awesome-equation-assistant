#include "widgets/zeropointofmonotonicfunctioncalculatorwidget.h"
#include <QtGui/QRegularExpressionValidator>

#include <QtCore/QRegularExpression>
#include <QtWidgets/QButtonGroup>

#include "solutions/solutions.h"

ZeroPointOfMonotonicFunctionCalculatorWidget::ZeroPointOfMonotonicFunctionCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::ZeroPointOfMonotonicFunctionCalculatorWidgetClass()) {
    ui->setupUi(this);

    const auto block = new QButtonGroup(this);
    block->addButton(ui->radioButtonIncrease);
    block->addButton(ui->radioButtonDecrease);

    ui->lineEditL->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditL));
    ui->lineEditR->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditR));
}

ZeroPointOfMonotonicFunctionCalculatorWidget::~ZeroPointOfMonotonicFunctionCalculatorWidget() {
    delete ui;
}

void ZeroPointOfMonotonicFunctionCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    if (ui->lineEditFX->text().isEmpty() || ui->lineEditL->text().isEmpty() || ui->lineEditR->text().isEmpty())
        return;
    ui->widget->addContent(QString::fromUtf8(solveZeroPointOfMonotonicFunction(
        std::string(ui->lineEditFX->text().toLocal8Bit()), Decimal(std::string(ui->lineEditL->text().toLocal8Bit())),
        Decimal(std::string(ui->lineEditR->text().toLocal8Bit())), ui->radioButtonIncrease->isChecked())));
}
