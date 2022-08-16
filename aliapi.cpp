#include "aliapi.h"
#include "alibabacloud/oss/OssClient.h"
#include "alibabacloud/alimt/AlimtClient.h"
#include "alibabacloud/core/AlibabaCloud.h"
#include "readwritefile.h"

QStringList option;


//阿里云api
Aliapi::Aliapi(QStringList inputoption)
{
    option = inputoption;
}



//上传文件
bool Aliapi::pushfile(QString inputfile){
    using namespace AlibabaCloud::OSS;

    /* 初始化OSS账号信息。*/
    /* 阿里云账号AccessKey拥有所有API的访问权限，风险很高。强烈建议您创建并使用RAM用户进行API访问或日常运维，请登录RAM控制台创建RAM用户。*/
    std::string AccessKeyId = option.at(0).toStdString();
    std::string AccessKeySecret = option.at(1).toStdString();
    /* yourEndpoint填写Bucket所在地域对应的Endpoint。以华东1（杭州）为例，Endpoint填写为https://oss-cn-hangzhou.aliyuncs.com。*/
    std::string Endpoint = option.at(2).toStdString();
    /* 填写Bucket名称，例如examplebucket。*/
    std::string BucketName = option.at(3).toStdString();
    /* 填写Object完整路径，完整路径中不能包含Bucket名称，例如exampledir/exampleobject.txt。*/
    std::string ObjectName = "cach/" + inputfile.toStdString();

    /* 初始化网络等资源。*/
    InitializeSdk();

    ClientConfiguration conf;
    OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
    /* 填写本地文件完整路径，例如D:\\localpath\\examplefile.txt，其中localpath为本地文件examplefile.txt所在本地路径。*/
    std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(inputfile.toStdString(), std::ios::in | std::ios::binary);
    PutObjectRequest request(BucketName, ObjectName, content);

    /*（可选）请参见如下示例设置访问权限ACL为私有（private）以及存储类型为标准存储（Standard）。*/
    //request.MetaData().addHeader("x-oss-object-acl", "private");
    //request.MetaData().addHeader("x-oss-storage-class", "Standard");

    auto outcome = client.PutObject(request);

    if (!outcome.isSuccess()) {
        /* 异常处理。*/
        std::cout << "PutObject fail" <<
                     ",code:" << outcome.error().Code() <<
                     ",message:" << outcome.error().Message() <<
                     ",requestId:" << outcome.error().RequestId() << std::endl;
        ShutdownSdk();
        return false;
    }

    /* 释放网络等资源。*/
    ShutdownSdk();
    return true;
}


//下载文件
bool Aliapi::downfile(QString downfile){
    using namespace AlibabaCloud::OSS;
    /* 初始化OSS账号信息。*/
    /* 阿里云账号AccessKey拥有所有API的访问权限，风险很高。强烈建议您创建并使用RAM用户进行API访问或日常运维，请登录RAM控制台创建RAM用户。*/
    std::string AccessKeyId = option.at(0).toStdString();
    std::string AccessKeySecret = option.at(1).toStdString();
    /* yourEndpoint填写Bucket所在地域对应的Endpoint。以华东1（杭州）为例，Endpoint填写为https://oss-cn-hangzhou.aliyuncs.com。*/
    std::string Endpoint = option.at(2).toStdString();
    /* 填写Bucket名称，例如examplebucket。*/
    std::string BucketName = option.at(3).toStdString();
    /* 填写Object完整路径，完整路径中不能包含Bucket名称，例如exampledir/exampleobject.txt。*/
    std::string ObjectName = "cach/" + downfile.toStdString();
    //保存到本地的文件名
    std::string FileNametoSave = downfile.toStdString();

    /* 初始化网络等资源。*/
    InitializeSdk();

    ClientConfiguration conf;
    OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);

    /* 下载Object到本地文件。*/
    GetObjectRequest request(BucketName, ObjectName);
    request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc| std::ios_base::binary); });

    auto outcome = client.GetObject(request);

    if (outcome.isSuccess()) {
        std::cout << "GetObjectToFile success" << outcome.result().Metadata().ContentLength() << std::endl;
    }
    else {
        /* 异常处理。*/
        std::cout << "GetObjectToFile fail" <<
                     ",code:" << outcome.error().Code() <<
                     ",message:" << outcome.error().Message() <<
                     ",requestId:" << outcome.error().RequestId() << std::endl;
        ShutdownSdk();
        return false;
    }

    /* 释放网络等资源。*/
    ShutdownSdk();
    return true;
}

