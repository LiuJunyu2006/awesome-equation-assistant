#pragma once

#include "ui_quarticequationcalculatorwidget.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class QuarticEquationCalculatorWidgetClass;
};
QT_END_NAMESPACE

class QuarticEquationCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    QuarticEquationCalculatorWidget(QWidget* parent = nullptr);
    ~QuarticEquationCalculatorWidget();

  private:
    Ui::QuarticEquationCalculatorWidgetClass* ui;
};
