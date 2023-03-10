#pragma once

#include "ui_quadraticequationcalculatorwidget.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class QuadraticEquationCalculatorWidgetClass;
};
QT_END_NAMESPACE

class QuadraticEquationCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    QuadraticEquationCalculatorWidget(QWidget* parent = nullptr);
    ~QuadraticEquationCalculatorWidget() override;

  private slots:
    void on_pushButton_clicked() const;

  private:
    Ui::QuadraticEquationCalculatorWidgetClass* ui;
};
