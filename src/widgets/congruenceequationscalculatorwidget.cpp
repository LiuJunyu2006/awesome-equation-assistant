#include "congruenceequationscalculatorwidget.h"

CongruenceEquationsCalculatorWidget::CongruenceEquationsCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::CongruenceEquationsCalculatorWidgetClass()) {
    ui->setupUi(this);
}

CongruenceEquationsCalculatorWidget::~CongruenceEquationsCalculatorWidget() {
    delete ui;
}

void CongruenceEquationsCalculatorWidget::init(int lines) {
    equations = lines;
    ui->tableWidget->setRowCount(lines);
}
