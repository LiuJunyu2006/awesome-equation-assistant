#include "widgets/systemoflinearequationscalculatorwidget.h"

#include <QtWidgets/QTableWidgetItem>

#include "solutions/solutions.h"

QString toSubscript(const QString& str) {
    QString res;
    for (const auto& ch : str) {
        switch (ch.toLatin1()) {
            case '0':
                res += QString::fromUtf8("\342\202\200");
                break;
            case '1':
                res += QString::fromUtf8("\342\202\201");
                break;
            case '2':
                res += QString::fromUtf8("\342\202\202");
                break;
            case '3':
                res += QString::fromUtf8("\342\202\203");
                break;
            case '4':
                res += QString::fromUtf8("\342\202\204");
                break;
            case '5':
                res += QString::fromUtf8("\342\202\205");
                break;
            case '6':
                res += QString::fromUtf8("\342\202\206");
                break;
            case '7':
                res += QString::fromUtf8("\342\202\207");
                break;
            case '8':
                res += QString::fromUtf8("\342\202\210");
                break;
            case '9':
                res += QString::fromUtf8("\342\202\211");
                break;
        }
    }
    return res;
}

QString toSuperscript(const QString& str) {
    QString res;
    for (const auto& ch : str) {
        switch (ch.toLatin1()) {
            case '0':
                res += QString::fromUtf8("\342\201\260");
                break;
            case '1':
                res += QString::fromUtf8("\342\201\261");
                break;
            case '2':
                res += QString::fromUtf8("\342\201\262");
                break;
            case '3':
                res += QString::fromUtf8("\342\201\263");
                break;
            case '4':
                res += QString::fromUtf8("\342\201\264");
                break;
            case '5':
                res += QString::fromUtf8("\342\201\265");
                break;
            case '6':
                res += QString::fromUtf8("\342\201\266");
                break;
            case '7':
                res += QString::fromUtf8("\342\201\267");
                break;
            case '8':
                res += QString::fromUtf8("\342\201\270");
                break;
            case '9':
                res += QString::fromUtf8("\342\201\271");
                break;
        }
    }
    return res;
}

SystemOfLinearEquationsCalculatorWidget::SystemOfLinearEquationsCalculatorWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::SystemOfLinearEquationsCalculatorWidgetClass()), unknowns(0), equations(0) {
    ui->setupUi(this);
}

SystemOfLinearEquationsCalculatorWidget::~SystemOfLinearEquationsCalculatorWidget() {
    delete ui;
}

void SystemOfLinearEquationsCalculatorWidget::init(int nums, int lines) {
    /*unknowns = nums;
    equations = lines;
    int columns = nums + 1;
    generateTip();
    ui->tableWidget->setColumnCount(columns);
    for (int i = 1; i <= unknowns; ++i) {
        auto item = new QTableWidgetItem();
        item->setText(QString("a" + toSubscript(QString::number(i))).arg(i));
        ui->tableWidget->setHorizontalHeaderItem(i - 1, item);
    }
    {
        auto item = new QTableWidgetItem();
        item->setText("b");
        ui->tableWidget->setHorizontalHeaderItem(unknowns, item);
    }
    ui->tableWidget->setRowCount(lines);*/
}

void SystemOfLinearEquationsCalculatorWidget::generateTip() const {
    /*QString tip("<html><head/><body><p>%1</p></body></html>");
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
    ui->label->setText(tip);*/
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
    ui->widget->clearContent();
    // ui->widget->addContent(solveSystemOfLinearEquations(vec));
}
