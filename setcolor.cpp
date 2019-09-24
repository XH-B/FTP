#include "setcolor.h"
#include "ui_setcolor.h"

setColor::setColor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setColor)
{
    ui->setupUi(this);
}

setColor::~setColor()
{
    delete ui;
}
