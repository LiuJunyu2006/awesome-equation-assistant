#include <QtWidgets/QApplication>

#include "mainwindow.h"
#include "widgets/congruenceequationscalculatorwidget.h"
#include "widgets/inputareawidget.h"

int main(int argc, char* argv[]) {
    // QApplication::setStyle("Plastique");
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
