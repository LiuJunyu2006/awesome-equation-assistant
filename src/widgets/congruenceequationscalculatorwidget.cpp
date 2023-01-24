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
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->addWidget(ui->label, 0, 0, 1, 1);
    gridLayout->addWidget(ui->pushButton, 1, 0, 1, 1);
    gridLayout->addWidget(inputArea, 2, 0, 1, 1);
    gridLayout->addWidget(ui->widget, 3, 0, 1, 1);
}

void CongruenceEquationsCalculatorWidget::on_pushButton_clicked() const {
    // QVector<QVector<Fraction>> vec(equations);
    // for (int i = 0; i < equations; ++i) {
    //     vec[i].resize(unknowns + 1);
    //     for (int j = 0; j < unknowns + 1; ++j) {
    //         QString str = ui->tableWidget->item(i, j)->text();
    //         vec[i][j] = Fraction(str);
    //     }
    // }
    ui->widget->clearContent();
    // ui->widget->addContent(solveSystemOfLinearEquations(vec));
}
