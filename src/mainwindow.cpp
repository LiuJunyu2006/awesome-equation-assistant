#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/cubicequationcalculatorwidget.h"
#include "widgets/quadraticequationcalculatorwidget.h"
#include "widgets/quarticequationcalculatorwidget.h"
#include "widgets/simultaneousquadraticequationscalculatorwidget.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow), id(0) {
    ui->setupUi(this);

    connect(ui->actionNewQuadraticEquationCalculator, &QAction::triggered, this,
            &MainWindow::newQuadraticEquationCalculator);
    connect(ui->actionNewSimultaneousQuadraticEquationsCalculator, &QAction::triggered, this,
            &MainWindow::newSimultaneousQuadraticEquationsCalculator);
    connect(ui->actionNewCubicEquationCalculator, &QAction::triggered, this, &MainWindow::newCubicEquationCalculator);
    connect(ui->actionNewQuarticEquationCalculator, &QAction::triggered, this,
            &MainWindow::newQuarticEquationCalculator);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::newQuadraticEquationCalculator() {
    ++id;
    auto widget = new QuadraticEquationCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8("\346\226\271\347\250\213 "
                          "%1\357\274\232\344\270\200\345\205\203\344\272\214\346\254\241\346\226\271\347\250\213")
            .arg(id));
}

void MainWindow::newSimultaneousQuadraticEquationsCalculator() {
    ++id;
    auto widget = new SimultaneousQuadraticEquationsCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8(
            "\346\226\271\347\250\213 "
            "%1\357\274\232\344\272\214\345\205\203\344\272\214\346\254\241\346\226\271\347\250\213\347\273\204")
            .arg(id));
}

void MainWindow::newCubicEquationCalculator() {
    ++id;
    auto widget = new CubicEquationCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8("\346\226\271\347\250\213 "
                          "%1\357\274\232\344\270\200\345\205\203\344\270\211\346\254\241\346\226\271\347\250\213")
            .arg(id));
}

void MainWindow::newQuarticEquationCalculator() {
    ++id;
    auto widget = new SimultaneousQuadraticEquationsCalculatorWidget(ui->tabWidget);
    ui->tabWidget->addTab(
        widget,
        QString::fromUtf8("\346\226\271\347\250\213 "
                          "%1\357\274\232\344\270\200\345\205\203\345\233\233\346\254\241\346\226\271\347\250\213")
            .arg(id));
}