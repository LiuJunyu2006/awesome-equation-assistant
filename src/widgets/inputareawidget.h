#pragma once

#include <QtCore/QString>
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

    void setLabel(int x, int y, const QString& str);

    QString getResult(int x, int y);

  private:
    QGridLayout* gridLayout;
    QWidget* contents;
    QVector<QVector<InputWidget*>> inputWidgets;
};
