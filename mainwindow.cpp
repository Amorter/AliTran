#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "global.h"

//主窗口构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //如果存在apioption,读取到内存
    if(ReadWriteFile::isexist("apioption.txt")){
        apioptionlist = ReadWriteFile::ReadCach(4,"apioption.txt");
    }
    //不存在需要初始化apioptionlist对象，不然会溢出崩溃
    else{
        apioptionlist << "" << "" << "" << "";
    }
    apioption = new class apioption();
}

//主窗口关闭事件
MainWindow::~MainWindow()
{
    delete ui;
    ReadWriteFile::WriteCach(4,apioptionlist.join("\n"),"apioption.txt");
}

//api设置按钮点击事件
void MainWindow::on_apioption_triggered()
{
    apioption->show();
}

