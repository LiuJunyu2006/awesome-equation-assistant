#include "mainwindow.h"

#include "quadraticequationcalculatorwidget.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->actionNewQuadraticEquationCalculator, &QAction::triggered, this,
            &MainWindow::newQuadraticEquationCalculator);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::newQuadraticEquationCalculator() {
    auto new_widget = new QuadraticEquationCalculatorWidget(ui->mdiArea);
    ui->mdiArea->addSubWindow(new_widget);
    new_widget->show();
}
