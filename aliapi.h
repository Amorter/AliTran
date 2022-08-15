#ifndef ALIAPI_H
#define ALIAPI_H
#include "alibabacloud/oss/OssClient.h"
#include <fstream>
#include <QFile>
#include <QString>

class Aliapi
{
public:
    Aliapi(QStringList option);
    int pushfile(QString inputfile);
    int downfile(QString downfile);
    int delfile(QString delfile);
};

#endif // ALIAPI_H
