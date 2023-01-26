#include "widgets/createcongruenceequationscalculatordialog.h"
#include <QtGui/QIntValidator>

#include <QtCore/QRegularExpression>

CreateCongruenceEquationsCalculatorDialog::CreateCongruenceEquationsCalculatorDialog(MainWindow* parent)
    : QDialog(parent), ui(new Ui::CreateCongruenceEquationsCalculatorDialogClass()) {
    ui->setupUi(this);

    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    connect(this, &CreateCongruenceEquationsCalculatorDialog::createCalculator, parent,
            &MainWindow::generateCongruenceEquationsCalculator);

    ui->lineEditEquations->setValidator(new QIntValidator(1, 99, ui->lineEditEquations));
}

CreateCongruenceEquationsCalculatorDialog::~CreateCongruenceEquationsCalculatorDialog() {
    delete ui;
}

void CreateCongruenceEquationsCalculatorDialog::on_buttonBox_accepted() {
    if (ui->lineEditEquations->text().toInt() == 0)
        return;
    emit createCalculator(ui->lineEditEquations->text().toInt());
    close();
}

void CreateCongruenceEquationsCalculatorDialog::on_buttonBox_rejected() {
    close();
}