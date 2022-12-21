#include <QLabel>
#include <QtWidgets/QApplication>

#include "mainwindow.h"

#include "solutions/fraction.h"

int main(int argc, char* argv[]) {
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    // QApplication::setStyle("Plastique");
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
