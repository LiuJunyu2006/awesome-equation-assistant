#include "congruenceequationscalculatorwidget.h"

CongruenceEquationsCalculatorWidget::CongruenceEquationsCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::CongruenceEquationsCalculatorWidgetClass()) {
    ui->setupUi(this);
    inputArea = new InputAreaWidget(this);
}

CongruenceEquationsCalculatorWidget::~CongruenceEquationsCalculatorWidget() {
    delete ui;
}

void CongruenceEquationsCalculatorWidget::init(int lines) {
    equations = lines;
    inputArea->init(lines, 2);
    ui->gridLayout->replaceWidget(ui->placeholder, inputArea);
}