//删除文件
bool Aliapi::delfile(QString delfile){
    using namespace AlibabaCloud::OSS;
    /* 初始化OSS账号信息。*/
    /* 阿里云账号AccessKey拥有所有API的访问权限，风险很高。强烈建议您创建并使用RAM用户进行API访问或日常运维，请登录RAM控制台创建RAM用户。*/
    std::string AccessKeyId = option.at(0).toStdString();
    std::string AccessKeySecret = option.at(1).toStdString();
    /* yourEndpoint填写Bucket所在地域对应的Endpoint。以华东1（杭州）为例，Endpoint填写为https://oss-cn-hangzhou.aliyuncs.com。*/
    std::string Endpoint = option.at(2).toStdString();
    /* 填写Bucket名称，例如examplebucket。*/
    std::string BucketName = option.at(3).toStdString();
    /* 填写Object完整路径，完整路径中不能包含Bucket名称，例如exampledir/exampleobject.txt。*/
    std::string ObjectName = "cach/" + delfile.toStdString();

    /* 初始化网络等资源。*/
    InitializeSdk();

    ClientConfiguration conf;
    OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);

    DeleteObjectRequest request(BucketName, ObjectName);

    /* 删除文件。*/
    auto outcome = client.DeleteObject(request);

    if (!outcome.isSuccess()) {
        /* 异常处理。*/
        std::cout << "DeleteObject fail" <<
                     ",code:" << outcome.error().Code() <<
                     ",message:" << outcome.error().Message() <<
                     ",requestId:" << outcome.error().RequestId() << std::endl;
        ShutdownSdk();
        return false;
    }

    /* 释放网络等资源。*/
    ShutdownSdk();
    return true;
}

//翻译任务
bool Aliapi::tran()
{
    std::cout << "Hello World" << std::endl;

    using namespace AlibabaCloud;
    using namespace AlibabaCloud::Alimt;
    AlibabaCloud::InitializeSdk();
    AlibabaCloud::ClientConfiguration configuration( "cn-hangzhou" );
    AlibabaCloud::Credentials credential( option.at(0).toStdString() , option.at(1).toStdString() );
    /* use STS Token
       credential.setSessionToken( "<your-sts-token>" );
       */

    //文档翻译任务
    AlimtClient client( credential, configuration );

    Model::CreateDocTranslateTaskRequest request;
    request.setTargetLanguage("zh");
    request.setSourceLanguage("en");
    request.setFileUrl("https://ksvip1.oss-cn-beijing.aliyuncs.com/cach/input.txt");

    auto outcome = client.createDocTranslateTask( request );
    if ( !outcome.isSuccess() )
    {
        std::cout << outcome.error().errorMessage() << std::endl;
        AlibabaCloud::ShutdownSdk();
        return false;
    }

    AlibabaCloud::ShutdownSdk();


    AlibabaCloud::InitializeSdk();
    //获取文档翻译任务结果下载url
    AlimtClient client1( credential, configuration );
    Model::GetDocTranslateTaskRequest request1;
    request1.setTaskId(outcome.result().getTaskId());
    auto outcome1 = client1.getDocTranslateTask( request1 );
    if( !outcome1.isSuccess() )
    {
        std::cout << outcome.error().errorMessage() << std::endl;
        AlibabaCloud::ShutdownSdk();
    }
    std::cout << outcome1.result().getStatus() << std::endl;

    AlibabaCloud::ShutdownSdk();
    return true;
}


