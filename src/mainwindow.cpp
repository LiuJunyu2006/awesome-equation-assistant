#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QDir>
#include <QtCore/QProcess>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFontDialog>

#include <widgets/settingswidget.h>

#include "widgets/aboutwidget.h"
#include "widgets/congruenceequationscalculatorwidget.h"
#include "widgets/createcongruenceequationscalculatordialog.h"
#include "widgets/createsystemoflinearequationscalculatordialog.h"
#include "widgets/cubicequationcalculatorwidget.h"
#include "widgets/linearcongruenceequationcalculatorwidget.h"
#include "widgets/quadraticequationcalculatorwidget.h"
#include "widgets/quarticequationcalculatorwidget.h"
#include "widgets/simultaneousquadraticequationscalculatorwidget.h"
#include "widgets/systemoflinearequationscalculatorwidget.h"
#include "widgets/zeropointofmonotonicfunctioncalculatorwidget.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow), id(0) {
    ui->setupUi(this);

    connect(ui->actionNewSystemOfLinearEquationsCalculator, &QAction::triggered, this,
            &MainWindow::createSystemOfLinearEquationsCalculator);

    connect(ui->actionNewQuadraticEquationCalculator, &QAction::triggered, this,
            &MainWindow::newQuadraticEquationCalculator);
    connect(ui->actionNewSimultaneousQuadraticEquationsCalculator, &QAction::triggered, this,
            &MainWindow::newSimultaneousQuadraticEquationsCalculator);

    connect(ui->actionNewCubicEquationCalculator, &QAction::triggered, this, &MainWindow::newCubicEquationCalculator);
    connect(ui->actionNewQuarticEquationCalculator, &QAction::triggered, this,
            &MainWindow::newQuarticEquationCalculator);

    connect(ui->actionNewLinearCongruenceEquationCalculator, &QAction::triggered, this,
            &MainWindow::newLinearCongruenceEquationCalculator);
    connect(ui->actionNewCongruenceEquationsCalculator, &QAction::triggered, this,
            &MainWindow::createCongruenceEquationsCalculator);

    connect(ui->actionNewZeroPointOfMonotonicFunctionCalculator, &QAction::triggered, this,
            &MainWindow::newZeroPointOfMonotonicFunctionCalculator);

    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::generateSystemOfLinearEquationsCalculator(int unknowns, int equations) {
    ++id;
    ui->actionIndependentForm->setEnabled(true);
    const auto widget = new SystemOfLinearEquationsCalculatorWidget(ui->tabWidget);
    widget->init(unknowns, equations);
    ui->tabWidget->addTab(
        widget, QString::fromUtf8("\346\226\271\347\250\213 "
                                  "%1\357\274\232\347\272\277\346\200\247\346\226\271\347\250\213\347\273\204")
                    .arg(id));
    ui->tabWidget->setCurrentWidget(widget);
}

void MainWindow::generateCongruenceEquationsCalculator(int unknowns) {
    ++id;
    ui->actionIndependentForm->setEnabled(true);
    const auto widget = new CongruenceEquationsCalculatorWidget(ui->tabWidget);
    widget->init(unknowns);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8(
            "\346\226\271\347\250\213 "
            "%1\357\274\232\347\272\277\346\200\247\345\220\214\344\275\231\346\226\271\347\250\213\347\273\204")
            .arg(id));
    ui->tabWidget->setCurrentWidget(widget);
}

void MainWindow::createSystemOfLinearEquationsCalculator() {
    const auto dialog = new CreateSystemOfLinearEquationsCalculatorDialog(this);
    dialog->setModal(true);
    dialog->show();
}

void MainWindow::newQuadraticEquationCalculator() {
    ++id;
    ui->actionIndependentForm->setEnabled(true);
    const auto widget = new QuadraticEquationCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8("\346\226\271\347\250\213 "
                          "%1\357\274\232\344\270\200\345\205\203\344\272\214\346\254\241\346\226\271\347\250\213")
            .arg(id));
    ui->tabWidget->setCurrentWidget(widget);
}

void MainWindow::newSimultaneousQuadraticEquationsCalculator() {
    ++id;
    ui->actionIndependentForm->setEnabled(true);
    const auto widget = new SimultaneousQuadraticEquationsCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8(
            "\346\226\271\347\250\213 "
            "%1\357\274\232\344\272\214\345\205\203\344\272\214\346\254\241\346\226\271\347\250\213\347\273\204")
            .arg(id));
    ui->tabWidget->setCurrentWidget(widget);
}

void MainWindow::newCubicEquationCalculator() {
    ++id;
    ui->actionIndependentForm->setEnabled(true);
    const auto widget = new CubicEquationCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8("\346\226\271\347\250\213 "
                          "%1\357\274\232\344\270\200\345\205\203\344\270\211\346\254\241\346\226\271\347\250\213")
            .arg(id));
    ui->tabWidget->setCurrentWidget(widget);
}

