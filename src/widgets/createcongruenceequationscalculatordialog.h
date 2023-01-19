#pragma once

#include "ui_createcongruenceequationscalculatordialog.h"

#include <QtWidgets/QDialog>

#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CreateCongruenceEquationsCalculatorDialogClass;
};
QT_END_NAMESPACE

class CreateCongruenceEquationsCalculatorDialog : public QDialog {
    Q_OBJECT

  public:
    CreateCongruenceEquationsCalculatorDialog(MainWindow* parent = nullptr);
    ~CreateCongruenceEquationsCalculatorDialog();

  signals:
    void createCalculator(int equations);

  private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

  private:
    Ui::CreateCongruenceEquationsCalculatorDialogClass* ui;
};
