#include "widgets/quarticequationcalculatorwidget.h"
#include <QtGui/QRegularExpressionValidator>

#include <QtCore/QRegularExpression>

#include "solutions/solutions.h"

QuarticEquationCalculatorWidget::QuarticEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::QuarticEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
    ui->lineEditA->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditA));
    ui->lineEditB->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditB));
    ui->lineEditC->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditC));
    ui->lineEditD->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditD));
    ui->lineEditE->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+(.[0-9]+)?"), ui->lineEditE));
}

QuarticEquationCalculatorWidget::~QuarticEquationCalculatorWidget() {
    delete ui;
}

void QuarticEquationCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    if (ui->lineEditA->text().isEmpty() || ui->lineEditB->text().isEmpty() || ui->lineEditC->text().isEmpty() ||
        ui->lineEditD->text().isEmpty() || ui->lineEditE->text().isEmpty())
        return;
    ui->widget->addContent(
        QString::fromUtf8(solveQuarticEquation(Decimal(std::string(ui->lineEditA->text().toLocal8Bit())),
                                               Decimal(std::string(ui->lineEditB->text().toLocal8Bit())),
                                               Decimal(std::string(ui->lineEditC->text().toLocal8Bit())),
                                               Decimal(std::string(ui->lineEditD->text().toLocal8Bit())),
                                               Decimal(std::string(ui->lineEditE->text().toLocal8Bit())))));
}
