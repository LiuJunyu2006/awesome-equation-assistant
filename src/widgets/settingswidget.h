#pragma once

#include "ui_settingswidget.h"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class SettingsWidgetClass;
};
QT_END_NAMESPACE

class SettingsWidget : public QDialog {
    Q_OBJECT

  public:
    SettingsWidget(QWidget* parent = nullptr);
    ~SettingsWidget();

  private:
    Ui::SettingsWidgetClass* ui;
};
