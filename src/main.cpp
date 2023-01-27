#include <QtCore/QFile>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

#include "mainwindow.h"
#include "widgets/congruenceequationscalculatorwidget.h"

int main(int argc, char* argv[]) {
    QApplication::setStyle("Windows");
    QApplication a(argc, argv);
    
    MainWindow w;
    w.show();

    return a.exec();
}
