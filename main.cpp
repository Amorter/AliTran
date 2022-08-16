#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
     if(translator.load("zh.qm"))
     a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
