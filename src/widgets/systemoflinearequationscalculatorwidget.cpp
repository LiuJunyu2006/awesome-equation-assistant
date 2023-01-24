#include "widgets/systemoflinearequationscalculatorwidget.h"

#include <sstream>
#include <vector>

#include "solutions/solutions.h"

SystemOfLinearEquationsCalculatorWidget::SystemOfLinearEquationsCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::SystemOfLinearEquationsCalculatorWidgetClass()), unknowns(0), equations(0) {
    ui->setupUi(this);
    inputArea = new InputAreaWidget(this);
    gridLayout = new QGridLayout(this);
}

SystemOfLinearEquationsCalculatorWidget::~SystemOfLinearEquationsCalculatorWidget() {
    delete ui;
}

void SystemOfLinearEquationsCalculatorWidget::init(int nums, int lines) {
    unknowns = nums;
    equations = lines;
    int columns = nums + 1;
    generateTip();
    inputArea->init(lines, columns);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->addWidget(ui->label, 0, 0, 1, 1);
    gridLayout->addWidget(ui->pushButton, 1, 0, 1, 1);
    gridLayout->addWidget(inputArea, 2, 0, 1, 1);
    gridLayout->addWidget(ui->widget, 3, 0, 1, 1);
}

void SystemOfLinearEquationsCalculatorWidget::generateTip() const {
    QString tip("<html><head/><body><p>%1</p></body></html>");
    for (int i = 1; i <= equations; ++i) {
        tip = tip.arg(
            QString(R"(a<span style="vertical-align:sub;">i,%1</span>x<span style="vertical-align:sub;">i,%1</span>)")
                .arg(i) +
            "%1");
        if (i < equations)
            tip = tip.arg("+%1");
        else
            tip = tip.arg("=%1");
    }
    tip = tip.arg(R"(b<span style="vertical-align:sub;">i</span>)");
    ui->label->setText(tip);
}

void SystemOfLinearEquationsCalculatorWidget::on_pushButton_clicked() const {
    // QVector<QVector<Fraction>> vec(equations);
    // for (int i = 0; i < equations; ++i) {
    //     vec[i].resize(unknowns + 1);
    //     for (int j = 0; j < unknowns + 1; ++j) {
    //         QString str = ui->tableWidget->item(i, j)->text();
    //         vec[i][j] = Fraction(str);
    //     }
    // }
    std::vector<std::vector<Rational>> vec;
    int lines = equations;
    int columns = unknowns + 1;
    vec.resize(equations);
    for (int i = 0; i < lines; ++i)
        for (int j = 0; j < columns; ++j) {
            std::stringstream ss(std::string(inputArea->getResult(i, j).toLocal8Bit()));
            Rational r;
            ss >> r;
            vec[i].push_back(r);
        }
    ui->widget->clearContent();
    ui->widget->addContent(QString::fromUtf8(solveSystemOfLinearEquations(unknowns, equations, vec)));
}
