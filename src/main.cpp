#include <QtGui/QFont>

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

#include "mainwindow.h"
#include "widgets/congruenceequationscalculatorwidget.h"

void checkConfigDir() {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    if (!configDir.exists())
        QDir::home().mkdir(".awesome-equation-assistant");
}

void checkConfigTheme() {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configTheme(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.basic-theme"));
    if (!configTheme.exists()) {
        configTheme.open(QFile::WriteOnly);
        configTheme.write("Default");
        configTheme.close();
    }
}

void applyConfigTheme() {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configTheme(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.basic-theme"));
    configTheme.open(QFile::ReadOnly);
    char theme[10];
    configTheme.read(theme, 10);
    QApplication::setStyle(theme);
    configTheme.close();
}

void checkConfigFont() {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configFont(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.font-family"));
    if (!configFont.exists()) {
        configFont.open(QFile::WriteOnly);
        configFont.write(QWidget().font().toString().toUtf8());
        configFont.close();
    }
}

void applyConfigFont() {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configFont(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.font-family"));
    configFont.open(QFile::ReadOnly);
    char font[1000];
    configFont.read(font, 1000);
    QFont newFont;
    newFont.fromString(QString::fromUtf8(font));
    QApplication::setFont(newFont);
}

void checkConfigGeometryX(const MainWindow& w) {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configGeometryX(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.x"));
    if (!configGeometryX.exists()) {
        configGeometryX.open(QFile::WriteOnly);
        configGeometryX.write(std::to_string(w.geometry().x()).c_str());
        configGeometryX.close();
    }
}

void applyConfigGeometryX(MainWindow& w) {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configGeometryX(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.x"));
    configGeometryX.open(QFile::ReadOnly);
    char num[10];
    configGeometryX.read(num, 10);
    w.setGeometry(std::stoi(num), w.y(), w.width(), w.height());
}

void checkConfigGeometryY(const MainWindow& w) {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configGeometryY(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.y"));
    if (!configGeometryY.exists()) {
        configGeometryY.open(QFile::WriteOnly);
        configGeometryY.write(std::to_string(w.geometry().y()).c_str());
        configGeometryY.close();
    }
}

void applyConfigGeometryY(MainWindow& w) {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configGeometryY(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.y"));
    configGeometryY.open(QFile::ReadOnly);
    char num[10];
    configGeometryY.read(num, 10);
    w.setGeometry(w.x(), std::stoi(num), w.width(), w.height());
}

void checkConfigGeometryWidth(const MainWindow& w) {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configGeometryWidth(
        configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.width"));
    if (!configGeometryWidth.exists()) {
        configGeometryWidth.open(QFile::WriteOnly);
        configGeometryWidth.write(std::to_string(w.geometry().width()).c_str());
        configGeometryWidth.close();
    }
}

void applyConfigGeometryWidth(MainWindow& w) {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configGeometryWidth(
        configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.width"));
    configGeometryWidth.open(QFile::ReadOnly);
    char num[10];
    configGeometryWidth.read(num, 10);
    w.setGeometry(w.x(), w.y(), std::stoi(num), w.height());
}

void checkConfigGeometryHeight(const MainWindow& w) {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configGeometryHeight(
        configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.height"));
    if (!configGeometryHeight.exists()) {
        configGeometryHeight.open(QFile::WriteOnly);
        configGeometryHeight.write(std::to_string(w.geometry().height()).c_str());
        configGeometryHeight.close();
    }
}

void applyConfigGeometryHeight(MainWindow& w) {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    QFile configGeometryHeight(
        configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.height"));
    configGeometryHeight.open(QFile::ReadOnly);
    char num[10];
    configGeometryHeight.read(num, 10);
    w.setGeometry(w.x(), w.y(), w.width(), std::stoi(num));
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    checkConfigDir();
    checkConfigTheme();
    applyConfigTheme();
    checkConfigFont();
    applyConfigFont();

    MainWindow w;

    w.show();

    checkConfigGeometryX(w);
    applyConfigGeometryX(w);
    checkConfigGeometryY(w);
    applyConfigGeometryY(w);
    checkConfigGeometryWidth(w);
    applyConfigGeometryWidth(w);
    checkConfigGeometryHeight(w);
    applyConfigGeometryHeight(w);

    return a.exec();
}
