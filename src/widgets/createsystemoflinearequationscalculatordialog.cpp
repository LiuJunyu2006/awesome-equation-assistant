#include "widgets/createsystemoflinearequationscalculatordialog.h"
#include <QtGui/QIntValidator>

#include <QtCore/QRegularExpression>

CreateSystemOfLinearEquationsCalculatorDialog::CreateSystemOfLinearEquationsCalculatorDialog(MainWindow* parent)
    : QDialog(parent), ui(new Ui::CreateSystemOfLinearEquationsCalculatorDialogClass()) {
    ui->setupUi(this);

    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    connect(this, &CreateSystemOfLinearEquationsCalculatorDialog::createCalculator, parent,
            &MainWindow::generateSystemOfLinearEquationsCalculator);

    ui->lineEditEquations->setValidator(new QIntValidator(1, 99, ui->lineEditEquations));
    ui->lineEditUnknowns->setValidator(new QIntValidator(1, 99, ui->lineEditUnknowns));
}

CreateSystemOfLinearEquationsCalculatorDialog::~CreateSystemOfLinearEquationsCalculatorDialog() {
    delete ui;
}

void CreateSystemOfLinearEquationsCalculatorDialog::on_buttonBox_accepted() {
    if (ui->lineEditEquations->text().toInt() == 0 || ui->lineEditUnknowns->text().toInt() == 0)
        return;
    emit createCalculator(ui->lineEditUnknowns->text().toInt(), ui->lineEditEquations->text().toInt());
    close();
}

void CreateSystemOfLinearEquationsCalculatorDialog::on_buttonBox_rejected() {
    close();
}