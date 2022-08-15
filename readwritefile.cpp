#include "readwritefile.h"
#include <QFile>
#include <QTextStream>
ReadWriteFile::ReadWriteFile()
{
}

//写入文件
QStringList ReadWriteFile::ReadCach(int line,QString name){
    QStringList out;
    QFile input = QFile(name);
    QTextStream inputstream = QTextStream(&input);
    input.open(QIODevice::ReadOnly);
    for (int var = 0; var < line; ++var)
        out << inputstream.readLine();
    return out;
}

//读取文件
void ReadWriteFile::WriteCach(int line,QString *text,QString name){
    QFile input = QFile(name);
    QTextStream inputstream = QTextStream(&input);
    input.open(QIODevice::WriteOnly | QIODevice::Truncate);
    inputstream << *text;
    input.close();
}

//判断文件是否存在
bool isexist(QString name){
    QFile input = QFile(name)
}
