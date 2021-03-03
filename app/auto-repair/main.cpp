#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    qDebug() << "TRACE==>   beginning program...";
    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
