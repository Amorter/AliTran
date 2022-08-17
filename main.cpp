#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "readwritefile.h"
int main(int argc, char *argv[])
{
    if(!ReadWriteFile::isexist("./language.txt")){
        ReadWriteFile::WriteCach("en","./language.txt");
    }

    //检查语言设置
    if(ReadWriteFile::ReadCach(1,"./language.txt").at(0).toStdString()=="zh"){
        QApplication a(argc, argv);
        QTranslator translator;
        if(translator.load("zh.qm")){
            a.installTranslator(&translator);
            MainWindow w;
            w.show();
            return a.exec();
        }
    //默认English
    }else{
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
}

