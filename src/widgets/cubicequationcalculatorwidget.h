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
    ~CubicEquationCalculatorWidget() override;

  private slots:
    void on_pushButton_clicked() const;

  private:
    Ui::CubicEquationCalculatorWidgetClass* ui;
};
