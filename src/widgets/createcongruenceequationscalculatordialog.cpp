#include "widgets/createcongruenceequationscalculatordialog.h"

CreateCongruenceEquationsCalculatorDialog::CreateCongruenceEquationsCalculatorDialog(MainWindow* parent)
    : QDialog(parent), ui(new Ui::CreateCongruenceEquationsCalculatorDialogClass()) {
    ui->setupUi(this);

    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    connect(this, &CreateCongruenceEquationsCalculatorDialog::createCalculator, parent,
            &MainWindow::generateCongruenceEquationsCalculator);
}

CreateCongruenceEquationsCalculatorDialog::~CreateCongruenceEquationsCalculatorDialog() {
    delete ui;
}

void CreateCongruenceEquationsCalculatorDialog::on_buttonBox_accepted() {
    emit createCalculator(ui->lineEditEquations->text().toInt());
    close();
}

void CreateCongruenceEquationsCalculatorDialog::on_buttonBox_rejected() {
    close();
}