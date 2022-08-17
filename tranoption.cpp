#include "tranoption.h"
#include "ui_tranoption.h"

tranoption::tranoption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tranoption)
{
    ui->setupUi(this);
}

tranoption::~tranoption()
{
    delete ui;
}
