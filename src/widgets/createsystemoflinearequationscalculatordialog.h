#pragma once

#include "ui_createsystemoflinearequationscalculatordialog.h"

#include <QtWidgets/QDialog>

#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CreateSystemOfLinearEquationsCalculatorDialogClass;
};
QT_END_NAMESPACE

class CreateSystemOfLinearEquationsCalculatorDialog : public QDialog {
    Q_OBJECT

  public:
    CreateSystemOfLinearEquationsCalculatorDialog(MainWindow* parent = nullptr);
    ~CreateSystemOfLinearEquationsCalculatorDialog() override;

  signals:
    void createCalculator(int unknowns, int equations);

  private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

  private:
    Ui::CreateSystemOfLinearEquationsCalculatorDialogClass* ui;
};
