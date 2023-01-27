#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget* parent) : QDialog(parent), ui(new Ui::SettingsWidgetClass()) {
    ui->setupUi(this);
}

SettingsWidget::~SettingsWidget() {
    delete ui;
}
