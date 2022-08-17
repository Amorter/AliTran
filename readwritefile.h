#ifndef READWRITEFILE_H
#define READWRITEFILE_H
#include <QString>
#include <iostream>


class ReadWriteFile
{
public:
    ReadWriteFile();
    static QStringList ReadCach(int line,QString name);
    static void WriteCach(QString text,QString name);
    static bool isexist(QString name);
    static QStringList InitializeOption(QStringList);//初始化option
};

#endif // READWRITEFILE_H
