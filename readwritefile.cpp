#include "readwritefile.h"
#include <QFile>
#include <QTextStream>

//读写文件工具类
ReadWriteFile::ReadWriteFile()
{
}

//读取文件
QStringList ReadWriteFile::ReadCach(int line,QString name){
    QStringList out;
    QFile input = QFile(name);
    QTextStream inputstream = QTextStream(&input);
    input.open(QIODevice::ReadOnly);
    for (int var = 0; var < line; ++var)
        out << inputstream.readLine();
    return out;
}

//写入文件
void ReadWriteFile::WriteCach(QString text,QString name){
    QFile input = QFile(name);
    QTextStream inputstream = QTextStream(&input);
    input.open(QIODevice::WriteOnly | QIODevice::Truncate);
    inputstream << text;
    input.close();
}

//判断文件是否存在
bool ReadWriteFile::isexist(QString name){
    QFile input = QFile(name);
    return input.exists();
}
