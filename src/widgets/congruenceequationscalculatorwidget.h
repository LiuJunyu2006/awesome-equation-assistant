#pragma once

#include "ui_congruenceequationscalculatorwidget.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

#include "widgets/inputareawidget.h"

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

  private slots:
    void on_pushButton_clicked() const;

  private:
    Ui::CongruenceEquationsCalculatorWidgetClass* ui;
    InputAreaWidget* inputArea;
    QGridLayout* gridLayout;

    int equations;
};
