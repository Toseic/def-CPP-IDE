#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1500,1200);
    QFile qssFile("./theme.qss");
    qssFile.open(QFile::ReadOnly);
    QString qss = QLatin1String(qssFile.readAll());
    w.setStyleSheet(qss);
    qssFile.close();
    w.setWindowIcon(QIcon("./icon.png"));
    w.show();

    return a.exec();
}
