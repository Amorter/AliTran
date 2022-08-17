#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "global.h"
#include "aliapi.h"
#include "readwritefile.h"
#include "curl.h"
#include <QtConcurrent/QtConcurrent>
#include <QMessagebox>

//主窗口构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //如果存option,读取到内存
    if(ReadWriteFile::isexist("apioption.txt")){
        optionlist = ReadWriteFile::ReadCach(4,"apioption.txt");
    }
    //不存在需要初始化apioptionlist对象，不然会溢出崩溃
    else{
        optionlist << "" << "" << "" << "" ;
    }

    //创建apioption窗口对象
    apioption = new class apioption();
}

//主窗口关闭事件
MainWindow::~MainWindow()
{
    delete ui;
    ReadWriteFile::WriteCach(optionlist.join("\n"),"apioption.txt");
}

//api设置按钮点击事件
void MainWindow::on_apioption_triggered()
{
    apioption->show();
}

//翻译按钮点击事件
void MainWindow::on_tranButton_clicked()
{
    ui->outinfo->setText("");
    //使用QT内置库进行异步访问
    QtConcurrent::run([=]() {
        ui->outinfo->append("启动翻译任务……");
        //将文本框内容保存到目录
        ui->outinfo->append("将输入写入本地");
        ReadWriteFile::WriteCach(ui->inputEdit->toPlainText(),"input.txt");
        ui->outinfo->append("写入本地文件成功");
        //创建Aliapi对象
        ui->outinfo->append("初始化阿里云api接口");
        Aliapi *aliapi = new Aliapi(optionlist);
        ui->outinfo->append("成功");
        //上传文件到阿里云OSS
        ui->outinfo->append("上传文件至阿里云OSS");
        if(aliapi->pushfile("input.txt")){
            ui->outinfo->append("上传成功");
            //执行翻译任务
            ui->outinfo->append("执行翻译任务");
            aliapi->tran();
            ui->outinfo->append("获取返回结果url成功");
            ui->outinfo->append("尝试下载文件到本地");
            curl outcurl = curl(outputfileurl);
            if(outcurl.curldown() == 0){
                ui->outinfo->append("下载成功,翻译结果在程序目录下output.txt文件中");
            }
            ui->outinfo->append("删除OSS缓存中");
            aliapi->delfile("input.txt");
            ui->outinfo->append("删除OSS缓存完成");
        }
    });

}

//切换为中文
void MainWindow::on_Lzh_cn_triggered()
{
    int ret = QMessageBox::warning(this, tr("prompt"),  tr("The language will be switched on the next startup"),
                                       QMessageBox::Ok | QMessageBox::Cancel,  QMessageBox::Ok);
    switch(ret)
        {
            case QMessageBox::Ok:
                //此处填入操作，例如msgBox.setText("you choose Save button!");
                ReadWriteFile::WriteCach("zh","language.txt");
                break;
            case QMessageBox::Cancel:
                //此处填入操作
                break;
        }
}

//切换为英语
void MainWindow::on_Len_us_triggered()
{
    int ret = QMessageBox::warning(this, tr("prompt"),  tr("The language will be switched on the next startup"),
                                       QMessageBox::Ok | QMessageBox::Cancel,  QMessageBox::Ok);
    switch(ret)
        {
            case QMessageBox::Ok:
                //此处填入操作，例如msgBox.setText("you choose Save button!");
                ReadWriteFile::WriteCach("en","language.txt");
                break;
            case QMessageBox::Cancel:
                //此处填入操作
                break;
        }
}

//tran option点击事件
void MainWindow::on_tran_option_triggered()
{

}

