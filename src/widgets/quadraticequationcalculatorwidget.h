#ifndef QUADRATICEQUATIONCALCULATORWIDGET_H
#define QUADRATICEQUATIONCALCULATORWIDGET_H

#include <QtQuickWidgets/QQuickWidget>

#include <QtWidgets/QFormLayout>
#include <QtWidgets/QWidget>

class QuadraticEquationCalculatorWidget : public QWidget {
    Q_OBJECT

  public:
    QuadraticEquationCalculatorWidget(QWidget* parent = nullptr);
    ~QuadraticEquationCalculatorWidget();

  private:
    QQuickWidget* widget;
    QFormLayout* layout;
};

#endif  // QUADRATICEQUATIONCALCULATORWIDGET_H
