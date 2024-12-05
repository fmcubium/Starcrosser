#include "mainwindow.h"

#include <QApplication>

#include "model/Graph.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Graph::create();
    w.show();
    int exitCode = a.exec();
    Graph::destroy();
    return exitCode;
}
