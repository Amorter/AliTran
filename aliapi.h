#ifndef ALIAPI_H
#define ALIAPI_H
#include <fstream>
#include <QFile>
#include <QString>

class Aliapi
{
public:
    Aliapi(QStringList option);
    bool pushfile(QString inputfile);
    bool downfile(QString downfile);
    bool delfile(QString delfile);
    bool tran();
};

#endif // ALIAPI_H
