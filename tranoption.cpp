#include "tranoption.h"
#include "ui_tranoption.h"
#include "global.h"
#include "tranlanguage.h"

tranoption::tranoption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tranoption)
{
    ui->setupUi(this);
    //加载缓存
}

tranoption::~tranoption()
{
    delete ui;
}

void tranoption::on_buttonBox_accepted()
{
    optionlist.replace(4, tranlanguage::catchlanguage(ui->Source->currentIndex()));
    optionlist.replace(5, tranlanguage::catchlanguage(ui->Target->currentIndex()));
    optionlist.replace(6, ui->TimeOutEdit->text());

}


void tranoption::on_buttonBox_rejected()
{

}

