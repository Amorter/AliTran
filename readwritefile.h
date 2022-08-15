#ifndef READWRITEFILE_H
#define READWRITEFILE_H
#include <QString>
#include <iostream>


class ReadWriteFile
{
public:
    ReadWriteFile();
    QStringList ReadCach(int line,QString name);
    void WriteCach(int line,QString *text,QString name);
    bool isexist(QString name);
};

#endif // READWRITEFILE_H
