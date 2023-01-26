#include "widgets/simultaneousquadraticequationscalculatorwidget.h"
#include <QtGui/QRegularExpressionValidator>

#include <QtCore/QRegularExpression>

#include "solutions/solutions.h"

SimultaneousQuadraticEquationsCalculatorWidget::SimultaneousQuadraticEquationsCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::SimultaneousQuadraticEquationsCalculatorWidgetClass()) {
    ui->setupUi(this);
    ui->lineEditA1->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditA1));
    ui->lineEditB1->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditB1));
    ui->lineEditC1->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditC1));
    ui->lineEditD1->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditD1));
    ui->lineEditE1->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditE1));
    ui->lineEditF1->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditF1));
    ui->lineEditA2->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditA2));
    ui->lineEditB2->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditB2));
    ui->lineEditC2->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditC2));
    ui->lineEditD2->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditD2));
    ui->lineEditE2->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditE2));
    ui->lineEditF2->setValidator(
        new QRegularExpressionValidator(QRegularExpression("[+-]?[0-9]+((/[0-9]+)|(.[0-9]+))?"), ui->lineEditF2));
}

SimultaneousQuadraticEquationsCalculatorWidget::~SimultaneousQuadraticEquationsCalculatorWidget() {
    delete ui;
}

void SimultaneousQuadraticEquationsCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
    if (ui->lineEditA1->text().isEmpty() || ui->lineEditB1->text().isEmpty() || ui->lineEditC1->text().isEmpty() ||
        ui->lineEditD1->text().isEmpty() || ui->lineEditE1->text().isEmpty() || ui->lineEditF1->text().isEmpty() ||
        ui->lineEditA2->text().isEmpty() || ui->lineEditB2->text().isEmpty() || ui->lineEditC2->text().isEmpty() ||
        ui->lineEditD2->text().isEmpty() || ui->lineEditE2->text().isEmpty() || ui->lineEditF2->text().isEmpty())
        return;
    ui->widget->addContent(QString::fromUtf8(
        solveSimultaneousQuadraticEquations(Expression(std::string(ui->lineEditA1->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditB1->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditC1->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditD1->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditE1->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditF1->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditA2->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditB2->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditC2->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditD2->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditE2->text().toLocal8Bit())),
                                            Expression(std::string(ui->lineEditF2->text().toLocal8Bit())))));
}
