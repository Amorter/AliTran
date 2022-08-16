#ifndef CURL_H
#define CURL_H
#include <QString>

class curl
{
public:
    curl(QString geturl);
    int curldown();
    static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);
};

#endif // CURL_H
