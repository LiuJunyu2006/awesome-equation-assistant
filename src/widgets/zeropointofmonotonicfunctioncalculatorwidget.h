#pragma once

#include "ui_zeropointofmonotonicfunctioncalculatorwidget.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ZeroPointOfMonotonicFunctionCalculatorWidgetClass;
};
QT_END_NAMESPACE

class ZeroPointOfMonotonicFunctionCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    ZeroPointOfMonotonicFunctionCalculatorWidget(QWidget* parent = nullptr);
    ~ZeroPointOfMonotonicFunctionCalculatorWidget() override;

  private slots:
    void on_pushButton_clicked() const;

  private:
    Ui::ZeroPointOfMonotonicFunctionCalculatorWidgetClass* ui;
};
