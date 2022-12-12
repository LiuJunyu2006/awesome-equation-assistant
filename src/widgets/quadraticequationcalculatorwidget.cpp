#include "quadraticequationcalculatorwidget.h"

#include <QtCore/QUrl>

QuadraticEquationCalculatorWidget::QuadraticEquationCalculatorWidget(QWidget* parent) : QWidget(parent) {
    widget = new QQuickWidget(this);
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    widget->setSource(QUrl("qrc:/qml/quadraticequationcalculatorview.qml"));
    layout = new QFormLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setWidget(0, QFormLayout::SpanningRole, widget);
}

QuadraticEquationCalculatorWidget::~QuadraticEquationCalculatorWidget() {}
