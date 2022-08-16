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
    ui->AcessKeyIDEdit->setText(apioptionlist.at(0));
    ui->AcessKeySecretEdit->setText(apioptionlist.at(1));
    ui->EndpointEdit->setText(apioptionlist.at(2));
    ui->BucketNameEdit->setText(apioptionlist.at(3));

}

apioption::~apioption()
{
    delete ui;
}


//save按钮点击事件
void apioption::on_buttonBox_accepted()
{

}

//cancel按钮点击事件
void apioption::on_buttonBox_rejected()
{

}

