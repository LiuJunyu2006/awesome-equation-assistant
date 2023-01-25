#include <QtCore/QFile>
#include <QtHttpServer/QHttpServer>
#include <QtNetwork/QHostAddress>
#include <QtWidgets/QApplication>

#include "mainwindow.h"
#include "widgets/congruenceequationscalculatorwidget.h"

static inline QString host(const QHttpServerRequest& request) {
    return QString::fromLatin1(request.value("Host"));
}

int main(int argc, char* argv[]) {
    // QApplication::setStyle("Plastique");
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
