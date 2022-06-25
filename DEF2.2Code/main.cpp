#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1500,1200);
        
    QFile qssFile(":/new/prefix1/theme/Light.qss");// load from cachefile TODO:
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        QString strFile = qssFile.readAll();
        w.setStyleSheet(strFile);
        qssFile.close();/*记得关闭QSS文件*/
    }

    w.setWindowIcon(QIcon("./icon.png"));
    w.show();


    return a.exec();
}
