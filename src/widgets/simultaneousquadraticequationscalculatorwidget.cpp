#include "widgets/simultaneousquadraticequationscalculatorwidget.h"

#include "solutions/solutions.h"

SimultaneousQuadraticEquationsCalculatorWidget::SimultaneousQuadraticEquationsCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::SimultaneousQuadraticEquationsCalculatorWidgetClass()) {
    ui->setupUi(this);
}

SimultaneousQuadraticEquationsCalculatorWidget::~SimultaneousQuadraticEquationsCalculatorWidget() {
    delete ui;
}

void SimultaneousQuadraticEquationsCalculatorWidget::on_pushButton_clicked() const {
    ui->widget->clearContent();
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
