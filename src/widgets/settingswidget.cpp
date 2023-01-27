#include "settingswidget.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtGui/QFont>

SettingsWidget::SettingsWidget(QWidget* parent) : QDialog(parent), ui(new Ui::SettingsWidgetClass()) {
    ui->setupUi(this);
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    if (!configDir.exists())
        QDir::home().mkdir(".awesome-equation-assistant");

    QFile configTheme(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.basic-theme"));
    if (!configTheme.exists()) {
        configTheme.open(QFile::WriteOnly);
        configTheme.write("Default");
        configTheme.close();
    }
    configTheme.open(QFile::ReadOnly);
    char theme[10];
    configTheme.read(theme, 10);
    if (QString(theme) == "Windows")
        ui->comboBoxTheme->setCurrentText("Classic");
    else if (QString(theme) == "Fusion")
        ui->comboBoxTheme->setCurrentText("Fusion");
    else
        ui->comboBoxTheme->setCurrentText("Default");
    configTheme.close();
}

SettingsWidget::~SettingsWidget() {
    delete ui;
}

void SettingsWidget::on_buttonBox_rejected() {
    close();
}

void SettingsWidget::on_buttonBox_accepted() {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    if (!configDir.exists())
        QDir::home().mkdir(".awesome-equation-assistant");

    QFile configTheme(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.basic-theme"));
    configTheme.open(QFile::WriteOnly);
    if (ui->comboBoxTheme->currentText() == "Classic")
        configTheme.write("Windows");
    else
        configTheme.write(ui->comboBoxTheme->currentText().toLocal8Bit());
    configTheme.close();
    close();
}