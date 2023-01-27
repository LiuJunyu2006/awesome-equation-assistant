#pragma once

#include <QtCore/QString>
#include <QtCore/QVector>
#include <QtCore/QRegularExpression>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

#include "widgets/inputwidget.h"

class InputAreaWidget : public QScrollArea {
    Q_OBJECT

  public:
    InputAreaWidget(QWidget* parent);
    ~InputAreaWidget() override;

    void init(int row, int column);

    void setLabel(int x, int y, const QString& str);

    void setLabelValidator(int x, int y, const QRegularExpression& re);

    QString getResult(int x, int y);

  private:
    QGridLayout* gridLayout;
    QWidget* contents;
    QVector<QVector<InputWidget*>> inputWidgets;
};
