#include "widgets/createsystemoflinearequationscalculatordialog.h"

CreateSystemOfLinearEquationsCalculatorDialog::CreateSystemOfLinearEquationsCalculatorDialog(MainWindow* parent)
    : QDialog(parent), ui(new Ui::CreateSystemOfLinearEquationsCalculatorDialogClass()) {
    ui->setupUi(this);

    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    connect(this, &CreateSystemOfLinearEquationsCalculatorDialog::createCalculator, parent,
            &MainWindow::generateSystemOfLinearEquationsCalculator);
}

CreateSystemOfLinearEquationsCalculatorDialog::~CreateSystemOfLinearEquationsCalculatorDialog() {
    delete ui;
}

void CreateSystemOfLinearEquationsCalculatorDialog::on_buttonBox_accepted() {
    emit createCalculator(ui->lineEditUnknowns->text().toInt(), ui->lineEditEquations->text().toInt());
    close();
}

void CreateSystemOfLinearEquationsCalculatorDialog::on_buttonBox_rejected() {
    close();
}