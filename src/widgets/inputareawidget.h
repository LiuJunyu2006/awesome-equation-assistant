#pragma once

#include <QtCore/QVector>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

#include "widgets/inputwidget.h"

class InputAreaWidget : public QScrollArea {
    Q_OBJECT

  public:
    InputAreaWidget(QWidget* parent);
    ~InputAreaWidget();

    void init(int row, int column);

  private:
    QGridLayout* gridLayout;
    QVector<QVector<InputWidget*>> inputWidgets;
};
