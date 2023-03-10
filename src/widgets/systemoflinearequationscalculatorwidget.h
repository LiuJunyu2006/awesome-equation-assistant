#pragma once

#include "ui_systemoflinearequationscalculatorwidget.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

#include "widgets/inputareawidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SystemOfLinearEquationsCalculatorWidgetClass;
};
QT_END_NAMESPACE

class SystemOfLinearEquationsCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    SystemOfLinearEquationsCalculatorWidget(QWidget* parent = nullptr);
    ~SystemOfLinearEquationsCalculatorWidget() override;

    void init(int nums, int lines);

  private slots:
    void on_pushButton_clicked() const;

  private:
    Ui::SystemOfLinearEquationsCalculatorWidgetClass* ui;
    InputAreaWidget* inputArea;
    QGridLayout* gridLayout;

    int unknowns, equations;

    void generateTip() const;
};
