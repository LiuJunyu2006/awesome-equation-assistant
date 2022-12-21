#pragma once

#include "ui_systemoflinearequationscalculatorwidget.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class SystemOfLinearEquationsCalculatorWidgetClass;
};
QT_END_NAMESPACE

class SystemOfLinearEquationsCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    SystemOfLinearEquationsCalculatorWidget(QWidget* parent = nullptr);
    ~SystemOfLinearEquationsCalculatorWidget();

    void init(int nums, int lines);

  private slots:
    void on_pushButton_clicked();

  private:
    Ui::SystemOfLinearEquationsCalculatorWidgetClass* ui;

    int unknowns, equations;

    void generateTip();
};
