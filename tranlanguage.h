#ifndef TRANLANGUAGE_H
#define TRANLANGUAGE_H
#include <QString>

class tranlanguage
{
public:
    tranlanguage();
    QString static catchlanguage(int index);
    int static catchindex(QString language);
};

#endif // TRANLANGUAGE_H
