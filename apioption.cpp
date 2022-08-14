#include "apioption.h"
#include "./ui_apioption.h"

apioption::apioption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apioption)
{
    ui->setupUi(this);
}

apioption::~apioption()
{
    delete ui;
}
