#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QtHttpServer/QHttpServer>
#include <QtHttpServer/QHttpServerResponse>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QSslCertificate>
#include <QtNetwork/QSslKey>

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    QHttpServer server;
    server.route("/", []() { return "Awesome Equation Assistant Server"; });

    //server.route("/file/<arg>",
    //             [](const QUrl& url) { return QHttpServerResponse::fromFile(QString(":/%1").arg(url.path())); });

    server.route("/file/katex/<arg>",
                 [](const QUrl& url) { return QString("<head><meta http-equiv=\"Refresh\" content=\"0; URL=https://cdn.jsdelivr.net/npm/katex@0.16.4/dist/%1\"></head>").arg(url.path()); });


    const auto sslCertificateChain = QSslCertificate::fromPath(QStringLiteral(":/assets/certificate.crt"));
    QFile privateKeyFile(QString(":/assets/private.key"));
    privateKeyFile.open(QIODevice::ReadOnly);
    server.sslSetup(sslCertificateChain.front(), QSslKey(&privateKeyFile, QSsl::Rsa));
    privateKeyFile.close();

    const auto port = server.listen(QHostAddress::Any, 50923);
    if (port)
        qDebug() << QString("Running on https://127.0.0.1:%1/").arg(port);
    else
        qDebug() << "Failed";
    return a.exec();
}
