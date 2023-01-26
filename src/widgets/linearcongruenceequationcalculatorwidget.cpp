#include "widgets/linearcongruenceequationcalculatorwidget.h"
#include <QtGui/QRegularExpressionValidator>

#include <QtCore/QRegularExpression>

#include "solutions/solutions.h"

LinearCongruenceEquationCalculatorWidget::LinearCongruenceEquationCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::LinearCongruenceEquationCalculatorWidgetClass()) {
    ui->setupUi(this);
    ui->lineEditA->setValidator(new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+"), ui->lineEditA));
    ui->lineEditB->setValidator(new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+"), ui->lineEditB));
    ui->lineEditN->setValidator(new QRegularExpressionValidator(QRegularExpression("[+]?[0-9]+"), ui->lineEditN));
}

LinearCongruenceEquationCalculatorWidget::~LinearCongruenceEquationCalculatorWidget() {
    delete ui;
}

void LinearCongruenceEquationCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    if (ui->lineEditA->text().isEmpty() || ui->lineEditB->text().isEmpty() || ui->lineEditN->text().isEmpty())
        return;
    ui->widget->addContent(
        QString::fromUtf8(solveLinearCongruenceEquation(BigInteger(std::string(ui->lineEditA->text().toLocal8Bit())),
                                                        BigInteger(std::string(ui->lineEditB->text().toLocal8Bit())),
                                                        BigInteger(std::string(ui->lineEditN->text().toLocal8Bit())))));
}
