#pragma once

#include "ui_aboutwidget.h"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class AboutWidgetClass;
};
QT_END_NAMESPACE

class AboutWidget : public QDialog {
    Q_OBJECT

  public:
    AboutWidget(QWidget* parent = nullptr);
    ~AboutWidget();

  private:
    Ui::AboutWidgetClass* ui;
};
