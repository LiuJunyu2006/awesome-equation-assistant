#include <QtWidgets/QApplication>

#include "mainwindow.h"

#include "widgets/inputareawidget.h"
#include "widgets/congruenceequationscalculatorwidget.h"

int main(int argc, char* argv[]) {
    // QApplication::setStyle("Plastique");
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    InputAreaWidget iw(nullptr);
    iw.init(3, 3);
    iw.show();

    CongruenceEquationsCalculatorWidget cw(nullptr);
    cw.init(3);
    cw.show();

    return a.exec();
}
