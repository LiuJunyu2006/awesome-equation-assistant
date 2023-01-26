#pragma once

#include <QtWidgets/QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

  public slots:
    void generateSystemOfLinearEquationsCalculator(int unknowns, int equations);

    void generateCongruenceEquationsCalculator(int unknowns);

  private slots:
    void createSystemOfLinearEquationsCalculator();

    void newQuadraticEquationCalculator();
    void newSimultaneousQuadraticEquationsCalculator();

    void newCubicEquationCalculator();
    void newQuarticEquationCalculator();

    void newLinearCongruenceEquationCalculator();
    void createCongruenceEquationsCalculator();

    void newZeroPointOfMonotonicFunctionCalculator();

    void closeTab(int index) const;

    void on_actionIndependentForm_triggered();

    void on_tabWidget_tabBarDoubleClicked(int index);

  private:
    Ui::MainWindow* ui;
    int id;
};
