#pragma once

#include "ui_cubicequationcalculatorwidget.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class CubicEquationCalculatorWidgetClass;
};
QT_END_NAMESPACE

class CubicEquationCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    CubicEquationCalculatorWidget(QWidget* parent = nullptr);
    ~CubicEquationCalculatorWidget();

  private:
    Ui::CubicEquationCalculatorWidgetClass* ui;
};
