#include "widgets/quarticequationcalculatorwidget.h"

#include "solutions/solutions.h"

QuarticEquationCalculatorWidget::QuarticEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::QuarticEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
}

QuarticEquationCalculatorWidget::~QuarticEquationCalculatorWidget() {
    delete ui;
}

void QuarticEquationCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    ui->widget->addContent(
        QString::fromUtf8(solveQuarticEquation(Decimal(std::string(ui->lineEditA->text().toLocal8Bit())),
                                               Decimal(std::string(ui->lineEditB->text().toLocal8Bit())),
                                               Decimal(std::string(ui->lineEditC->text().toLocal8Bit())),
                                               Decimal(std::string(ui->lineEditD->text().toLocal8Bit())),
                                               Decimal(std::string(ui->lineEditE->text().toLocal8Bit())))));
}
