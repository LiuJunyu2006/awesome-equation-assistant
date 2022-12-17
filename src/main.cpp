#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtWidgets/QApplication>

#include "mainwindow.h"
#include "math/fraction.h"
#include "widgets/katexviewer.h"

int main(int argc, char* argv[]) {
    // QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    // QApplication::setStyle("Windows");
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
