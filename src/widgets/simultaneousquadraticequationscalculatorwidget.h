#pragma once

#include "ui_simultaneousquadraticequationscalculatorwidget.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class SimultaneousQuadraticEquationsCalculatorWidgetClass;
};
QT_END_NAMESPACE

class SimultaneousQuadraticEquationsCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    SimultaneousQuadraticEquationsCalculatorWidget(QWidget* parent = nullptr);
    ~SimultaneousQuadraticEquationsCalculatorWidget() override;

  private slots:
    void on_pushButton_clicked() const;

  private:
    Ui::SimultaneousQuadraticEquationsCalculatorWidgetClass* ui;
};
