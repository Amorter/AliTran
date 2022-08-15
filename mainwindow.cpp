#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    apioption = new class apioption();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_apioption_triggered()
{
    apioption->show();

}

