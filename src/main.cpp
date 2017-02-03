#include "mainwindow.h"
//#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    QObject* root = engine.rootObjects()[0];
//    HandlerSignals* handler = new HandlerSignals(root);

//    QObject::connect(root, SIGNAL(qmlSignal(QString)),
//                     handler, SLOT(cppSlot(QString)));

    return app.exec();
}
