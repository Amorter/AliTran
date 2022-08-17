#include "apioption.h"
#include "./ui_apioption.h"
#include "global.h"

//api窗口构造函数
apioption::apioption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apioption)
{
    ui->setupUi(this);

    //从内存获取apioption显示到文本框
    ui->AcessKeyIDEdit->setText(optionlist.at(0));
    ui->AcessKeySecretEdit->setText(optionlist.at(1));
    ui->EndpointEdit->setText(optionlist.at(2));
    ui->BucketNameEdit->setText(optionlist.at(3));

}

apioption::~apioption()
{
    delete ui;
}


//save按钮点击事件
void apioption::on_buttonBox_accepted()
{
    //从文本框获取内容保存到内存中的apioption对象
    optionlist.replace(0,ui->AcessKeyIDEdit->text());
    optionlist.replace(1,ui->AcessKeySecretEdit->text());
    optionlist.replace(2,ui->EndpointEdit->text());
    optionlist.replace(3,ui->BucketNameEdit->text());
}

//cancel按钮点击事件
void apioption::on_buttonBox_rejected()
{

}

