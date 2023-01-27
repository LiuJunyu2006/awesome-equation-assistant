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
    ~SettingsWidget() override;

  private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

  private:
    Ui::SettingsWidgetClass* ui;
};
