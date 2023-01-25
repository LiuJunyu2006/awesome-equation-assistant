#include "congruenceequationscalculatorwidget.h"

#include "solutions/solutions.h"

CongruenceEquationsCalculatorWidget::CongruenceEquationsCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::CongruenceEquationsCalculatorWidgetClass()) {
    ui->setupUi(this);
    inputArea = new InputAreaWidget(this);
    gridLayout = new QGridLayout(this);
}

CongruenceEquationsCalculatorWidget::~CongruenceEquationsCalculatorWidget() {
    delete ui;
}

void CongruenceEquationsCalculatorWidget::init(int lines) {
    equations = lines;
    inputArea->init(lines, 2);
    for (int i = 1; i <= lines; ++i) {
        inputArea->setLabel(
            i - 1, 0,
            QString("<html><head/><body><p>a<span style=\" vertical-align:sub;\">%1</span>=</p></body></html>").arg(i));
        inputArea->setLabel(
            i - 1, 1,
            QString("<html><head/><body><p>n<span style=\" vertical-align:sub;\">%1</span>=</p></body></html>").arg(i));
    }
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->addWidget(ui->label, 0, 0, 1, 1);
    gridLayout->addWidget(ui->pushButton, 1, 0, 1, 1);
    gridLayout->addWidget(inputArea, 2, 0, 1, 1);
    gridLayout->addWidget(ui->widget, 3, 0, 1, 1);
}

void CongruenceEquationsCalculatorWidget::on_pushButton_clicked() const {
    std::vector<std::pair<BigInteger, BigInteger>> vec;
    for (int i = 0; i < equations; ++i) {
        vec.emplace_back(BigInteger(std::string(inputArea->getResult(i, 0).toLocal8Bit())),
                         BigInteger(std::string(inputArea->getResult(i, 1).toLocal8Bit())));
    }
    ui->widget->clearContent();
    ui->widget->addContent(QString::fromUtf8(solveCongruenceEquations(equations, vec)));
}
