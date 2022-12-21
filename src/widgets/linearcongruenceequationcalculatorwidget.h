#pragma once

#include "ui_linearcongruenceequationcalculatorwidget.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class LinearCongruenceEquationCalculatorWidgetClass;
};
QT_END_NAMESPACE

class LinearCongruenceEquationCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    LinearCongruenceEquationCalculatorWidget(QWidget* parent = nullptr);
    ~LinearCongruenceEquationCalculatorWidget();

  private:
    Ui::LinearCongruenceEquationCalculatorWidgetClass* ui;
};