void MainWindow::newQuarticEquationCalculator() {
    ++id;
    ui->actionIndependentForm->setEnabled(true);
    const auto widget = new QuarticEquationCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8("\346\226\271\347\250\213 "
                          "%1\357\274\232\344\270\200\345\205\203\345\233\233\346\254\241\346\226\271\347\250\213")
            .arg(id));
    ui->tabWidget->setCurrentWidget(widget);
}

void MainWindow::newLinearCongruenceEquationCalculator() {
    ++id;
    ui->actionIndependentForm->setEnabled(true);
    const auto widget = new LinearCongruenceEquationCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8("\346\226\271\347\250\213 "
                          "%1\357\274\232\347\272\277\346\200\247\345\220\214\344\275\231\346\226\271\347\250\213")
            .arg(id));
    ui->tabWidget->setCurrentWidget(widget);
}

void MainWindow::createCongruenceEquationsCalculator() {
    const auto dialog = new CreateCongruenceEquationsCalculatorDialog(this);
    dialog->setModal(true);
    dialog->show();
}

void MainWindow::newZeroPointOfMonotonicFunctionCalculator() {
    ++id;
    ui->actionIndependentForm->setEnabled(true);
    const auto widget = new ZeroPointOfMonotonicFunctionCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8("\346\226\271\347\250\213 "
                          "%1\357\274\232\345\215\225\350\260\203\345\207\275\346\225\260\351\233\266\347\202\271")
            .arg(id));
    ui->tabWidget->setCurrentWidget(widget);
}

void MainWindow::closeTab(int index) const {
    ui->tabWidget->removeTab(index);
    if (ui->tabWidget->count() == 0)
        ui->actionIndependentForm->setEnabled(false);
}

void MainWindow::on_actionIndependentForm_triggered() {
    const auto p = ui->tabWidget->currentWidget();
    p->setParent(this);
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(p));
    p->setWindowFlag(Qt::Window);
    p->move(x() + 10, y() + 10);
    p->show();
    if (ui->tabWidget->count() == 0)
        ui->actionIndependentForm->setEnabled(false);
}

void MainWindow::on_actionAddMainWindow_triggered() {
    QProcess* newProcess = new QProcess;
    newProcess->start(QDir(QApplication::applicationDirPath()).absoluteFilePath("awesome-equation-assistant"));
}

void MainWindow::on_actionSettings_triggered() {
    const auto p = new SettingsWidget(this);
    p->setModal(true);
    p->show();
}

void MainWindow::on_actionFontSettings_triggered() {
    bool ok;
    QFont newFont = QFontDialog::getFont(&ok, font(), this);
    if (ok) {
        QApplication::setFont(newFont);

        const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
        if (!configDir.exists())
            QDir::home().mkdir(".awesome-equation-assistant");

        QFile configFont(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.font-family"));
        configFont.open(QFile::WriteOnly);
        configFont.write(newFont.toString().toUtf8());
        configFont.close();
    }
}

void MainWindow::on_actionAbout_triggered() {
    const auto p = new AboutWidget(this);
    p->setModal(true);
    p->show();
}

void MainWindow::on_tabWidget_tabBarDoubleClicked(int index) {
    const auto p = ui->tabWidget->widget(index);
    p->setParent(this);
    ui->tabWidget->removeTab(index);
    p->setWindowFlag(Qt::Window);
    p->move(x() + 10, y() + 10);
    p->show();
    if (ui->tabWidget->count() == 0)
        ui->actionIndependentForm->setEnabled(false);
}

void MainWindow::closeEvent(QCloseEvent* event) {
    const QDir configDir(QDir::homePath() + QDir::separator() + ".awesome-equation-assistant");
    if (!configDir.exists())
        QDir::home().mkdir(".awesome-equation-assistant");

    QFile configGeometryX(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.x"));
    configGeometryX.open(QFile::WriteOnly);
    configGeometryX.write(std::to_string(geometry().x()).c_str());
    configGeometryX.close();

    QFile configGeometryY(configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.y"));
    configGeometryY.open(QFile::WriteOnly);
    configGeometryY.write(std::to_string(geometry().y()).c_str());
    configGeometryY.close();

    QFile configGeometryWidth(
        configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.width"));
    configGeometryWidth.open(QFile::WriteOnly);
    configGeometryWidth.write(std::to_string(geometry().width()).c_str());
    configGeometryWidth.close();

    QFile configGeometryHeight(
        configDir.absoluteFilePath("awesome-equation-assistant.config.appearance.geometry.height"));
    configGeometryHeight.open(QFile::WriteOnly);
    configGeometryHeight.write(std::to_string(geometry().height()).c_str());
    configGeometryHeight.close();
}