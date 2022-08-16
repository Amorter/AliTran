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
};

#endif // READWRITEFILE_H
