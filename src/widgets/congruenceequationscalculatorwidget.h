#pragma once

#include "ui_congruenceequationscalculatorwidget.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class CongruenceEquationsCalculatorWidgetClass;
};
QT_END_NAMESPACE

class CongruenceEquationsCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    CongruenceEquationsCalculatorWidget(QWidget* parent = nullptr);
    ~CongruenceEquationsCalculatorWidget();

    void init(int lines);

  private:
    Ui::CongruenceEquationsCalculatorWidgetClass* ui;

    int equations;
};
